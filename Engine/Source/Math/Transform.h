#pragma once
#include "VectorTwo.h"
#include "Core/Serializable.h"

struct Transform : public Serializable
{
	VectorTwo position{ 0, 0 };
	float rotation = 0;
	float scale = 1;

	Transform() = default;
	Transform(VectorTwo position, float rotation = 0, float scale = 1) :
	
		position{ position },
		rotation { rotation },
		scale{ scale }
	{}

	VectorTwo Forward() { return VectorTwo{ 1, 0 }.Rotate(Math::DegToRad(rotation)); }

	// Inherited via Serializable
	void Read(const json_t& value) override;
	void Write(json_t& value) override;
};