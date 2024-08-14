#include "EnginePhysicsComponent.h"
#include "Framework/Actor.h"

void EnginePhysicsComponent::Initialize()
{
}

void EnginePhysicsComponent::Update(float dt)
{
	velocity += acceleration * dt;
	owner->transform.position += velocity * dt;

	velocity *= 1.0f / (1.0f + damping * dt);

	acceleration = VectorTwo{ 0, 0 };
}

void EnginePhysicsComponent::ApplyForce(const VectorTwo& force)
{
	assert(mass != 0);
	acceleration += force / mass;
}

void EnginePhysicsComponent::SetPosition(const VectorTwo& position)
{
	owner->transform.position = position;
}

void EnginePhysicsComponent::Read(const json_t& value)
{
	PhysicsComponent::Read(value);
}

void EnginePhysicsComponent::Write(json_t& value)
{
}