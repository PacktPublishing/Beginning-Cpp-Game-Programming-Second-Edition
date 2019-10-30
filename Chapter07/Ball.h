#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Ball
{
private:
	Vector2f m_Position;	
	RectangleShape m_Shape;

	float m_Speed = 1000.0f;
	float m_DirectionX = .2f;
	float m_DirectionY = .2f;

public:
	Ball(float startX, float startY);

	FloatRect getPosition();

	RectangleShape getShape();

	float getXVelocity();

	void reboundSides();

	void reboundBatOrTop();

	void reboundBottom();

	void update(Time dt);

};
