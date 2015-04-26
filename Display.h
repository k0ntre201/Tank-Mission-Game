#ifndef DISPLAY_H
#define DISPLAY_H

#include <SDL2\SDL.h>
#include <SDL2\SDL_surface.h>
#include <SDL2\SDL_video.h>
#include <string>
//#include <SDL_image.h>

class Display
{
public:
	Display(int width,int height,const std::string& title);
	virtual ~Display();
	void Update();
	void Clear(float r, float g, float b, float a);
	bool IsClosed();
	SDL_Window*	 m_window;

private:
	SDL_GLContext m_glcontext;
	bool m_isClose;
};

#endif