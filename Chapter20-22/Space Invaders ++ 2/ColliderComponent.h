#pragma once
#include "Component.h"
#include <iostream>

class ColliderComponent : public Component
{
private:
	string m_Type = "collider";
	bool m_Enabled = false;

public:

	/****************************************************
	*****************************************************
	From Component interface
	*****************************************************
	*****************************************************/

	string Component::getType() {
		return m_Type;
	}

	void Component::disableComponent() {
		m_Enabled = false;
	}

	void Component::enableComponent() {
		m_Enabled = true;
	}

	bool Component::enabled() {
		return m_Enabled;
	}

	void Component::start(GameObjectSharer* gos, GameObject* self) {

	}
};

