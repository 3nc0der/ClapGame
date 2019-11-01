#include "hpBot.hpp"

cHPBot::cHPBot()
{
	mv_try = 1;
}

cHPBot::~cHPBot()
{
}

void cHPBot::mf_play()
{
	unsigned short int cube1, cube2, size = 1;

	cube1 = static_cast<unsigned short int>(cHelper::getRandom(6, 1));
	cube2 = static_cast<unsigned short int>(cHelper::getRandom(6, 1));

	

	do
	{
		switch (mv_try)
		{
			case 1:
			{
				mv_requestedCombi[0] = cube1 + cube2;
			}break;
			case 2:
			{
				mv_requestedCombi[0] = cube1;
				mv_requestedCombi[1] = cube2;
				size = 2;
			}break;
			case 3:
			{
				mv_requestedCombi[0] = cHelper::MAX(cube1, cube2) - cHelper::MIN(cube1, cube2);
			}break;
		}

		mv_try++;

	} while ((!(mv_try <= 3) || !(mv_board.mf_checkCombination(mv_requestedCombi, size))));
}

inline unsigned short int * cHPBot::mf_requestCombi()
{
	mv_try++;

	return mv_requestedCombi;
}
