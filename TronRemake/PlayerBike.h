#ifndef __PLAYERBIKE_H
#define __PLAYERBIKE_H
#include "Bike.h"


class PlayerBike : public Bike
{

private:

	typedef Bike base;
	InputManager* mInput;
	int mLives;
	bool mBoosted;

		
public:
	int mScore;

	int Lives();
	int Score();

	PlayerBike();
	~PlayerBike();

	void Update();
	void SetLives(int value);
	void AddScore(int change);
	void SetHighScore(int value);
	void HandleMovement() override;
	void SetupPlayer() override;
};


#endif // !__PLAYERBIKE_H