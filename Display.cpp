////////////////////////////////////////////////////////////////////////////////////////
// tutaj nastêpuje inicjalizacja i utowrzenie okna z kontekstem renderigu dla opengl'a//
////////////////////////////////////////////////////////////////////////////////////////


#include "Display.h"
#include <GL\glew.h>
#include <iostream>


Display::Display(int width, int height,const std::string& title)
{
	//inicjujemy wszystko
	SDL_Init(SDL_INIT_EVERYTHING);

	//wczytujemy atrybuty pixeli oraz zalaczamy double buffer
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE,8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	//tworze dwie "flagi" 1 do wyswietlania okna ogl a droga + fullscren dopasowany do ekranu
	int flag1 = SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE;
	int flag2 = SDL_WINDOW_OPENGL | SDL_WINDOW_FULLSCREEN_DESKTOP;

	//tworzymy okno i przylaczamy context ogl
	m_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flag1);
	m_glcontext = SDL_GL_CreateContext(m_window);
	//m_surface = SDL_GetWindowSurface(m_window);

	GLenum status = glewInit();
	if (status != GLEW_OK)
		std::cerr << "glew cannot be initialize" << std::endl;


	m_isClose = false;

	glEnable(GL_DEPTH_TEST);

	glAlphaFunc(GL_GREATER, 0.1);
	glEnable(GL_ALPHA_TEST);

}
//destruktor czysciciel
Display::~Display()
{
	SDL_GL_DeleteContext(m_glcontext);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

//czyscimy caly ekan
void Display::Clear(float r, float g, float b, float a)
{
	glClearColor(r, g, b, a);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

//czy zamkniete
bool Display::IsClosed()
{
	return m_isClose;
}

//update okna wraz z namiana oknien pomiedzy opengl i okno
void Display::Update()
{
	SDL_GL_SwapWindow(m_window);
}
