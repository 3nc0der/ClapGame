#pragma once

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <fstream>

static bool randInitialized = false;//tells wether rand was initialized or not

class cHelper
{

	public:
	
		static inline int getRandom(int max, int min = 0)
		{
			//if rand didnt get initialized init it and set the bool to true
			if (!randInitialized)
				srand(static_cast<int>(time(NULL))); randInitialized = true;

			//if min !< max return a fix value
			if (max == min)
				return max;
			else if (min > max)
				return min;

			//else calculate the range and return the random
			int range = (max - min) + 1;

			return (rand() % range + min);
		}

		static inline int MAX(int a, int b)
		{
			return (a > b) ? a : b;
		}

		static inline int MIN(int a, int b)
		{
			return (a < b) ? a : b;
		}

		static void makeChanceTable()
		{
			float table[6][6] = {};

			for (int i = 0; i < 6; i++)
			{
				for (int j = 0; j < 6; j++)
				{
					table[i][j] = 0.0f;
				}
			}

			for (int i = 0; i < 1000; i++)
			{
				int dice1 = getRandom(6, 1);
				int dice2 = getRandom(6, 1);

				table[dice1 - 1][dice2 - 1] += 1.0f;
			}

			for (int i = 0; i < 6; i++)
			{
				for (int j = 0; j < 6; j++)
				{
					table[i][j] /= 1000.0f;
				}
			}
		}

	private:

		
};
