#ifndef __AIFSM_H
#define __AIFSM_H
#include "Types.h"
#include "AiStateDead.h"
#include "AiStateMoving.h"
#include "AiStateTurning.h"
#include "MainMenu.h"

class AiFSM
{

protected:


private:

	GameEntity* mBike;
	AiStateBase* currentState;
	AiStateMoving* movingState = new AiStateMoving();
	AiStateTurning* turnState = new AiStateTurning();
	AiStateDead* deadState = new AiStateDead();



public:

	AiFSM(GameEntity* bike);
	~AiFSM();
	void Update();
	void SetState(AiStates state);

};

#endif