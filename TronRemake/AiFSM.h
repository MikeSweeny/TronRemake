#ifndef __AIFSM_H
#define __AIFSM_H
#include "Types.h"
#include "AiStateDead.h"
#include "AiStateMoving.h"
#include "AiStateTurning.h"

class AiFSM
{

protected:


private:

	AiStateBase* currentState;
	AiStateMoving* movingState;
	AiStateTurning* turnState;
	AiStateDead* deadState;



public:

	AiFSM(GameEntity* bike);
	~AiFSM();
	void Update();
	void SetState(AiStates state);

};

#endif