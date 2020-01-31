#ifndef __PLAYER2BIKE_H
#define __PLAYER2BIKE_H
#include "PlayerBike.h"

class Player2Bike : public Bike
{
private:

	typedef Bike base;
	InputManager* mInput;
	int mLives;
	bool mBoosted;


public:
	int Lives();

	Player2Bike();
	~Player2Bike();
	void Update();
	void HandleMovement() override;
	void PlaceTrail();
	void SetupPlayer() override;


};
#endif

