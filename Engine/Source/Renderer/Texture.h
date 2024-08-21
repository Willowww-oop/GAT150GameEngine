#pragma once
#include "../Resources/Resource.h"
#include "../Math/VectorTwo.h"
#include <string>

struct VectorTwo;

struct SDL_Texture;

class Texture : public Resource
{
public:
	Texture() = default;
	Texture(SDL_Texture* texture) : m_texture{ texture } {}

	bool Create(std::string name, ...) override;
	bool Load(const std::string& filename, class Renderer& renderer);

	VectorTwo GetSize();

	friend class Renderer;

private:
	SDL_Texture* m_texture{ nullptr };

	// Inherited via Resource
};