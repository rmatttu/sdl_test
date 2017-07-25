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


	// �摜
	SDL_Surface *image;
	image = IMG_Load("res/bird_koruri.png");
	if (!image) {
		printf("IMG_Load: %s\n", IMG_GetError());
		return 1;
		// �����ŃG���[�������s��
	}
	SDL_Texture *texture;
	texture = SDL_CreateTextureFromSurface(render, image);

	int volume = 128;
	SDL_Event ev;
	while (true) {
		// �摜�̕`��
		SDL_RenderCopy(render, texture, nullptr, nullptr);

		//���̕`��
		SDL_SetRenderDrawColor(render, 255, 0, 0, 255);
		SDL_RenderDrawLine(render, 10, 10, 400, 400);

		// ��ʂ̃t���b�v
		SDL_RenderPresent(render);

		// ��ʂ̃N���A
		SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
		SDL_RenderClear(render);
		// �C�x���g�̏���
		while (SDL_PollEvent(&ev))
		{

			switch (ev.type)
			{
			case SDL_KEYDOWN:
				switch (ev.key.keysym.sym) {
				case SDLK_ESCAPE:    //���������ꂽ�̂�ESC�L�[�Ȃ�I��
					return 0;
					break;
				case SDLK_RIGHT:    //�����E�J�[�\���Ȃ�
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
				case SDLK_RIGHT:    //�����E�J�[�\���Ȃ�
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
