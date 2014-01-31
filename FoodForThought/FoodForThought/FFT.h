#pragma once

#include "game.h"

class FFT : public Game
{
private:
	void VInitialize();
	void VUpdate(int deltaMS);
	void VHandleEvent(SDL_Event& event);
	void VDraw(Graphics& graphics);
};

