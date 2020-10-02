float x0 = 0.0; int f = 0,menuload=0,pointerPos=1;
float introy = 0.0, expy = 0.0, expx = 0.0;GLsizei width = 540, height = 620;
float r=1.0, g=1.0, b=1.0;
float menx = 0, meny = 0, udtheta = -20, rltheta = 0,transx=0, transy = -90,backspeed=0.02;
int spinstop = 0,notexture=0;
int done1 = 0, done2 = 0, done3 = 0,DONE=0, stateChangeflag = 0;//for background transitions
int state = 0;
//state is a flag to keep track of which mode is on currently
//state =0 -->intro page
//state =1 -->menu
//state =2,3,4 -->start,instructions,about
 
void printString(float fx, float fy, float fz, const char *s,float color,int style);
void expand();
void island_name_entry();
void intro(float animationSpeed);
void islandTitle(), polygon(int a, int b, int c, int d), colorcube(float ud_angle, float rl_angle), reshape(int w, int h), menuPointer();
void NormalKeys(unsigned char key, int x, int y), SpecialKeys(int key, int x, int y), resetTransitionData(),transitionBack(int a1, int a2, int t);
void I(), S(), L(), A(), N(), D(),Ab(), B(), O(), U(), T(),about(),instr(),story();
float ddha1=0.0,ddha2=0.0;
void dodecahedron(float x,float y,float z)//keep z between 0.0-3.0 only
{
  const float phi = (1.0f + sqrt(5.0f)) * 0.5f; // "golden ratio"
  float r=0;
  const float b = 1 / phi;
  const float c = (2- phi);
  GLfloat ddcolor[][3]={
    {1,1,1},
    {1,1,0},
    {1,0,1},
    {1,0,0},
    {0,1,1},
    {0,1,0},
    {0,0,1},
    {0,0,0},
    {0.5,0.5,0.5},
    {0.5,0.5,0},
    {0.5,0,0.5},
    {0.5,0,1}
  };
	ddha1+=0.05;ddha2+=0.05;
	//if(ddhtrans>=-111.0)ddhtrans-=0.3;else if(ddhtrans<=-108.96) ddhtrans+=0.3;
	if (abs(ddha1) >= 360)ddha1 = 0;
	if (abs(ddha2) >= 360)ddha2 = 0;
	//-108.96
	z=z+-50;
	glLoadIdentity();
	glTranslatef(x,y,z);
	glRotatef(ddha1, 1, 0, 0);
	glRotatef(ddha2, 0, 1, 0);
  glColor3fv(ddcolor[1]);
  glBegin(GL_POLYGON);
  glVertex3f(c, 0 , 1);
  glVertex3f(-c , 0,  1);
  glVertex3f(-b , b , b );
  glVertex3f(0 , 1,  c);
  glVertex3f(b , b,  b);
  glEnd();
  glColor3fv(ddcolor[2]);
  glBegin(GL_POLYGON);
  glVertex3f(-c,0,1);
  glVertex3f(c,0,1);
  glVertex3f(b,-b,b);
  glVertex3f(0,-1,c);
  glVertex3f(-b,-b,b);
  glEnd();
  glColor3fv(ddcolor[3]);
  glBegin(GL_POLYGON);
  glVertex3f(c,0,-1);
  glVertex3f(-c,0,-1);
  glVertex3f(-b,-b,-b);
  glVertex3f(0,-1,-c);
  glVertex3f(b,-b,-b);
  glEnd();
  glColor3fv(ddcolor[4]);
  glBegin(GL_POLYGON);
  glVertex3f(-c,0,-1);
  glVertex3f(c,0,-1);
  glVertex3f(b,b,-b);
  glVertex3f(0,1,-c);
  glVertex3f(-b,b,-b);
  glEnd();
  glColor3fv(ddcolor[5]);
  glBegin(GL_POLYGON);
  glVertex3f(0,1,-c);
  glVertex3f(0,1,c);
  glVertex3f(b,b,b);
  glVertex3f(1,c,0);
  glVertex3f(b,b,-b);
  glEnd();
  glColor3fv(ddcolor[6]);
  glBegin(GL_POLYGON);
  glVertex3f(0,1,c);
  glVertex3f(0,1,-c);
  glVertex3f(-b,b,-b);
  glVertex3f(-1,c,0);
  glVertex3f(-b,b,b);
  glEnd();
  glColor3fv(ddcolor[7]);
  glBegin(GL_POLYGON);
  glVertex3f(0,-1,-c);
  glVertex3f(0,-1,c);
  glVertex3f(-b,-b,b);
  glVertex3f(-1,-c,0);
  glVertex3f(-b,-b,-b);
  glEnd();
  glColor3fv(ddcolor[8]);
  glBegin(GL_POLYGON);
  glVertex3f(0,-1,c);
  glVertex3f(0,-1,-c);
  glVertex3f(b,-b,-b);
  glVertex3f(1,-c,0);
  glVertex3f(b,-b,b);
  glEnd();
  glColor3fv(ddcolor[9]);
  glBegin(GL_POLYGON);
  glVertex3f(1,  c,  0);
  glVertex3f(1, -c,  0);
  glVertex3f(b, -b,  b  );
  glVertex3f(c,  0,  1);
  glVertex3f(b,  b,  b);
  glEnd();
  glColor3fv(ddcolor[10]);
  glBegin(GL_POLYGON);
  glVertex3f(1, -c,  0);
  glVertex3f(1,  c,  0);
  glVertex3f(b,  b, -b);
  glVertex3f(c,  0 ,-1);
  glVertex3f(b, -b, -b);
  glEnd();
  glColor3fv(ddcolor[11]);
  glBegin(GL_POLYGON);
  glVertex3f(-1,  c,  0);
  glVertex3f(-1, -c,  0);
  glVertex3f(-b, -b, -b);
  glVertex3f(-c,  0, -1);
  glVertex3f(-b,  b, -b);
  glEnd();
  glColor3fv(ddcolor[0]);
  glBegin(GL_POLYGON);
  glVertex3f(-1, -c,  0);
  glVertex3f(-1,  c,  0);
  glVertex3f(-b,  b,  b);
  glVertex3f(-c,  0,  1);
  glVertex3f(-b, -b,  b);
  glEnd();
}
void about() {
	glClearColor(r, g, b, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	colorcube(udtheta, rltheta);
  dodecahedron(-10,-11,0);
  dodecahedron(10,-11,0);
	if (DONE == 1) {
		int x = -5.8;
		printString(-4.8, 20, -65, "ABOUT", 1, 4);
		printString(-18 + x, 8, -50, "Welcome to The Island. An immersive open world experience built using Opengl(GLUT) in C++.", 1, 6);

		printString(-18 + x, 4, -50,  "The Island takes you to a beautiful, intricately-detailed world that is waiting to be explored,", 1, 6);
		printString(-18 + x, 2, -50,  "places so incredibly immersive that you’ll feel like you are there physically. ", 1, 6);

		printString(-18 + x, -3, -50, "Step into the shoes of Mateo Sánchez, who's rickety old crop-duster crashed into this strange", 1, 6);
		printString(-18 + x, -5, -50, "place, to  start a new life on The Island. Teleported to a mysterious place in the Bermuda ", 1, 6);
		printString(-18 + x, -7, -50,"Triangle, your goal is to survive, to exolore, to have FUN.", 1, 6);
		printString(-3, -15, -50,"CREDITS", 1, 7);
		printString(-10, -17, -50, "Created by Ebenezer B and Fozail Akram.", 1, 6);
	}
	printString(-3, -28, -50, "Press ESC to Go Back.", 1, 3);

	/*std::string str = std::to_string(done1);
	printString(12, -10, -50, str, 0, 6);
	str = std::to_string(done2);
	printString(12, -15, -50, str, 0, 6);
	str = std::to_string(done3);
	printString(12, -20, -50, str, 0, 6);*/
	glutSwapBuffers();
}
void story() {
	glClearColor(r, g, b, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	colorcube(udtheta, rltheta);
	if (DONE == 1) {
		int x = -2;
		printString(-4.3, 20, -65, "STORY", 1, 4);
		printString(-18 + x, 10, -50, "    You are Mateo Sánchez, a 27 year old lad from Cuba, owns an  old  cropduster ", 1, 6);
		printString(-18 + x, 8, -50, "that  you  use  to dust  the  corn-fields  of  some  of  the  other townsfolk in  order ", 1, 6);
		printString(-18 + x, 6, -50, "to make a living. Tired of this monotonus life, you decide to run away and to leave", 1, 6);
		printString(-18 + x, 4, -50, "this boring life behind.                                                 ", 1, 6);
		printString(-18 + x, -1, -50, "    So, you hoard  as  much  suppiles as your little plane can carry and set out to ", 1, 6);
		printString(-18 + x, -3, -50, "an island in the  Carribbean,  to  start a  new life. As you  are flying, it gets foggy, ", 1, 6);
		printString(-18 + x, -5, -50, "you panic, you lose your bearings and enter the Bermuda Triangle.              ", 1, 6);
		printString(-18 + x, -10, -50, "    Your  compass  isn't  working  , you  are running out of fuel and need to find a ", 1, 6);
		printString(-18 + x, -12, -50, "place to  land soon! In your distress  you see a weird object looming closer.", 1, 6);
		printString(-18 + x, -14, -50, "You panic, you are about to crash into.....                                    ", 1, 6);
		printString(-18, -19, -50, "                               A CUBE !??                                   ", 1, 7);
	}
  printString(-4, -28, -50, "Press ESC to Go Back.", 0, 3);

	/*std::string str = std::to_string(done1);
	printString(12, -10, -50, str, 0, 6);
	str = std::to_string(done2);
	printString(12, -15, -50, str, 0, 6);
	str = std::to_string(done3);
	printString(12, -20, -50, str, 0, 6);*/
	glutSwapBuffers();
}
void instr() {
	glClearColor(r, g, b, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	colorcube(udtheta,rltheta);
	if (DONE == 1) {
		int x = -2;
		int y = 9;
		printString(-8, 33, -65, "INSTRUCTIONS", 1, 4);

		printString(-18 + x, 12 + y, -50, "Movement", 1, 7);
		printString(-18 + x, 10 + y, -50, "1 --> Use the arrow keys to move the camera ", 1, 6);
		printString(-18 + x, 8 + y, -50,  "2 --> Press the following for movement: ", 1, 6);
		printString(-18 + x, 6 + y, -50,  "    w - forward ", 1, 6);
		printString(-18 + x, 4 + y, -50,  "    s - backwards  ", 1, 6);
		printString(-18 + x, 2 + y, -50,  "    a - left  ", 1, 6);
		printString(-18 + x, 0 + y, -50,  "    d - right  ", 1, 6);
		printString(-18 + x, -2 + y, -50, "3 --> Use your mouse to point and click objects in the scene ", 1, 6);
		printString(-18 + x, -4 + y, -50, "4 --> Press ESC key to return to main menu and to exit ", 1, 6);

		printString(-18 + x, -8 + y, -50, "Survival Rules", 1, 7);
		printString(-18 + x, -10 + y, -50, "1 --> Once you enter The Cube, click SPACEBAR key to land on the island.", 1, 6);
		printString(-18 + x, -12 + y, -50, "2 --> Your health will keep decrease as you move around and explore. ", 1, 6);
		printString(-18 + x, -14 + y, -50, "3 --> Health level is shown in the bottom right side of the screen. ", 1, 6);
		printString(-18 + x, -16 + y, -50, "4 --> Keep eating any food that you may find to replenish your health.  ", 1, 6);
		printString(-18 + x, -18 + y, -50, "5 --> The map shows your current location and resources on the island. ", 1, 6);
		printString(-18 + x, -20 + y, -50, "6 --> Press ESC to exit and return to Main Menu. ", 1, 6);

		printString(-18 + x, -24 + y, -50, "Window Resolution", 1, 7);
		printString(-18 + x, -26 + y, -50, "1 --> Maximize the Game Window for an immersive experience. ", 1, 6);
		printString(-18 + x, -28 + y, -50, "2 --> Note: The he game will work just as fine in the default window size.", 1, 6);
		printString(-18 + x, -30 + y, -50, "3 --> Warning: Do not reduce the window to smaller than the default size.", 1, 6);
		printString(-18, -34 + y, -50, "                       Explore to Survive!                                  ", 1, 7);
	}
  printString(-4, -28, -50, "Press ESC to Go Back.", 0, 3);

	/*std::string str = std::to_string(done1);
	printString(12, -10, -50, str, 0, 6);
	str = std::to_string(done2);
	printString(12, -15, -50, str, 0, 6);
	str = std::to_string(done3);
	printString(12, -20, -50, str, 0, 6);*/
	glutSwapBuffers();
}
// --------------------------------------------------
//             PRINT STRINGS ONTO WONDOW
// --------------------------------------------------
void printString(float fx,float fy,float fz,const char *s,float color,int style) {
	glLoadIdentity();
	glColor3f(color, color, color);
	glRasterPos3f(fx, fy, fz);
	switch (style)
	{
	case 1:for (int i = 0; i < strlen(s); i++) {
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, s[i]);
	}break;
	case 2:for (int i = 0; i < strlen(s); i++) {
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, s[i]);
	}break;
	case 3:for (int i = 0; i < strlen(s); i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, s[i]);
	}break;
	case 4:for (int i = 0; i < strlen(s); i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, s[i]);
	}break;
	case 5:for (int i = 0; i < strlen(s); i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, s[i]);
	}break;
	case 6:for (int i = 0; i < strlen(s); i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, s[i]);
	}break;
	case 7:for (int i = 0; i < strlen(s); i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, s[i]);
	}break;
	}
}
// --------------------------------------------------
//                FLAMBOYANT OPENING
// --------------------------------------------------
void expand()
{
	glClearColor(r, g, b, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0, -20 + introy, -50);
	glBegin(GL_QUADS);
	glColor3f(0.98, 0.98, 0.969);
	glVertex3f(-0.5 - expx, 0.5, 0);
	glVertex3f(-0.5 - expx, -0.5 - expy, 0);
	glColor3f(0.82, 0.82, 0.729);
	glVertex3f(0.2 - expx, -0.5 - expy, 0);
	glVertex3f(0.2 - expx, 0.5, 0);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0.98, 0.98, 0.969);
	glVertex3f(-0.5 + expx, 0.5, 0);
	glVertex3f(-0.5 + expx, -0.5 - expy, 0);
	glColor3f(0.82, 0.82, 0.729);
	glVertex3f(0.2 + expx, -0.5 - expy, 0);
	glVertex3f(0.2 + expx, 0.5, 0);
	glEnd();

	glutSwapBuffers();
}
void island_name_entry(){
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0, -20 + introy, -50);
	glBegin(GL_QUADS);
	glColor3f(0.98, 0.98, 0.969);
	glVertex3f(-0.5, 0.5, 0);
	glVertex3f(-0.5, -0.5 - expy, 0);
	glColor3f(0.82, 0.82, 0.729);
	glVertex3f(0.5, -0.5 - expy, 0);
	glVertex3f(0.5, 0.5, 0);

	glEnd();
	glutSwapBuffers();

}
void intro(float animationSpeed) {
	//PRETTY MUCH USELESS EXCEPT FOR THE ELSE PART

	if (f == 0) {
		introy = introy + animationSpeed;
		if (introy >= 30.00)
		{
			f = 1;
		}
		island_name_entry();
	}
	else if (f == 1) {
		expy += animationSpeed;
		if (expy >= 6.00)
		{
			f = 2;
		}
		island_name_entry();
	}
	else if (f == 2) {
		expx += animationSpeed;
		if (expx >= 10.00)
		{
			f = 3;
		}
		expand();
	}
	else
	{
		islandTitle();
	}
}
void I() {
	glLoadIdentity();
	glTranslatef(0, -20 + introy, -50);
	glBegin(GL_QUADS);
	glColor3f(0.098, 0.098, 1);
	glVertex3f(-0.5 - expx, 0.5, 0);
	glVertex3f(-0.5 - expx, -0.5 - expy, 0);
	glColor3f(1,1,1);
	glVertex3f(0.2 - expx, -0.5 - expy, 0);
	glVertex3f(0.2 - expx, 0.5, 0);
	glEnd();
}
void S() {
	glLoadIdentity();
	glTranslatef(-0.5, 0, -50);
	glBegin(GL_QUADS);//middle line
	glColor3f(0, 0, 0);
  glColor3f(0.098, 0.098, 1);
	glVertex3f(-7, 8, 0);
	glVertex3f(-7, 7, 0);
	glColor3f(1,1,1);
	glVertex3f(-6, 6, 0);
	glVertex3f(-6, 7, 0);
	glEnd();
	glLoadIdentity();
	glTranslatef(-0.75, 0, -50);
	glBegin(GL_QUADS);//top line
	glColor3f(0, 0, 0);
  glColor3f(0.098, 0.098, 1);
	glVertex3f(-5, 10.7, 0);
	glVertex3f(-7.3, 8.5, 0);
	glColor3f(1,1,1);
	glVertex3f(-7.3, 7.5, 0);
	glVertex3f(-5, 9.7, 0);
	glEnd();
	glLoadIdentity();
	glTranslatef(-0.75, -4, -50);
	glBegin(GL_QUADS);//last line
	glColor3f(0, 0, 0);
  glColor3f(0.098, 0.098, 1);
	glVertex3f(-5, 10.7, 0);
	glVertex3f(-7.3, 8.5, 0);
	glColor3f(1,1,1);
	glVertex3f(-7.3, 7.5, 0);
	glVertex3f(-5, 9.7, 0);
	glEnd();
}
void L() {
	glLoadIdentity();//long line
	glTranslatef(-1.1, -20 + introy, -50);
	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
  glColor3f(0.098, 0.098, 1);
	glVertex3f(-0.5 - expx + 8, 0.5, 0);
	glVertex3f(-0.5 - expx + 8, -0.5 - expy, 0);
	glColor3f(1,1,1);
	glVertex3f(0.2 - expx + 8, -0.5 - expy, 0);
	glVertex3f(0.2 - expx + 8, 0.5, 0);
	glEnd();
	glLoadIdentity();//short line
	glTranslatef(-2.6, 3.5, -50);
	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
  glColor3f(0.098, 0.098, 1);
	glVertex3f(0, 0.7, 0);
	glVertex3f(0, 0, 0);
	glColor3f(1,1,1);
	glVertex3f(2, 0, 0);
	glVertex3f(2, 0.7, 0);
	glEnd();
}
void A() {
	glLoadIdentity();//long line
	glTranslatef(-0.9, -0.3, -50);
	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
  glColor3f(0.098, 0.098, 1);
	glVertex3f(3, 10.7, 0);
	glVertex3f(1, 3.8, 0);
	glColor3f(1,1,1);
	glVertex3f(1.7, 3.8, 0);
	glVertex3f(3.7, 10.7, 0);
	glEnd();
	glLoadIdentity();//short line
	glTranslatef(1.8, 6, -50);
	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
  glColor3f(0.098, 0.098, 1);
	glVertex3f(0, 0.7, 0);
	glVertex3f(0, 0, 0);
	glColor3f(1,1,1);
	glVertex3f(2, 0, 0);
	glVertex3f(2, 0.7, 0);
	glEnd();
}
void N() {
	glLoadIdentity();
	glTranslatef(13.1, 0.2, -50);
	glBegin(GL_QUADS);//middle line
  glColor3f(0.098, 0.098, 1);
	glColor3f(0, 0, 0);
	glVertex3f(-7, 8.3, 0);
	glVertex3f(-7, 7, 0);
	glColor3f(1, 1, 1);
	glVertex3f(-6, 5, 0);
	glVertex3f(-6, 6.3, 0);
	glEnd();
	glLoadIdentity();//lines
	glTranslatef(-0.6, -20 + introy, -50);
	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
  glColor3f(0.098, 0.098, 1);
	glVertex3f(-0.5 + expx - 1.5, 0.5, 0);
	glVertex3f(-0.5 + expx - 1.5, -0.5 - expy, 0);
	glColor3f(0.82, 0.82, 0.729);
	glVertex3f(0.2 + expx - 1.5, -0.5 - expy, 0);
	glVertex3f(0.2 + expx - 1.5, 0.5, 0);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
  glColor3f(0.098, 0.098, 1);
	glVertex3f(-0.5 + expx - 4, 0.5, 0);
	glVertex3f(-0.5 + expx - 4, -0.5 - expy, 0);
		glColor3f(1,1,1);
	glVertex3f(0.2 + expx - 4, -0.5 - expy, 0);
	glVertex3f(0.2 + expx - 4, 0.5, 0);
	glEnd();

}
void D() {
	glLoadIdentity();//straight line
	glTranslatef(0, -20 + introy, -50);
	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
  glColor3f(0.098, 0.098, 1);
	glVertex3f(-0.5 + expx, 0.5, 0);
	glVertex3f(-0.5 + expx, -0.5 - expy, 0);
	glColor3f(0.82, 0.82, 0.729);
	glVertex3f(0.2 + expx, -0.5 - expy, 0);
	glVertex3f(0.2 + expx, 0.5, 0);
	glEnd();
	glLoadIdentity();//last line
	glTranslatef(17.5, -4, -50);
	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
  glColor3f(0.098, 0.098, 1);
	glVertex3f(-5, 10.7, 0);
	glVertex3f(-7, 8.5, 0);
	glColor3f(1,1,1);
	glVertex3f(-7, 7.5, 0);
	glVertex3f(-5, 9.7, 0);
	glEnd();
	glLoadIdentity();//top line
	glTranslatef(5.5, -0.2, -50);
	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
  glColor3f(0.098, 0.098, 1);
	glVertex3f(5, 10.7, 0);
	glVertex3f(5, 9.7, 0);
	glColor3f(1,1,1);
	glVertex3f(7, 7.5, 0);
	glVertex3f(7, 8.5, 0);
	glEnd();
}
void islandTitle(){
	glClearColor(r, g, b, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	I(); S(); L(); D(); A(); N();
	printString(0, 0, -50, "An Open World Experience", 1, 6);
	printString(-6.5, -25, -50, "Press SPACEBAR to Continue...", 1, 6);
	//std::string str = std::to_string(udtheta);
  char s[20];
	sprintf(s,"udtheta = %f",udtheta);
	printString(12, -10, -50,s , 0, 6);
	sprintf(s,"rltheta = %f",rltheta);
	printString(12, -15, -50,s , 0, 6);
	sprintf(s,"trans = %f",trans);
	printString(12, -20, -50, s, 0, 6);
	if (spinstop == 0) {
		udtheta -= backspeed;
		rltheta = 30;
		if (abs(udtheta) >= 360)udtheta = 0;
		if (abs(rltheta) >= 360)rltheta = 0;
		colorcube(udtheta, rltheta);
	}
	else
		colorcube(udtheta, rltheta);
	glutSwapBuffers();

}
// --------------------------------------------------
//                 CUBE DRAWING
// --------------------------------------------------
GLfloat vertices[][3] = { {-100.0,-100.0,-100.0},{100.0,-100.0,-100.0},
{100.0,100.0,-100.0},{-100.0,100.0,-100.0},{-100.0,-100.0,100.0},
{100.0,-100.0,100.0},{100.0,100.0,100.0},{-100.0,100.0,100.0} };
void polygon(int a, int b, int c, int d)
{

	glBegin(GL_POLYGON);

	glVertex3fv(vertices[a]);
	glVertex3fv(vertices[b]);
	glVertex3fv(vertices[c]);
	glVertex3fv(vertices[d]);
	glEnd();
}
void colorcube(float ud_angle,float rl_angle)
{
	glLoadIdentity();
	glTranslatef(0, 0,trans);
	glRotatef(ud_angle, 1, 0, 0);
	glRotatef(rl_angle, 0, 1, 0);

	glColor3f(0, 0, 0);
	polygon(2, 3, 7, 6);//topface....black
	glColor3f(0.651, 0.929, 1);
	polygon(0, 1, 5, 4);//bottomface...blue

  glColor3f(1, 0.851, 0.251);
  polygon(4, 5, 6, 7);//front face... facing the camera...yellow
	glColor3f(0.502, 0.298, 0.698);
	polygon(0, 3, 2, 1);//back face...purple

	glColor3f(1, 0.49, 0.49);
	polygon(1, 2, 6, 5);//rightface...peach
	glColor3f(0.251, 0.851, 0.251);
	polygon(0, 4, 7, 3);//left face...green
}
// --------------------------------------------------
//           GAME MENU(opening screen)
// --------------------------------------------------
void gameMenu() {
	glClearColor(r, g, b, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	/*udtheta = 42;
	rltheta = 45;
	trans = -282;*/
	if (DONE==1)
	{
		udtheta=42,rltheta= 45;
		I(); S(); L(); D(); A(); N();
		printString(-5, 0, -50, "An Open World Experience", 1, 5);
		printString(11.5, -7, -50, "Play", 0, 7);
		printString(11.5, -12, -50, "Instructions", 0, 7);
		printString(11.5, -17, -50, "Story", 0, 7);
		printString(11.5, -22, -50, "About", 0, 7);
		printString(-3, -28, -50, "Press ESC to Quit...", 0, 3);
		menuPointer();
	}
	colorcube(udtheta, rltheta);
	glutSwapBuffers();
}
void menuPointer() {
	int ypos;
	glLoadIdentity();
	glTranslatef(1, 0, -50);
	switch (pointerPos)
	{
	case 1:ypos = -10;
		glColor3f(0.82, 0.82, 0.729);
		glBegin(GL_POLYGON);
		glVertex3f(21.5, -11, -50);
		glVertex3f(21.5, -15, -50);
		glColor3f(1, 1, 1);
		glVertex3f(40, -15, -50);
		glVertex3f(40, -11, -50);
		glEnd();
		dodecahedron(21,ypos+3.5,0);
		break;
	case 2:ypos = -15;
		glColor3f(0.82, 0.82, 0.729);
		glBegin(GL_POLYGON);
		glVertex3f(21.5, -11-10, -50);
		glVertex3f(21.5, -15-10, -50);
		glColor3f(1, 1, 1);
		glVertex3f(40, -15-10, -50);
		glVertex3f(40, -11-10, -50);
		glEnd();
		dodecahedron(21,ypos+3.5,0);
		break;
	case 3:ypos = -20;
		glColor3f(0.82, 0.82, 0.729);
		glBegin(GL_POLYGON);
		glVertex3f(21.5, -11-20, -50);
		glVertex3f(21.5, -15-20, -50);
		glColor3f(1, 1, 1);
		glVertex3f(40, -15-20, -50);
		glVertex3f(40, -11-20, -50);
		glEnd();
		dodecahedron(21,ypos+3.5,0);
		break;
	case 4:ypos = -25;
		glColor3f(0.82, 0.82, 0.729);
		glBegin(GL_POLYGON);
		glVertex3f(21.5, -11 - 30, -50);
		glVertex3f(21.5, -15 - 30, -50);
		glColor3f(1, 1, 1);
		glVertex3f(40, -15 - 30, -50);
		glVertex3f(40, -11 - 30, -50);
		glEnd();
		dodecahedron(21,ypos+3.5,0);
		break;
	}
}
// --------------------------------------------------
//             BACKGROUND TRANSITION
// --------------------------------------------------
void resetTransitionData() {
	done1 = 0; done2 = 0; done3 = 0; DONE = 1;
}
void transitionBack(int a1, int a2, int t) {
	stateChangeflag = 0;
	if (DONE == 1 || done1 == 1 && done2 == 1 && done3 == 1) { DONE = 1; resetTransitionData(); return; }

	if ((int)udtheta > a1) { udtheta -= 0.1; }
	else if ((int)udtheta < a1) { udtheta += 0.1; }
	else { done1 = 1; }

	if ((int)rltheta < a2) { rltheta += 0.1; }
	else if ((int)rltheta > a2) { rltheta -= 0.1; }
	else { done2 = 1; }

	if (trans < t) { trans += 0.5; }
	else if (trans > t) { trans -= 0.5; }
	else { done3 = 1; }
}
