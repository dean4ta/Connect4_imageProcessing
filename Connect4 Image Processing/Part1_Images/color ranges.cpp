//find color ranges
#include <iostream>
#include <png.hpp>

using namespace std;
using namespace png;

int main()
{
	cout << "enter 1 through 5";
	string num;
	getline(cin,num);
	
	image<rgb_pixel> myImage("0"+num+".png");
	unsigned width = myImage.get_width();
	unsigned height = myImage.get_height();
	
	image<gray_pixel_1> binaryBoard(width,height);
	
	//Blue Board
	for (unsigned ii = 0; ii < height; ++ii) {
		for (unsigned jj = 0; jj < width; ++jj) {
			rgb_pixel pix = myImage[ii][jj];
			if (pix.red >= 5 && pix.red <= 60 && pix.green >= 20 && pix.green <= 70 && pix.blue >= 60 && pix.blue <= 110) {
				binaryBoard[ii][jj] = 1;
				//Add here!
			}
		}
	}
	binaryBoard.write("0"+num+"Board.png");
	
	//Yellow Chip
	image<gray_pixel_1> binaryYellow(width,height);
	
	for (unsigned ii = 0; ii < height; ++ii) {
		for (unsigned jj = 0; jj < width; ++jj) {
			rgb_pixel pix = myImage[ii][jj];
			//if (pix.red >= 0 && pix.red <= 255 && pix.green >= 0 && pix.green <= 255 && pix.blue >= 0 && pix.blue <= 255) {
			if (pix.red >= 150 && pix.red <= 250 && pix.green >= 130 && pix.green <= 210 && pix.blue >= 8 && pix.blue <= 50) {
				binaryYellow[ii][jj] = 1;
				//Add here!
			}
		}
	}
	binaryYellow.write("0"+num+"Yellow.png");
	
	//Red Chip
	image<gray_pixel_1> binaryRed(width,height);
	
	for (unsigned ii = 0; ii < height; ++ii) {
		for (unsigned jj = 0; jj < width; ++jj) {
			rgb_pixel pix = myImage[ii][jj];
			if (pix.red >= 120 && pix.red <= 210 && pix.green >= 18 && pix.green <= 40 && pix.blue >= 12 && pix.blue <= 50) {
				binaryRed[ii][jj] = 1;
				//Add here!
			}
		}
	}
	binaryRed.write("0"+num+"Red.png");
	return 0;
}
