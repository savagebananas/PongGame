#include "Ball.h"

Ball::Ball(float startX, float startY) {
	m_Position.x = startX;
	m_Position.y = startY;

	m_Shape.setSize(sf::Vector2f(10, 10));
	m_Shape.setPosition(m_Position);
}

FloatRect Ball::getPosition() {
	return m_Shape.getGlobalBounds();
}

RectangleShape Ball::getShape() {
	return m_Shape;
}

float Ball::getXVelocity() {
	return m_DirectionX;
}

/// <summary>
/// Shoots ball to other x-direction if hit sides
/// </summary>
void Ball::reboundSides() {
	m_DirectionX = -m_DirectionX;
}

/// <summary>
/// Shoots ball to other y-direction if hits bat or top
/// </summary>
void Ball::reboundBatOrTop() {
	m_DirectionY = -m_DirectionY;
	m_Speed = m_Speed * 1.1f;
}

/// <summary>
/// Ball reached the bottom -> reset ball position to top center and shoot it downward
/// </summary>
void Ball::reboundBottom() {
	m_Position.y = 0;
	m_Position.x = 500;
	m_DirectionY = -m_DirectionY;
	m_Speed = 800.0f; // reset speed
}

void Ball::update(Time dt) {
	m_Position.y += m_DirectionY * m_Speed * dt.asSeconds();
	m_Position.x += m_DirectionX * m_Speed * dt.asSeconds();

	// Move the ball
	m_Shape.setPosition(m_Position);
}