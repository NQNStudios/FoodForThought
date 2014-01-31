#pragma once

#include <map>
#include <string>

struct SDL_Window;
struct SDL_Surface;
struct SDL_Rect;
struct Uint32;

class Graphics
{
public:
	Graphics();
	~Graphics();

	SDL_Surface* LoadImage(const std::string& filePath, Uint32 transparentColor);

	void Clear();
	void Update();

	void BlitSurface(SDL_Surface* source, SDL_Rect* sourceRect, SDL_Rect* destRect);

private:
	SDL_Window* m_Window;
	SDL_Surface* m_Screen;
};

