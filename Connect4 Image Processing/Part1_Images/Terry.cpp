#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <png.hpp>

using namespace std;
using namespace png;

//part 1
vector<vector<int>> processBoard(string imageName)
{
	image<rgb_pixel> Board(imageName);
	vector<vector<int>> boardLayout;
	//get board width
	unsigned ImageWidth = Board.get_width();
	unsigned ImageHeight = Board.get_height();
	unsigned WidthStart, WidthEnd;
	unsigned HeightTop, HeightBottom;
	
	//left side of board
	for(unsigned ii = 0; ii < ImageWidth; ++ii)
	{
	rgb_pixel pix = Board[ImageHeight/2][ii];
		if (pix.red >= 5 && pix.red <= 60 && pix.green >= 20 && pix.green <= 70 && pix.blue >= 60 && pix.blue <= 110) {
			WidthStart = ii;
			break;
		}
	}
	//cout << "left side" << endl;
	//right side
	for(int ii = ImageWidth-1; ii >= 0; --ii)
	{
	rgb_pixel pix = Board[ImageHeight/2][ii];
		if (pix.red >= 5 && pix.red <= 60 && pix.green >= 20 && pix.green <= 70 && pix.blue >= 60 && pix.blue <= 110) {
			WidthEnd = ii;
			break;
		}
	}
	//cout << "left side" << endl;
	unsigned BoardWidth = WidthEnd-WidthStart;
	
	//get board height values-------------------
	for(unsigned ii = 0; ii < ImageHeight; ++ii)
	{
	rgb_pixel pix = Board[ii][BoardWidth/2+WidthStart];
		if (pix.red >= 5 && pix.red <= 60 && pix.green >= 20 && pix.green <= 70 && pix.blue >= 60 && pix.blue <= 110) {
			HeightTop = ii;
			break;
		}
	}
	//cout << "height 1" <<endl;
	for(int ii = ImageHeight-1; ii >= 1; --ii)
	{
	rgb_pixel pix = Board[ii][BoardWidth/2+WidthStart];
		if (pix.red >= 5 && pix.red <= 60 && pix.green >= 20 && pix.green <= 70 && pix.blue >= 60 && pix.blue <= 110) {
			HeightBottom = ii;
			break;
		}
	}
	//cout << "height 2" <<endl;
	unsigned BoardHeight = HeightBottom-HeightTop;
	
	//unsigned BoardHeight = BoardWidth*0.78;
	
	//cout << "Image width is " << ImageWidth << endl << "Image height is " << ImageHeight << endl;
	//cout << "Width Start is " << WidthStart << endl;
	//cout << "Width End is " << WidthEnd << endl;
	//cout << "Board width is " << BoardWidth << endl;
	//cout << "Top Height is " << HeightTop << endl;
	//cout << "Bottom Height is " << HeightBottom << endl;
	//cout << "Board Height is " << BoardHeight << endl;
	
	//check the grid spots-----------------------
	unsigned colStep = (BoardWidth*.8)/6;
	unsigned rowStep = (BoardHeight*.8)/5;
	
	//cout << "colStep is " << colStep << endl;
	//cout << "rowStep is " << rowStep << endl;
	
	//check row by row for chips
	image<rgb_pixel> pix(imageName);
	for (int row = 1; row <=6; ++row){
		vector <int> indyRow;
		for (int col = 1; col <=7; ++col){
			rgb_pixel pix = Board[HeightTop+row*rowStep-20][WidthStart+col*colStep-20];
			
			//find yellow chip
			if (pix.red >= 150 && pix.red <= 250 && pix.green >= 130 && pix.green <= 210 && pix.blue >= 8 && pix.blue <= 50){
				indyRow.push_back(1);
			}
			//find red chip
			else if (pix.red >= 120 && pix.red <= 210 && pix.green >= 18 && pix.green <= 40 && pix.blue >= 12 && pix.blue <= 50){
				indyRow.push_back(2);
			}
			else{
				indyRow.push_back(0);
			}
			//push back row
			if (indyRow.size() == 7) {
				boardLayout.push_back(indyRow);
			}
		}
	}
	
	for (int row=0; row < 6; ++row){
		for (int col=0; col < 7; ++col){
			cout << boardLayout.at(row).at(col);
		}
		cout << endl;
	}
	return boardLayout;
}

