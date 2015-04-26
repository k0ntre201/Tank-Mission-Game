#include "main_menu.h"
#include <iostream>

Main_menu::Main_menu(SDL_Renderer* render, int height)
{
	this->render = render;
	this->height = height;
}

void Main_menu::init_evrything()
{
	if (!IMG_Init(IMG_INIT_JPG))
	{
		std::cerr << "cannot initialize sdl image!" << std::endl;
	}
	if (TTF_Init()==-1)
	{
		std::cerr << "cannot initialize sdl TTF!" << std::endl;
	}
}

void Main_menu::init_ev()
{
	init_evrything();
	//TTF_Init();
	textcolor = { 0, 205, 102 };
	backcolor = { 238, 118, 33 };
	font = TTF_OpenFont("./res/league-gothic.regular.ttf", 76);
	new_game_rect.x = 100;
	new_game_rect.y = height - 250;
	new_game_rect.w = 150;
	new_game_rect.h = 50;
	quit_rect.x = 100;
	quit_rect.y = height - 190;
	quit_rect.w = 100;
	quit_rect.h = 50;
	//render = SDL_CreateRenderer(window, -1, 0);
	image=IMG_Load("./res/tank-wallpapers-8.jpg");
	texture=SDL_CreateTextureFromSurface(render, image);
	
	myfont=TTF_RenderText_Solid(font, "New Game", textcolor);
	m_font_newgame=SDL_CreateTextureFromSurface(render, myfont);
	quitfont=TTF_RenderText_Solid(font, "Quit", textcolor);
	m_font_quit=SDL_CreateTextureFromSurface(render, quitfont);
	pressed = false;
	next = false;
	px = 0;
	py = 0; 
}

void Main_menu::render_sdl()
{
	SDL_RenderCopy(render, texture, NULL, NULL);
	SDL_RenderCopy(render, m_font_newgame, NULL, &new_game_rect);
	SDL_RenderCopy(render, m_font_quit, NULL, &quit_rect);
	SDL_RenderPresent(render);

}

bool Main_menu::draw_menu()
{
	init_ev();
	//render_sdl();
	SDL_RenderCopy(render, texture, NULL, NULL);
	SDL_RenderCopy(render, m_font_newgame, NULL, &new_game_rect);
	SDL_RenderCopy(render, m_font_quit, NULL, &quit_rect);
	SDL_RenderPresent(render);
	while (!next)
	{
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
		if (px >= new_game_rect.x && px <= new_game_rect.x + new_game_rect.w && py >= new_game_rect.y && py <= new_game_rect.y + new_game_rect.h)
		{
			myfont = TTF_RenderText_Shaded(font, "New Game", backcolor, textcolor);
			m_font_newgame = SDL_CreateTextureFromSurface(render, myfont);
			if (pressed)
				next = true;
		}
		else
		{
			myfont = TTF_RenderText_Solid(font, "New Game", textcolor);
			m_font_newgame = SDL_CreateTextureFromSurface(render, myfont);
		}

		if (px >= quit_rect.x && px <= quit_rect.x + quit_rect.w && py >= quit_rect.y && py <= quit_rect.y + quit_rect.h)
		{
			quitfont = TTF_RenderText_Shaded(font, "Quit", textcolor, backcolor);
			m_font_quit = SDL_CreateTextureFromSurface(render, quitfont);
			if (pressed)
			{
				return false;
			}
		}
		else
		{
			quitfont = TTF_RenderText_Solid(font, "Quit", textcolor);
			m_font_quit = SDL_CreateTextureFromSurface(render, quitfont);
		}
	}
	return true;
}

Main_menu::~Main_menu()
{
	IMG_Quit();
	TTF_Quit();
	SDL_DestroyTexture(texture);
	SDL_DestroyTexture(m_font_newgame);
	SDL_DestroyTexture(m_font_quit);
	SDL_DestroyRenderer(render);
	SDL_FreeSurface(image);
	SDL_FreeSurface(myfont);
	SDL_FreeSurface(quitfont);
//	SDL_FreeSurface(menu_surface);
}