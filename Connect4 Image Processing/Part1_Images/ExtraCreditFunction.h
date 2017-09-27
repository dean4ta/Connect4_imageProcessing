// extra credit function
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

image<rgb_pixel> DrawGame(vector<vector<int>> boardLayout){
	
	cout << "begining " << endl;
	image<rgb_pixel> board(500,500);
	for (int x = 0; x < 500; ++x){
		for (int y = 0; y < 500; ++y){
			board[x][y][2] = 255;
		}
	}
	vector<vector<int>> layout = boardLayout;
	int xstep = 55;
	int ystep = 62;
	//checks the row
	for (int row = 0; row < 6; ++row){
		//checks the row
		cout << endl <<"row: " << row << endl;
		for (int col = 0; col < 7; ++col){
			cout << "col: " << col << endl;
			if (layout.at(row).at(col) == 0){
				for ( int x = (row+1)*xstep-20; x <= (row+1)*xstep+20; ++x) {
					for ( int y = (col+1)*ystep-20; y <= (col+1)*ystep+20; ++y) {
						if ( 20 >= sqrt((x-((row+1)*xstep))*(x-((row+1)*xstep))+(y-(col+1)*ystep)*(y-(col+1)*ystep))) {
							board[x][y][2] = 0;
							if (x == (row+1)*xstep && y == (col+1)*ystep){
								cout << "          black " << endl;
							}
						}
					}
				}
			}
			else if (layout.at(row).at(col) == 1){
				for ( int x = (row+1)*xstep-20; x <= (row+1)*xstep+20; ++x) {
					for ( int y = (col+1)*ystep-20; y <= (col+1)*ystep+20; ++y) {
						if ( 20 >= sqrt((x-((row+1)*xstep))*(x-((row+1)*xstep))+(y-(col+1)*ystep)*(y-(col+1)*ystep))) {
							board[x][y][2] = 0;
							board[x][y][1] = 255;
							board[x][y][0] = 255;
							if (x == (row+1)*xstep && y == (col+1)*ystep){
								cout << "          yellow " << endl;
							}
						}
					}
				}
			}
			else if (layout.at(row).at(col) == 2){
				for ( int x = (row+1)*xstep-20; x <= (row+1)*xstep+20; ++x) {
					for ( int y = (col+1)*ystep-20; y <= (col+1)*ystep+20; ++y) {
						if ( 20 >= sqrt((x-((row+1)*xstep))*(x-((row+1)*xstep))+(y-(col+1)*ystep)*(y-(col+1)*ystep))) {
							board[x][y][2] = 0;
							board[x][y][0] = 255;
							if (x == (row+1)*xstep && y == (col+1)*ystep){
								cout << "          red " << endl;
							}
						}
					}
				}
			}
		}
	}
	//board.write("GraphicBoard.png");
	
	return board;
}
