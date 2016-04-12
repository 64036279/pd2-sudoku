#include <iostream>
#include <fstream>
using namespace std;


class Sudoku 
{
	int j,i,l,k,w,x,y,z;
	int s[9][9],u[9][9],d[9][9];;
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
        int check(int,int,int);
    	int check2(int,int,int );
    	int check3(int,int,int);
    	int get(int,int);
    	int get2(int,int);
    	int get3(int,int);
    	
    
    	
};
