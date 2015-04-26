#ifndef WIN_OR_LOSE_H
#define WIN_OR_LOSE_H


#include <SDL2\SDL.h>
#include <SDL2\SDL_surface.h>
#include <SDL2\SDL_video.h>
#include <SDL2\SDL_image.h>
#include <string>

class Win
{
public:
	Win(SDL_Window* window, int wight, int height,const std::string& filename);
	~Win();
	bool ng_or_q();
	SDL_Event ev;
private:
	SDL_Renderer* render;
	SDL_Rect r_win, r_New_game, r_Quit_off;
	SDL_Surface* win;
	SDL_Surface* New_game_s;
	SDL_Surface* Quit_off;
	SDL_Surface* new_game_on;
	SDL_Surface* Quit_on;
	SDL_Texture* win_t;
	SDL_Texture* New_game_t;
	SDL_Texture* Quit_t;
};

#endif