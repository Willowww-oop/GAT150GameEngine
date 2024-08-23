#pragma once
#include "PhysicsComponent.h"
#include "Physics/RigidBody.h"

#include <memory>

class Box2DPhysicsComponent : public PhysicsComponent
{
public:
	Box2DPhysicsComponent() = default;
	Box2DPhysicsComponent(const Box2DPhysicsComponent& other);

	CLASS_DECLARATION(Box2DPhysicsComponent)
	CLASS_PROTOTYPE(Box2DPhysicsComponent)

	void Initialize() override;
	void Update(float dt) override;

	void ApplyForce(const VectorTwo& force) override;
	void ApplyTorque(float torque) override;

	void SetPosition(const VectorTwo& position) override;
	void SetVelocity(const VectorTwo& velocity) override;

public:
	RigidBody::def_t rigidBodyDef;
	VectorTwo size{ 0, 0 };

private:
	std::unique_ptr<RigidBody> m_rigidBody;
};