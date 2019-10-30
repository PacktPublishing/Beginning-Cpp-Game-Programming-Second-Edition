#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "Component.h"
#include "GraphicsComponent.h"
#include "GameObjectSharer.h"
#include "UpdateComponent.h"

class GameObject {
private:
	vector<shared_ptr<Component>> m_Components;

	string m_Tag;
	bool m_Active = false;
	int m_NumberUpdateComponents = 0;
	bool m_HasUpdateComponent = false;
	int m_FirstUpdateComponentLocation = -1;
	int m_GraphicsComponentLocation = -1;
	bool m_HasGraphicsComponent = false;
	int m_TransformComponentLocation = -1;
	int m_NumberRectColliderComponents = 0;
	int m_FirstRectColliderComponentLocation = -1;
	bool m_HasCollider = false;
	bool m_HasStateComponent = false;
	int m_StateComponentLocation = -1;

public:
	void update(float fps);
	void draw(RenderWindow& window);
	void addComponent(shared_ptr<Component> component);

	void setActive();
	void setInactive();
	bool isActive();
	void setTag(String tag);
	string getTag();

	void start(GameObjectSharer* gos);

	// Slow only use in init and start
	shared_ptr<Component> getComponentByTypeAndSpecificType(
		string type, string specificType);

	FloatRect& getEncompassingRectCollider();
	bool hasCollider();
	bool hasUpdateComponent();
	string getEncompassingRectColliderTag();

	shared_ptr<GraphicsComponent> getGraphicsComponent();
	shared_ptr<TransformComponent> getTransformComponent();
	shared_ptr<UpdateComponent> getFirstUpdateComponent();
};