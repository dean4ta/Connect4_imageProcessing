#include <png.hpp>
#include <iostream>

using namespace std;
using namespace png;

int main()
{
	int yMin = 9, yMax = 424;
	int xMin = 245, xMax = 786;	
	double width = xMax-xMin;
	double height = yMax-yMin;
	
	double xStep = (width*0.8)/6;
	double yStep = (height*0.8)/5;
	
	image<rgb_pixel> pixels("01.png");
	
	double ySpot = yMin + height*0.1;
	for (int row = 0; row < 6; ++row) {
		double xSpot = xMin + width*0.1;
		for (int col = 0; col < 7; ++col) {
				pixels[ySpot][xSpot][0] = 255;
				pixels[ySpot][xSpot][1] = 255;
				pixels[ySpot][xSpot][2] = 255;
				xSpot += xStep;
		}
		ySpot += yStep;
	}
	
	pixels.write("DidThisWork.png");
	
	return 0;
}
