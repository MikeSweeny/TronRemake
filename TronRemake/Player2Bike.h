#ifndef __PLAYER2BIKE_H
#define __PLAYER2BIKE_H
#include "PlayerBike.h"

class Player2Bike : public Bike
{
private:

	typedef Bike base;
	InputManager* mInput;
	int mScore;
	bool mBoosted;

	int Score();

public:
	Player2Bike();
	~Player2Bike();
	void Update();
	void AddScore(int change);
	void HandleMovement() override;
	void PlaceTrail();
	void SetupPlayer() override;


};
#endif

