#pragma once

#include "bot.hpp"

class cLPBot : public cBot
{
public:

	cLPBot();
	~cLPBot();

	//bot plays a turn
	void mf_play();

	//clacs the points per round ave
	void mf_calcPointsPerRound();
};
