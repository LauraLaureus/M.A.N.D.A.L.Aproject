#include "SystemHeader.h"
#include "AudioHeader.h"
#include "GraphicsHeader.h"
#include "ThreadingHeader.h"

#include <SFML/Audio.hpp>



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
	/*AudioMaster::playSoundFile("testAudio.wav");
	system("pause");
	AudioMaster::playSoundFile("testAudio.wav");*/

	sf::SoundBuffer buffer;

	char* nameBuffer = new char[1024];
	if (GetModuleFileName(NULL, nameBuffer, 1024)) {
		
	}
	
	string absolutePath(nameBuffer);
	int pointer = absolutePath.rfind("\\");
	absolutePath = absolutePath.substr(0, pointer + 1);
	printf("%s", absolutePath.c_str());


	if (!buffer.loadFromFile(absolutePath + "testAudio.wav")) {
		system("pause");
		return 1;
	}
	
	sf::Sound sound;
	sound.setBuffer(buffer);
	sound.play(); // serxiiiii

	
	system("pause");
	return 0;
}