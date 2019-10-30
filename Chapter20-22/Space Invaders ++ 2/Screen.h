#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "InputHandler.h"
#include "UIPanel.h"
#include "ScreenManagerRemoteControl.h"

class InputHandler;

class Screen {
private:
	vector<shared_ptr<InputHandler>> m_InputHandlers;
	vector<unique_ptr<UIPanel>> m_Panels;

protected:
	void addPanel(unique_ptr<UIPanel> p,
		ScreenManagerRemoteControl* smrc,
		shared_ptr<InputHandler> ih);

public:
	virtual void initialise();
	void virtual update(float fps);
	void virtual draw(RenderWindow& window);
	void handleInput(RenderWindow& window);

	View m_View;
};