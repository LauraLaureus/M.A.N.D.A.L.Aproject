#include "SystemHeader.h"
#include "AudioHeader.h"
#include "GraphicsHeader.h"
#include "ThreadingHeader.h"
#include "include\easylog\easyLog.h"
#include "TobiiInterface.h"

using namespace std;


void changeViewPort(int w, int h)
{
	glViewport(0, 0, w, h);
}

void render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glutSwapBuffers();
}



int main(int argc, char *argv[]) {

	glutInit(&argc, argv);
	
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(1200,768 );
	

	glutCreateWindow("M.A.N.D.A.L.A. project");
	glutFullScreen();

	glutCloseFunc();

	GLenum err = glewInit();
	if (GLEW_OK != err) {
		fprintf(stderr, "GLEW error");
		return 1;
	}



	//Initialization zone 
	/*
	CREATE SCENES OBJECTS AND SO ON here. 
	*/
	TobiiInterface* tobii = new TobiiInterface();
	glm::vec2 gaze = tobii->getGazePoint();
	

	/*SoundEffectComponent component("/Assets/audio/testAudio.wav");
	SoundEffectComponent component2("/Assets/audio/testAudio2.wav");

	component.play();
	component2.play();

	system("pause");

	

	component.stop();
	component2.stop();

	MusicComponent music("testAudio.wav");
	music.play();

	*/

	std::string sceneReturn;

	//GAME LOOP
	while (true) {
		glutMainLoopEvent();
		gaze = tobii->getGazePoint();
		printf("Gaze: %f,%f", gaze.x, gaze.y);
	}
	
	delete tobii;

	
	return 0;
}