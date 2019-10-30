#pragma once
#include <SFML/Graphics.hpp>
#include "TextureHolder.h"

using namespace sf;

class Engine
{
private:
	// The texture holder
	TextureHolder th;

	const int TILE_SIZE = 50;
	const int VERTS_IN_QUAD = 4;

	// The force pushing the characters down
	const int GRAVITY = 300;

	// A regular RenderWindow
	RenderWindow m_Window;

	// The main Views
	View m_MainView;
	View m_LeftView;
	View m_RightView;

	// Three views for the background
	View m_BGMainView;
	View m_BGLeftView;
	View m_BGRightView;

	View m_HudView;

	// Declare a sprite and a Texture for the background
	Sprite m_BackgroundSprite;
	Texture m_BackgroundTexture;

	// Is the game currently playing?
	bool m_Playing = false;

	// Is character 1 or 2 the current focus?
	bool m_Character1 = true;

	// Start in full screen mode
	bool m_SplitScreen = false;

	// How much time is left in the current level
	float m_TimeRemaining;
	Time m_GameTimeTotal;

	// Is it time for a new/first level?
	bool m_NewLevelRequired = true;
	
	// Private functions for internal use only
	void input();
	void update(float dtAsSeconds);
	void draw();
	
public:
	// The Engine constructor
	Engine();

	// Run will call all the private functions
	void run();

};
