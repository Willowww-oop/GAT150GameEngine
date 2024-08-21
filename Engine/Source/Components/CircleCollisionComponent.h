#pragma once
#include "CollisionComponent.h"

class CircleCollisionComponent : public CollisionComponent
{
public:
	CLASS_DECLARATION(CircleCollisionComponent)

public:
	float radius = 0.0f;

	void Initialize() override;
	void Update(float dt) override;
	bool CheckCollision(const CollisionComponent* collision) override;


};