#include<stdio.h>
#include<stdlib.h>
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"


int main(int argc, char* args[]) {
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window* window = SDL_CreateWindow("Hey", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, 0);
	SDL_Renderer* render = SDL_CreateRenderer(window, -1, 0);

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

	return 0;
}
