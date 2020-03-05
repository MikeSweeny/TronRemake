#ifndef __AIFSM_H
#define __AIFSM_H

class AiFSM
{

protected:


private:

	static AiFSM* mInstance;


public:
	AiFSM();
	~AiFSM();
	AiFSM* Instance();

};

#endif