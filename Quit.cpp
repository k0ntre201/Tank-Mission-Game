/////////////////////////////////////////////////////////////////////////////////////////
// iniscjacja i rysowanie 3 okien, czyli gdy naciœniemy esc, gdy wygramy lub przegramy //
/////////////////////////////////////////////////////////////////////////////////////////

#include "Quit.h"

Quit::Quit(SDL_Window* window, int height, int wight)
{
	IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
	render = SDL_CreateRenderer(window, -1, 0);
	r_A_Y_S.h = 200;
	r_A_Y_S.w = 400;
	r_A_Y_S.x = (wight / 2) - 200;
	r_A_Y_S.y = (height/ 2) - 100;
	r_ont.h = 80;
	r_ont.w= 160;
	r_ont.x = r_A_Y_S.x + 10;
	r_ont.y = r_A_Y_S.y + 100;
	r_q.h = 80;
	r_q.w = 160;
	r_q.x = r_A_Y_S.x + 210;
	r_q.y = r_A_Y_S.y + 100;
	A_Y_S_S = IMG_Load("./res/quit/back.jpg");
	cont_s = IMG_Load("./res/quit/cont_off.jpg");
	q_s = IMG_Load("./res/quit/quit_off.jpg");
	q_s_on = IMG_Load("./res/quit/quit_on.jpg");
	cont_s_on = IMG_Load("./res/quit/cont_on.jpg");

	t_A_Y_S = SDL_CreateTextureFromSurface(render, A_Y_S_S);
	contin = SDL_CreateTextureFromSurface(render, q_s);
	qui = SDL_CreateTextureFromSurface(render, cont_s);


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
	win = IMG_Load("./res/win_or_lose/win.jpg");
	lose = IMG_Load("./res/win_or_lose/lose.jpg");
	New_game_s = IMG_Load("./res/win_or_lose/New_game.jpg");
	Quit_off = IMG_Load("./res/win_or_lose/Quit_off.jpg");
	Quit_on = IMG_Load("./res/win_or_lose/Quit_on.jpg");
	new_game_on = IMG_Load("./res/win_or_lose/new_game_on.jpg");

	lose_t = SDL_CreateTextureFromSurface(render, lose);
	win_t = SDL_CreateTextureFromSurface(render, win);
	New_game_t = SDL_CreateTextureFromSurface(render, Quit_off);
	Quit_t = SDL_CreateTextureFromSurface(render, New_game_s);
}

Quit::~Quit()
{
	IMG_Quit();
	SDL_DestroyRenderer(render);
	SDL_FreeSurface(A_Y_S_S);
	SDL_FreeSurface(cont_s);
	SDL_FreeSurface(q_s);
	SDL_FreeSurface(q_s_on);
	SDL_FreeSurface(cont_s_on);
	SDL_DestroyTexture(t_A_Y_S);
	SDL_DestroyTexture(contin);
	SDL_DestroyTexture(qui);

	SDL_FreeSurface(win);
	SDL_FreeSurface(New_game_s);
	SDL_FreeSurface(Quit_off);
	SDL_FreeSurface(new_game_on);
	SDL_FreeSurface(Quit_on);
	SDL_DestroyTexture(win_t);
	SDL_DestroyTexture(New_game_t);
	SDL_DestroyTexture(Quit_t);
	SDL_DestroyTexture(lose_t);
}

bool Quit::cont_or_quit()
{
	bool pressed = false;
	bool next = false;
	int px = 0, py = 0;
	while (!next)
	{
		SDL_RenderCopy(render, t_A_Y_S, NULL, &r_A_Y_S);
		SDL_RenderCopy(render, contin, NULL, &r_ont);
		SDL_RenderCopy(render, qui, NULL, &r_q);
		SDL_RenderPresent(render);
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_MOUSEMOTION)
			{
				SDL_GetMouseState(&px, &py);
				pressed = false;
				//std::cout << px << " " << py << std::endl;
			}
			if (event.type == SDL_MOUSEBUTTONDOWN)
				pressed = true;
		}
		if (px >= r_ont.x && px <= r_ont.x + r_ont.w && py >= r_ont.y && py <= r_ont.y + r_ont.h)
		{
			contin = SDL_CreateTextureFromSurface(render, cont_s_on);
			if (pressed)
				return false;
		}
		else
			contin = SDL_CreateTextureFromSurface(render, cont_s);
		if (px >= r_q.x && px <= r_q.x + r_q.w && py >= r_q.y && py <= r_q.y + r_q.h)
		{
			qui = SDL_CreateTextureFromSurface(render, q_s_on);
			if (pressed)
				return true;
		}
		else
			qui = SDL_CreateTextureFromSurface(render, q_s);
	}
}

bool Quit::ng_or_q()
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
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_MOUSEMOTION)
			{
				SDL_GetMouseState(&px, &py);
				pressed = false;
				//std::cout << px << " " << py << std::endl;
			}
			if (event.type == SDL_MOUSEBUTTONDOWN)
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

bool Quit::ng_or_q2()
{
	bool pressed = false;
	bool next = false;
	int px = 0, py = 0;
	while (!next)
	{
		SDL_RenderCopy(render, lose_t, NULL, &r_win);
		SDL_RenderCopy(render, New_game_t, NULL, &r_New_game);
		SDL_RenderCopy(render, Quit_t, NULL, &r_Quit_off);
		SDL_RenderPresent(render);
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_MOUSEMOTION)
			{
				SDL_GetMouseState(&px, &py);
				pressed = false;
				//std::cout << px << " " << py << std::endl;
			}
			if (event.type == SDL_MOUSEBUTTONDOWN)
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