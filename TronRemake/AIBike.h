#ifndef __AIBIKE_H
#define __AIBIKE_H
#include "Bike.h"
#include "Timer.h"
#include "AiFSM.h"
#include <cstdlib>
#include <stdlib.h>
#include <time.h>


class AIBike : public Bike
{

private:

	Timer* mTimer;
	float currenttime;


	typedef Bike base;


	float ChangePathInterval();
	int RandomPath();
	bool ValidPath(Direction dir);

public:
	AIBike();
	~AIBike();

	AiFSM* aiBrain;
	float checkDistance = 35;
	bool CollisionAvoidF(Vector2 pos);
	bool CollisionAvoidL(Vector2 pos);
	bool CollisionAvoidR(Vector2 pos);
	void SetTriggerBoxes();
	Vector2 topTriggerBoxPos;
	Vector2 botTriggerBoxPos;
	Vector2 leftTriggerBoxPos;
	Vector2 rightTriggerBoxPos;
	std::vector<Direction> validDirections = { LEFT, RIGHT };
	void IncrementTimer();
	Vector2 checkPos;
	int path;

	void Update();
	void Move() override;
	void Turn() override;
	void SetupPlayer() override;


	void HandleMovement() override;

	
};


#endif 