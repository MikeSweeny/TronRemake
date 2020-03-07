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

	int path;
	int previouspath;

	typedef Bike base;


	float ChangePathInterval();
	int RandomPath();
	bool ValidPath(int path);

public:
	AIBike();
	~AIBike();

	AiFSM* aiBrain;
	Vector2 sightF = Vector2(0, 0);
	Vector2 sightL = Vector2(0, 0);
	Vector2 sightR = Vector2(0, 0);
	std::vector<Direction> validDirections = { LEFT, RIGHT };
	void IncrementTimer();
	Vector2 checkPos;

	void Update();
	void Move() override;
	void Turn() override;
	void SetupPlayer() override;


	void HandleMovement() override;

	
};


#endif 