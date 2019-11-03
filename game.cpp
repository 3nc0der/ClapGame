#include "game.hpp"

cGame::cGame():mv_roundsPlayed(0), mv_roundsToPlay(0)
{

}

cGame::~cGame()
{
	//iterate through all players
	std::vector<cPlayer*>::iterator i;

	for (i = mv_playerList.begin(); i != mv_playerList.end(); i++)
	{
		//delete every entry
		mv_playerList.erase(i);
	}

	mv_playerList.clear();
}

void cGame::mf_init(sInitGame init)
{
	mv_roundsToPlay = init.rounds;

	mv_playerList = init.players;
}

void cGame::mf_playRound()
{
	//one more round will be played
	mv_roundsPlayed++;

	//iterate through all players
	std::vector<cPlayer*>::iterator i;
	
	for (i = mv_playerList.begin(); i != mv_playerList.end(); i++)
	{
		//so that every player can play
		(*i)->mf_play();
	}
}

void cGame::mf_run()
{
	//iterate through all rounds
	for (int i = 0; i < mv_roundsToPlay; i++)
	{
		//every round is played
		mf_playRound();
	}

	float lowestPPR = 100.0f;
	const char* name = "unknown";

	//iterate through all players
	std::vector<cPlayer*>::iterator i;

	for (i = mv_playerList.begin(); i != mv_playerList.end(); i++)
	{
		//choose the player with the lowest PPRAverage
		if ((*i)->mf_getPPRAverage() < lowestPPR)
		{
			lowestPPR = (*i)->mf_getPPRAverage();
			name = (*i)->mf_getName();
		}
	}

	std::cout << std::endl << lowestPPR << std::endl;

	std::cout << "the lowest bot (" << name << ") could get " << lowestPPR / 55.0f * 100.0f << " % from the highest score.";

	//reset everything
	mv_roundsPlayed = 0;

	for (i = mv_playerList.begin(); i != mv_playerList.end(); i++)
	{
		//reset every player
		(*i)->mf_resetPlayer();
	}
}

void cGame::mf_addPlayer(cPlayer * player)
{
	//just push the new element in
	mv_playerList.push_back(player);

	return;
}

void cGame::mf_removePlayer(int playerID)
{
	//get an iterator that points to the position of the unlucky player, that will be removed
	std::vector<cPlayer*>::iterator i = mv_playerList.begin();
	i += playerID;

	//delete this entry
	mv_playerList.erase(i);

	return;
}
