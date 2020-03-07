#include "AiStateMoving.h"

AiStateMoving::AiStateMoving(GameEntity* bike)
{
	mBike = bike;
}

AiStateMoving::~AiStateMoving()
{
}

void AiStateMoving::StateEnter()
{
}

void AiStateMoving::StateExit()
{
}

void AiStateMoving::StateUpdate()
{
	mBike->Move();
}
