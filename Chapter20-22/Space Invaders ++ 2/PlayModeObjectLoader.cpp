#include "PlayModeObjectLoader.h"
#include "ObjectTags.h"
#include <iostream>
#include <fstream>

void PlayModeObjectLoader::
loadGameObjectsForPlayMode(
	string pathToFile, vector<GameObject>& gameObjects)
{
	ifstream reader(pathToFile);
	string lineFromFile;

	float x = 0, y = 0, width = 0, height = 0;
	string value = "";
	while (getline(reader, lineFromFile)) {
		if (lineFromFile.find(
			ObjectTags::START_OF_OBJECT) != string::npos) {

			GameObjectBlueprint bp;
			m_BOP.parseNextObjectForBlueprint(reader, bp);
			m_GameObjectFactoryPlayMode.buildGameObject(
				bp, gameObjects);
		}
	}
}

