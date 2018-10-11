#include "stdafx.h"
#include "SoundManager.h"
#include "Windows.h"

SoundManager::SoundManager()
{
	mciSendString(L"open music.wav type waveaudio alias music", nullptr, 0, nullptr);
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
