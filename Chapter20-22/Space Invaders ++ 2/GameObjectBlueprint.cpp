#include "GameObjectBlueprint.h"

float GameObjectBlueprint::getWidth() {
	return m_Width;
}

void GameObjectBlueprint::setWidth(float width) {
	m_Width = width;
}

float GameObjectBlueprint::getHeight() {
	return m_Height;
}

void GameObjectBlueprint::setHeight(float height) {
	m_Height = height;
}

float GameObjectBlueprint::getLocationX() {
	return m_LocationX;
}

void GameObjectBlueprint::setLocationX(float locationX) {
	m_LocationX = locationX;
}

float GameObjectBlueprint::getLocationY() {
	return m_LocationY;
}

void GameObjectBlueprint::setLocationY(float locationY) {
	m_LocationY = locationY;
}


void GameObjectBlueprint::setName(string name)
{
	m_Name = "" + name;
}

string GameObjectBlueprint::getName()
{
	return m_Name;
}

vector<string>& GameObjectBlueprint::getComponentList()
{
	return m_ComponentList;
}

void GameObjectBlueprint::addToComponentList(string newComponent)
{
	m_ComponentList.push_back(newComponent);
}

string GameObjectBlueprint::getBitmapName()
{
	return m_BitmapName;
}

void GameObjectBlueprint::setBitmapName(string bitmapName)
{
	m_BitmapName = "" + bitmapName;
}

string GameObjectBlueprint::getEncompassingRectColliderLabel() {
	return m_EncompassingRectColliderLabel;
}

bool GameObjectBlueprint::getEncompassingRectCollider() {
	return m_EncompassingRectCollider;
}

void GameObjectBlueprint::setEncompassingRectCollider(string label) {
	m_EncompassingRectCollider = true;
	m_EncompassingRectColliderLabel = "" + label;
}