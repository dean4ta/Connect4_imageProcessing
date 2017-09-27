//not the function 

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

int main(){
	cout << "enter name of image" << endl;
	string imageName;
	getline(cin, imageName);
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
	cout << "left side" << endl;
	//right side
	for(int ii = ImageWidth-1; ii >= 0; --ii)
	{
	rgb_pixel pix = Board[ImageHeight/2][ii];
		if (pix.red >= 5 && pix.red <= 60 && pix.green >= 20 && pix.green <= 70 && pix.blue >= 60 && pix.blue <= 110) {
			WidthEnd = ii;
			break;
		}
	}
	cout << "left side" << endl;
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
	cout << "height 1" <<endl;
	for(int ii = ImageHeight-1; ii >= 1; --ii)
	{
	rgb_pixel pix = Board[ii][BoardWidth/2+WidthStart];
		if (pix.red >= 5 && pix.red <= 60 && pix.green >= 20 && pix.green <= 70 && pix.blue >= 60 && pix.blue <= 110) {
			HeightBottom = ii;
			break;
		}
	}
	cout << "height 2" <<endl;
	unsigned BoardHeight = HeightBottom-HeightTop;
	
	//unsigned BoardHeight = BoardWidth*0.78;
	
	cout << "Image width is " << ImageWidth << endl << "Image height is " << ImageHeight << endl;
	cout << "Width Start is " << WidthStart << endl;
	cout << "Width End is " << WidthEnd << endl;
	cout << "Board width is " << BoardWidth << endl;
	cout << "Top Height is " << HeightTop << endl;
	cout << "Bottom Height is " << HeightBottom << endl;
	cout << "Board Height is " << BoardHeight << endl;
	
	//check the grid spots-----------------------
	unsigned colStep = (BoardWidth*.8)/6;
	unsigned rowStep = (BoardHeight*.8)/5;
	
	cout << "colStep is " << colStep << endl;
	cout << "rowStep is " << rowStep << endl;
	
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
	return 0;
}
