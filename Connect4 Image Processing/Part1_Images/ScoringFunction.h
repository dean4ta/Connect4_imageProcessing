//part 2 function
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;


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
