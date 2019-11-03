#include "game.hpp"
#include "hpBot.hpp"
#include "lpBot.hpp"

using namespace std;

int main()
{
	cHelper::makeChanceTable();

	std::vector<cPlayer*> players;
	players.push_back(new cLPBot());
	players.push_back(new cHPBot());

	//fill in a init struct for the game
	sInitGame init;
	init.rounds = 10;
	init.players = players;

	//create the game instance
	cGame* game = new cGame();

	game->mf_init(init);

	int buffer = 1;

	do
	{
		game->mf_run();

		std::cout << "continue? 1 = yes / 0 = no" << std::endl;
		std::cin >> buffer;
		std::cout << std::endl;

	} while (buffer != 0);

	return 0;
}