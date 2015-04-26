#ifndef QUIT_H
#define QIUT_H

#include <SDL2\SDL.h>
#include <SDL2\SDL_surface.h>
#include <SDL2\SDL_video.h>
#include <SDL2\SDL_image.h>

class Quit
{
public:
	Quit(SDL_Window* window,int height, int wight);
	~Quit();
	bool cont_or_quit();
	bool ng_or_q();
	bool ng_or_q2();
	SDL_Event event;
private:
	SDL_Renderer* render;
	SDL_Rect r_A_Y_S, r_ont, r_q;
	SDL_Surface* A_Y_S_S;
	SDL_Surface* cont_s;
	SDL_Surface* q_s;
	SDL_Surface* cont_s_on;
	SDL_Surface* q_s_on;
	SDL_Texture* t_A_Y_S;
	SDL_Texture* contin;
	SDL_Texture* qui;

	SDL_Rect r_win, r_New_game, r_Quit_off;
	SDL_Surface* win;
	SDL_Surface* lose;
	SDL_Surface* New_game_s;
	SDL_Surface* Quit_off;
	SDL_Surface* new_game_on;
	SDL_Surface* Quit_on;
	SDL_Texture* win_t;
	SDL_Texture* New_game_t;
	SDL_Texture* Quit_t;
	SDL_Texture* lose_t;
};

#endif