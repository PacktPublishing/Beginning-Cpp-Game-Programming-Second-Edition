#pragma once

#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;


class LevelManager
{
private:
	Vector2i m_LevelSize;
	Vector2f m_StartPosition;
	float m_TimeModifier = 1;
	float m_BaseTimeLimit = 0;
	int m_CurrentLevel = 0;
	const int NUM_LEVELS = 4;

public:

	const int TILE_SIZE = 50;
	const int VERTS_IN_QUAD = 4;

	float getTimeLimit();

	Vector2f getStartPosition();

	int** nextLevel(VertexArray& rVaLevel);

	Vector2i getLevelSize();

	int getCurrentLevel();

};
