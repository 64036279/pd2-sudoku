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
	w= 0;
	for( i=0;i<9;i++) 
	{
		for(j=0;j<9;j++)
		{
			cin>>s[i][j] ;

		}
	}
	for(i=0;i<9;++i)
	{
		for(j=0;j<9;++j)
		{
			if(s[i][j]!=0)
			{
				for(k=0;k<9;++k)
				{
					if((s[i][j]==s[i][k])&&j!=k)
					{
						w=1;
						break;
					}
					if((s[i][j]==s[k][j])&&i!=k)
					{
						w=1;
						break;
					}
	                if(s[i-(i%3)+k][j-(j%3)+k]==s[i][j]&&i!=(i-(i%3)+k)&&j!=j-(j%3)+k)
								break;
				}
			}
		}
	}
}


void Sudoku::changeNum(int a , int b)
{
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			if(s[i][j]==a)
			{
				s[i][j]=b;
			}
			else if(s[i][j]==b)
			{
				s[i][j]=a;
			}
		}
	}
}


	void Sudoku::changeRow(int a , int b)
{
	for( i = 0;i<3;i++)
	{
		for(j=0;j<9;j++ )
		{
			swap(s[i+(a*3)][j],s[i+(b*3)][j]);
		}	
	}
}

void Sudoku::changeCol(int a,int b)
{
	for( j=0;j<3;j++)
	{
		for(i=0;i<9;i++)
		{
			swap(s[i][j+(a*3)],s[i][j+(b*3)]);
		}	
	}
}

void Sudoku::rotate(int n)
{
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
	i=0;j=0;
	for(i=0;i<9;i++)
	{
        for(j=0;j<9;j++)
        {
            s[i][j]=u[i][j];
        }
	}
}

void Sudoku::flip(int n)
{
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
	else
	{
		for(i=0;i<9;i++)
		{
			for(j=8;j>0||j==0;j--)
			{
				u[i][8-j]=s[i][j];
			}
		}
	}
	i=0;j=0;
	for(i=0;i<9;i++)
	{
        for(j=0;j<9;j++)
        {
            s[i][j]=u[i][j];
        }
	}
}

void Sudoku::transform()
{

	srand(time(NULL));
	changeNum(rand()%9+1,rand()%9+1);
	changeRow(rand()%3,rand()%3);
	changeCol(rand()%3,rand()%3);
	rotate(rand()%20);
	flip(rand()%2);
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			cout<<s[i][j]<<"\n";
		}
		cout<<"\n";
	}
}
int Sudoku::get(int a,int b)
{
	int i;
    if( a<9&&b<9)
    {
        if(s[a][b]!=0)
        {
            if((b+1)<9) 
				return get(a,b+1);
            else if((a+1)<9) 
				return get(a+1,0);
            else return 1;
        }
        else
        {

            for( i=0;i<9;i++)
            {
                if( check(a,b,i+1))
                {

                    s[a][b]=i+1;
                    if((b+1)<9)
                    {
                    	
                        if(get(a,b+1))
							return 1;
                        else s[a][b] = 0;
                    }
                    else if((a+1)<9)
                    {
                        if(get(a+1,0))
							return 1;
                        else s[a][b]=0;
                    }
                    else 
						return 1;
                }
            }
        }
        return 0;
    }
    else 
		return 1;
}

int Sudoku::get2(int a,int b)
{
	int i;
    if(a>0&&b>0)
    {
        if(d[a][b]!=0)
        {
            if((b-1)>0) 
				return get2(a,b-1);
            else if((a-1)>0) 
				return get2(a-1,0);
            else 
				return 1;
        }
        else
        {

            for(i=10;i>1;i--)
            {
                if(check2(a,b,i-1))
                {

                    d[a][b]=i-1;
                    if((b-1)>0)
                    {
                    	
                        if( get2(a,b-1)) 
							return 1;
                        else d[a][b]=0;
                    }
                    else if((a+1)>0)
                    {
                        if(get2(a-1,0)) 
							return 1;
                        else d[a][b]=0;
                    }
                    else 
						return 1;
                }
            }
        }
        return 0;
    }
    else return 1;
}

int Sudoku::get3(int a,int b)
{
	int i;
    if(a<9&&b<9)
    {
        if(d[a][b] != 0)
        {
            if((b+1)<9) 
				return get3(a,b+1);
            else if((a+1)<9) 
				return get3(a+1,0);
            else 
				return 1;
        }
        else
        {

            for(i=8;i>=0;i--)
            {
                if(check3(a,b,i+1))
                {

                    d[a][b]=i+1;
                    if((b+1)<9)
                    {
                    	
                        if(get3(a,b+1))
							 return 1;
                        else d[a][b]=0;
                    }
                    else if((a+1)<9)
                    {
                        if(get3( a+1, 0))
							 return 1;
                        else d[a][b]=0;
                    }
                    else 
						return 1;
                }
            }
        }
        return 0;
    }
    else 
		return 1;
}



int Sudoku::check(int a, int b, int c)
{
    int rowStart=(a/3)*3;
    int colStart=(b/3)*3;//初始值設定 
    
    for(j=0;j<9;j++)
    {
        if(s[a][j]==c)
	   		 return 0;
        if(s[j][b]==c)
			 return 0;
        if(s[rowStart+(j%3)][colStart+(j/3)]==c)
		     return 0;
    }
    return 1;
}

int Sudoku::check2(int a,int b,int c)
{
    int rowStart=(a/3)*3;
    int colStart=(b/3)*3;
    
    for( j= 8;j>=0;j--)
    {
        if(d[a][j]==c)
			return 0;
        if(d[j][b]==c)
			return 0;
        if(d[rowStart+(j%3)][colStart+(j/3)]==c)
			return 0;
    }
    return 1;
}
int Sudoku::check3(int a,int b,int c)
{
    int rowStart=(a/3)*3;
    int colStart=(b/3)*3;
    
    for( j=0;j<9;j++)
    {
        if (d[a][j]==c)
			return 0;
        if (d[j][b]==c)
			return 0;
        if (d[rowStart+(j%3)][colStart+(j/3)]==c)
			return 0;
    }
    return 1;
}


void Sudoku::solve()
{
	for(i=0;i<9;++i)
	{
		for(j=0;j<9;++j)
		{
			d[i][j]=s[i][j];
		}
	}
	if(w==1) 
	{
		cout<<"0"<<"\n";
		return;
    }
	x=get(0,0);
	y=get3(0,0); 

	if(x==1)
	{
		z=0;
		for( i=0;i<9;++i)
		{
			for(int u=0;u<9;++u)
			{
				if(s[i][u]!=d[i][u])
					z=1;
			}
		}

		if(z==1) 
			cout<<"2"<<"\n";
		else
		{
			cout<<"1"<<"\n";
			for(i=0;i<9;i++)
			{	
				for(j=0;j<9;j++)
				{
					cout<<s[i][j]<<" ";
				}
				cout<<"\n";
			}
		}
			
	}
	
	else
	{
		cout<<"0"<<"\n";
	}
}



int main()
	{
       
            Sudoku ss;
	ss.readIn();
	ss.solve();
	return 0;

	}	
