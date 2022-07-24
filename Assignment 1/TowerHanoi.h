//Wei Chen c3355372
//15/05/2022
//Class to represent a game of TowerHanoi, using three stacks
//header file

#ifndef AMBIVALENT_TOWER
#define AMBIVALENT_TOWER

#include "LStack.h"
#include "Disc.h"

class TowerHanoi{
	
	public:
		//de/constructors
		TowerHanoi();
		TowerHanoi(int numOfDisc);
		~TowerHanoi();

		//mutator
		bool move(int rodFrom, int rodTo);	//checks if input move is legal. if legal, perform move and return true. return false only otherwise

		//accessors
		bool checkWin() const;				//check if game is won.
		string getState() const;			//return a string that is visual representation of the game

		//internal functions
		int dgen(const int i);				//generates diameter during Disc construction
		string vgen(const int i);			//generates string value during Disc construction

	private:
		//TowerHanoi data variables
		LStack<Disc>* rod1;
		LStack<Disc>* rod2;
		LStack<Disc>* rod3;
};
ostream& operator << (ostream& out, const TowerHanoi& h);
//overloaded << operator for returning gamestate, using getState()

#endif