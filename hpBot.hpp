#pragma once

#include "bot.hpp"

class cHPBot : public cBot
{

	public:

		cHPBot();
		~cHPBot();

		//bot plays a turn
		void mf_play();

		//clacs the points per round ave
		void mf_calcPointsPerRound();
};
