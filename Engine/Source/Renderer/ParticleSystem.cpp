#include "ParticleSystem.h"
#include "Particle.h"

void ParticleSystem::Update(float dt)
{

	for (auto& particle : m_particles)
	{
		if (particle.isActive) particle.Update(dt);
	}

}

void ParticleSystem::Draw(Renderer& renderer)
{
	for (auto& particle : m_particles)
	{
		if (particle.isActive) particle.Draw(renderer);
	}
}

Particle* ParticleSystem::GetFreeParticle()
{
	for (auto& particle : m_particles)
	{
		if (!particle.isActive) return &particle;
	}
	return nullptr;
}

void ParticleSystem::AddParticle(const Particle::Data& data)
{
	Particle* particle = GetFreeParticle();
	if (particle)
	{
		particle->Initialize(data);
	}
}


