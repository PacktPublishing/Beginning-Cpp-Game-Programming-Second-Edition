#pragma once
#include "Zombie.h"

using namespace sf;

int createBackground(VertexArray& rVA, IntRect arena);
Zombie* createHorde(int numZombies, IntRect arena);
