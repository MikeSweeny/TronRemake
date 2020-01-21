#ifndef __TIMER_H
#define __TIMER_H
#include <SDL.h>

namespace SDLFramework
{
	class Timer
	{

	public:
		static Timer* Instance();
		static void Release();
		void Reset();
		float DeltaTime();
		void TimeScale(float ts);
		float TimeScale();
		void Update();

	private:
		static Timer* sInstance;
		unsigned int mStartTicks;
		unsigned int mElapsedTicks;
		float mDeltaTime;
		float mTimeScale;

		Timer();
		~Timer();

	};
}
#endif