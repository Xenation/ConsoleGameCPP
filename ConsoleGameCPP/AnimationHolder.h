#pragma once
// Forward declarations
class Graphic;
class Entity;

class AnimationHolder
{
public:

public:
	static AnimationHolder& instance() {
		// Singleton implementation with C++11 compiler : initializer for a local static variable is only run once
		static AnimationHolder *instance = new AnimationHolder();
		return *instance;
	}
	void setStanding(Entity& entity);
	void setRunningRight1(Entity& entity);
	void setRunningRight2(Entity& entity);
	void setRunningRight3(Entity& entity);
	void setRunningRight4(Entity& entity);
	void setRunningLeft1(Entity& entity);
	void setRunningLeft2(Entity& entity);
	void setRunningLeft3(Entity& entity);
	void setRunningLeft4(Entity& entity);

	AnimationHolder();
	~AnimationHolder();
private:
	const char** playerStanding;
	const char** playerRunningRight1;
	const char** playerRunningRight2;
	const char** playerRunningRight3;
	const char** playerRunningRight4;
	const char** playerRunningLeft1;
	const char** playerRunningLeft2;
	const char** playerRunningLeft3;
	const char** playerRunningLeft4;

	Graphic* playerStandingGraph;
	Graphic* playerRunningRightGraph1;
	Graphic* playerRunningRightGraph2;
	Graphic* playerRunningRightGraph3;
	Graphic* playerRunningRightGraph4;
	Graphic* playerRunningLeftGraph1;
	Graphic* playerRunningLeftGraph2;
	Graphic* playerRunningLeftGraph3;
	Graphic* playerRunningLeftGraph4;

	// TODO: Utiliser table ou Array plutôt !
};

