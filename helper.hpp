#pragma once

#include <stdlib.h>
#include <time.h>
#include <stdio.h>

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

	private:

		
};
