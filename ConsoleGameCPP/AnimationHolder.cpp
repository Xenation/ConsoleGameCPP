#include "stdafx.h"
#include "AnimationHolder.h"
#include "ArtGraphic.h"
#include "Entity.h"

AnimationHolder::AnimationHolder()
{
	// Creating the graphs here
	playerStanding = new const wchar_t*[3];
	playerStanding[0] = L" ☻  ";
	playerStanding[1] = L"/|\\/";
	playerStanding[2] = L"/ \\ ";
	playerStandingGraph = new ArtGraphic(playerStanding, 4, 3);

	playerRunningRight1 = new const wchar_t*[3];
	playerRunningRight1[0] = L" ☻  ";
	playerRunningRight1[1] = L"/|\\/";
	playerRunningRight1[2] = L" >\\ ";
	playerRunningRightGraph1 = new ArtGraphic(playerRunningRight1, 4, 3);

	playerRunningRight2 = new const wchar_t*[3];
	playerRunningRight2[0] = L" ☻  ";
	playerRunningRight2[1] = L"/|\\/";
	playerRunningRight2[2] = L" |\\ ";
	playerRunningRightGraph2 = new ArtGraphic(playerRunningRight2, 4, 3);

	playerRunningRight3 = new const wchar_t*[3];
	playerRunningRight3[0] = L" ☻  ";
	playerRunningRight3[1] = L"/|\\/";
	playerRunningRight3[2] = L" |> ";
	playerRunningRightGraph3 = new ArtGraphic(playerRunningRight3, 4, 3);

	playerRunningRight4 = new const wchar_t*[3];
	playerRunningRight4[0] = L" ☻  ";
	playerRunningRight4[1] = L"/|\\/";
	playerRunningRight4[2] = L"/ \\ ";
	playerRunningRightGraph4 = new ArtGraphic(playerRunningRight4, 4, 3);

	playerRunningLeft1 = new const wchar_t*[3];
	playerRunningLeft1[0] = L"  ☻ ";
	playerRunningLeft1[1] = L"\\/|\\";
	playerRunningLeft1[2] = L" /< ";
	playerRunningLeftGraph1 = new ArtGraphic(playerRunningLeft1, 4, 3);

	playerRunningLeft2 = new const wchar_t*[3];
	playerRunningLeft2[0] = L"  ☻ ";
	playerRunningLeft2[1] = L"\\/|\\";
	playerRunningLeft2[2] = L" /| ";
	playerRunningLeftGraph2 = new ArtGraphic(playerRunningLeft2, 4, 3);

	playerRunningLeft3 = new const wchar_t*[3];
	playerRunningLeft3[0] = L"  ☻ ";
	playerRunningLeft3[1] = L"\\/|\\";
	playerRunningLeft3[2] = L" <| ";
	playerRunningLeftGraph3 = new ArtGraphic(playerRunningLeft3, 4, 3);

	playerRunningLeft4 = new const wchar_t*[3];
	playerRunningLeft4[0] = L"  ☻ ";
	playerRunningLeft4[1] = L"\\/|\\";
	playerRunningLeft4[2] = L" / \\";
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