#pragma once
#ifndef SOUND_ENGINE_H
#define SOUND_ENGINE_H

#include <SFML/Audio.hpp>

using namespace sf;

class SoundEngine
{
private:
	SoundBuffer m_ShootBuffer;
	SoundBuffer m_PlayerExplodeBuffer;
	SoundBuffer m_InvaderExplodeBuffer;
	SoundBuffer m_ClickBuffer;

	Sound m_ShootSound;
	Sound m_PlayerExplodeSound;
	Sound m_InvaderExplodeSound;
	Sound m_UhSound;
	Sound m_OhSound;
	Sound m_ClickSound;

public:
	SoundEngine();

	static void playShoot();
	static void playPlayerExplode();
	static void playInvaderExplode();
	static void playClick();

	static SoundEngine* m_s_Instance;
};

#endif