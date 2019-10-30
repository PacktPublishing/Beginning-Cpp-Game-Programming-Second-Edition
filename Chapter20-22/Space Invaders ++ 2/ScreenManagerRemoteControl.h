#pragma once
#include <string>
#include <vector>
#include "GameObject.h"
#include "GameObjectSharer.h"

using namespace std;

class ScreenManagerRemoteControl
{
public:
	virtual void SwitchScreens(string screenToSwitchTo) = 0;
	virtual void loadLevelInPlayMode(string screenToLoad) = 0;
	virtual vector<GameObject>& getGameObjects() = 0;
	virtual GameObjectSharer& shareGameObjectSharer() = 0;
};

