#include "Bat.h"

// This the constructor and it is called when we create an object
Bat::Bat(float startX, float startY)
{
	m_Position.x = startX;
	m_Position.y = startY;

	m_Shape.setSize(sf::Vector2f(100, 5));
	m_Shape.setPosition(m_Position);
	
}

FloatRect Bat::getPosition()
{
	return m_Shape.getGlobalBounds();
}

RectangleShape Bat::getShape()
{
	return m_Shape;
}

void Bat::moveLeft()
{
	m_MovingLeft = true;

}

void Bat::moveRight()
{
	m_MovingRight = true;
}

void Bat::stopLeft()
{
	m_MovingLeft = false;

}

void Bat::stopRight()
{
	m_MovingRight = false;
}

void Bat::update(Time dt)
{
	if (m_MovingLeft) {
		m_Position.x -= m_Speed * dt.asSeconds();
	}

	if (m_MovingRight) {
		m_Position.x += m_Speed * dt.asSeconds();
	}

	m_Shape.setPosition(m_Position);
}
