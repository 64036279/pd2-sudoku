#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstdio>
#include<ctime>
#include"Sudoku.h"
using namespace std;


void Sudoku::giveQuestion()
{
	int i,j;
	int a[9][9];

	a[0][0]=9;a[1][0]=3;a[2][0]=1;a[3][0]=7;a[4][0]=6;a[5][0]=8;a[6][0]=5;a[7][0]=4;a[8][0]=2;
	a[0][1]=0;a[1][1]=6;a[2][1]=4;a[3][1]=2;a[4][1]=9;a[5][1]=0;a[6][1]=0;a[7][1]=0;a[8][1]=1;
	a[0][2]=0;a[1][2]=7;a[2][2]=0;a[3][2]=0;a[4][2]=1;a[5][2]=4;a[6][2]=0;a[7][2]=0;a[8][2]=0;
	a[0][3]=0;a[1][3]=0;a[2][3]=3;a[3][3]=0;a[4][3]=0;a[5][3]=6;a[6][3]=8;a[7][3]=0;a[8][3]=0;
	a[0][4]=0;a[1][4]=2;a[2][4]=0;a[3][4]=0;a[4][4]=0;a[5][4]=9;a[6][4]=0;a[7][4]=6;a[8][4]=0;
	a[0][5]=6;a[1][5]=0;a[2][5]=9;a[3][5]=4;a[4][5]=0;a[5][5]=0;a[6][5]=1;a[7][5]=0;a[8][5]=0;
	a[0][6]=0;a[1][6]=9;a[2][6]=0;a[3][6]=8;a[4][6]=3;a[5][6]=0;a[6][6]=0;a[7][6]=1;a[8][6]=0;
	a[0][7]=0;a[1][7]=0;a[2][7]=0;a[3][7]=6;a[4][7]=4;a[5][7]=2;a[6][7]=9;a[7][7]=3;a[8][7]=0;
	a[0][8]=3;a[1][8]=4;a[2][8]=6;a[3][8]=9;a[4][8]=0;a[5][8]=1;a[6][8]=2;a[7][8]=0;a[8][8]=0;
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			if(j!=8)
			cout<<a[i][j]<<" ";
			if(j==8)
			cout<<a[i][j]<<"\n";
		}
	}
}

void Sudoku::readIn()
{
	int i,j;
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			cin>>d[i][j];
			s[i][j]=d[i][j];
		}
	}
	for(i=0;i<9;i++)
	{
        for(j=0;j<9;j++)
        {
            u[i][j]=s[i][j];
        }
	}
}

void Sudoku::solve()
{
	int a,pre_hole=0,now_hole=90;
	if(notCorrect())
	{
		cout<<"0";
		return;
	}
	while(pre_hole!=now_hole)
	{
		pre_hole=now_hole;
        onePossible();
        now_hole=countZero();
    }
	a=countZero();
	if(a)
	{
        cout<<"2";
	}
	else
	{
        cout<<"1"<<endl;
        out();
    }
}

void Sudoku::changeNum(int a, int b)
{
	int i,j;
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			if(s[i][j]==a)
			{
				u[i][j]=b;
			}
			else if(s[i][j]==b)
			{
				u[i][j]=a;
			}
		}
	}
}

