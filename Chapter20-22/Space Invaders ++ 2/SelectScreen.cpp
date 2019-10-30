#include "SelectScreen.h"
#include "SelectUIPanel.h"
#include "SelectInputHandler.h"

SelectScreen::SelectScreen(
	ScreenManagerRemoteControl* smrc, Vector2i res)
{
	auto suip = make_unique<SelectUIPanel>(res);
	auto sih = make_shared<SelectInputHandler>();
	addPanel(move(suip), smrc, sih);
	m_ScreenManagerRemoteControl = smrc;

	m_BackgroundTexture.loadFromFile("graphics/background.png");

	m_BackgroundSprite.setTexture(m_BackgroundTexture);
	auto textureSize = m_BackgroundSprite.
		getTexture()->getSize();

	m_BackgroundSprite.setScale(float(
		m_View.getSize().x) / textureSize.x,
		float(m_View.getSize().y) / textureSize.y);
}

void SelectScreen::draw(RenderWindow& window)
{
	// Change to this screen's view to draw
	window.setView(m_View);
	window.draw(m_BackgroundSprite);

	// Draw the UIPanel view(s)
	Screen::draw(window);
}