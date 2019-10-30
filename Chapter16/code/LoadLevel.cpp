#include "Engine.h"

void Engine::loadLevel()
{
	m_Playing = false;

	// Delete the previously allocated memory
	for (int i = 0; i < m_LM.getLevelSize().y; ++i)
	{
		delete[] m_ArrayLevel[i];

	}
	delete[] m_ArrayLevel;

	// Load the next 2d array with the map for the level
	// And repopulate the vertex array as well
	m_ArrayLevel = m_LM.nextLevel(m_VALevel);

	// How long is this new time limit
	m_TimeRemaining = m_LM.getTimeLimit();

	// Spawn Thomas and Bob
	m_Thomas.spawn(m_LM.getStartPosition(), GRAVITY);
	m_Bob.spawn(m_LM.getStartPosition(), GRAVITY);

	// Make sure this code isn't run again
	m_NewLevelRequired = false;
}