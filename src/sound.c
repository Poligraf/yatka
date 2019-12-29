
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>

#include "sound.h"
#include "main.h"

Mix_Music *music[MUSIC_TRACK_NUM];
int current_track = 0;
Mix_Chunk *hit = NULL;

void selectNextTrack(void)
{
	current_track = (current_track + 1) % MUSIC_TRACK_NUM;
}

void selectPreviousTrack(void)
{
	current_track = (current_track + MUSIC_TRACK_NUM - 1) % MUSIC_TRACK_NUM;
}

void trackFinished(void)
{
	if (GS_GAMEOVER != gamestate)
	{
		if (!repeattrack)
		{
			selectNextTrack();
		}
		Mix_PlayMusic(music[current_track], 1);

		// informing event
		SDL_Event event;

		event.type = SDL_USEREVENT;
		event.user.code = current_track;
		event.user.data1 = 0;
		event.user.data2 = 0;
		SDL_PushEvent(&event);
	}
}
