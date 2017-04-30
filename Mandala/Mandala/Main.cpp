#include "SystemHeader.h"
#include "AudioHeader.h"
#include "GraphicsHeader.h"
#include "ThreadingHeader.h"


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


sf::SoundBuffer myBuffer;
sf::Sound sound;

void play() {
	std::string fileName = AudioMaster::getAbsoluteFileName("testAudio.wav");
	myBuffer = AudioMaster::loadFile(fileName);
	sound.setBuffer(myBuffer);
	sound.setVolume(100);
	sound.play();
	
}


int main(int argc, char *argv[]) {

	
	
	
	play();
	system("pause");

	//AudioMaster::playSoundFile(myBuffer, 100, false);
	system("pause");

	/*sf::Sound sound;
	sound.setBuffer(myBuffer);
	sound.setVolume(100);
	sound.play();
	system("pause");*/

	return 0;
}