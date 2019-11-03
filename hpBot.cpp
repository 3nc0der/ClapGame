#include "hpBot.hpp"

cHPBot::cHPBot()
{
	mv_try = 1;
	mv_currentPoints = 0;
	mv_roundsPlayed = 0;
	mv_perfectRounds = 0;
}

cHPBot::~cHPBot()
{
}

void cHPBot::mf_play()
{
	bool hasPossibleMove = true;

	while (hasPossibleMove)
	{
		unsigned short int cube1, cube2, size = 1;

		cube1 = static_cast<unsigned short int>(cHelper::getRandom(6, 1));
		cube2 = static_cast<unsigned short int>(cHelper::getRandom(6, 1));

		for (mv_try = 1; mv_try <= 3; mv_try++)
		{
			switch (mv_try)
			{
				case 1:
				{
					if (cube1 == cube2)
					{
						mv_requestedCombi[0] = 10;
						size = 1;
					}
					else
					{
						mv_requestedCombi[0] = cube1 + cube2;
						size = 1;
					}
				}break;

				case 2:
				{
					if ((cube1 == cube2) && (cube1 >= 5))
					{
						mv_try = 4;
						hasPossibleMove = false;
					}
					else if ((cube1 == cube2) && (cube1 < 5))
					{
						mv_requestedCombi[0] = cube1 + cube2;
						size = 1;
					}
					else
					{
						mv_requestedCombi[0] = cube1;
						mv_requestedCombi[1] = cube2;
						size = 2;
					}
				}break;

				case 3:
				{
					if (cube1 == cube2)
					{
						mv_try = 4;
						hasPossibleMove = false;
					}
					else
					{
						mv_requestedCombi[0] = cHelper::MAX(cube1, cube2) - cHelper::MIN(cube1, cube2);
						size = 1;
					}
				}break;
			}

			if (mv_board.mf_checkCombination(mv_requestedCombi, size))
			{
				mv_try = 4;
			}
			else if (mv_try == 3 && !mv_board.mf_checkCombination(mv_requestedCombi, size))
			{
				mv_try = 4;
				hasPossibleMove = false;
			}
		}
	}

	if (mv_board.mf_getPoints() == 0)
	{
		mv_perfectRounds++;
	}

	mv_currentPoints += mv_board.mf_getPoints();
	mv_board.mf_resetBoard();

	mv_roundsPlayed++;

	std::cout << "Current Points: " << mv_currentPoints << std::endl;
	mf_calcPointsPerRound();
	std::cout << "PPR Average: " << mv_averagePointsPerRound << std::endl;
	std::cout << "Perfect rounds: " << mv_perfectRounds << std::endl << std::endl;
}

inline unsigned short int * cHPBot::mf_requestCombi()
{
	mv_try++;

	return mv_requestedCombi;
}

void cHPBot::mf_calcPointsPerRound()
{
	mv_averagePointsPerRound = (float)mv_currentPoints / (float)mv_roundsPlayed;
}