void Sudoku::changeRow(int a, int b)
{
	if((a==0&&b==1)||(a==1&&b==0))
	{
		u[0][0]=s[3][0];u[1][0]=s[4][0];u[2][0]=s[5][0];
		u[0][1]=s[3][1];u[1][1]=s[4][1];u[2][1]=s[5][1];
		u[0][2]=s[3][2];u[1][2]=s[4][2];u[2][2]=s[5][2];
		u[0][3]=s[3][3];u[1][3]=s[4][3];u[2][3]=s[5][3];
		u[0][4]=s[3][4];u[1][4]=s[4][4];u[2][4]=s[5][4];
		u[0][5]=s[3][5];u[1][5]=s[4][5];u[2][5]=s[5][5];
		u[0][6]=s[3][6];u[1][6]=s[4][6];u[2][6]=s[5][6];
		u[0][7]=s[3][7];u[1][7]=s[4][7];u[2][7]=s[5][7];
		u[0][8]=s[3][8];u[1][8]=s[4][8];u[2][8]=s[5][8];
	}
	if((a==0&&b==2)||(a==2&&b==0))
	{
		u[0][0]=s[6][0];u[1][0]=s[7][0];u[2][0]=s[8][0];
		u[0][1]=s[6][1];u[1][1]=s[7][1];u[2][1]=s[8][1];
		u[0][2]=s[6][2];u[1][2]=s[7][2];u[2][2]=s[8][2];
		u[0][3]=s[6][3];u[1][3]=s[7][3];u[2][3]=s[8][3];
		u[0][4]=s[6][4];u[1][4]=s[7][4];u[2][4]=s[8][4];
		u[0][5]=s[6][5];u[1][5]=s[7][5];u[2][5]=s[8][5];
		u[0][6]=s[6][6];u[1][6]=s[7][6];u[2][6]=s[8][6];
		u[0][7]=s[6][7];u[1][7]=s[7][7];u[2][7]=s[8][7];
		u[0][8]=s[6][8];u[1][8]=s[7][8];u[2][8]=s[8][8];
	}
	if((a==1&&b==2)||(a==2&&b==1))
	{
		u[3][0]=s[6][0];u[4][0]=s[7][0];u[5][0]=s[8][0];
		u[3][1]=s[6][1];u[4][1]=s[7][1];u[5][1]=s[8][1];
		u[3][2]=s[6][2];u[4][2]=s[7][2];u[5][2]=s[8][2];
		u[3][3]=s[6][3];u[4][3]=s[7][3];u[5][3]=s[8][3];
		u[3][4]=s[6][4];u[4][4]=s[7][4];u[5][4]=s[8][4];
		u[3][5]=s[6][5];u[4][5]=s[7][5];u[5][5]=s[8][5];
		u[3][6]=s[6][6];u[4][6]=s[7][6];u[5][6]=s[8][6];
		u[3][7]=s[6][7];u[4][7]=s[7][7];u[5][7]=s[8][7];
		u[3][8]=s[6][8];u[4][8]=s[7][8];u[5][8]=s[8][8];
	}
}

void Sudoku::changeCol(int a,int b)
{
	if((a==0&&b==1)||(a==1&&b==0))
	{
		u[0][0]=s[0][3];u[0][1]=s[0][4];u[0][2]=s[0][5];
		u[1][0]=s[1][3];u[1][1]=s[1][4];u[1][2]=s[1][5];
		u[2][0]=s[2][3];u[2][1]=s[2][4];u[2][2]=s[2][5];
		u[3][0]=s[3][3];u[3][1]=s[3][4];u[3][2]=s[3][5];
		u[4][0]=s[4][3];u[4][1]=s[4][4];u[4][2]=s[4][5];
		u[5][0]=s[5][3];u[5][1]=s[5][4];u[5][2]=s[5][5];
		u[6][0]=s[6][3];u[6][1]=s[6][4];u[6][2]=s[6][5];
		u[7][0]=s[7][3];u[7][1]=s[7][4];u[7][2]=s[7][5];
		u[8][0]=s[8][3];u[8][1]=s[8][4];u[8][2]=s[8][5];
	}
	if((a==0&&b==2)||(a==2&&b==0))
	{
		u[0][0]=s[0][6];u[0][1]=s[0][7];u[0][2]=s[0][8];
		u[1][0]=s[1][6];u[1][1]=s[1][7];u[1][2]=s[1][8];
		u[2][0]=s[2][6];u[2][1]=s[2][7];u[2][2]=s[2][8];
		u[3][0]=s[3][6];u[3][1]=s[3][7];u[3][2]=s[3][8];
		u[4][0]=s[4][6];u[4][1]=s[4][7];u[4][2]=s[4][8];
		u[5][0]=s[5][6];u[5][1]=s[5][7];u[5][2]=s[5][8];
		u[6][0]=s[6][6];u[6][1]=s[6][7];u[6][2]=s[6][8];
		u[7][0]=s[7][6];u[7][1]=s[7][7];u[7][2]=s[7][8];
		u[8][0]=s[8][6];u[8][1]=s[8][7];u[8][2]=s[8][8];
	}
	if((a==1&&a==2)||(a==2&&b==1))
	{
		u[0][3]=s[0][6];u[0][4]=s[0][7];u[0][5]=s[0][8];
		u[1][3]=s[1][6];u[1][4]=s[1][7];u[1][5]=s[1][8];
		u[2][3]=s[2][6];u[2][4]=s[2][7];u[2][5]=s[2][8];
		u[3][3]=s[3][6];u[3][4]=s[3][7];u[3][5]=s[3][8];
		u[4][3]=s[4][6];u[4][4]=s[4][7];u[4][5]=s[4][8];
		u[5][3]=s[5][6];u[5][4]=s[5][7];u[5][5]=s[5][8];
		u[6][3]=s[6][6];u[6][4]=s[6][7];u[6][5]=s[6][8];
		u[7][3]=s[7][6];u[7][4]=s[7][7];u[7][5]=s[7][8];
		u[8][3]=s[8][6];u[8][4]=s[8][7];u[8][5]=s[8][8];
	}
}

