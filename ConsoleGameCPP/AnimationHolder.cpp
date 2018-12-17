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

	playerRunningRight[0] = new const wchar_t*[3];
	playerRunningRight[0][0] = L" ☻  ";
	playerRunningRight[0][1] = L"/|\\/";
	playerRunningRight[0][2] = L" >\\ ";
	playerRunningRightGraphs[0] = new ArtGraphic(playerRunningRight[0], 4, 3);

	playerRunningRight[1] = new const wchar_t*[3];
	playerRunningRight[1][0] = L" ☻  ";
	playerRunningRight[1][1] = L"/|\\/";
	playerRunningRight[1][2] = L" |\\ ";
	playerRunningRightGraphs[1] = new ArtGraphic(playerRunningRight[1], 4, 3);

	playerRunningRight[2] = new const wchar_t*[3];
	playerRunningRight[2][0] = L" ☻  ";
	playerRunningRight[2][1] = L"/|\\/";
	playerRunningRight[2][2] = L" |> ";
	playerRunningRightGraphs[2] = new ArtGraphic(playerRunningRight[2], 4, 3);

	playerRunningRight[3] = new const wchar_t*[3];
	playerRunningRight[3][0] = L" ☻  ";
	playerRunningRight[3][1] = L"/|\\/";
	playerRunningRight[3][2] = L"/ \\ ";
	playerRunningRightGraphs[3] = new ArtGraphic(playerRunningRight[3], 4, 3);

	playerRunningLeft[0] = new const wchar_t*[3];
	playerRunningLeft[0][0] = L"  ☻ ";
	playerRunningLeft[0][1] = L"\\/|\\";
	playerRunningLeft[0][2] = L" /< ";
	playerRunningLeftGraphs[0] = new ArtGraphic(playerRunningLeft[0], 4, 3);

	playerRunningLeft[1] = new const wchar_t*[3];
	playerRunningLeft[1][0] = L"  ☻ ";
	playerRunningLeft[1][1] = L"\\/|\\";
	playerRunningLeft[1][2] = L" /| ";
	playerRunningLeftGraphs[1] = new ArtGraphic(playerRunningLeft[1], 4, 3);

	playerRunningLeft[2] = new const wchar_t*[3];
	playerRunningLeft[2][0] = L"  ☻ ";
	playerRunningLeft[2][1] = L"\\/|\\";
	playerRunningLeft[2][2] = L" <| ";
	playerRunningLeftGraphs[2] = new ArtGraphic(playerRunningLeft[2], 4, 3);

	playerRunningLeft[3] = new const wchar_t*[3];
	playerRunningLeft[3][0] = L"  ☻ ";
	playerRunningLeft[3][1] = L"\\/|\\";
	playerRunningLeft[3][2] = L" / \\";
	playerRunningLeftGraphs[3] = new ArtGraphic(playerRunningLeft[3], 4, 3);
}


AnimationHolder::~AnimationHolder()
{
}

Graphic* AnimationHolder::GetPlayerStandingGraph() {
	return playerStandingGraph;
}

void AnimationHolder::SetStanding(Entity& entity) {
	entity.graphic = playerStandingGraph;
}

void AnimationHolder::SetRunningRight(Entity& entity, int stateIndex) {
	if ( stateIndex <= 3 ) {
		entity.graphic = playerRunningRightGraphs[stateIndex];
	}
}

void AnimationHolder::SetRunningLeft(Entity& entity, int stateIndex) {
	if ( stateIndex <= 3 ) {
		entity.graphic = playerRunningLeftGraphs[stateIndex];
	}
}