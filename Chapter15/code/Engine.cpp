#include "Engine.h"


Engine::Engine()
{
	// Get the screen resolution and create an SFML window and View
	Vector2f resolution;
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;

	m_Window.create(VideoMode(resolution.x, resolution.y),
		"Thomas was late",
		Style::Fullscreen);

	// Initialize the full screen view
	m_MainView.setSize(resolution);
	m_HudView.reset(
		FloatRect(0, 0, resolution.x, resolution.y));

	// Inititialize the split-screen Views
	m_LeftView.setViewport(
		FloatRect(0.001f, 0.001f, 0.498f, 0.998f));

	m_RightView.setViewport(
		FloatRect(0.5f, 0.001f, 0.499f, 0.998f));

	m_BGLeftView.setViewport(
		FloatRect(0.001f, 0.001f, 0.498f, 0.998f));

	m_BGRightView.setViewport(
		FloatRect(0.5f, 0.001f, 0.499f, 0.998f));

	// Can this graphics card use shaders?
	if (!sf::Shader::isAvailable())
	{
		// Time to get a new PC
		m_Window.close();
	}

	m_BackgroundTexture = TextureHolder::GetTexture(
		"graphics/background.png");

	// Associate the sprite with the texture
	m_BackgroundSprite.setTexture(m_BackgroundTexture);

}

void Engine::run()
{
	// Timing 	
	Clock clock;

	while (m_Window.isOpen())
	{
		Time dt = clock.restart();
		// Update the total game time
		m_GameTimeTotal += dt;
		// Make a decimal fraction from the delta time
		float dtAsSeconds = dt.asSeconds();

		input();
		update(dtAsSeconds);
		draw();
	}
}