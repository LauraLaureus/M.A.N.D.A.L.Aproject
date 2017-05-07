#include "SystemHeader.h"
#include "AudioHeader.h"
#include "GraphicsHeader.h"
#include "ThreadingHeader.h"
#include "easylog\easyLog.h"



using namespace std;

/*
void changeViewPort(int w, int h)
{
	glViewport(0, 0, w, h);
}

void render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glutSwapBuffers();
}



int main(int argc, char* argv[]) {

	// Initialize GLUT
	glutInit(&argc, argv);
	// Set up some memory buffers for our display
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	// Set the window size
	glutInitWindowSize(800, 600);
	// Create the window with the title "Hello,GL"
	glutCreateWindow("Hello, GL");
	// Bind the two functions (above) to respond when necessary
	glutReshapeFunc(changeViewPort);
	glutDisplayFunc(render);

	// Very important!  This initializes the entry points in the OpenGL driver so we can 
	// call all the functions in the API.
	GLenum err = glewInit();
	if (GLEW_OK != err) {
		fprintf(stderr, "GLEW error");
		return 1;
	}


	glutMainLoop();
	return 0;
}*/


int main(int argc, char *argv[]) {

	/*soundCollection = new std::unordered_map<std::string,sf::SoundBuffer>();
	std::string fileName = AudioMaster::getAbsoluteFileName("testAudio.wav");
	std::string fileName2 = AudioMaster::getAbsoluteFileName("testAudio2.wav");

	sf::SoundBuffer internalBuffer = AudioMaster::loadFile(fileName);
	sf::SoundBuffer internalBuffer2 = AudioMaster::loadFile(fileName2);
	(*soundCollection)[fileName] = internalBuffer;
	(*soundCollection)[fileName2] = internalBuffer2;
	play2(fileName,1);
	play2(fileName2,2);

	easyLog loging = *new easyLog();
	loging.addInfoToLog("audio", fileName + "was played");*/

	SoundEffectComponent component("testAudio.wav");
	SoundEffectComponent component2("testAudio2.wav");

	component.play();
	component2.play();

	system("pause");

	

	component.stop();
	component2.stop();

	MusicComponent music("testAudio.wav");
	music.play();


	system("pause");
	return 0;
}