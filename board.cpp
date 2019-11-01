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
	//run through the given values
	for (int i = 0; i < size; i++)
	{
		//and check by the values wether these pedals are available
		if (!mv_pedals[pedals[i]-1].clapped)
		{
			mv_pedals[pedals[i] - 1].clapped = true;
			return true;
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
