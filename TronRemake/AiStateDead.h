#ifndef __AISTATEDEAD_H
#define __AISTATEDEAD_H
#include "AiStateBase.h"



class AiStateDead : public AiStateBase
{
private:
	typedef AiStateBase base;
public:
	AiStateDead(AiFSM* fsm);
	~AiStateDead();
	void StateEnter();
	void StateExit();
	void StateUpdate();
};


#endif // !__AISTATEDEAD_H