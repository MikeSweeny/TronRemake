#ifndef __AISTATEDECIDING_H
#define __AISTATEDECIDING_H
#include "AiStateBase.h"



class AiStateTurning : public AiStateBase
{
private:

public:
	AiStateTurning();
	~AiStateTurning();
	void StateEnter();
	void StateExit();
	void StateUpdate();
};


#endif // !__AISTATEDECIDING_H