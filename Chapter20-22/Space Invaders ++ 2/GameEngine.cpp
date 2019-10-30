#include "GameEngine.h"

GameEngine::GameEngine()
{
	m_Resolution.x = VideoMode::getDesktopMode().width;
	m_Resolution.y = VideoMode::getDesktopMode().height;
	m_Window.create(VideoMode(m_Resolution.x, m_Resolution.y),
		"Space Invaders++", Style::Fullscreen);

	m_ScreenManager = unique_ptr<ScreenManager>(new ScreenManager(
		Vector2i(m_Resolution.x, m_Resolution.y)));
}

void GameEngine::run()
{
	while (m_Window.isOpen())
	{
		m_DT = m_Clock.restart();
		m_FPS = m_DT.asSeconds();
		handleInput();
		update();
		draw();
	}
}

void GameEngine::handleInput()
{
	m_ScreenManager->handleInput(m_Window);
}

void GameEngine::update()
{
	m_ScreenManager->update(m_FPS);
}

void GameEngine::draw()
{
	m_Window.clear(Color::Black);
	m_ScreenManager->draw(m_Window);
	m_Window.display();
}