//part 2
void EvaluateBoard(vector<vector<int>> board, int &yellow, int &red)
{
	
	//vector<vector<int>> board = { {0,0,0,0,0,0,0},{0,0,0,0,0,0,0},{0,0,0,0,0,0,0},{0,0,0,2,0,0,0},{0,0,0,2,0,0,0},{0,0,1,1,1,0,0} };
	vector<int> group1;
	vector<int> group2;
	vector<int> group3;
	vector<int> group4;
	
	yellow = 0;
	red = 0;
	
	//rows
	for (int ii = 0; ii < 6; ++ii)
	{
		//cols
		for (int jj = 0; jj < 7; ++jj)
		{
			if (jj < 4)
			{
			group1 = {board.at(ii).at(jj),board.at(ii).at(jj+1),board.at(ii).at(jj+2),board.at(ii).at(jj+3)};
			
				int zeros = count(group1.begin(),group1.end(),0);
				int ones = count(group1.begin(),group1.end(),1);
				int twos = count(group1.begin(),group1.end(),2);
				
				
				if (ones == 4)
				{
					yellow += 1000;
				}
				if (ones == 3 && zeros == 1) {
					yellow += 10;
				}
				if (ones == 2 && zeros == 2) {
					yellow += 1;
				}
				if (twos == 4){
					red += 1000;
				}
				if (twos == 3 && zeros == 1) {
					red += 10;
				}
				if (twos == 2 && zeros == 2) {
					red += 1;
				}
			
			}
			
			if (ii < 3)
			{
			group2 = {board.at(ii).at(jj),board.at(ii+1).at(jj),board.at(ii+2).at(jj),board.at(ii+3).at(jj)};
				
				
				int zeros = count(group2.begin(),group2.end(),0);
				int ones = count(group2.begin(),group2.end(),1);
				int twos = count(group2.begin(),group2.end(),2);
				if (ones == 4)
				{
					yellow += 1000;
				}
				if (ones == 3 && zeros == 1) {
					yellow += 10;
					
				}
				if (ones == 2 && zeros == 2) {
					yellow += 1;
				}
				if (twos == 4){
					red += 1000;
				}
				if (twos == 3 && zeros == 1) {
					red += 10;
				}
				if (twos == 2 && zeros == 2) {
					red += 1;
				}
			
			}
		
			if( ii < 3 && jj< 4)
			{
			group3 = {board.at(ii).at(jj),board.at(ii+1).at(jj+1),board.at(ii+2).at(jj+2),board.at(ii+3).at(jj+3)};
				
				int zeros = count(group3.begin(),group3.end(),0);
				int ones = count(group3.begin(),group3.end(),1);
				int twos = count(group3.begin(),group3.end(),2);
				if (ones == 4)
				{
					yellow += 1000;
				}
				if (ones == 3 && zeros == 1) {
					yellow += 10;
				}
				if (ones == 2 && zeros == 2) {
					yellow += 1;
				}
				if (twos == 4){
					red += 1000;
				}
				if (twos == 3 && zeros == 1) {
					red += 10;
				}
				if (twos == 2 && zeros == 2) {
					red += 1;
				}
			
			}
			
			if (ii > 2 && jj < 4 )
			{
			group4 = {board.at(ii).at(jj),board.at(ii-1).at(jj+1),board.at(ii-2).at(jj+2),board.at(ii-3).at(jj+3)};
			
				int zeros = count(group4.begin(),group4.end(),0);
				int ones = count(group4.begin(),group4.end(),1);
				int twos = count(group4.begin(),group4.end(),2);
				if (ones == 4)
				{
					yellow += 1000;
				}
				if (ones == 3 && zeros == 1) {
					yellow += 10;
				}
			   if (ones == 2 && zeros == 2) {
					yellow += 1;
				}
				if (twos == 4){
					red += 1000;
				}
				if (twos == 3 && zeros == 1) {
					red += 10;
				}
				if (twos == 2 && zeros == 2) {
					red += 1;
					}
			}
		}
	}
	cout << yellow<<endl;
	cout << red<<endl;
}
//part 3
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
		cout << "testing lvl 1 " << ii << endl;
		vector<vector<int>>newboard = board;
		//zz to row
		for ( int zz = 5; zz>=0; --zz)
		{
		 spot = newboard.at(zz).at(ii);
		
			if ( spot == 0)
			{
				cout << "Row " << zz << endl;
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
			cout << "starting lvl 2 " << jj << endl;
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
		cout << "theMin is " << theMin << endl;
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
			cout << "aa is " << aa << endl;
		}
	}
	for (int we = 0; we < 7; ++we){
		cout << level1score.at(we) << " ";
	}
	cout << endl;
	sort(level1score.begin(),level1score.end());
	bestScore = level1score.at(level1score.size()-1);
	cout << "2 Best Score is " << bestScore << endl;
	cout << "2 Best Move is  " << bestMove << endl;
}

int main(){
	cout << "enter name of image" << endl;
	string image;
	getline(cin, image);
	vector<vector<int>> boardLayout = processBoard(image);
	//vector<vector<int>> boardLayout = {{0,0,0,0,0,0,0}, {0,0,0,0,0,0,0}, {0,0,0,0,0,0,0}, {2,0,0,1,0,0,0}, {2,0,0,1,0,0,0}, {2,0,0,1,0,0,0}};
	//vector<vector<int>> boardLayout = {{0,0,0,0,0,0,0}, {0,0,0,0,0,0,0}, {0,0,0,0,0,0,0}, {0,0,0,0,0,0,0}, {2,0,0,1,0,0,0}, {2,2,0,1,1,0,0}};
	int red = 0, yellow = 0;
	EvaluateBoard(boardLayout, yellow, red);
	int bestMove=0, bestScore=0;
	FindBestMove(boardLayout, bestMove, bestScore);
	return 0;
}
