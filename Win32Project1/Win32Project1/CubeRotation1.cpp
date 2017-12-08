#include <time.h>
#include <stdlib.h>
#include  "gult/glut.h"
#include <windows.h>
#include <iostream>
#include <conio.h>
#include <math.h>
#include <string>
#include <fstream>

using namespace std;

int N=30,M=20;
int Scale=25;

int w = Scale*N;
int h = Scale*M;

int dir,num=4;

struct 
{ int x;
  int y;}  s[100];

class Fructs
{ 
public:
    int x,y;

    void New()
    {  x=rand() % N;
        y=rand() % M;   }
    
    void DrawApple()
   {   glColor3f(0.0,1.0,0.0);
       glRectf(x*Scale,y*Scale,(x+1)*Scale,(y+1)*Scale); }

} m[10];

 void DrawSnake()
 {  
  glColor3f(0.0,0.0,1.0);
  for (int i=0;i<num;i++)
    {glRectf(s[i].x*Scale, s[i].y*Scale, (s[i].x+0.9)*Scale, (s[i].y+0.9)*Scale); }
 }

  void Result()
 {
 ofstream file("results.txt",ios_base::app);
  file << endl << (num-2)*10;
  file.close();
 }

 void Tick()
 {
    for (int i=num;i>0;--i)
     {s[i].x=s[i-1].x;
     s[i].y=s[i-1].y;}

    if (dir==0) s[0].y+=1;      
    if (dir==1) s[0].x-=1;        
    if (dir==2) s[0].x+=1;         
    if (dir==3) s[0].y-=1;         

  for (int i=0;i<10;i++)
    if ((s[0].x==m[i].x) && (s[0].y==m[i].y)) 
      {num++; m[i].New();}
 
	if (s[0].x>N) {
		char buf[9];
		char mess[100] ="��� ��������� = ";
 
    itoa((num-2)*10,buf,10);
        strcat(mess,buf);
		MessageBoxA(NULL, "Game Over", "��� ���������!", MB_OK | MB_ICONWARNING);
		Result();
		MessageBoxA(NULL, mess, "���������", MB_OK);
		MessageBoxA(NULL, "���� �� ������ �������� ���������� ��������� ���� - �������� ��������� �������� results.txt, ���� ������������ � ������� �������.", "���������� ��������� ����", MB_OK);
		 exit(1);
	}
	if (s[0].x<0) 
	{
		char buf[9];
		char mess[100] ="��� ��������� = ";
 
    itoa((num-2)*10,buf,10);
        strcat(mess,buf);
		MessageBoxA(NULL, "Game Over", "��� ���������!", MB_OK | MB_ICONWARNING);
		Result();
		MessageBoxA(NULL, mess, "���������", MB_OK);
		MessageBoxA(NULL, "���� �� ������ �������� ���������� ��������� ���� - �������� ��������� �������� results.txt, ���� ������������ � ������� �������.", "���������� ��������� ����", MB_OK);
		exit(1);
     
		
	}
	if (s[0].y>M) dir=3; 
	if (s[0].y<0) dir=0;
 
 for (int i=1;i<num;i++)
  if (s[0].x==s[i].x && s[0].y==s[i].y)  num=i;
 }
 


void DrawField()
  {
   glColor3f(0.0,0.7,0.0);
   glBegin(GL_LINES);
    for (int i=0; i<w; i+=Scale) 
      {glVertex2f(i,0); glVertex2f(i,h);}
    for (int j=0; j<h; j+=Scale)  
      {glVertex2f(0,j); glVertex2f(w,j);}
    glEnd();
}


void display() {

     glClear(GL_COLOR_BUFFER_BIT);

    //DrawField();

    DrawSnake(); 

   for (int i=0;i<10;i++)
     m[i].DrawApple();

   glFlush();
   glutSwapBuffers();
}


void KeyboardEvent(int key, int a, int b)
{   
    switch(key)
    {
        case 101 :     dir=0; break;
         case 102:   dir=2; break;
        case 100 :  dir=1; break;
        case 103 :  dir=3; break;
     }
}

void timer(int = 0)
{
  display();

  Tick();
       
 glutTimerFunc(100,timer,0);
}


 
// ����������� �������� ��� ����
#define ����������� 1
#define ��������	2
#define ������	3
#define ������	4
 
#define FILL	1
#define LINE	2
 
#define pochatok 1
#define vuhid 2


void fail(int option)
{switch (option) {
	case pochatok:
	s[0].x=N / 2;
     s[0].y=M / 2;
	 dir=0;
	 break;
	case vuhid:
		exit(1);
		break;
		
}
}

 
// �������������� ����
int fillMenu, shrinkMenu, mainMenu, colorMenu,newMenu;
// ���� ����
float red = 1.0f, blue=0.5f, green=0.5f;
// ������ ���������
float scale = 1.0f;
// ������ ����
int menuFlag = 0;
 
 
void processMenuStatus(int status, int x, int y) {
	if (status == GLUT_MENU_IN_USE)
		menuFlag = 1;
	else
		menuFlag = 0;
}
 
void processMainMenu(int option) {
 
	//������ ����� �� ������
	//��� �������� ��� �������
}
 
void processFillMenu(int option) {
	switch (option) {
		case FILL: glPolygonMode(GL_FRONT, GL_FILL); break;
		case LINE: glPolygonMode(GL_FRONT, GL_LINE); break;
	}
}
 

 
void processColorMenu(int option) {
	switch (option) {
		case �������� :
			glClearColor(1.0,0.0,0.0,1.0);
			break;
		case ����������� :
			glClearColor(1.0,1.0,0.6,1.0); 
			break;
		case ������ :
			glClearColor(0.0,0.0,0.0,1.0);
			break;
		case ������ :
			glClearColor(1.0,1.0,0.0,1.0);
			break;
	}
}
 
void createPopupMenus() {
	fillMenu = glutCreateMenu(processFillMenu);
	glutAddMenuEntry("�������",FILL);
	glutAddMenuEntry("˳�",LINE);
	colorMenu = glutCreateMenu(processColorMenu);
	glutAddMenuEntry("�����������",�����������);
	glutAddMenuEntry("��������",��������);
	glutAddMenuEntry("������",������);
	glutAddMenuEntry("������",������);
	newMenu = glutCreateMenu(fail);
	glutAddMenuEntry("���� ���",pochatok);
	glutAddMenuEntry("�����",vuhid);
	mainMenu = glutCreateMenu(processMainMenu);
	glutAddSubMenu("����", newMenu);
	glutAddSubMenu("³����������", fillMenu);
	glutAddSubMenu("����", colorMenu);

	// ���������� ���� � ������ ������
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	//������ ���������� ����
	glutMenuStatusFunc(processMenuStatus);
}

 
int __stdcall WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nShowCmd) {
 	
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

	for (int i=0;i<10;i++)
     m[i].New();
     s[0].x=N / 2;
     s[0].y=M / 2;
	 dir=0;
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB );
	glutInitWindowPosition(300,150); 
	glutInitWindowSize (w, h);
	glutCreateWindow ("�����_�����"); 
	glClearColor(1.0,1.0,0.6,1.0);  //���� ����
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,w,0,h);
	glutDisplayFunc (display);
	glutSpecialFunc(KeyboardEvent);
	glutTimerFunc(100,timer,0);	
	createPopupMenus();
 	glutMainLoop();
 	return 1;
}

