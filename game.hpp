#pragma once

#include <iostream>
#include <vector>
#include <list>

#include "player.hpp"

struct sInitGame
{
	int rounds;//how many rounds you want to play
	std::vector<cPlayer*> players;//all the contributing players
};

//this class holds the game with its principles and rules
//and everything you need to play the game
class cGame
{

	public:

		cGame();
		~cGame();

		//initializes the game
		void mf_init(sInitGame init);

		//the class does its magic and plays a round
		void mf_playRound();

		//the game plays all rounds
		void mf_run();

		//adds a player to the game
		void mf_addPlayer(cPlayer * player);
		void mf_removePlayer(int playerID);//removes a player from the game

	private:

		std::vector<cPlayer*> mv_playerList;//list of all active players
		int mv_roundsPlayed;//how many rounds were played
		int mv_roundsToPlay;//how many rounds are left
};