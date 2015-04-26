#include <iostream>
#include <GL\glew.h>
#include "Display.h"
#include "shader.h"
#include "mesh.h"
#include <cstdlib>
#include "textures.h"
#include "Variabels.h"
#include <cmath>
#include "camera.h"
#include "tank_transform.h"
#include <SDL2\SDL_image.h>
#include <SDL2\SDL_ttf.h>
#include "Check_collision.h"
#include "main_menu.h"
#include "Quit.h"
#include "SDL2\SDL_timer.h">
#include "Win_or_lose.h"
#include "particle.h"
#include "shadow.h"

int wight = 1360;
int height = 768;

int main(int argc, char** argv)
{
	Display display(wight, height, "Tank mission");
	// Variables for display and tank
	bool quit = false;
	bool move_forward = false;
	bool move_right = false;
	bool move_left = false;
	bool move_back = false;
	bool c = true;

	SDL_Init(SDL_INIT_EVERYTHING);
	Camera camera(glm::vec3(0.0f, 0.75f, -2.5f), 45.0f, (float)wight / height, 0.01f, 1000.0f);
	Camera temp_camera(glm::vec3(0.0f, 0.75f, -2.5f), 45.0f, (float)wight / height, 0.01f, 1000.0f);

	//Shadow shadow;

	// Loading shader
	Shader shader("./res/basicShader");
	Shader transparent("./res/transparent");
	Shader bullet_shader("./res/bulletshader");
	
	// Loading object
	Mesh statistic("./res/OBJ/stat.obj");
	Mesh mesz("./res/tank_down.obj");
	Mesh tank_up("./res/tank_up.obj");
	Mesh sky_box("./res/All project/3dmodels/sky_box.obj");
	Mesh Build_five("./res/OBJ/Build_five.obj");
	Mesh Build_five_som("./res/OBJ/Build_five_som.obj");
	Mesh Build_five_window("./res/OBJ/Build_five_window.obj");
	Mesh Build_four("./res/OBJ/Build_four.obj");
	Mesh Build_four_som("./res/OBJ/Build_four_som.obj");
	Mesh Build_four_window("./res/OBJ/Build_four_window.obj");
	Mesh Build_one("./res/OBJ/Build_one.obj");
	Mesh Build_one_som("./res/OBJ/Build_one_som.obj");
	Mesh Build_one_window("./res/OBJ/Build_one_window.obj");
	Mesh Build_seven("./res/OBJ/Build_seven.obj");
	Mesh Build_seven_som("./res/OBJ/Build_seven_som.obj");
	Mesh Build_seven_window("./res/OBJ/Build_seven_window.obj");
	Mesh Build_six("./res/OBJ/Build_six.obj");
	Mesh Build_six_som("./res/OBJ/Build_six_som.obj");
	Mesh Build_six_window("./res/OBJ/Build_six_window.obj");
	Mesh Build_three("./res/OBJ/Build_three.obj");
	Mesh Build_three_som("./res/OBJ/Build_three_som.obj");
	Mesh Build_three_window("./res/OBJ/Build_three_window.obj");
	Mesh Build_two("./res/OBJ/Build_two.obj");
	Mesh Build_two_window("./res/OBJ/Build_two_window.obj");
	Mesh Curb("./res/OBJ/Curb.obj");
	Mesh Death_star("./res/OBJ/Death_star.obj");
	Mesh Dummy_planae("./res/OBJ/Dummy_planae.obj");
	Mesh Grass("./res/OBJ/Grass.obj");
	Mesh Lantern_up("./res/OBJ/Lantern_up.obj");
	Mesh Leaves_1("./res/OBJ/Leaves_1.obj");
	Mesh Leaves_2("./res/OBJ/Leaves_2.obj");
	Mesh Leaves_3("./res/OBJ/Leaves_3.obj");
	Mesh Leaves_4("./res/OBJ/Leaves_4.obj");
	Mesh Light_lantern("./res/OBJ/Light_lantern.obj");
	Mesh Road_1("./res/OBJ/Road_1.obj");
	Mesh road_2("./res/OBJ/road_2.obj");
	Mesh Road_3("./res/OBJ/Road_3.obj");
	Mesh Sauron_eye("./res/OBJ/Sauron_eye.obj");
	Mesh target_1("./res/OBJ/target_1.obj");
	Mesh target_2("./res/OBJ/target_2.obj");
	Mesh target_3("./res/OBJ/target_3.obj");
	Mesh Truck("./res/OBJ/Truck.obj");
	Mesh Trunk("./res/OBJ/Trunk.obj");
	Mesh Bullet("./res/OBJ/bullet.obj");
	Mesh grass_1("./res/OBJ/grass/grass_1.obj");
	Mesh grass_2("./res/OBJ/grass/grass_2.obj");
	Mesh grass_3("./res/OBJ/grass/grass_3.obj");
	Mesh grass_4("./res/OBJ/grass/grass_4.obj");
	Mesh paproc("./res/OBJ/grass/paproc.obj");
	Mesh bluszcz("./res/OBJ/grass/bluszcz.obj");

	// Loading textures
	Texture tex("./res/BrickOldOvergrown0018_1_S.jpg");
	Texture build_one_texture("./res/building/CinderblockClean0017_2_M.jpg");
	Texture build_one_window_texture("./res/building/4626448516_4365d2e85b_z.jpg");
	Texture sky_box_t("./res/All project/textures/sky-09.jpg");
	Texture tree_down_t("./res/All project/textures/BarkDecidious0146_3_M.jpg");
	Texture tree_leaves_t("./res/All project/textures/Bez nazwy-1.png");
	Texture rust_texture("./res/textures/rust_texture.jpg");
	Texture AsphaltCloseups("./res/textures/AsphaltCloseups.jpg");
	Texture BrickFacade("./res/textures/BrickFacade.jpg");
	Texture CinderblockClean("./res/textures/CinderblockClean.jpg");
	Texture Concrete("./res/textures/Concrete.jpg");
	Texture clone_leaves("./res/textures/clone_leaves.png");
	Texture Death_stass_texture("./res/textures/Death_stass_texture.png");
	Texture glass_wall("./res/textures/glass_wall.jpg");
	Texture Grass_text("./res/textures/Grass_text.jpg");
	Texture kafle__beton("./res/textures/kafle__beton.jpg");
	Texture Leaves_lipa("./res/textures/Leaves_lipa.png");
	Texture metal_texture("./res/textures/metal_texture.jpg");
	Texture oildrum_col("./res/textures/oildrum_col.jpg");
	Texture oko_saurona("./res/textures/oko_saurona.jpg");
	Texture road_2_texture("./res/textures/road_2_texture.jpg");
	Texture road_3_texture("./res/textures/road_3_texture.jpg");
	Texture willow_leaves("./res/textures/willow_leaves.png");
	Texture WoodFine("./res/textures/WoodFine.jpg");
	Texture tex2("./res/png_cookie_by_ellatutorials-d5r8nel.png");
	Texture grass_1_t("./res/OBJ/grass/grass_1.png");
	Texture grass_2_t("./res/OBJ/grass/grass_2.png");
	Texture grass_3_t("./res/OBJ/grass/grass_3.png");
	Texture paproc_t("./res/OBJ/grass/paproc.png");
	Texture bluszcz_t("./res/OBJ/grass/bluszcz.jpg");

	// transformation like a move, rotate and scale
	Transform tran2;
	Transform sky_transform;
	

	//draw a menu
	bool next = false;

	//if (!menu.draw_menu())
		//exit(0);
	
	IMG_Init(IMG_INIT_JPG);
	TTF_Init();

	SDL_Color textcolor = { 0, 205, 102 };
	SDL_Color backcolor{ 238, 118, 33 };
	TTF_Font* font = TTF_OpenFont("./res/league-gothic.regular.ttf",76);
	SDL_Rect rect;
	rect.x = 100;
	rect.y = height - 250;
	rect.w = 150;
	rect.h = 50;
	SDL_Rect quitrect;
	quitrect.x = 100;
	quitrect.y = height - 190;
	quitrect.w = 100;
	quitrect.h = 50;
	SDL_Renderer* render = SDL_CreateRenderer(display.m_window, -1, 0);
	SDL_Surface* image = IMG_Load("./res/tank8.jpg");
	SDL_Texture* texture = SDL_CreateTextureFromSurface(render, image);
	SDL_Surface* myfont = TTF_RenderText_Solid(font, "New Game", textcolor);
	SDL_Texture* m_font = SDL_CreateTextureFromSurface(render, myfont);
	SDL_Surface* quitfont = TTF_RenderText_Solid(font, "Quit", textcolor);
	SDL_Texture* m_font_quit = SDL_CreateTextureFromSurface(render, quitfont);
	SDL_Event event;
	bool pressed = false;
	int px = 0, py = 0;
	
	while (!next)
	{
		SDL_RenderCopy(render, texture, NULL, NULL);
		SDL_RenderCopy(render, m_font, NULL, &rect);
		SDL_RenderCopy(render, m_font_quit, NULL, &quitrect);
		SDL_RenderPresent(render);
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_MOUSEMOTION)
			{
				SDL_GetMouseState(&px, &py);
				pressed = false;
			}
			if (event.type == SDL_MOUSEBUTTONDOWN)
				pressed = true;
		}
		if (px >= rect.x && px <= rect.x + rect.w && py >= rect.y && py <= rect.y + rect.h)
		{
			myfont = TTF_RenderText_Shaded(font, "New Game", textcolor, backcolor);
			m_font = SDL_CreateTextureFromSurface(render, myfont);
			if (pressed)
				next = true;
		}
		else
		{
			myfont = TTF_RenderText_Solid(font, "New Game", textcolor);
			m_font = SDL_CreateTextureFromSurface(render, myfont);
		}

		if (px >= quitrect.x && px <= quitrect.x + quitrect.w && py >= quitrect.y && py <= quitrect.y + quitrect.h)
		{
			quitfont = TTF_RenderText_Shaded(font, "Quit", textcolor, backcolor);
			m_font_quit = SDL_CreateTextureFromSurface(render, quitfont);
			if (pressed)
			{
				exit(0);
			}
		}
		else
		{
			quitfont = TTF_RenderText_Solid(font, "Quit", textcolor);
			m_font_quit = SDL_CreateTextureFromSurface(render, quitfont);
		}
	}

	IMG_Quit();
	TTF_Quit();

	SDL_DestroyTexture(m_font);
	SDL_DestroyTexture(m_font_quit);
	SDL_DestroyRenderer(render);
	SDL_FreeSurface(image);
	SDL_FreeSurface(myfont);
	SDL_FreeSurface(quitfont);

	// variables for bullets and tank
	Variables::Bullets bullets;
	Variables::Tank tank;
	tank.tran.SetScal(glm::vec3(0.25f, 0.25f, 0.25f));
	tank.tran_up.SetScal(glm::vec3(0.25f, 0.25f, 0.25f));
	tank.tran.SetPos(glm::vec3(0.0f, 0.05, 0.0f));
	tank.tran_up.SetPos(glm::vec3(0.0f, 0.05, 0.0f));
	bullets.a[0] = bullets.a[1] = bullets.a[2] = false;
	for (auto &x : bullets.gr)
		x = 0;

	Variables::Bullets temp_bullets;
	Variables::Tank temp_tank;
	temp_bullets = bullets;
	temp_tank = tank;

	int i;
	//statsistic
	Transform stat_transform;
	stat_transform.GetScal() = glm::vec3(0.25, 0.25, 0.25);
	float y_high = 2.15f;
	float y_start = 0.7f;
	glm::vec3 start_stat = glm::vec3(0.0, y_start, -y_high);
	stat_transform.GetPos() = start_stat;
	stat_transform.GetRot() = glm::vec3(180.0, 180.0, 0.0);
	char a = '0';
	char b = '0';
	unsigned int low = 3;
	// loading a statictic and scope textures
	std::string scorrut = "./res/statistic/";
	std::string filename;
	std::string png = ".png";
	Texture table_of_stat_text[4][11];
	for (unsigned int k = 0; k < 4; k++, a++,low--)
	{
		b = '0';
		filename.clear();
		for (unsigned int j = 0; j < 11-low; j++, b++)
		{
			filename = scorrut;
			filename += a;
			filename += 'b';
			if (j == 10)
				b = 'a';
			filename += b;
			filename += png;
			table_of_stat_text[k][j].LoadImage(filename);
		}
	}
	IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
	Quit a_quit(display.m_window, height, wight);

	// loading a particle
	const float gravity = 4.0*0.0000981f;
	bool is_explosion = false;
	bool is_explosion2 = false;
	Particle part(0.1f);
	Particle part2(0.03f);

	// event for mouse and keyboard
	SDL_Event ev;

	SDL_ShowCursor(SDL_DISABLE);
	
	// for FPS
	const int FPS = 60;
	Uint32 start;
	
	// Loop where is true game :)
	tank.tank_t.speed = 0.0f;
	bool what1 = false;
	bool what2 = false;
	while (!quit)
	{
		// gets time
		start = SDL_GetTicks();
		// prevorious position for tank for checking collosion
		tank.tank_t_prev.posx = tank.tank_t.posx;
		tank.tank_t_prev.posy = tank.tank_t.posy;
		// take a event of keyboard and mouse
		while(SDL_PollEvent(&ev))
		{
			if (ev.type == SDL_QUIT)
				quit = true;
			if (ev.type == SDL_KEYDOWN)
			{
				switch (ev.key.keysym.sym)
				{
				case SDLK_w:
					move_forward=true;
					break;
				case SDLK_s:
					move_back = true;
					break;
				case SDLK_d:
					move_right = true;
					break;
				case SDLK_a:
					move_left = true;
					break;
				case SDLK_LSHIFT:
					tank.speed = true;
					break;
				case SDLK_ESCAPE:
					SDL_ShowCursor(SDL_ENABLE);
					quit = true;
					break;
				case SDLK_c:
					if (c)
						c = false;
					else
						c = true;
					camera.setCamera(c);
					camera.rotatebyY(0.0f, tank.rot_counter, tank.tank_t.angle, tank.tank_t.posy, tank.tank_t.posx);
					camera.Pith(0.0f, tank.tank_t.angle_y, tank.tank_t.posx, tank.tank_t.posy);
					break;
				}
			}
			if (ev.type == SDL_KEYUP)
			{
				switch (ev.key.keysym.sym)
				{
				case SDLK_w:
					move_forward = false;
					break;
				case SDLK_s:
					move_back = false;
					break;
				case SDLK_d:
					move_right = false;
					break;
				case SDLK_a:
					move_left = false;
					break;
				case SDLK_LSHIFT:
					tank.speed = false;
					break;
				}
			}
			if (ev.type == SDL_MOUSEMOTION)
			{
				pressed = true;
				SDL_GetMouseState(&tank.mx, &tank.my);
			}
			else
			{
				pressed = false;
			}
			if (ev.type == SDL_MOUSEBUTTONDOWN)
			{
				
				tank.is_press = true;
				if (tank.is_press)
				{
					if (bullets.licznik>60)
						bullets.nubber_of_bullets--;
					if (bullets.nubber_of_bullets > 0)
					{
						bullets.shoot[bullets.nubber_of_bullets] = true;
						bullets.licznik = 0;
					}
				}
			}
			else
				tank.is_press = false;
		}
		// end of loop for event
		// now check what of variables is true for move a tank, or changing a camera
		if (tank.speed)
		{
			if (tank.tank_t.speed <= 0.07f && tank.tank_t.speed >= 0.04f)
				tank.tank_t.speed += 0.001f;
		}
		else if (!tank.speed)
		{
			if (tank.tank_t.speed > 0.04f)
				tank.tank_t.speed -= 0.001f;
		}
		if (move_back || move_forward)
		{
			if (tank.tank_t.speed <= 0.04)
				tank.tank_t.speed += 0.001f;
		}
		else if (!(move_back || move_forward))
		{
			if (tank.tank_t.speed > 0.0f)
				tank.tank_t.speed -= 0.001f;
		}
		// c=true->camera TPS or camera FPS
		camera.setCamera(c);
		//calculate posinion of tank
		tank.pos.z = tank.tank_t.speed*cosinus(tank.rot_counter);
		tank.pos.x = tank.tank_t.speed*sinus(tank.rot_counter);
		// mouse event
		if (pressed)
		{
			if (tank.mx > tank.mwx)
			{
				tank.tank_t.angle += 1;
				camera.rotatebyY(1, tank.rot_counter, tank.tank_t.angle, tank.tank_t.posy, tank.tank_t.posx);
				SDL_WarpMouseInWindow(display.m_window, tank.mwx, tank.mwy);
			}
			else if (tank.mx<tank.mwx)
			{
				tank.tank_t.angle -= 1;
				camera.rotatebyY(-1, tank.rot_counter, tank.tank_t.angle, tank.tank_t.posy, tank.tank_t.posx);
				SDL_WarpMouseInWindow(display.m_window, tank.mwx, tank.mwy);
			}

			if (tank.my<tank.mwy && tank.tank_t.angle_y >= -5)
			{
				tank.tank_t.angle_y -= 0.25f;
				camera.Pith(0.25f, tank.tank_t.angle_y, tank.tank_t.posx, tank.tank_t.posy);
				SDL_WarpMouseInWindow(display.m_window, tank.mwx, tank.mwy);
			}
			else if (tank.my>tank.mwy && tank.tank_t.angle_y <= 5)
			{
				tank.tank_t.angle_y += 0.25f;
				camera.Pith(-0.25f, tank.tank_t.angle_y, tank.tank_t.posx, tank.tank_t.posy);
				SDL_WarpMouseInWindow(display.m_window, tank.mwx, tank.mwy);
			}
		}
		pressed = false;
		if (move_forward)
		{
			what1 = true;
			what2 = false;
			tank.tank_t.posy += tank.pos.z;
			tank.tank_t.posx += tank.pos.x;
		}
		if (move_back)
		{
			what1 = false;
			what2 = true;
			tank.tank_t.posy -= tank.pos.z;
			tank.tank_t.posx -= tank.pos.x;
		}
		if (move_right)
		{
			tank.rot_counter -= 0.5f;
			camera.rotatebyY(-0.5f, tank.rot_counter, tank.tank_t.angle, tank.tank_t.posy, tank.tank_t.posx);
		}
		if (move_left)
		{
			tank.rot_counter += 0.5f;
			camera.rotatebyY(0.5f, tank.rot_counter, tank.tank_t.angle, tank.tank_t.posy, tank.tank_t.posx);
		}
		if (what1 && tank.tank_t.speed>0.0f)
		{
			tank.tank_t.posy += tank.pos.z;
			tank.tank_t.posx += tank.pos.x;
		}
		if (what2 && tank.tank_t.speed > 0.0f)
		{
			tank.tank_t.posy -= tank.pos.z;
			tank.tank_t.posx -= tank.pos.x;
		}
		//clear a display on black color
		display.Clear(0.0f, 0.0f, 0.0f, 1.0f);
		//check the collision. When it's true then takes prevorious position for tank
		if (col::check_collision_for_tank(glm::vec3(tank.tank_t.posx, 0.0f, tank.tank_t.posy), bullets.a))
		{
			tank.tank_t.posx = tank.tank_t_prev.posx;
			tank.tank_t.posy = tank.tank_t_prev.posy;
		}
		//takes the position and rotation for vertex shader
		tank.tran.GetPos().x = tank.tank_t.posx;
		tank.tran.GetPos().z = tank.tank_t.posy;
		
		tank.tran.GetRot().y = tank.rot_counter;

		tank.tran_up.GetPos().x = tank.tank_t.posx;
		tank.tran_up.GetPos().z = tank.tank_t.posy;
		tank.tran_up.GetRot().y = tank.rot_counter + tank.tank_t.angle;

		sky_transform.GetPos() = tank.tran_up.GetPos();

		//create a bullets when they're shoots
		bullet_shader.Bind();
		if (bullets.nubber_of_bullets<10 && bullets.nubber_of_bullets>-1)
		{
			for (i = bullets.n - 1; i > bullets.nubber_of_bullets - 1; i--)
			{
				if (bullets.shoot[i])
				{
					// create and atribution the position for i bullet
					bullets.gr[i] += gravity;
					bullets.bullet_tr[i].x = bullets.bullet_speed*sinus(bullets.bullet_rot[i].x);
					bullets.bullet_tr[i].y = bullets.bullet_speed*sinus(-(bullets.bullet_rot[i].y)) - bullets.gr[i];
					bullets.bullet_tr[i].z = bullets.bullet_speed*cosinus(bullets.bullet_rot[i].x);
					bullets.bullet_pos[i] += bullets.bullet_tr[i];
					bullets.bullet_transform.GetPos().x = bullets.bullet_pos[i].x;
					bullets.bullet_transform.GetPos().y = bullets.bullet_pos[i].y;
					bullets.bullet_transform.GetPos().z = bullets.bullet_pos[i].z;
					
					// bind shader and draw the bullet
					bullet_shader.Update(bullets.bullet_transform, camera);
					Bullet.Draw();
					
					// checking collision with building or end of map or with ground
					if (col::for_bullets_with_houses(bullets.bullet_pos[i]))
					{
						bullets.shoot[i] = false;
						is_explosion2 = true;
						part2.init_first_pos(bullets.bullet_pos[i]);
					}
					// checking the collision with barells
					if (bullets.sh < 3)
					{
						if ((bullets.wat = col::target_collision(bullets.bullet_pos[i], bullets.a)) > 0)
						{
							bullets.a[bullets.wat - 1] = true;
							bullets.shoot[i] = false;
							bullets.sh++;
							bullets.k--;
							part.init_first_pos(bullets.bullet_pos[i]);
							is_explosion = true;
						}
					}

				}
			}
		}

		//atribute the position for bullets
		for (i = 0; i < bullets.nubber_of_bullets; i++)
		{
			bullets.bullet_pos[i].x = tank.tank_t.posx;
			bullets.bullet_pos[i].y = 0.75f;
			bullets.bullet_pos[i].z = tank.tank_t.posy;
			bullets.bullet_rot[i].x = tank.rot_counter + tank.tank_t.angle;
			bullets.bullet_rot[i].y = tank.tank_t.angle_y;
			bullets.shoot[i] = false;
		}
		//drawing a explosion of barels when is collosion with bullet
		if (is_explosion)
			is_explosion = part.draw_particle(camera);
		if (is_explosion2)
			is_explosion2 = part2.draw_particle(camera);

		// drawing a statistic
		stat_transform.GetPos() = tank.tran.GetPos();
		stat_transform.GetRot().y = tank.tran_up.GetRot().y;
		if (c)
		{
			y_high = 2.15f;
			y_start = 0.7f;
		}
		else
		{
			y_high = -0.35f;
			y_start = 0.7f;
		}
		stat_transform.GetPos() = tank.tran.GetPos() + glm::vec3((-y_high)*sinus(tank.rot_counter + tank.tank_t.angle), y_start + y_high*sinus(tank.tank_t.angle_y), (-y_high)*cosinus(tank.rot_counter + tank.tank_t.angle));

		shader.Bind();
		if (bullets.nubber_of_bullets>-1)
		{
			table_of_stat_text[bullets.k][bullets.nubber_of_bullets].Bind(0);
			shader.Update(stat_transform, camera);
			statistic.Draw();
		}

		// changing the position of camera
		camera.move(tank.tank_t.posx, tank.tank_t.posy);

		// drawing all scene
		tex.Bind(0);

		shader.Update(tank.tran, camera);
		mesz.Draw();

		shader.Update(tank.tran_up, camera);
		tank_up.Draw();

		sky_box_t.Bind(0);
		shader.Update(sky_transform, camera);
		sky_box.Draw();

		rust_texture.Bind(0);
		shader.Update(tran2, camera);
		Truck.Draw();

		build_one_texture.Bind(0);
		shader.Update(tran2, camera);;
		Build_one.Draw();
		Build_two.Draw();
		Build_four_som.Draw();

		build_one_window_texture.Bind(0);
		shader.Update(tran2, camera);
		Build_five_window.Draw();
		Build_four_window.Draw();
		Build_one_window.Draw();
		Build_seven_window.Draw();
		Build_three_window.Draw();
		Build_two_window.Draw();
		Light_lantern.Draw();

		glass_wall.Bind(0);
		shader.Update(tran2, camera);
		Build_six_window.Draw();

		tree_down_t.Bind(0);
		shader.Update(tran2, camera);
		Trunk.Draw();

		//drawing a barels 
		oildrum_col.Bind(0);
		shader.Update(tran2, camera);
		if (!bullets.a[1])
			target_1.Draw();
		if (!bullets.a[0])
			target_2.Draw();
		if (!bullets.a[2])
			target_3.Draw();

		AsphaltCloseups.Bind(0);
		shader.Update(tran2, camera);
		Road_1.Draw();

		road_2_texture.Bind(0);
		shader.Update(tran2, camera);
		road_2.Draw();

		road_3_texture.Bind(0);
		shader.Update(tran2, camera);
		Road_3.Draw();

		oko_saurona.Bind(0);
		shader.Update(tran2, camera);
		Sauron_eye.Draw();

		Concrete.Bind(0);
		shader.Update(tran2, camera);
		Build_six.Draw();
		Build_four.Draw();

		WoodFine.Bind(0);
		shader.Update(tran2, camera);
		Build_six_som.Draw();

		CinderblockClean.Bind(0);
		shader.Update(tran2, camera);
		Build_three.Draw();

		BrickFacade.Bind(0);
		shader.Update(tran2, camera);
		Build_three_som.Draw();
		Build_five_som.Draw();

		kafle__beton.Bind(0);
		shader.Update(tran2, camera);
		Build_seven_som.Draw();
		Curb.Draw();
		Build_five.Draw();

		metal_texture.Bind(0);
		shader.Update(tran2, camera);
		Build_seven.Draw();
		Lantern_up.Draw();
		Build_one_som.Draw();

		Death_stass_texture.Bind(0);
		shader.Update(tran2, camera);
		Death_star.Draw();

		Grass_text.Bind(0);
		shader.Update(tran2, camera);
		Grass.Draw();

		transparent.Bind();
		tree_leaves_t.Bind(0);
		transparent.Update(tran2, camera);
		Leaves_1.Draw();

		willow_leaves.Bind(0);
		transparent.Update(tran2, camera);
		Leaves_4.Draw();

		Leaves_lipa.Bind(0);
		transparent.Update(tran2, camera);
		Leaves_3.Draw();

		clone_leaves.Bind(0);
		transparent.Update(tran2, camera);
		Leaves_2.Draw();

		grass_1_t.Bind(0);
		transparent.Update(tran2, camera);
		grass_1.Draw();

		grass_2_t.Bind(0);
		transparent.Update(tran2, camera);
		grass_2.Draw();
		grass_4.Draw();

		grass_3_t.Bind(0);
		transparent.Update(tran2, camera);
		grass_3.Draw();

		paproc_t.Bind(0);
		transparent.Update(tran2, camera);
		paproc.Draw();

		bluszcz_t.Bind(0);
		transparent.Update(tran2, camera);
		bluszcz.Draw();

		// drawing a menu for when pressed esc
		if (quit)
		{
			quit = a_quit.cont_or_quit();
			if (!quit)
				SDL_ShowCursor(SDL_DISABLE);
		}

		// checking a time for controling fps
		if (1000.0f / (float)FPS > SDL_GetTicks() - start)
			SDL_Delay((1000.0f / (float)FPS) - (SDL_GetTicks() - start));


		bullets.licznik++;
		// when you win or lose draw a menu for chose new game or quit
		if (bullets.sh == 3 && !is_explosion)
		{
			SDL_ShowCursor(SDL_ENABLE);
			quit = a_quit.ng_or_q();
			if (!quit)
			{
				bullets = temp_bullets;
				tank = temp_tank;
				camera = temp_camera;
				SDL_ShowCursor(SDL_DISABLE);
			}
		}
		else if (bullets.nubber_of_bullets == 0 && bullets.sh < 3 && !is_explosion)
		{
			SDL_ShowCursor(SDL_ENABLE);
			quit = a_quit.ng_or_q2();
			if (!quit)
			{
				bullets = temp_bullets;
				tank = temp_tank;
				camera = temp_camera;
				SDL_ShowCursor(SDL_DISABLE);
			}
		}
		//update a display/swap buffer
		display.Update();

	}
	//close image loader of sdl2
	IMG_Quit();
	return 0;
}