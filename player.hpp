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

		//getter
		unsigned short int mf_getCurrentPoints() { return mv_currentPoints; };
		unsigned short int mf_getRoundsPlayed() { return mv_roundsPlayed; };
		unsigned short int mf_getPlayerID() { return mv_playerID; };
		float mf_getPPRAverage() { return mv_averagePointsPerRound; };

		//resets the player for a new round
		void mf_resetPlayer();

	protected:

		unsigned short int mv_currentPoints;//holds the points of the player
		unsigned short int mv_roundsPlayed;//holds the amount of rounds the player played
		float mv_averagePointsPerRound;//holds how much points this player gains per round on average
		unsigned short int mv_playerID;//ID of the player for identification
		cBoard mv_board;//this players board
		unsigned short int mv_perfectRounds;//indicates the amount of rounds in which the player has 0 points added to his account
};