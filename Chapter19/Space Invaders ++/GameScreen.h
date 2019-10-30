#pragma once
#include "Screen.h"
#include "GameInputHandler.h"
#include "GameOverInputHandler.h"

class GameScreen : public Screen
{
private:
	ScreenManagerRemoteControl* m_ScreenManagerRemoteControl;
	shared_ptr<GameInputHandler> m_GIH;


	Texture m_BackgroundTexture;
	Sprite m_BackgroundSprite;
public:
	static bool m_GameOver;

	GameScreen(ScreenManagerRemoteControl* smrc, Vector2i res);
	void initialise() override;
	void virtual update(float fps);
	void virtual draw(RenderWindow& window);	
};