void Sudoku::rotate(int n)
{
	int i,j;
	if(n%4==0)
	{
		for(i=0;i<9;i++)
		{
			for(j=0;j<9;j++)
			{
				u[i][j]=s[i][j];
			}
		}
	}
	if(n%4==1)
	{
		for(j=0;j<9;j++)
		{
			for(i=8;i>0||i==0;i--)
			{
				u[j][8-i]=s[i][j];
			}
		}
	}
	if(n%4==2)
	{
		for(i=8;i>0||i==0;i--)
		{
			for(j=8;j>0||j==0;j--)
			{
				u[8-i][8-j]=s[i][j];
			}
		}
	}
	if(n%4==3)
	{
		for(j=8;j>0||j==0;j--)
		{
			for(i=0;i<9;i++)
			{
				u[8-j][i]=s[i][j];
			}
		}
	}
}

void Sudoku::flip(int n)
{
	int i,j;
	if(n==1)
	{
		for(i=0;i<9;i++)
		{
			for(j=8;j>0||j==0;j--)
			{
				u[i][8-j]=s[i][j];
			}
		}
	}
	if(n==0)
	{
		for(i=8;i>0||i==0;i--)
		{
			for(j=0;j<9;j++)
			{
				u[8-i][j]=s[i][j];
			}
		}
	}
}

void Sudoku::transform()
{
	  int i,j;
	  readIn();
	  srand(time(NULL));
	  changeNum(rand()%9+1,rand()%9+1);
//	  changeRow(rand()%3,rand()%3);
//	  changeCol(rand()%3,rand()%3);
	//  rotate(rand()%101);
	//  flip(rand()%2);
	  cout<<"\n";
	  for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			if(j!=8)
			cout<<u[i][j]<<" ";
			if(j==8)
			cout<<u[i][j]<<"\n";
		}
	}
}

bool Sudoku::notCorrect()
	{
		int i,j,k,l,a;
	    for(i=0;i<9;i++)
		{
	        for(j=0;j<9;j++)
			{
	            if(s[i][j])
				{
	                for(k=0;k<9;k++)
	                    if(s[k][j]==s[i][j]&&i!=k)
						 return true;
	                for(l=0;l<9;l++)
	                    if(s[i][l]==s[i][j]&&j!=l)
						 return true;

	                for(k=0;k<3;k++)
	                    for(l=0;l<3;l++)
	                        if(s[i-(i%3)+k][j-(j%3)+l]==s[i][j]&&i!=(i-(i%3)+k)&&j!=j-(j%3)+l)
							 return true;
	            }
	        }
	    }
	    return false;
	}

void Sudoku::onePossible()
{
	int i,j,k,l,m,n,sum=0,a=45,record[9];
	if(!notCorrect());
	{
		for(i=0;i<9;i++)
		{
			for(j=0;j<9;j++)
			{
                for(int i_1=0;i_1<9;i_1++)
                {
                    record[i_1]=1;
                }

                for(k=0;k<9;k++)
                {
                    if(s[k][j])
                    record[s[k][j]-1]=0;
                }
                for(l=0;l<9;l++)
                {
                    if(s[i][l])
                    record[s[i][l]-1]=0;
                }
                for(m=0;m<3;m++)
                {
                    for(n=0;n<3;n++)
                    {
                        if(s[i-(i%3)+n][j-(j%3)+m])
                        {
                            record[s[i-(i%3)+n][j-(j%3)+m]-1]=0;
                        }
                    }
                }
                sum = 0 ;
                for(int i_1=0;i_1<9;i_1++)
                {
                    if(record[i_1]==1)
                    {
                        sum++;
                        a=i_1+1;
                    }
                }
                if(s[i][j]==0&&sum == 1)
                {
                    s[i][j]=a;
                }


			}
        }
    }
}

int Sudoku::countZero()
{
    int hole=0 ;
    for(int i=0;i<9;i++)
        for( int j=0;j<9;j++)
            if(!s[i][j])hole++ ;
    return hole ;
}

void Sudoku::out()
{
	int i,j;
	  for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			if(j!=8)
			cout<<s[i][j]<<" ";
			if(j==8)
			cout<<s[i][j]<<"\n";
		}
	}
}

int main()
	{
       
            Sudoku a;
            a.readIn();
            a.solve();
        return 0;


	}
