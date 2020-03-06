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

	static AiFSM* mInstance;
	AiStateBase* currentState;
	AiStateMoving* movingState = new AiStateMoving();
	AiStateTurning* turnState = new AiStateTurning();
	AiStateDead* deadState = new AiStateDead();


public:

	AiFSM();
	~AiFSM();
	static AiFSM* Instance();
	void Update();
	void SetState(AiStates state);

};

#endif