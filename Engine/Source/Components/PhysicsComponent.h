#pragma once
#include "Component.h"

class PhysicsComponent : public Component
{
public:
	CLASS_DECLARATION(PhysicsComponent)
	

	virtual void ApplyForce(const VectorTwo& force) = 0;
	virtual void ApplyTorque(float angle) = 0;
	virtual void SetPosition(const VectorTwo& position) = 0;
	virtual void SetVelocity(const VectorTwo& velocity) = 0;

public:
	VectorTwo velocity{ 0, 0 };
	VectorTwo acceleration{ 0, 0 };	
	float mass{ 1 };
	float damping{ 0 };
};