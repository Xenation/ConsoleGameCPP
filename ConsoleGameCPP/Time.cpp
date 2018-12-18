#include "stdafx.h"
#include "Time.h"


Time::Time() {
	timer = new NYTimer();
}

Time::~Time() {
	delete(timer);
}

float Time::GetDeltaTime() {
	return Time::GetInstance().deltaTime;
}

void Time::SetDeltaTime(float newTime) {
	Time::GetInstance().deltaTime = newTime;
}

float Time::time() {
	return Time::GetInstance().timer->getElapsedMs();
}
