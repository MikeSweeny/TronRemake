#ifndef __AIBIKE_H
#define __AIBIKE_H
#include "Bike.h"
#include <cstdlib>


class AIBike : public Bike
{

private:

	typedef Bike base;
	int mAIScore;

	int RandomPath();

	int AIScore();

public:
	AIBike();
	~AIBike();
	void Update();

	void HandleMovement() override;

	
};


#endif 