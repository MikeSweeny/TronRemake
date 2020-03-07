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
	int mAIScore;


	float ChangePathInterval();
	int RandomPath();
	bool ValidPath(int path);

	int GetAIScore();

public:
	AIBike();
	~AIBike();
	AiFSM* aiBrain;

	void Update();
	void AddScore(int change);
	void Move() override;
	void SetupPlayer() override;
	void HandleMovement() override;

	
};


#endif 