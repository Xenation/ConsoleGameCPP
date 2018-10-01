#include "stdafx.h"
#include "Time.h"


Time::Time() {
	timer = new NYTimer();
}

Time::~Time() {
	delete(timer);
}

float Time::getDeltaTime() {
	return Time::getInstance().deltaTime;
}

float Time::time() {
	return Time::getInstance().timer->getElapsedMs();
}
