#pragma once
#include "Renderer.h"
#include "Resources/Resource.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include <string>

struct Color;
class Font;
class Renderer;

class Text
{
public:
	Text() = default;
	Text(res_t<Font> font)
	{
		m_font = font;
	}
	~Text();

	bool Create(Renderer& renderer, const std::string& text, const Color& color);
	void Draw(Renderer& renderer, int x, int y);

private:
	res_t<Font> m_font;
	SDL_Texture* m_texture{ nullptr };
};