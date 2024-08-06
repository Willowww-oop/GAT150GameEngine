#pragma once
#include "../Resources/Resource.h"
#include "../Math/VectorTwo.h"
#include <string>

struct VectorTwo;

class Texture : public Resource
{
public:
	Texture() = default;
	~Texture();

	bool Create(std::string name, ...) override;
	bool Load(const std::string& filename, class Renderer& renderer);

	VectorTwo GetSize();

	friend class Renderer;

private:
	struct SDL_Texture* m_texture{ nullptr };

	// Inherited via Resource
};