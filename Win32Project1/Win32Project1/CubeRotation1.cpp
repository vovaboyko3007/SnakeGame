#include <time.h>
//#include <SFML\Graphics.hpp>
#include <stdlib.h>
#include  "gult/glut.h"
#include <windows.h>
#include <iostream>

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
 
  if (s[0].x>N) dir=1;  if (s[0].x<0) dir=2;
  if (s[0].y>M) dir=3;  if (s[0].y<0) dir=0;
 
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
/*
void menu(){  
    int f=1,k,code;
    SetColor(0,0);
    GotoXY(27,12);
    SetColor(14,0); 
    cout << Rus("-->Новая игра<--");
    GotoXY(30,13);
    SetColor(15,0); 
    cout<<Rus("   Выход   ");
    do{
        k=0;
        code=getch();
        if (code==224||code==0)
            code=getch();
        if(code==80){
            f=f*(-1);
            if (f==1){
                GotoXY(27,12); SetColor(14,0); cout<<Rus("-->Новая игра<--");
                GotoXY(30,13); SetColor(15,0); cout<<Rus("   Выход   ");
            }else{ 
                GotoXY(27,12); SetColor(15,0); cout<<Rus("   Новая игра   ");
                GotoXY(30,13); SetColor(14,0); cout<<Rus("-->Выход<--");
            }
        }else if(code==72){
            f=f*(-1);
            if (f==1){
                GotoXY(27,12); SetColor(14,0); cout<<Rus("-->Новая игра<--");
                GotoXY(30,13); SetColor(15,0); cout<<Rus("   Выход   ");
            }else{ 
                GotoXY(27,12); SetColor(15,0);  cout<<Rus("   Новая игра   ");
                GotoXY(30,13); SetColor(14,0); cout<<Rus("-->Выход<--");
            }
        }else if(code==13) k=1; 
    }while (k==0);
    if(f!=1) exit(0);
    //дальше запускаем функцию игры=)
    gamefunc();
}*/

int __stdcall WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nShowCmd){

    srand(time(0));
    
    for (int i=0;i<10;i++)
        m[i].New();
    

     s[0].x=10;
     s[0].y=10;

glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB );
glutInitWindowSize (w, h);
glutCreateWindow ("Вужик_жужик"); 
glClearColor(1.0,1.0,0.6,1.0);  //цвет фона
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0,w,0,h);

glutDisplayFunc (display);
glutSpecialFunc(KeyboardEvent);
glutTimerFunc(100,timer,0);

glutMainLoop();
}
