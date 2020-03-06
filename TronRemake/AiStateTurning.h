#ifndef __AISTATEDECIDING_H
#define __AISTATEDECIDING_H
#include "AiStateBase.h"



class AiStateTurning : public AiStateBase
{
private:
	typedef AiStateBase base;
public:
	AiStateTurning(AiFSM* fsm);
	~AiStateTurning();
	void StateEnter();
	void StateExit();
	void StateUpdate();
};


#endif // !__AISTATEDECIDING_H