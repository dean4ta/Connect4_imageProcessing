#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include "ScoringFunction.h"


using namespace std;

void FindBestMove(vector<vector<int>> boardLayout, int &bestMove, int &bestScore)
{
	cout << "starting BM" << endl;
	//keep code running for now
	vector<int> level1score;
	vector<vector<int>> board = boardLayout;
	vector<int> level2score(7,0);
	int yellowScore = 1;
	int redScore = 1;
	int spot;
	int winningMove, winningScore;
	
	//level 1 counts cols
	//change to col
	for (int ii = 0; ii< 7; ++ii)
	{
		//cout << "testing lvl 1 " << ii << endl;
		vector<vector<int>>newboard = board;
		//zz to row
		for ( int zz = 5; zz>=0; --zz)
		{
		 spot = newboard.at(zz).at(ii);
		
			if ( spot == 0)
			{
				//cout << "Row " << zz << endl;
				newboard.at(zz).at(ii) = 1;
				break;
			}
		}
		
		EvaluateBoard(newboard, yellowScore, redScore);
		
			if ( yellowScore >= 1000)
			{
				winningMove = ii + 1;
				winningScore = yellowScore - redScore;
				cout << "best Move is " << winningMove << endl << "best Score is " << winningScore << endl;
				cout<< "Game Over!" << endl;
				return;
			}
		//}
		// lvl 2 checks for red
		for ( int jj = 0; jj< 7; ++jj)
		{
			vector<vector<int>>newerboard = newboard;
			//cout << "starting lvl 2 " << jj << endl;
			for ( int kk = 5; kk >= 0; --kk)
			{
				spot = newerboard.at(kk).at(jj);
				
				if ( spot == 0)
				{
					newerboard.at(kk).at(jj) = 2;
					break;
				}
			}
			
			EvaluateBoard(newerboard, yellowScore, redScore);
			
			int score = yellowScore - redScore;
			level2score.at(jj) = score;
		}
		sort(level2score.begin(),level2score.end());
		int theMin = level2score.at(0);
		//cout << "theMin is " << theMin << endl;
		level1score.push_back(theMin);
	}
	int ups = -1000000;
	/*
	for (int qq = 0; qq < 7; ++qq)
	{
		//cout << "starting lvl 2 " << qq << endl;
		value  = level1score.at(qq);
		
		if ( value > bestScore)
		{
			//bestScore is max
			bestScore = value;
			//bestMove is here
			bestMove = qq +1 ;
			cout << "Best Score is " << bestScore << endl;
			cout << "Best Move is  " << bestMove << endl;
		}
		//bestMove = qq +1 ;
	}*/
	for (unsigned aa=0; aa < level1score.size(); ++aa){
		if (level1score.at(aa) > ups){
			ups = level1score.at(aa);
			bestMove = aa+1;
			//cout << "aa is " << aa << endl;
		}
	}
	for (int we = 0; we < 7; ++we){
		//cout << level1score.at(we) << " ";
	}
	cout << endl;
	sort(level1score.begin(),level1score.end());
	bestScore = level1score.at(level1score.size()-1);
	cout << "Best Score is " << bestScore << endl;
	cout << "Best Move is  " << bestMove << endl;
}
