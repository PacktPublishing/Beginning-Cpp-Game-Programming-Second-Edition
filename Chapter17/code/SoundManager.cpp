#include "SoundManager.h"
#include <SFML/Audio.hpp>

using namespace sf;

SoundManager::SoundManager()
{
	// Load the sound in to the buffers
	m_FireBuffer.loadFromFile("sound/fire1.wav");
	m_FallInFireBuffer.loadFromFile("sound/fallinfire.wav");
	m_FallInWaterBuffer.loadFromFile("sound/fallinwater.wav");
	m_JumpBuffer.loadFromFile("sound/jump.wav");
	m_ReachGoalBuffer.loadFromFile("sound/reachgoal.wav");

	// Associate the sounds with the buffers
	m_Fire1Sound.setBuffer(m_FireBuffer);
	m_Fire2Sound.setBuffer(m_FireBuffer);
	m_Fire3Sound.setBuffer(m_FireBuffer);
	m_FallInFireSound.setBuffer(m_FallInFireBuffer);
	m_FallInWaterSound.setBuffer(m_FallInWaterBuffer);
	m_JumpSound.setBuffer(m_JumpBuffer);
	m_ReachGoalSound.setBuffer(m_ReachGoalBuffer);

	// When the player is 50 pixels away sound is full volume
	float minDistance = 150;
	// The sound reduces steadily as the player moves further away
	float attenuation = 15;

	// Set all the attenuation levels
	m_Fire1Sound.setAttenuation(attenuation);
	m_Fire2Sound.setAttenuation(attenuation);
	m_Fire3Sound.setAttenuation(attenuation);

	// Set all the minimum distance levels
	m_Fire1Sound.setMinDistance(minDistance);
	m_Fire2Sound.setMinDistance(minDistance);
	m_Fire3Sound.setMinDistance(minDistance);

	// Loop all the fire sounds
	// when they are played
	m_Fire1Sound.setLoop(true);
	m_Fire2Sound.setLoop(true);
	m_Fire3Sound.setLoop(true);
}

void SoundManager::playFire(Vector2f emitterLocation, Vector2f listenerLocation)
{
	// Where is the listener? Thomas.
	Listener::setPosition(listenerLocation.x, listenerLocation.y, 0.0f);

	switch (m_NextSound)
	{
	case 1:
		// Locate/move the source of the sound
		m_Fire1Sound.setPosition(emitterLocation.x, emitterLocation.y, 0.0f);

		if (m_Fire1Sound.getStatus() == Sound::Status::Stopped)
		{
			// Play the sound, if its not already
			m_Fire1Sound.play();
		}
		break;

	case 2:
		// Do the same as previous for the second sound
		m_Fire2Sound.setPosition(emitterLocation.x, emitterLocation.y, 0.0f);

		if (m_Fire2Sound.getStatus() == Sound::Status::Stopped)
		{
			m_Fire2Sound.play();
		}
		break;

	case 3:
		// Do the same as previous for the third sound
		m_Fire3Sound.setPosition(emitterLocation.x, emitterLocation.y, 0.0f);

		if (m_Fire3Sound.getStatus() == Sound::Status::Stopped)
		{
			m_Fire3Sound.play();
		}
		break;
	}

	// Increment to the next fire sound
	m_NextSound++;

	// Go back to 1 when the third sound has been started
	if (m_NextSound > 3)
	{
		m_NextSound = 1;
	}
}

void SoundManager::playFallInFire()
{
	m_FallInFireSound.setRelativeToListener(true);
	m_FallInFireSound.play();
}

void SoundManager::playFallInWater()
{
	m_FallInWaterSound.setRelativeToListener(true);
	m_FallInWaterSound.play();
}

void SoundManager::playJump()
{
	m_JumpSound.setRelativeToListener(true);
	m_JumpSound.play();
}

void SoundManager::playReachGoal()
{
	m_ReachGoalSound.setRelativeToListener(true);
	m_ReachGoalSound.play();
}
