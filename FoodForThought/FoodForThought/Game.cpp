#include "Game.h"

namespace
{
	const int kFPS = 60;
}


Game::Game()
{
	SDL_Init(SDL_INIT_EVERYTHING);
}


Game::~Game()
{
	SDL_Quit();
}


void Game::Run()
{
	Graphics graphics;
	SDL_Event event;

	VInitialize();

	m_Running = true;
	int lastUpdateTime = SDL_GetTicks();

	while (m_Running)
	{
		const int startTimeMS = SDL_GetTicks();

		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				m_Running = false;
				break;
			}

			VHandleEvent(event);
		}

		const int currentTimeMS = SDL_GetTicks();
		VUpdate(currentTimeMS - lastUpdateTime);
		lastUpdateTime = currentTimeMS;

		VDraw(graphics);

		const int msPerFrame = 1000 / kFPS;
		const int elapsedTimeMS = (SDL_GetTicks() - startTimeMS);

		if (elapsedTimeMS < msPerFrame)
			SDL_Delay(msPerFrame - elapsedTimeMS);
	}
}


void Game::Exit()
{
	m_Running = false;
}