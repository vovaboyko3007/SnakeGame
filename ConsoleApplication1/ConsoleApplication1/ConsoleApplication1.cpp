#include "stdafx.h"
#include <windows.h>
#include <glut.h>   //Подключение библиотеки glut.h
 
void Initialize()
{
//Выбрать фоновый (очищающий) цвет
glClearColor(0.0,0.0,0.0,1.0);
 
//Установить проекцию
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(0.0,1.0,0.0,1.0,-1.0,1.0);
}
 
void Draw()
{
//Очищаем экран glClear(GL_COLOR_BUFFER_BIT);
 
//Отрисовка квадрата 
glColor3f(0.0,0.0,0.0); //Выбираем белый цвет
glBegin(GL_POLYGON);
glVertex3f(0.25,0.25,0.0); //Координаты квадрата
glVertex3f(0.75,0.25,0.0); 
glVertex3f(0.75,0.75,0.0);
glVertex3f(0.25,0.75,0.0);
glEnd();
glFlush();
}
void line(){
 
	glColor3f(1.0,0.0,0.0);
	glLineWidth(2.5); 
	glBegin(GL_LINES);
	glVertex2i(50,50);
	glVertex2i(50,100);
	glEnd();
 
}
 
 
//Войти в главный цикл
int main()
{

glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(400,400);		//Указываем размер окна
glutInitWindowPosition(500,200);	//Позиция окна
glutCreateWindow("Polygon");		//Имя окна
Initialize();						//Вызов функции Initialize
glutDisplayFunc(Draw);				//Вызов функции отрисовки
glutDisplayFunc(line); 
glutMainLoop();
return 0;
}