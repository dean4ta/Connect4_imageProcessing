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

int main (){
	unsigned ImageWidth = 1024, ImageHeight = 576;
	unsigned HeightTop = 10;
	unsigned WidthStart = 248;
	unsigned rowStep = 66;
	unsigned colStep = 71;
	image<rgb_pixel> WithWhite(ImageWidth,ImageHeight);
	
//			WithWhite[76][319][0] = 255;
			WithWhite[76][319][1] = 255;
			WithWhite[76][319][2] = 255;
	for (int row = 1; row <=6; ++row){
		vector <int> indyRow;
		for (int col = 1; col <=7; ++col){
			//iteration 1 gives [76][319][0,1,2]
			WithWhite[76][319][0] = 255;
			WithWhite[76][319][1] = 255;
			WithWhite[76][319][2] = 255;
		}
	}
	WithWhite.write("00DidThisWork.png");
	return 0;
}
