#ifndef __AISTATEMOVING_H
#define __AISTATEMOVING_H
#include "AiStateBase.h"


class AiStateMoving : public AiStateBase
{
private:

public:
	AiStateMoving();
	~AiStateMoving();
	void StateEnter();
	void StateExit();
	void StateUpdate();
};


#endif