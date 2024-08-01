#pragma once
#include "../Math/VectorTwo.h"
#include "../Math/Transform.h"
#include "Color.h"
#include "Renderer.h"
#include <vector>

// * - pointer
// & - reference

class Model
{
public:
	Model() = default;
	Model(const std::vector<VectorTwo>& points,const Color& color) :
		m_points { points },
		m_color { color }
	{}

	void Draw(Renderer& renderer, const VectorTwo& position, float angle, float scale);
	void Draw(Renderer& renderer, Transform& transform);

	float GetRadius();


private:
	std::vector<VectorTwo> m_points;
	Color m_color;
};