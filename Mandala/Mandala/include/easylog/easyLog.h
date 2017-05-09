#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <string>
#include <set>
#include <direct.h>
#include <windows.h>

using namespace std;

	class easyLog
	{
	public:
		easyLog(string logDir);
		easyLog();

		bool addInfoToLog(string namelog, string newinfo);
		bool closeLog(string namelog);

	private:
		set<string> logs;
		string log;
		string getTime();
		void addNewLogFile(string namelog);
		bool addLogInfo(string info, string patch);
	};

	
