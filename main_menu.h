#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include <SDL2\SDL.h>
#include <SDL2\SDL_surface.h>
#include <SDL2\SDL_video.h>
#include <SDL2\SDL_image.h>
#include <SDL2\SDL_ttf.h>

class Main_menu
{
public:
	Main_menu(SDL_Renderer* render, int height);
	bool draw_menu();
	~Main_menu();
private:
	void init_evrything();
	void render_sdl();
	void init_ev();
	SDL_Window *window;
	int height;
	SDL_Surface* menu_surface;
	SDL_Color textcolor;
	SDL_Color backcolor;
	TTF_Font* font;
	SDL_Rect new_game_rect;
	SDL_Rect quit_rect;
	SDL_Renderer* render;
	SDL_Surface* image;
	SDL_Texture* texture;
	SDL_Surface* myfont;
	SDL_Texture* m_font_newgame;
	SDL_Surface* quitfont;
	SDL_Texture* m_font_quit;
	SDL_Event event;
	bool pressed;
	bool next;
	int px, py;
};


#endif