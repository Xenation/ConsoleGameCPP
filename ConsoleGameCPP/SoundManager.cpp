#include "stdafx.h"
#include "SoundManager.h"
#include "Windows.h"
#pragma comment( lib, "winmm.lib" )

SoundManager::SoundManager()
{
	mciSendString(L"open music.wav type waveaudio alias music", nullptr, 0, nullptr);
	// Immediatlely play and stop to avoid a stutter during the first play
	StartMusic();
	StopMusic();
}


SoundManager::~SoundManager()
{
}

void SoundManager::StartMusic()
{
	mciSendString(L"play music from 0", nullptr, 0, nullptr);
}
void SoundManager::StopMusic() {
	mciSendString(L"stop music", nullptr, 0, nullptr);
}
