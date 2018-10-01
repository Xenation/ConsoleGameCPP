#pragma once

#include "NYTimer.h"

class Time {
public:
	static Time& getInstance() {
		static Time instance;
		return instance;
	}
	static float getDeltaTime();
	static float time();
	float deltaTime = 1.0;
private:
	Time();
	~Time();
	Time(Time const&);	// Don't Implement
	void operator=(Time const&);	// Don't implement
	NYTimer* timer;
};

