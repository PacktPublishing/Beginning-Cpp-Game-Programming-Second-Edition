#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"

using namespace std;

class UIPanel {
private:
	RectangleShape m_UIPanel;
	bool m_Hidden = false;
	vector<shared_ptr<Button>> m_Buttons;

protected:
	float m_ButtonWidth = 0;
	float m_ButtonHeight = 0;
	float m_ButtonPadding = 0;

	Font m_Font;
	Text m_Text;

	void addButton(float x, float y, int width, int height,
		int red, int green, int blue,
		string label);

public:
	View m_View;

	UIPanel(Vector2i res, int x, int y,
		float width, float height,
		int alpha, int red, int green, int blue);

	vector<shared_ptr<Button>> getButtons();
	virtual void draw(RenderWindow& window);
	void show();
	void hide();
};
