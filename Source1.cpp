#include "Win_or_lose.h"

Win::Win(SDL_Window* window, int wight, int height, const std::string& filename)
{
	//IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
	render = SDL_CreateRenderer(window, -1, 0);
	r_win.h = 200;
	r_win.w = 400;
	r_win.x = (wight / 2) - 200;
	r_win.y = (height / 2) - 100;
	r_New_game.h = 80;
	r_New_game.w = 160;
	r_New_game.x = r_win.x + 10;
	r_New_game.y = r_win.y + 100;
	r_Quit_off.h = 80;
	r_Quit_off.w = 160;
	r_Quit_off.x = r_win.x + 210;
	r_Quit_off.y = r_win.y + 100;
	win = IMG_Load(filename.c_str());
	New_game_s = IMG_Load("./res/win_or_lose/New_game.jpg");
	Quit_off = IMG_Load("./res/win_or_lose/Quit_off.jpg");
	Quit_on = IMG_Load("./res/win_or_lose/Quit_on.jpg");
	new_game_on = IMG_Load("./res/win_or_lose/new_game_on.jpg");

	win_t = SDL_CreateTextureFromSurface(render, win);
	New_game_t = SDL_CreateTextureFromSurface(render, Quit_off);
	Quit_t = SDL_CreateTextureFromSurface(render, New_game_s);
}

Win::~Win()
{
	SDL_DestroyRenderer(render);
	SDL_FreeSurface(win);
	SDL_FreeSurface(New_game_s);
	SDL_FreeSurface(Quit_off);
	SDL_FreeSurface(new_game_on);
	SDL_FreeSurface(Quit_on);
	SDL_DestroyTexture(win_t);
	SDL_DestroyTexture(New_game_t);
	SDL_DestroyTexture(Quit_t);
}

bool Win::ng_or_q()
{
	bool pressed = false;
	bool next = false;
	int px = 0, py = 0;
	while (!next)
	{
		SDL_RenderCopy(render, win_t, NULL, &r_win);
		SDL_RenderCopy(render, New_game_t, NULL, &r_New_game);
		SDL_RenderCopy(render, Quit_t, NULL, &r_Quit_off);
		SDL_RenderPresent(render);
		while (SDL_PollEvent(&ev))
		{
			if (ev.type == SDL_MOUSEMOTION)
			{
				SDL_GetMouseState(&px, &py);
				pressed = false;
			}
			if (ev.type == SDL_MOUSEBUTTONDOWN)
				pressed = true;
		}
		if (px >= r_New_game.x && px <= r_New_game.x + r_New_game.w && py >= r_New_game.y && py <= r_New_game.y + r_New_game.h)
		{
			New_game_t = SDL_CreateTextureFromSurface(render, new_game_on);
			if (pressed)
				return false;
		}
		else
			New_game_t = SDL_CreateTextureFromSurface(render, New_game_s);
		if (px >= r_Quit_off.x && px <= r_Quit_off.x + r_Quit_off.w && py >= r_Quit_off.y && py <= r_Quit_off.y + r_Quit_off.h)
		{
			Quit_t = SDL_CreateTextureFromSurface(render, Quit_on);
			if (pressed)
				return true;
		}
		else
			Quit_t = SDL_CreateTextureFromSurface(render, Quit_off);
	}
}