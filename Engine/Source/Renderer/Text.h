#pragma once
#include "Renderer.h"
#include "Resources/Resource.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include "Texture.h"

struct Color;
class Font;
class Renderer;

class Text
{
public:
	Text() = default;
	Text(res_t<Font> font) : m_font{ font }{}
	~Text() = default;

	bool Create(Renderer& renderer, const std::string& text, const Color& color);
	void Draw(Renderer& renderer, float x, float y, float angle = 0);
	
	void SetFont(res_t<Font> font) { m_font = font; }
	res_t<Texture> GetTexture() { return m_texture; }

private:
	res_t<Font> m_font{ nullptr };
	res_t<Texture> m_texture{ nullptr };
};
