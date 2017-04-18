//Jeff Chastine
#include "SystemHeader.h"
#include "AudioHeader.h"
#include "GraphicsHeader.h"

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


const int SRATE = 44100;
const int SSIZE = 1024;

ALbyte buffer[22050];
ALint sample;

int main(int argc, char *argv[]) {
	alGetError();
	ALCdevice *device = alcCaptureOpenDevice(NULL, SRATE, AL_FORMAT_STEREO16, SSIZE);
	if (alGetError() != AL_NO_ERROR) {
		return 0;
	}
	alcCaptureStart(device);

	while (true) {
		alcGetIntegerv(device, ALC_CAPTURE_SAMPLES, (ALCsizei)sizeof(ALint), &sample);
		alcCaptureSamples(device, (ALCvoid *)buffer, sample);

		// ... do something with the buffer 
	}

	alcCaptureStop(device);
	alcCaptureCloseDevice(device);

	return 0;
}