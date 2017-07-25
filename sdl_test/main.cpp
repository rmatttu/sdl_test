#include<stdio.h>
#include<stdlib.h>
#include"SDL.h"
#include"SDL_image.h"
#include"SDL_ttf.h"
#include"SDL_mixer.h"


int main(int argc, char* args[]) {
	SDL_Init(SDL_INIT_VIDEO);
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


	// 画像
	SDL_Surface *image;
	image = IMG_Load("res/bird_koruri.png");
	if (!image) {
		printf("IMG_Load: %s\n", IMG_GetError());
		return 1;
		// ここでエラー処理を行う
	}
	SDL_Texture *texture;
	texture = SDL_CreateTextureFromSurface(render, image);

	SDL_Event ev;
	while (true) {
		// 画像の描画
		SDL_RenderCopy(render, texture, nullptr, nullptr);

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
			
			if (ev.type == SDL_QUIT) {

				return 0;
			}
		}
		SDL_Delay(0);
	}

	Mix_FreeMusic(music);
	Mix_CloseAudio();

	return 0;
}
