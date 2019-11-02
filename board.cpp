#include "board.hpp"

cBoard::cBoard()
{
	//init the pedals with their values
	for (int i = 0; i < 10; i++)
	{
		mv_pedals[i].value = i + 1;
		mv_pedals[i].clapped = false;
	}
}

cBoard::~cBoard()
{
}

bool cBoard::mf_clapPedal(unsigned short int* pedals, unsigned short int size)
{
	if (size == 1)
	{
		//and check by the values wether these pedals are available
		if (!mv_pedals[pedals[0] - 1].clapped)
		{
			mv_pedals[pedals[0] - 1].clapped = true;
			return true;
		}
	}
	else
	{
		//and check by the values wether these pedals are available
		if (!mv_pedals[pedals[0] - 1].clapped)
		{
			if (!mv_pedals[pedals[1] - 1].clapped)
			{
				mv_pedals[pedals[0] - 1].clapped = true;
				mv_pedals[pedals[1] - 1].clapped = true;
				return true;
			}
		}
	}

	return false;
}

void cBoard::mf_resetBoard()
{
	//go thru whole board and reset pedals
	for (int i = 0; i < 10; i++)
	{
		mv_pedals[i].clapped = false;
	}

	return;
}

bool cBoard::mf_checkCombination(unsigned short int* combi, unsigned short int size)
{
	//check if the values are the same
	if (combi[0] == combi[1])
	{
		//if they are and bigger than 4 the players only possible move is to clap 10
		if (combi[0] >= 5)
		{
			combi[0] = 10;
			size = 1;
		}
	}

	//check wether the bot requests one or two values
	if (size == 1)
	{
		//check if the request is in a validated range
		if (combi[0] > 10)
			combi[0] = 10;
		else if (combi[0] == 0)
			combi[0] = 10;

		//now it is, so try to clap the pedal
		if (mf_clapPedal(combi, size))
		{
			return true;
		}

		//else return false
		return false;
	}
	else
	{
		//in case there are more requestet values, the bot wants to clap two pedals at once
		if (mf_clapPedal(combi, size))
		{
			return true;
		}

		//else return false
		return false;
	}

	return false;
}

unsigned int cBoard::mf_getPoints()
{
	unsigned int counter = 0;

	for (int i = 0; i < 10; i++)
	{
		if (!mv_pedals[i].clapped)
		{
			counter += mv_pedals[i].value;
		}
	}

	return counter;
}
