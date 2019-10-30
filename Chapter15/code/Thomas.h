#pragma once
#include "PlayableCharacter.h"

class Thomas : public PlayableCharacter
{
public:
	// A constructor specific to Thomas
	Thomas::Thomas();

	// The overriden input handler for Thomas
	bool virtual handleInput();

};
