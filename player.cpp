#include "player.hpp"

cPlayer::cPlayer()
{
}

cPlayer::~cPlayer()
{
}

void cPlayer::mf_play()
{
	int cube1, cube2;

	cube1 = cHelper::getRandom(6, 1);
	cube2 = cHelper::getRandom(6, 1);
}

void cPlayer::mf_resetPlayer()
{
	mv_currentPoints = 0;
	mv_roundsPlayed = 0;
}
