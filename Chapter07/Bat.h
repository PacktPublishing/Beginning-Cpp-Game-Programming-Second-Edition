#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Bat
{
private:
	Vector2f m_Position;

	// A RectangleShape object
	RectangleShape m_Shape;

	float m_Speed = 1000.0f;

	bool m_MovingRight = false;
	bool m_MovingLeft = false;


public:
	Bat(float startX, float startY);

	FloatRect getPosition();

	RectangleShape getShape();

	void moveLeft();

	void moveRight();

	void Bat::stopLeft();

	void Bat::stopRight();

	void update(Time dt);

};
