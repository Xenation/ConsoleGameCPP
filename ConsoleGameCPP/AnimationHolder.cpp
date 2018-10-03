#include "stdafx.h"
#include "AnimationHolder.h"
#include "ArtGraphic.h"
#include "Entity.h"

AnimationHolder::AnimationHolder()
{
	// Creating the graphs here
	playerStanding = new const char*[3];
	playerStanding[0] = " o  ";
	playerStanding[1] = "/|\\/";
	playerStanding[2] = "/ \\ ";
	playerStandingGraph = new ArtGraphic(playerStanding, 4, 3);

	playerRunningRight1 = new const char*[3];
	playerRunningRight1[0] = " o  ";
	playerRunningRight1[1] = "/|\\/";
	playerRunningRight1[2] = " >\\ ";
	playerRunningRightGraph1 = new ArtGraphic(playerRunningRight1, 4, 3);

	playerRunningRight2 = new const char*[3];
	playerRunningRight2[0] = " o  ";
	playerRunningRight2[1] = "/|\\/";
	playerRunningRight2[2] = " |\\ ";
	playerRunningRightGraph2 = new ArtGraphic(playerRunningRight2, 4, 3);

	playerRunningRight3 = new const char*[3];
	playerRunningRight3[0] = " o  ";
	playerRunningRight3[1] = "/|\\/";
	playerRunningRight3[2] = " |> ";
	playerRunningRightGraph3 = new ArtGraphic(playerRunningRight3, 4, 3);

	playerRunningRight4 = new const char*[3];
	playerRunningRight4[0] = " o  ";
	playerRunningRight4[1] = "/|\\/";
	playerRunningRight4[2] = "/ \\ ";
	playerRunningRightGraph4 = new ArtGraphic(playerRunningRight4, 4, 3);

	playerRunningLeft1 = new const char*[3];
	playerRunningLeft1[0] = " o  ";
	playerRunningLeft1[1] = "/|\\/";
	playerRunningLeft1[2] = "/<  ";
	playerRunningLeftGraph1 = new ArtGraphic(playerRunningLeft1, 4, 3);

	playerRunningLeft2 = new const char*[3];
	playerRunningLeft2[0] = " o  ";
	playerRunningLeft2[1] = "/|\\/";
	playerRunningLeft2[2] = "/|  ";
	playerRunningLeftGraph2 = new ArtGraphic(playerRunningLeft2, 4, 3);

	playerRunningLeft3 = new const char*[3];
	playerRunningLeft3[0] = " o  ";
	playerRunningLeft3[1] = "/|\\/";
	playerRunningLeft3[2] = "<|  ";
	playerRunningLeftGraph3 = new ArtGraphic(playerRunningLeft3, 4, 3);

	playerRunningLeft4 = new const char*[3];
	playerRunningLeft4[0] = " o  ";
	playerRunningLeft4[1] = "/|\\/";
	playerRunningLeft4[2] = "/ \\ ";
	playerRunningLeftGraph4 = new ArtGraphic(playerRunningLeft4, 4, 3);
}


AnimationHolder::~AnimationHolder()
{
}

Graphic* AnimationHolder::getPlayerStandingGraph() {
	return playerStandingGraph;
}

void AnimationHolder::setStanding(Entity& entity) {
	entity.graphic = playerStandingGraph; // TODO : méthode public setter dans Entity ?
}

void AnimationHolder::setRunningRight1(Entity& entity) {
	entity.graphic = playerRunningRightGraph1; // TODO : méthode public setter dans Entity ?
}

void AnimationHolder::setRunningRight2(Entity& entity) {
	entity.graphic = playerRunningRightGraph2; // TODO : méthode public setter dans Entity ?
}

void AnimationHolder::setRunningRight3(Entity& entity) {
	entity.graphic = playerRunningRightGraph3; // TODO : méthode public setter dans Entity ?
}

void AnimationHolder::setRunningRight4(Entity& entity) {
	entity.graphic = playerRunningRightGraph4; // TODO : méthode public setter dans Entity ?
}


void AnimationHolder::setRunningLeft1(Entity& entity) {
	entity.graphic = playerRunningLeftGraph1; // TODO : méthode public setter dans Entity ?
}

void AnimationHolder::setRunningLeft2(Entity& entity) {
	entity.graphic = playerRunningLeftGraph2; // TODO : méthode public setter dans Entity ?
}

void AnimationHolder::setRunningLeft3(Entity& entity) {
	entity.graphic = playerRunningLeftGraph3; // TODO : méthode public setter dans Entity ?
}

void AnimationHolder::setRunningLeft4(Entity& entity) {
	entity.graphic = playerRunningLeftGraph4; // TODO : méthode public setter dans Entity ?
}