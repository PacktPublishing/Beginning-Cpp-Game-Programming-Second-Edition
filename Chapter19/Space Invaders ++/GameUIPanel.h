#pragma once
#include "UIPanel.h"

class GameUIPanel : public UIPanel
{
public:
	GameUIPanel(Vector2i res);
	void draw(RenderWindow& window) override;
};