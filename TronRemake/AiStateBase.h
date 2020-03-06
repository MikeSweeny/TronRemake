#ifndef __AISTATEBASE_H
#define __AISTATEBASE_H
#include "AiFSM.h"

class AiStateBase
{
protected:

	AiFSM* mFSM;

public:

	AiStateBase();
	AiStateBase();
	~AiStateBase();

	virtual void StateEnter() = 0;
	virtual void StateExit() = 0;
	virtual void StateUpdate() = 0;



};


#endif