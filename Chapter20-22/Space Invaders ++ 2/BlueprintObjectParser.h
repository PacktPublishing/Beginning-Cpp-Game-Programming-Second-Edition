#pragma once
#include "GameObjectBlueprint.h"
#include <string>

using namespace std;

class BlueprintObjectParser {
private:
	string extractStringBetweenTags(
		string stringToSearch, string startTag, string endTag);

public:
	void parseNextObjectForBlueprint(
		ifstream& reader, GameObjectBlueprint& bp);
};