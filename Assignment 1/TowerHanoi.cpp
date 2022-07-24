//Wei Chen c3355372
//15/05/2022
//Class to represent a game of TowerHanoi, using three stacks
//implementation

#include "TowerHanoi.h"
#include "LStack.h"
#include "Disc.h"

TowerHanoi::TowerHanoi(){				//empty constructor, used during getState()
	rod1 = new LStack<Disc>();
	rod2 = new LStack<Disc>();
	rod3 = new LStack<Disc>();
}

TowerHanoi::TowerHanoi(int numOfDisc){	//constructor given number of discs
	rod1 = new LStack<Disc>();
	rod2 = new LStack<Disc>();
	rod3 = new LStack<Disc>();

	for(int i=numOfDisc; i>0; i--){ 
		Disc d = Disc(vgen(i), dgen(i));
		rod1->push(d);
	}
}

TowerHanoi::~TowerHanoi(){				//destructor, setting rods to NULL should invoke LStack destructor
	rod1 = NULL;
	rod2 = NULL;
	rod3 = NULL;
}

int TowerHanoi::dgen(const int i){		//disc diameter generator
	int d = i*2-1;
	return d;
}
string TowerHanoi::vgen(const int i){	//disc string value generator
	string v="";
	for(int j=0;j<i;j++){
		v+="X";
	}
	for(int j=1;j<i;j++){
		v+="X";
	}
	return v;
}

//pre: two integers representing stacks of the TowerHanoi are given
//post: returns whether there is valid move from the provided stack positions, performs move if yes
bool TowerHanoi::move(int rodFrom, int rodTo) {
	if(rodFrom>=1&&rodTo>=1&&rodFrom<=3&&rodTo<=3&&rodFrom!=rodTo){
		switch(rodFrom){
			case 1:
				if(!rod1->isEmpty()){
					switch(rodTo){
						case 2: if(rod2->isEmpty()||rod1->peek()<rod2->peek()){ //thanks shortcircuit evaluation
							rod2->push(rod1->pop());
							return true;
						} break;
						case 3: if(rod3->isEmpty()||rod1->peek()<rod3->peek()){
							rod3->push(rod1->pop());
							return true;
						} break;
					}
				} break;
			case 2:
				if(!rod2->isEmpty()){
					switch(rodTo){
						case 1: if(rod1->isEmpty()||rod2->peek()<rod1->peek()){
							rod1->push(rod2->pop());
							return true;
						} break;
						case 3: if(rod3->isEmpty()||rod2->peek()<rod3->peek()){
							rod3->push(rod2->pop());
							return true;
						} break;
					}
				} break;
			case 3:
				if(!rod3->isEmpty()){
					switch(rodTo){
						case 1: if(rod1->isEmpty()||rod3->peek()<rod1->peek()){
							rod1->push(rod3->pop());
							return true;
						} break;
						case 2: if(rod2->isEmpty()||rod3->peek()<rod2->peek()){
							rod2->push(rod3->pop());
							return true;
						} break;
					}
				} break;
		}
	}
	return false;	//i could write this better.
}

//post: returns a string representing game state
string TowerHanoi::getState() const{
	//the string variable and temporary stacks
	string state="\n";
	LStack<Disc>* t1 = new LStack<Disc>();
	LStack<Disc>* t2 = new LStack<Disc>();
	LStack<Disc>* t3 = new LStack<Disc>();
	
	//calculate highest of three stacks
	int max = rod1->size();
	if(rod2->size()>max)
		max = rod2->size();
	if(rod3->size()>max)
		max = rod3->size();
	
	//runs "max" times
	while(max>0){
		//if a rod of game is not empty, and is on same level as highest stack, add it onto string. pop onto temp stack after.
		//else add string representing empty position
		if(!rod1->isEmpty()&&rod1->size()==max){
			int gapsize = (11-rod1->peek().get_diam())/2;
			for(int j=0; j<gapsize; j++){
				state+=" ";
			}
			state += rod1->peek().get_value();
			for(int j=0; j<gapsize; j++){
				state+=" ";
			}
			t1->push(rod1->pop());
		}
		else{state += "           ";}

		if(!rod2->isEmpty()&&rod2->size()==max){
			int gapsize = (11-rod2->peek().get_diam())/2;
			for(int j=0; j<gapsize; j++){
				state+=" ";
			}
			state += rod2->peek().get_value();
			for(int j=0; j<gapsize; j++){
				state+=" ";
			}
			t2->push(rod2->pop());
		}
		else{state += "           ";}

		if(!rod3->isEmpty()&&rod3->size()==max){
			int gapsize = (11-rod3->peek().get_diam())/2;
			for(int j=0; j<gapsize; j++){
				state+=" ";
			}
			state += rod3->peek().get_value();
			for(int j=0; j<gapsize; j++){
				state+=" ";
			}
			t3->push(rod3->pop());
		}
		else{state += "           ";}

		state+="\n";
		max--;		//reduce max height
	}

	//now state string is produced, re-load game's stacks
	while(!t1->isEmpty()){
		rod1->push(t1->pop());
	}
	while(!t2->isEmpty()){
		rod2->push(t2->pop());
	}
	while(!t3->isEmpty()){
		rod3->push(t3->pop());
	}

	//finish off game state string
	std::string board(33, '-');
	state+= board;
	state+= "\n     1          2          3     \n";
	return state;
}

//if game is won, return true. else return false
bool TowerHanoi::checkWin() const{
	if(rod1->isEmpty()&&rod2->isEmpty()){
		return true;
	}
	return false;
}

//calls getState to get game state, return it in an ostream
ostream& operator << (ostream& out, const TowerHanoi& h){
	out << h.getState(); 
	return out;
}
