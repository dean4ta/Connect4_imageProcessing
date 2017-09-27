#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>



using namespace std;

void FindBestMove(vector<vector<int>> boardLayout, int &bestMove, int &bestScore)
{
	//keep code running for now
	vector<vector<int>> board;
	vector<vector<int>>newboard = board;
	vector<double> level2score;
	vector<double>level1score;
	double yellow;
	double red;
	int spot;
	
	for (int ii = 0; ii< 7; ++ii)
	{
		for ( int zz = 5; zz>=0; --zz)
		{
		 spot = newboard.at(zz).at(ii);
		
			if ( spot == 0)
			{
				newboard.at(zz).at(ii) = 1;
				break;
			}
		}
		
		//EvaluateBoard(newboard, yellow, red);
		
		if ( yellow >= 1000)
		{
			cout<< "Game Over!";
			return 0;
		}
	
		for ( int jj = 0; jj< 7; ++jj)
		{
			for ( int kk = 5; kk>=0; --kk)
			{
				spot = newboard.at(kk).at(ii);
				
				if ( spot == 0)
				{
					newboard.at(kk).at(ii) = 1;
					break;
				}
			}
			
			//EvaluateBoard(newboard, yellow, red);
			
			double score = yellow - red;
			level2score.at(jj) = score;
		}
		sort(level2score.begin(),level2score.end());
		double theMin = level2score.at(0);
		level1score.push_back(theMin);
		
		
	}
		
	
	double max = -1000000;
	double here;
	for (int qq = 0; qq < 7; ++qq)
	{
		double value  = level1score.at(qq);
		
		if ( value > max)
		{
			max = value;
			here = qq;
		}
	}
	
	return 0;
}
