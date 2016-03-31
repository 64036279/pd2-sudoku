#include <iostream>
#include <fstream>
using namespace std;


class Sudoku 
{
	int s[9][9],u[9][9],d[9][9];
	public:
    	void giveQuestion();
    	void readIn();
    	void solve();
    	void changeNum(int,int);
    	void changeRow(int,int);
    	void changeCol(int,int);
    	void rotate(int);
    	void flip(int);
    	void transform();
    	bool notCorrect();
    	void onePossible();
    	int countZero();
    	void begin();
    	bool possible[9][9]; 
    	void out();
    	
};
