#include <Windows.h>
#include <glut.h>
#include<stdlib.h>
#include<stdio.h>
#include<fstream>
#include<math.h>
#include"tex.h"
#include"intromenu.h"

void NormalKeys(unsigned char key, int x, int y), SpecialKeys(int key, int x, int y), reshape(int w, int h);
void skypolygon(int a, int b, int c, int d,int t), skycube(float ud_angle, float rl_angle,int sky_num);
void Start(),InitializeTextures();
int sky=1;

void Start(){
  glClearColor(r, g, b, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  if (DONE == 1) {
  skycube(udtheta,rltheta,sky);}
  glutSwapBuffers();
}
// --------------------------------------------------
//                 SKYCUBE DRAWING
// --------------------------------------------------
GLfloat skybox_vertices[][3] = { {-100.0,-100.0,-100.0},{100.0,-100.0,-100.0},
{100.0,100.0,-100.0},{-100.0,100.0,-100.0},{-100.0,-100.0,100.0},
{100.0,-100.0,100.0},{100.0,100.0,100.0},{-100.0,100.0,100.0} };
void skypolygon(int a,int b,int c,int d,int t)
{
  glBindTexture(GL_TEXTURE_2D, texture[t]);
 glBegin(GL_QUADS);
 glTexCoord2f(0.0, 0.0);
 glVertex3fv(skybox_vertices[a]);
 glTexCoord2f(1.0, 0.0);
 glVertex3fv(skybox_vertices[b]);
 glTexCoord2f(1.0, 1.0);
 glVertex3fv(skybox_vertices[c]);
 glTexCoord2f(0.0, 1.0);
 glVertex3fv(skybox_vertices[d]);
 glEnd();
}
void skycube(float ud_angle,float rl_angle,int sky_num){
  glLoadIdentity();
  glTranslatef(0, 0,trans);
  glRotatef(ud_angle, 1, 0, 0);
  glRotatef(rl_angle, 0, 1, 0);
  switch (sky_num) {
    case 1:
    //glColor3f(0, 0, 0);
    skypolygon( 7, 6,2, 3, 0);//topface....black
    //glColor3f(1, 0, 1);
    skypolygon(0, 1, 5, 4, 1);//bottomface... pink
    //glColor3f(1, 1, 0);
    skypolygon(4, 5, 6, 7, 2);//front face... facing the camera...yellow
    //glColor3f(1,0,0);
    skypolygon(1, 0, 3, 2, 3);//back face... red
    //glColor3f(0, 1, 0);
    skypolygon(5, 1, 2, 6, 4);//rightface... green
    //glColor3f(0, 0, 1);
    skypolygon(0, 4, 7, 3,5);//left face... blue
    break;
  case 2:
    //glColor3f(0, 0, 0);
    skypolygon( 7, 6,2, 3, 6);//topface....black
    //glColor3f(1, 0, 1);
    skypolygon(0, 1, 5, 4, 7);//bottomface... pink
    //glColor3f(1, 1, 0);
    skypolygon(4, 5, 6, 7, 8);//front face... facing the camera...yellow
    //glColor3f(1,0,0);
    skypolygon(1, 0, 3, 2, 9);//back face... red
    //glColor3f(0, 1, 0);
    skypolygon(5, 1, 2, 6, 10);//rightface... green
    //glColor3f(0, 0, 1);
    skypolygon(0, 4, 7, 3, 11);//left face... blue
    break;
  case 3:
    //glColor3f(0, 0, 0);
    skypolygon( 7, 6,2, 3, 12);//topface....black
    //glColor3f(1, 0, 1);
    skypolygon(0, 1, 5, 4, 13);//bottomface... pink
    //glColor3f(1, 1, 0);
    skypolygon(4, 5, 6, 7, 14);//front face... facing the camera...yellow
    //glColor3f(1,0,0);
    skypolygon(1, 0, 3, 2, 15);//back face... red
    //glColor3f(0, 1, 0);
    skypolygon(5, 1, 2, 6, 16);//rightface... green
    //glColor3f(0, 0, 1);
    skypolygon(0, 4, 7, 3, 17);//left face... blue
    break;
  }
}
// --------------------------------------------------
//                    KEYBOARD
// --------------------------------------------------
void NormalKeys(unsigned char key, int x, int y) {
	spinstop = 1;

	if (key == 27)//when ESC is pressed...
	{
		if(state==1)
		exit(0);
		else {
      glDisable(GL_TEXTURE_2D);
      glShadeModel(GL_SMOOTH);
			state = 1; stateChangeflag = 1;
		}
	}
	else if (key=='w') {
		trans += 3;
	}
	else if (key=='s'){
		trans -= 3;
	}
	else if (key==32)//SPACEBAR
	{
    if (state==0) {
      state = 1;
  		//enterGameMenu();
    }
    else if(state == 2){//If SPACEBAR is pressed, change sky
      // glDisable(GL_TEXTURE_2D);
      // glShadeModel(GL_SMOOTH);
      //InitializeTextures();
      sky++;
      if (sky==4) {
        sky=1;
      }
    }

	}
	else if(key==13)//to choose opyion in menu when ENTER is pressed
	{
		switch (pointerPos)
		{
		case 1:
      state = 2;stateChangeflag = 1;//Start the Game
      InitializeTextures();
      break;
		case 2:
      glDisable(GL_TEXTURE_2D);
      glShadeModel(GL_SMOOTH);
      state = 3; stateChangeflag = 1;//Instructions
			break;
		case 3:
      glDisable(GL_TEXTURE_2D);
      glShadeModel(GL_SMOOTH);
      state = 4; stateChangeflag = 1;//Story
			break;
		case 4:
      glDisable(GL_TEXTURE_2D);
      glShadeModel(GL_SMOOTH);
      state = 5; stateChangeflag = 1;//About
      break;
		}
	}
}

void SpecialKeys(int key, int x, int y) {
	spinstop = 1;
	if (abs(udtheta) >= 360)udtheta = 0;
	if (abs(rltheta) >= 360)rltheta = 0;
	if (state==1)
	{
		switch (key) {
		case GLUT_KEY_UP:
			pointerPos--;
			if (pointerPos == 0)pointerPos = 4;
			break;
		case GLUT_KEY_DOWN:
			pointerPos++;
			if (pointerPos == 5)pointerPos = 1;
			break;
		}
	}
	//else if (state==2)
	else
	{
		switch (key) {
		case GLUT_KEY_UP:udtheta++;
			//colorcube(udtheta, rltheta);
      break;
		case GLUT_KEY_DOWN:udtheta--;
			//colorcube(udtheta, rltheta);
      break;
		case GLUT_KEY_RIGHT:rltheta++;;
			//colorcube(udtheta, rltheta);
      break;
		case GLUT_KEY_LEFT:rltheta--;
			//colorcube(udtheta, rltheta);
      break;
		case GLUT_KEY_F3:
			r = 0.0;
			g = 0.0;
			b = 0.0; break;
		}
	}
}

// --------------------------------------------------
//               REQUIRED STUFF
// --------------------------------------------------
void display()
{
	glClearColor(r, g, b, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(x0,0,-50);
	glColor3f(0.82, 0.82, 0.729);
	glBegin(GL_POLYGON);
	glVertex3f(-1.0, 1.0,0);
	glVertex3f(-1.0, -1.0,0);
	glColor3f(0.98, 0.98, 0.969);
	glVertex3f(1.0-0.5, -1.0,0);
	glVertex3f(1.0-0.5, 1.0,0);
	glEnd();
	glutSwapBuffers();
}
void idle() {
	if (state == 0){
    intro(0.1);
  }
	else if (state == 1) {
		if (stateChangeflag == 1)DONE = 0;
		transitionBack(42, 45, -375);
		gameMenu();
	}
	else if (state == 2) {
    if (stateChangeflag==1)DONE = 0;
    transitionBack(90, 45, -80);
		Start();
	}
	else if (state == 3) {
		if (stateChangeflag==1)DONE = 0;
		transitionBack(0,90,-270);
		instr();
	}
	else if (state == 4) {
		if (stateChangeflag == 1)DONE = 0;
		transitionBack(-15, -45, -15);
		story();
	}
	else if (state == 5) {
		if (stateChangeflag == 1)DONE = 0;
		transitionBack(90, 45, -170);
		about();
	}
}
void InitializeTextures(){
  int totalImages=18;
  glEnable(GL_TEXTURE_2D);
  glShadeModel(GL_FLAT);
  const char *x[totalImages]={"assets/space1top.bmp",//top
                              "assets/space1down.bmp",//down
                              "assets/space1front.bmp",//front
                              "assets/space1back.bmp",//back
                              "assets/space1right.bmp",//right
                              "assets/space1left.bmp",//left
                              "assets/space2top.bmp",//top
                              "assets/space2down.bmp",//down
                              "assets/space2front.bmp",//front
                              "assets/space2back.bmp",//back
                              "assets/space2right.bmp",//right
                              "assets/space2left.bmp",//left
                              "assets/space3top.bmp",//top
                              "assets/space3down.bmp",//down
                              "assets/space3front.bmp",//front
                              "assets/space3back.bmp",//back
                              "assets/space3right.bmp",//right
                              "assets/space3left.bmp"};//left
  glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
  if(CreateTextures(totalImages,x))//defined in tex.h
  notexture=0;
  glEnable(GL_TEXTURE_2D);
  glShadeModel(GL_FLAT);
}
void myinit()
{
	glClearColor(r, g, b, 1.0);
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//gluOrtho2D(0, 500, 0, 500);
	glViewport(0, 0, width, height);
	gluPerspective(60, width/height, 10, 300.0);
	glMatrixMode(GL_MODELVIEW);
}
void reshape(int w, int h) {
	if (h == 0)
		h = 1;
	float ratio = 1.0* w / h;
	width = w; height = h;
	glViewport(0, 0, w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//gluOrtho2D(0, 500, 0, 500);
	//glLoadIdentity();
	//glTranslatef(0, 1, 0);
	gluPerspective(60, ratio, 10, 300.0);
	glMatrixMode(GL_MODELVIEW);
}


int main(int argc, char**argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);

	glutInitWindowSize(540,650);
	glutInitWindowPosition(480, 30);
	glutCreateWindow("Island");
	//glutFullScreen();
	glutDisplayFunc(display);
	glutIdleFunc(idle);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(NormalKeys);
	glutSpecialFunc(SpecialKeys);
	myinit();
	glutMainLoop();
}
