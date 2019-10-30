#include "GameUIPanel.h"
#include <sstream>
#include "WorldState.h"

int WorldState::SCORE;
int WorldState::LIVES;

GameUIPanel::GameUIPanel(Vector2i res) :
	UIPanel(res,
		1, // The left
		1, // The top
		res.x / 3, // 1/3 width screen
		res.y / 12,
		50, 255, 255, 255) // a, r, g, b 
{
	m_Text.setFillColor(sf::Color(0, 255, 0, 255));
	m_Text.setString("Score: 0 Lives: 3 Wave: 1");
	m_Font.loadFromFile("fonts/Roboto-Bold.ttf");
	m_Text.setFont(m_Font);
	m_Text.setPosition(Vector2f(15, 15));
	m_Text.setCharacterSize(60);
}

void GameUIPanel::draw(RenderWindow& window)
{
	UIPanel::draw(window);

	std::stringstream ss;
	ss << "Score: " << WorldState::SCORE << "  Lives: "
		<< WorldState::LIVES << " Wave: "
		<< WorldState::WAVE_NUMBER;
	m_Text.setString(ss.str());

	window.draw(m_Text);
}