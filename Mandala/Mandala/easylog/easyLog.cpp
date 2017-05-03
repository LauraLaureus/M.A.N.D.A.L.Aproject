#include "easyLog.h"

	// Constructores: Ejemplo de string de directorio "c:\\logs\\newLogs\\"
	easyLog::easyLog(string logDir)
	{
		log = logDir;
		_mkdir(log.c_str());
	}

	easyLog::easyLog()
	{
		log = "log\\";
		_mkdir(log.c_str());
	}

	// Método encargado de añadir una nueva línea al fichero de log especificado.
	// -En caso de no existir el fichero, este es creado.
	// -Si existe, la información es añadida al final del fichero.

	bool easyLog::addInfoToLog(string namelog, string newinfo)
	{
		// Se comprueba si existe ya un fichero con ese nombre.
		if (easyLog::logs.count(namelog + ".txt")==0)
		{
			addNewLogFile(namelog);
		}
		set<string>::iterator iter = logs.find(namelog + ".txt");
		if (easyLog::addLogInfo(newinfo, *iter)) return true;
		return false;
	}

	bool easyLog::closeLog(string namelog)
	{
		return false;
	}


	//Hora actual del sistema.
	// -El formato es: "DD/MM/YY|hh:mm:ss-> "
	string easyLog::getTime()
	{
		char buffer[32];
		__time32_t clock;
		struct tm newtime;
		_time32(&clock);
		_localtime32_s(&newtime, &clock);
		strftime(buffer, 32, "%D|%T->", &newtime);
		return string(buffer);
	}

	// Añadimos un nuevo log a la lista de logs que se están usando en la ejecución actual.
	void easyLog::addNewLogFile(string namelog)
	{
		logs.insert(namelog + ".txt");
	}

	// Se añade una nueva línea de al final del fichero de log especificado.
	bool easyLog::addLogInfo(string info, string patch)
	{
		FILE* fp;
		int err = fopen_s(&fp, (log+ patch).c_str(), "a");
		if (err != 0)
		{
			return false;
		}
		fputs((getTime() + ": " + info + "\n").c_str(), fp);
		fclose(fp);
		return true;
	}


