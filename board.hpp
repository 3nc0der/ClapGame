#pragma once

//describes one pedal with value and status
struct sPedal
{
	unsigned short int value;
	bool clapped;
};

class cBoard
{

	public:

		cBoard();
		~cBoard();

		//activates a pedal, given by its value
		bool mf_clapPedal(unsigned short int * pedals, unsigned short int size);

		//resets the board
		void mf_resetBoard();

		//checks if the board has the combination the player requests available
		bool mf_checkCombination(unsigned short int* combi, unsigned short int size);

	private:

		sPedal mv_pedals[10];//the pedals
};
