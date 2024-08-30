#include "AudioComponent.h"
#include "Framework/Object.h"
#include "Resources/ResourceManager.h"
#include "Audio/AudioClip.h"
#include "Audio/AudioSource.h"
#include "Engine.h"


FACTORY_REGISTER(AudioComponent)

AudioComponent::AudioComponent(const AudioComponent& other)
{
	playOnStart = other.playOnStart;
	loop = other.loop;
	volume = other.volume;
	pitch = other.pitch;
	soundName = other.soundName;

	if (other.m_audioSource)
	{
		m_audioSource = std::make_unique<AudioSource>(*other.m_audioSource.get());
	}

}

void AudioComponent::Initialize()
{
	if (!m_audioSource && !soundName.empty())
	{
		auto audioClip = ResourceManager::Instance().Get<AudioClip>(soundName, owner->scene->engine->GetAudio());
		m_audioSource = std::make_unique<AudioSource>(audioClip);
	}

}

void AudioComponent::Update(float dt)
{
	if (playOnStart == true)
	{
		playOnStart = false;
		Play();
	}
}

void AudioComponent::Play()
{
	if (m_audioSource) m_audioSource->Play(owner->scene->engine->GetAudio(), loop, volume, pitch);
}

void AudioComponent::Play(bool loop, float volume, float pitch)
{
	if (m_audioSource) m_audioSource->Play(owner->scene->engine->GetAudio(), loop, volume, pitch);
}

bool AudioComponent::IsPlaying()
{
	return m_audioSource->isPlaying();
}

void AudioComponent::Stop()
{
	if (m_audioSource) m_audioSource->Stop();
}

void AudioComponent::Pause(bool pause)
{
	if (m_audioSource) m_audioSource->Pause();
}

void AudioComponent::SetVolume(float volume)
{
	this->volume = volume;
	if (m_audioSource->isPlaying()) m_audioSource->SetVolume(volume);
}

void AudioComponent::SetPitch(float pitch)
{
	this->pitch = pitch;
	if (m_audioSource->isPlaying()) m_audioSource->SetPitch(pitch);
}

void AudioComponent::Read(const json_t& value)
{
	READ_DATA(value, playOnStart);
	READ_DATA(value, loop);
	READ_DATA(value, volume);
	READ_DATA(value, pitch);
	READ_DATA(value, soundName);
}

void AudioComponent::Write(json_t& value)
{
	//
}

