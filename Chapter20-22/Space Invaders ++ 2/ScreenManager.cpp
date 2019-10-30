#include "ScreenManager.h"

ScreenManager::ScreenManager(Vector2i res)
{
	m_Screens["Game"] = unique_ptr<GameScreen>(
		new GameScreen(this, res));

	m_Screens["Select"] = unique_ptr<SelectScreen>(
		new SelectScreen(this, res));
}

void ScreenManager::handleInput(RenderWindow& window)
{
	m_Screens[m_CurrentScreen]->handleInput(window);
}

void ScreenManager::update(float fps)
{
	m_Screens[m_CurrentScreen]->update(fps);
}

void ScreenManager::draw(RenderWindow& window)
{
	m_Screens[m_CurrentScreen]->draw(window);
}