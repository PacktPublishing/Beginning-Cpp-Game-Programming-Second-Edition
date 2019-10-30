#include <SFML/Audio.hpp>
#include <assert.h>
#include "SoundEngine.h"

using namespace std;
using namespace sf;

SoundEngine* SoundEngine::m_s_Instance = nullptr;

SoundEngine::SoundEngine()
{
	assert(m_s_Instance == nullptr);
	m_s_Instance = this;

	// Load the sound in to the buffers
	m_ShootBuffer.loadFromFile("sound/shoot.ogg");
	m_PlayerExplodeBuffer.loadFromFile("sound/playerexplode.ogg");
	m_InvaderExplodeBuffer.loadFromFile("sound/invaderexplode.ogg");
	m_ClickBuffer.loadFromFile("sound/click.ogg");

	// Associate the sounds with the buffers
	m_ShootSound.setBuffer(m_ShootBuffer);
	m_PlayerExplodeSound.setBuffer(m_PlayerExplodeBuffer);
	m_InvaderExplodeSound.setBuffer(m_InvaderExplodeBuffer);
	m_ClickSound.setBuffer(m_ClickBuffer);
}

void SoundEngine::playShoot()
{
	m_s_Instance->m_ShootSound.play();
}

void SoundEngine::playPlayerExplode()
{
	m_s_Instance->m_PlayerExplodeSound.play();
}

void SoundEngine::playInvaderExplode()
{
	m_s_Instance->m_InvaderExplodeSound.play();
}

void SoundEngine::playClick()
{
	m_s_Instance->m_ClickSound.play();
}