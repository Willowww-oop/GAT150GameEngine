#pragma once
#include "Math/VectorTwo.h"
#include <box2d/box2d.h>
#include <memory>

#define PIXELS_PER_UNIT	48.0f

inline b2Vec2  ConvertVec2(const VectorTwo& v) { return b2Vec2{ v.x, v.y }; }
inline VectorTwo ConvertVec2(const b2Vec2& v)  { return VectorTwo{ v.x, v.y }; }

class Physics
{
public:
	Physics() = default;

	bool Initialize();
	void Shutdown();

	void Update(float dt);
	void UpdateCollision();

	static VectorTwo WorldToScreen(const VectorTwo& world)	{ return world * PIXELS_PER_UNIT; }
	static VectorTwo ScreenToWorld(const VectorTwo& screen) { return screen * (1.0f / PIXELS_PER_UNIT); }
	
	friend class RigidBody;

private:
	b2WorldId m_worldId;
};
