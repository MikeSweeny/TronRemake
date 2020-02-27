#ifndef __AIBIKE_H
#define __AIBIKE_H
#include "Bike.h"
#include "Timer.h"
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
	void Update();
	void AddScore(int change);

	void HandleMovement() override;

	void SetupPlayer() override;

	
};


#endif 