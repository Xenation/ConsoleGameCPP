#pragma once

#include "NYTimer.h"

/*
===============================================================================
Class used for the time functions
===============================================================================
*/
class Time {
public:
	static Time& GetInstance() {
		static Time instance;
		return instance;
	}
	static float GetDeltaTime();
	static void SetDeltaTime(float newTime);
	static float time();
private:
	Time();
	~Time();
	Time(Time const&);	// Don't Implement
	void operator=(Time const&);	// Don't implement
	NYTimer* timer;
	float deltaTime = 1.0;
};

