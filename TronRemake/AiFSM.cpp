#include "AiFSM.h"

AiFSM* AiFSM::mInstance = nullptr;

AiFSM* AiFSM::Instance()
{
	if (mInstance == nullptr)
	{
		mInstance = new AiFSM();
	}
	return mInstance;
}

void AiFSM::Update()
{
	currentState->StateUpdate();
}

void AiFSM::SetState(AiStateBase* state)
{
	currentState = state;
}

AiFSM::AiFSM()
{

}

AiFSM::~AiFSM()
{

}
