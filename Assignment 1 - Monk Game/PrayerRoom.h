#pragma once

#include "pch.h"

using namespace std;

class PrayerRoom
{
public:
	PrayerRoom();
	~PrayerRoom();
	void HealPlayer();

private:
	int timer;
};