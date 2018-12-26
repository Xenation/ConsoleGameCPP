#pragma once

#include "NYTimer.h"

/*
===============================================================================
Class used for time keeping
===============================================================================
*/
class Time {
public:
	static Time& GetInstance() {
		static Time instance;
		return instance;
	}
	// Returns the time between the current and last frame
	static float GetDeltaTime();
	static void SetDeltaTime(float newTime);
	// Returns the time since the start of the application
	static float time();
private:
	Time();
	~Time();
	Time(Time const&);	// Don't Implement
	void operator=(Time const&);	// Don't implement
	NYTimer* timer;
	float deltaTime = 1.0;
};

