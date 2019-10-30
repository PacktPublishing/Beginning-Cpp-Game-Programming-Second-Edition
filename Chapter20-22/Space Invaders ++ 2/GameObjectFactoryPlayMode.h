#pragma once
#include "GameObjectBlueprint.h"
#include "GameObject.h"
#include <vector>

class GameObjectFactoryPlayMode {
public:
	void buildGameObject(GameObjectBlueprint& bp,
		std::vector <GameObject>& gameObjects);
};