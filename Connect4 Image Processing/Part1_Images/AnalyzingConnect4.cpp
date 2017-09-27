// final analysis

#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <png.hpp>
#include "boardProcessing.h"
//#include "ScoringFunction.h"
#include "BestMove.h"
#include "ExtraCreditFunction.h"

using namespace std;
using namespace png;

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
	//image<rgb_pixel> hello;
	//DrawGame(boardLayout);
	//board.write("GraphicBoard.png");
	
	return 0;
}
