#include "AiFSM.h"

void AiFSM::Update()
{
	currentState->StateUpdate();
}

void AiFSM::SetState(AiStates state)
{
	switch (state)
	{
	case MOVING:
		currentState->StateExit();
		currentState = movingState;
		currentState->StateEnter();
		break;
	case TURNING:
		currentState->StateExit();
		currentState = turnState;
		currentState->StateEnter();
		break;
	case DEAD:
		currentState->StateExit();
		currentState = deadState;
		currentState->StateEnter();
		break;
	default:
		break;
	}
}

AiFSM::AiFSM(GameEntity* bike)
{
	movingState = new AiStateMoving(bike);
	turnState = new AiStateTurning(bike);
	deadState = new AiStateDead(bike);

	currentState = movingState;
}

AiFSM::~AiFSM()
{

}
