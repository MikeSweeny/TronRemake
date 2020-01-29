#ifndef __PLAYERBIKE_H
#define __PLAYERBIKE_H
#include "Bike.h"


class PlayerBike : public Bike
{

private:

	InputManager* mInput;
	int mScore;
	bool mBoosted;

	int Score();
		
public:
	PlayerBike();
	~PlayerBike();
	void Update();
	void AddScore(int change);
	void HandleMovement();
};


#endif // !__PLAYERBIKE_H