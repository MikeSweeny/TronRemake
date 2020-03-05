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

AiFSM::AiFSM()
{

}

AiFSM::~AiFSM()
{

}
