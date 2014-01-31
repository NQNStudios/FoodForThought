#pragma once

#include <SDL.h>

class Game
{
public:
	Game();
	~Game();

	void Run();
	void Exit();
private:
	virtual void VInitialize() = 0;
	virtual void VUpdate(int deltaMS) = 0;
	virtual void VHandleEvent(SDL_Event& event) = 0;
	virtual void VDraw(Graphics& graphics) = 0;

	bool m_Running;
};

