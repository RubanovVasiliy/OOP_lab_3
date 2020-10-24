#include <glut.h>
#include <vector>
#include <array>
#include <ctime>
#include <iostream>
#include "Point.h"


using namespace std;

GLdouble ball_x_max, ball_x_min, ball_y_max, ball_y_min;

vector<point> circles;
vector<point> lines;
vector<point> points;
vector<point> ellipses;
vector<point> rhombuses;
vector<point> squares;
vector<point> parallelepipeds;

char title[] = "Lab 2";
double ball_radius = 0.05;;
int window_width = 600;
int window_height = 600;
int window_pos_x = 50;
int window_pos_y = 50;
int refresh_millis = 30;

bool fullScreenMode = true;

GLdouble clip_area_x_left;
GLdouble clip_area_x_right;
GLdouble clip_area_y_bottom;
GLdouble clip_area_y_top;


void init_gl()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
}


void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	for (auto i = circles.begin(); i != circles.end(); ++i)
	{
		i->draw_circle();
	}

	for (auto i = lines.begin(); i != lines.end(); ++i)
	{
		i->draw_line();
	}
	
	for (auto i = points.begin(); i != points.end(); ++i)
	{
		i->draw_point();
	}

	for (auto i = ellipses.begin(); i != ellipses.end(); ++i)
	{
		i->draw_ellipse();
	}

	for (auto i = rhombuses.begin(); i != rhombuses.end(); ++i)
	{
		i->draw_rhombus();
	}

	for (auto i = squares.begin(); i != squares.end(); ++i)
	{
		i->draw_square();
	}

	for (auto i = parallelepipeds.begin(); i != parallelepipeds.end(); ++i)
	{
		i->draw_parallelepiped();
	}

	glutSwapBuffers();
}


void reshape(const GLsizei width, GLsizei height)
{
	if (height == 0) height = 1;
	const auto aspect = static_cast<GLdouble>(width) / static_cast<GLdouble>(height);

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (width >= height)
	{
		clip_area_x_left = -1.0 * aspect;
		clip_area_x_right = 1.0 * aspect;
		clip_area_y_bottom = -1.0;
		clip_area_y_top = 1.0;
	}
	else
	{
		clip_area_x_left = -1.0;
		clip_area_x_right = 1.0;
		clip_area_y_bottom = -1.0 / aspect;
		clip_area_y_top = 1.0 / aspect;
	}
	gluOrtho2D(clip_area_x_left, clip_area_x_right, clip_area_y_bottom, clip_area_y_top);
	ball_x_min = clip_area_x_left + ball_radius;
	ball_x_max = clip_area_x_right - ball_radius;
	ball_y_min = clip_area_y_bottom + ball_radius;
	ball_y_max = clip_area_y_top - ball_radius;
}

void timer(int value)
{
	glutPostRedisplay();
	glutTimerFunc(refresh_millis, timer, 0);
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27:
		exit(0);
		break;
	}
}

void specialKeys(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_F1:    // F1: Toggle between full-screen and windowed mode
		fullScreenMode = !fullScreenMode;         // Toggle state
		if (fullScreenMode) {                     // Full-screen mode
			window_pos_x = glutGet(GLUT_WINDOW_X); // Save parameters for restoring later
			window_pos_y = glutGet(GLUT_WINDOW_Y);
			window_width = glutGet(GLUT_WINDOW_WIDTH);
			window_height = glutGet(GLUT_WINDOW_HEIGHT);
			glutFullScreen();                      // Switch into full screen
		}
		else {                                         // Windowed mode
			glutReshapeWindow(window_width, window_height); // Switch into windowed mode
			glutPositionWindow(window_pos_x, window_pos_y);   // Position top-left corner
		}
		break;
	}
}

int main(int argc, char** argv)
{
	srand(time(nullptr));
	for (auto i = 0; i < 10; ++i)
	{
		auto c = point();
		circles.push_back(c);
		auto l = point();
		lines.push_back(l);
		auto p = point();
		points.push_back(p);
		auto e = point();
		ellipses.push_back(e);
		auto r = point();
		rhombuses.push_back(r);
		auto s = point();
		squares.push_back(s);
		auto par = point();
		parallelepipeds.push_back(par);
	}

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(window_width, window_height);
	glutInitWindowPosition(window_pos_x, window_pos_y);
	glutCreateWindow(title);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(specialKeys);
	glutTimerFunc(0, timer, 0);
	glutFullScreen();
	init_gl();
	glutMainLoop();
	return 0;
}