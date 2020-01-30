#ifndef __AIBIKE_H
#define __AIBIKE_H
#include "Bike.h"
#include "Timer.h"
#include <cstdlib>


class AIBike : public Bike
{

private:
	Timer* mTimer;

	float currenttime;

	int path;
	int previouspath;

	typedef Bike base;
	int mAIScore;


	int RandomPath();

	int AIScore();

public:
	AIBike();
	~AIBike();
	void Update();
	void AddScore(int change);

	void HandleMovement() override;
	void PlaceTrail();

	void SetupPlayer() override;

	
};


#endif 