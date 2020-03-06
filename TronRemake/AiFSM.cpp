#include "AiFSM.h"

AiFSM* AiFSM::mInstance = nullptr;

AiFSM* AiFSM::Instance()
{
	if (mInstance == nullptr)
	{
		mInstance = new AiFSM();
	}
	return mInstance;
}

void AiFSM::Update()
{
	currentState->StateUpdate();
}

void AiFSM::SetState(AiStates state)
{
	switch (state)
	{
	case MOVING:
		currentState = movingState;
		break;
	case TURNING:
		currentState = turnState;
		break;
	case DEAD:
		currentState = deadState;
		break;
	default:
		break;
	}
}

AiFSM::AiFSM()
{

}

AiFSM::~AiFSM()
{

}
