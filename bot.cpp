#include "bot.hpp"

void cBot::mf_play()
{
	int cube1, cube2;

	cube1 = cHelper::getRandom(6, 1);
	cube2 = cHelper::getRandom(6, 1);

	mv_requestedCombi[0] = cube1;
	mv_requestedCombi[1] = cube2;
}
