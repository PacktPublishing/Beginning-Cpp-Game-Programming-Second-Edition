#include "Particle.h"

Particle::Particle(Vector2f direction)
{

	// Determine the direction
	//m_Velocity = direction;
	m_Velocity.x = direction.x;
	m_Velocity.y = direction.y;
}

void Particle::update(float dtAsSeconds)
{
	// Move the particle
	m_Position += m_Velocity * dtAsSeconds;
}

void Particle::setPosition(Vector2f position)
{
	m_Position = position;

}

Vector2f Particle::getPosition()
{
	return m_Position;
}