#pragma once

#include "bot.hpp"

class cHPBot : public cBot
{

	public:

		cHPBot();
		~cHPBot();

		//bot plays a turn
		void mf_play();

		//asks the game if this combination is available on the board
		inline unsigned short int* mf_requestCombi();
};
