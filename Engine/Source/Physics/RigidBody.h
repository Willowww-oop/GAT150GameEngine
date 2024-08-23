#pragma once
#include "Math/Transform.h"
#include <box2d/box2d.h>

class RigidBody
{
public:
	struct def_t
	{
		// body
		float gravityScale = 1;
		float damping = 0;
		float angularDamping = 0;
		bool  constrainAngle = false;
		bool  isDynamic = true;

		// shape
		float friction = 0.0f;
		float restitution = 0.5f;
		float density = 1.0f;
		bool isSensor = false;

		class Actor* actor{ nullptr };
	};

public:
	RigidBody(const Transform& transform, const VectorTwo& size, const def_t& def, const class Physics& physics);
	~RigidBody();

	void SetTransform(const VectorTwo& position, float rotation);
	VectorTwo GetPosition();

	float GetAngle();

	void ApplyForce(const VectorTwo& force);
	void SetVelocity(const VectorTwo& velocity);
	VectorTwo GetVelocity();

	void ApplyTorque(float torque);
	void SetAngularVelocity(float velocity);

private:
	b2BodyId m_bodyId{ b2_nullBodyId };
};