#pragma once

#include <iostream>
#include "helper.hpp"
#include "board.hpp"

//This class describes one player and gives access to everything the player can do
class cPlayer
{

	public:

		cPlayer();
		~cPlayer();

		//the player will play his turn
		virtual void mf_play();

	protected:

		unsigned short int mv_currentPoints;//holds the points of the player
		unsigned short int mv_roundsPlayed;//holds the amount of rounds the player played
		float mv_averagePointsPerRound;//holds how much points this player gains per round on average
		unsigned short int mv_playerID;//ID of the player for identification
		cBoard mv_board;//this players board
};