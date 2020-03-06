#ifndef __AISTATEBASE_H
#define __AISTATEBASE_H

class AiStateBase
{
protected:


public:

	AiStateBase();
	~AiStateBase();
	virtual void StateEnter() = 0;
	virtual void StateExit() = 0;
	virtual void StateUpdate() = 0;




};


#endif