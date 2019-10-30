#pragma once
#include "GameObjectSharer.h"
#include "PlayerUpdateComponent.h"

class PhysicsEnginePlayMode
{
private:
	shared_ptr<PlayerUpdateComponent> m_PUC;

	GameObject* m_Player;
	bool m_InvaderHitWallThisFrame = false;
	bool m_InvaderHitWallPreviousFrame = false;
	bool m_NeedToDropDownAndReverse = false;
	bool m_CompletedDropDownAndReverse = false;


	void detectInvaderCollisions(
		vector<GameObject>& objects,
		const vector<int>& bulletPositions);

	void detectPlayerCollisionsAndInvaderDirection(
		vector<GameObject>& objects,
		const vector<int>& bulletPositions);

	void handleInvaderDirection();

public:
	void initilize(GameObjectSharer& gos);
	void detectCollisions(
		vector<GameObject>& objects,
		const vector<int>& bulletPositions);
};

