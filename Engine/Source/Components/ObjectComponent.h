#pragma once
#include "PhysicsComponent.h"

class ObjectComponent : public PhysicsComponent
{
public:

	CLASS_DECLARATION(ObjectComponent)

	void SetPosition(const VectorTwo& position) = 0;
	void SetVelocity(const VectorTwo& velocity) = 0;

public:

	int score = { 0 };

};