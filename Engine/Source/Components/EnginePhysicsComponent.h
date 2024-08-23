#pragma once
#include "PhysicsComponent.h"

class EnginePhysicsComponent : public PhysicsComponent
{
public:
	CLASS_DECLARATION(EnginePhysicsComponent)
	CLASS_PROTOTYPE(EnginePhysicsComponent)

	void Initialize() override;
	void Update(float dt) override;

	void ApplyForce(const VectorTwo& force) override;
	void ApplyTorque(float angle) override;
	void SetPosition(const VectorTwo& position) override;
	inline void SetVelocity(const VectorTwo& velocity) override {
		this->velocity = velocity;
	}
};
