#pragma once
#include "InputHandler.h"

class GameOverInputHandler :
	public InputHandler
{
public:
	void handleKeyPressed(Event& event,
		RenderWindow& window) override;

	void handleLeftClick(std::string&
		buttonInteractedWith, RenderWindow& window) override;
};
