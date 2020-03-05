#ifndef __AISTATEDECIDING_H
#define __AISTATEDECIDING_H
#include "AiStateBase.h"



class AiStateDeciding : public AiStateBase
{
private:
	typedef AiStateBase base;
public:
	AiStateDeciding(AiFSM* fsm);
	~AiStateDeciding();
	void StateEnter();
	void StateExit();
	void StateUpdate();
};


#endif // !__AISTATEDECIDING_H