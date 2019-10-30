#include "GameInputHandler.h"
#include "SoundEngine.h"
#include "GameScreen.h"

class BulletSpawner;

void GameInputHandler::initialize() 
{
	m_PUC = static_pointer_cast<PlayerUpdateComponent>
		(getPointerToScreenManagerRemoteControl()
			->shareGameObjectSharer()
			.findFirstObjectWithTag("Player")
			.getComponentByTypeAndSpecificType(
				"update", "player"));

	m_PTC = getPointerToScreenManagerRemoteControl()->
		shareGameObjectSharer().findFirstObjectWithTag(
			"Player").getTransformComponent();
}

void GameInputHandler::handleGamepad()
{
	float deadZone = 10.0f;
	float x = Joystick::getAxisPosition(0, sf::Joystick::X);
	float y = Joystick::getAxisPosition(0, sf::Joystick::Y);

	if (x < deadZone && x > -deadZone)
	{
		x = 0;
	}

	if (y < deadZone && y > -deadZone)
	{
		y = 0;
	}

	m_PUC->updateShipTravelWithController(x, y);

	// Has the player pressed the B button?
	if (Joystick::isButtonPressed(0, 1))
	{
		mBButtonPressed = true;
	}

	// Has player just released the B button?
	if (!Joystick::isButtonPressed(0, 1) && mBButtonPressed)
	{
		mBButtonPressed = false;

		// Shoot a bullet
		SoundEngine::playShoot();
		Vector2f spawnLocation;
		spawnLocation.x = m_PTC->getLocation().x +
			m_PTC->getSize().x / 2;

		spawnLocation.y = m_PTC->getLocation().y;

		static_cast<GameScreen*>(getmParentScreen())->
			getBulletSpawner()->spawnBullet(spawnLocation, true);
	}
}

void GameInputHandler::handleKeyPressed(
	Event& event, RenderWindow& window)
{
	// Handle key presses
	if (event.key.code == Keyboard::Escape)
	{
		SoundEngine::playClick();
		getPointerToScreenManagerRemoteControl()->
			SwitchScreens("Select");
	}	

	if (event.key.code == Keyboard::Left)
	{
		m_PUC->moveLeft();
	}

	if (event.key.code == Keyboard::Right)
	{
		m_PUC->moveRight();
	}

	if (event.key.code == Keyboard::Up)
	{
		m_PUC->moveUp();
	}

	if (event.key.code == Keyboard::Down)
	{
		m_PUC->moveDown();
	}
}

void GameInputHandler::handleKeyReleased(
	Event& event, RenderWindow& window)
{
	if (event.key.code == Keyboard::Left)
	{
		m_PUC->stopLeft();
	}

	else if (event.key.code == Keyboard::Right)
	{
		m_PUC->stopRight();
	}

	else if (event.key.code == Keyboard::Up)
	{
		m_PUC->stopUp();
	}

	else if (event.key.code == Keyboard::Down)
	{
		m_PUC->stopDown();
	}

	else if (event.key.code == Keyboard::Space)
	{
		// Shoot a bullet
		SoundEngine::playShoot();
		Vector2f spawnLocation;
		spawnLocation.x = m_PTC->getLocation().x + 
			m_PTC->getSize().x / 2;

		spawnLocation.y = m_PTC->getLocation().y;

		static_cast<GameScreen*>(getmParentScreen())->
			spawnBullet(spawnLocation, true);
	}
}