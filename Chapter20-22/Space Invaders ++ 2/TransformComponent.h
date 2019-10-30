#pragma once
#include "Component.h"
#include<SFML/Graphics.hpp>

using namespace sf;

class Component;

class TransformComponent : public Component {
private:
	const string m_Type = "transform";
	Vector2f m_Location;
	float m_Height;
	float m_Width;
	//float m_Facing = 180;

public:
	TransformComponent(
		float width, float height, Vector2f location);

	Vector2f& getLocation();

	Vector2f getSize();

	/****************************************************
	*****************************************************
	From Component interface
	*****************************************************
	*****************************************************/

	string Component::getType()
	{
		return m_Type;
	}

	string Component::getSpecificType()
	{
		// Only one type of Transform so just return m_Type
		return m_Type;
	}

	void Component::disableComponent() {}

	void Component::enableComponent() {}

	bool Component::enabled()
	{
		return false;
	}

	void Component::start(GameObjectSharer* gos, GameObject* self) {}

};