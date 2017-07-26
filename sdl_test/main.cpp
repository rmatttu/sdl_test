#include<stdio.h>
#include<stdlib.h>
#include<string>
#include"SDL.h"
#include"SDL_image.h"
#include"SDL_ttf.h"
#include"SDL_mixer.h"


int main(int argc, char* args[]) {

	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = SDL_CreateWindow("Hey", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, 0);
	SDL_Renderer* render = SDL_CreateRenderer(window, -1, 0);

	//auto mix = Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
	auto mix = Mix_OpenAudio(44100, AUDIO_S16LSB, MIX_DEFAULT_CHANNELS, 1024);
	if (mix != 0) {
		return 2;
	}
	Mix_Music *music = Mix_LoadMUS("res/em.ogg");
	if (music == nullptr) {
		return 3;
	}
	Mix_PlayMusic(music, -1);


	if (TTF_Init() == -1) {
		printf("TTF_Init: %s\n", TTF_GetError());
		exit(2);
	}
	TTF_Font* Sans = TTF_OpenFont("res/ipag-mona.ttf", 72); //this opens a font style and sets a size
	if (!Sans){
		SDL_Log(SDL_GetError());
		return 0;
	}
	SDL_Color White = { 255, 0, 0 };  // this is the color in rgb format, maxing out all would give you the color white, and it will be your text's color
	SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Sans, "put your text here", White); // as TTF_RenderText_Solid could only be used on SDL_Surface then you have to create the surface first
	if (!surfaceMessage)return 0;
	SDL_Texture* Message = SDL_CreateTextureFromSurface(render, surfaceMessage); //now you can convert it into a texture
	if (!Message)return 0;
	SDL_Rect Message_rect; //create a rect
	Message_rect.x = 0;  //controls the rect's x coordinate 
	Message_rect.y = 0; // controls the rect's y coordinte
	Message_rect.w = 800; // controls the width of the rect
	Message_rect.h = 100; // controls the height of the rect
	//Mind you that (0,0) is on the top left of the window/screen, think a rect as the text's box, that way it would be very simple to understance
	//Now since it's a texture, you have to put RenderCopy in your game loop area, the area where the whole code executes
	//SDL_RenderCopy(render, Message, NULL, &Message_rect); //you put the renderer's name first, the Message, the crop size(you can ignore this if you don't want to dabble with cropping), and the rect which is the size and coordinate of your texture
	//Don't forget too free your surface and texture


















    // テストです


	// 画像
	SDL_Surface *image;
	image = IMG_Load("res/bird_koruri.png");
	if (!image) {
		printf("IMG_Load: %s\n", IMG_GetError());
		return 1;
		// ここでエラー処理を行う
	}
	SDL_Texture *texture;
	texture  = SDL_CreateTextureFromSurface(render, image);

	int volume = 128;
	SDL_Event ev;
	while (true) {
		// 文字描画
		SDL_RenderCopy(render, Message, NULL, &Message_rect); //you put the renderer's name first, the Message, the crop size(you can ignore this if you don't want to dabble with cropping), and the rect which is the size and coordinate of your texture
		// 画像の描画
		SDL_RenderCopy(render, texture , nullptr, nullptr);
		//線の描画
		SDL_SetRenderDrawColor(render, 255, 0, 0, 255);
		SDL_RenderDrawLine(render, 10, 10, 400, 400);

		// 画面のフリップ
		SDL_RenderPresent(render);

		// 画面のクリア
		SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
		SDL_RenderClear(render);
		// イベントの処理
		while (SDL_PollEvent(&ev))
		{

			switch (ev.type)
			{
			case SDL_KEYDOWN:
				switch (ev.key.keysym.sym) {
				case SDLK_ESCAPE:    //もし押されたのがESCキーなら終了
					return 0;
					break;
				case SDLK_RIGHT:    //もし右カーソルなら
					++volume;
					break;
				case SDLK_LEFT:
					--volume;
					break;
				case SDLK_UP:
					break;
				case SDLK_DOWN:
					break;
				default:
					break;
				}

				switch (ev.key.keysym.sym) {
				case SDLK_RIGHT:    //もし右カーソルなら
					break;
				case SDLK_LEFT:
					break;
				case SDLK_UP:
					break;
				case SDLK_DOWN:
					break;
				default:
					break;
				}
				break;
			case SDL_QUIT:
				return 0;
				break;
			default:
				break;
			}
		}
		SDL_Delay(0);
		if (0 > volume) volume = 0;
		if (128 < volume) volume = 128;
		Mix_VolumeMusic(volume);

		std::string str = std::to_string(Mix_VolumeMusic(-1));
		char* cstr = new char[str.size() + 1];
		strcpy_s(cstr,str.size() + 1, str.c_str());
		SDL_Log(cstr);
		free(cstr);

	}

	Mix_FreeMusic(music);
	Mix_CloseAudio();

	return 0;
}
