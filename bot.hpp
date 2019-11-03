#pragma once

#include "player.hpp"

//Base class for bots, inherits from player
class cBot : public cPlayer
{

	public:

		//bot plays a turn
		virtual void mf_play();

	protected:

		unsigned short int mv_requestedCombi[2];//what combi the bot wants to activate on the board

		unsigned short int mv_try;//tells how many times the bot already tried to find a suiteable combi on the board
};
