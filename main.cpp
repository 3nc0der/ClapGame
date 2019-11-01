#include "game.hpp"
#include "hpBot.hpp"

using namespace std;

int main()
{


	std::vector<cPlayer*> players;
	players.push_back(new cHPBot());

	//fill in a init struct for the game
	sInitGame init;
	init.rounds = 10;
	init.players = players;

	//create the game instance
	cGame* game = new cGame();

	game->mf_init(init);

	game->mf_run();

	return 0;
}