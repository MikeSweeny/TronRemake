#include "AiStateBase.h"

AiStateBase::AiStateBase()
{
}

AiStateBase::AiStateBase(AiFSM* fsm)
{
	mFSM = fsm;
}

AiStateBase::~AiStateBase()
{
}
