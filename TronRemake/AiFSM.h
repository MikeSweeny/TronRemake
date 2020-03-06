#ifndef __AIFSM_H
#define __AIFSM_H
#include "AiStateBase.h"
#include "AiStateDead.h"
#include "AiStateMoving.h"
#include "AiStateTurning.h"

class AiFSM
{

protected:


private:

	static AiFSM* mInstance;
	AiStateBase* currentState;



public:
	AiFSM();
	~AiFSM();
	AiFSM* Instance();
	void Update();
	void SetState(AiStateBase* state);

};

#endif