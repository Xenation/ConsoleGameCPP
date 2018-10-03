#include "stdafx.h"
#include "PlayerState.h"
#include "StandingState.h"
#include "RunningLeftState.h"
#include "RunningRightState.h"
#include "JumpingState.h"

StandingState PlayerState::standing;
RunningRightState PlayerState::runningRight;
RunningLeftState PlayerState::runningLeft;
JumpingState PlayerState::jumping;