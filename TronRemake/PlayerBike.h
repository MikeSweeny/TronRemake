#ifndef __PLAYERBIKE_H
#define __PLAYERBIKE_H
#include "Bike.h"


class PlayerBike : public Bike
{

private:

	typedef Bike base;
	InputManager* mInput;
	int mScore;
	bool mBoosted;

	Vector2 frontOfBike;

	int Score();
	void HandleCollisions();
		
public:
	PlayerBike();
	~PlayerBike();
	void Update();
	void AddScore(int change);
	void HandleMovement() override;
	void PlaceTrail();
	void SetupPlayer() override;
};


#endif // !__PLAYERBIKE_H