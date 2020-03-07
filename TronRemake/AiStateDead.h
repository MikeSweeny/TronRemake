#ifndef __AISTATEDEAD_H
#define __AISTATEDEAD_H
#include "AiStateBase.h"



class AiStateDead : public AiStateBase
{
private:

public:
	AiStateDead(GameEntity* bike);
	~AiStateDead();
	void StateEnter();
	void StateExit();
	void StateUpdate();
};


#endif // !__AISTATEDEAD_H