#include "Engine.h"
#include <SFML/Graphics.hpp>
#include <sstream>

using namespace sf;

void Engine::update(float dtAsSeconds)
{
	if (m_NewLevelRequired)
	{
		// These calls to spawn will be moved to a new
		// LoadLevel function soon
		// Spawn Thomas and Bob
		//m_Thomas.spawn(Vector2f(0,0), GRAVITY);
		//m_Bob.spawn(Vector2f(100, 0), GRAVITY);

		// Make sure spawn is called only once
		//m_TimeRemaining = 10;
		//m_NewLevelRequired = false;

		// Load a level
		loadLevel();
		
	}

	if (m_Playing)
	{
		// Update Thomas
		m_Thomas.update(dtAsSeconds);

		// Update Bob
		m_Bob.update(dtAsSeconds);

		// Detect collisions and see if characters have reached the goal tile
		// The second part of the if condition is only executed
		// when thomas is touching the home tile
		if (detectCollisions(m_Thomas) && detectCollisions(m_Bob))
		{
			// New level required
			m_NewLevelRequired = true;

			// Play the reach goal sound

		}
		else
		{
			// Run bobs collision detection
			detectCollisions(m_Bob);
		}

		// Let bob and thomas jump on each others heads
		if (m_Bob.getFeet().intersects(m_Thomas.getHead()))
		{
			m_Bob.stopFalling(m_Thomas.getHead().top);
		}
		else if (m_Thomas.getFeet().intersects(m_Bob.getHead()))
		{
			m_Thomas.stopFalling(m_Bob.getHead().top);
		}

		// Count down the time the player has left
		m_TimeRemaining -= dtAsSeconds;

		// Have Thomas and Bob run out of time?
		if (m_TimeRemaining <= 0)
		{
			m_NewLevelRequired = true;
		}

	}// End if playing
		
	// Set the appropriate view around the appropriate character
	if (m_SplitScreen)
	{
		m_LeftView.setCenter(m_Thomas.getCenter());
		m_RightView.setCenter(m_Bob.getCenter());
	}
	else
	{
		// Centre full screen around appropriate character
		if (m_Character1)
		{
			m_MainView.setCenter(m_Thomas.getCenter());
		}
		else
		{
			m_MainView.setCenter(m_Bob.getCenter());
		}
	}
}