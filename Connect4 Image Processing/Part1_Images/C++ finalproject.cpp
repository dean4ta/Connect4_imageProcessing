#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <fstream>
#include <numeric>
#include <png.hpp>

using namespace std;
using namespace png;

//PART 1

vector<vector<int>> processBoard(string imageName)
{
    image<rgb_pixel> Board(imageName);
    vector<vector<int>> boardLayout;
    unsigned width = Board.get_width();
    unsigned height = Board.get_height();
    unsigned top, bottom;
    unsigned leftSide, rightSide;
    
    
    
    for(unsigned ii = 0; ii < width; ++ii)
    {
        rgb_pixel pix = Board[height/2][ii];
        if (pix.red >= 5 && pix.red <= 60 && pix.green >= 20 && pix.green <= 70 && pix.blue >= 60 && pix.blue <= 110) {
            leftSide = ii;
            break;
        }
    }
    
    for(int ii = width-1; ii >= 0; --ii)
    {
        rgb_pixel pix = Board[height/2][ii];
        if (pix.red >= 5 && pix.red <= 60 && pix.green >= 20 && pix.green <= 70 && pix.blue >= 60 && pix.blue <= 110) {
            rightSide = ii;
            break;
        }
    }
   
    unsigned BoardWidth = leftSide-rightSide;
    
    
    for(unsigned ii = 0; ii < height; ++ii)
    {
        rgb_pixel pix = Board[ii][BoardWidth/2+leftSide];
        if (pix.red >= 5 && pix.red <= 60 && pix.green >= 20 && pix.green <= 70 && pix.blue >= 60 && pix.blue <= 110) {
            top = ii;
            break;
        }
    }
   
    for(int ii = height-1; ii >= 1; --ii)
    {
        rgb_pixel pix = Board[ii][BoardWidth/2+leftSide];
        if (pix.red >= 5 && pix.red <= 60 && pix.green >= 20 && pix.green <= 70 && pix.blue >= 60 && pix.blue <= 110) {
            bottom = ii;
            break;
        }
    }
    
    unsigned BoardHeight = bottom-top;
    
   
    unsigned colStep = (BoardWidth*.8)/6;
    unsigned rowStep = (BoardHeight*.8)/5;
    
    
    image<rgb_pixel> pix(imageName);
    for (int row = 1; row <=6; ++row){
        vector <int> singleRow;
        for (int col = 1; col <=7; ++col){
            rgb_pixel pix = Board[top+row*rowStep-19][leftSide+col*colStep-19];
            
            //find yellow
            if (pix.red >= 150 && pix.red <= 250 && pix.green >= 130 && pix.green <= 210 && pix.blue >= 8 && pix.blue <= 50){
                singleRow.push_back(1);
            }
            //find red
            else if (pix.red >= 120 && pix.red <= 210 && pix.green >= 18 && pix.green <= 40 && pix.blue >= 12 && pix.blue <= 50){
                singleRow.push_back(2);
            }
            else{
                singleRow.push_back(0);
            }
            
            if (singleRow.size() == 7) {
                boardLayout.push_back(singleRow);
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




//PART 2

void EvaluateBoard(vector<vector<int>> board, int &yellow, int &red)
{
    
    vector<int> group1;
    vector<int> group2;
    vector<int> group3;
    vector<int> group4;
    
    yellow = 0;
    red = 0;
    
    
    for (int ii = 0; ii < 6; ++ii)
    {
       
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


//PART 3


void FindBestMove(vector<vector<int>> boardLayout, int &bestMove, int &bestScore)
{
    
    vector<int> level1score;
    vector<vector<int>> board = boardLayout;
    vector<int> level2score(7,0);
    int yellowScore = 1;
    int redScore = 1;
    int spot;
    //int winningMove, winningScore;
    
    
    for (int ii = 0; ii< 7; ++ii)
    {
        
        vector<vector<int>>newboard = board;
        
        for ( int zz = 5; zz>=0; --zz)
        {
            spot = newboard.at(zz).at(ii);
            
            if ( spot == 0)
            {
                
                newboard.at(zz).at(ii) = 1;
                break;
            }
        }
        
        EvaluateBoard(newboard, yellowScore, redScore);
        
        if ( yellowScore >= 1000)
        {
            bestMove = ii + 1;
            bestScore = yellowScore - redScore;
            cout << "best Move is " << bestMove << endl << "best Score is " << bestScore << endl;
            cout<< "Game Over!" << endl;
            return;
        }
        
        for ( int jj = 0; jj< 7; ++jj)
        {
            vector<vector<int>>newerboard = newboard;
            
            for ( int xx = 5; xx >= 0; --xx)
            {
                spot = newerboard.at(xx).at(jj);
                
                if ( spot == 0)
                {
                    newerboard.at(xx).at(jj) = 2;
                    break;
                }
            }
            
            EvaluateBoard(newerboard, yellowScore, redScore);
            
            int score = yellowScore - redScore;
            level2score.at(jj) = score;
        }
        sort(level2score.begin(),level2score.end());
        int theMin = level2score.at(0);
        
        level1score.push_back(theMin);
    }
    bestScore = -1000000;
    
     for (int qq = 0; qq < 7; ++qq)
     {
     
     int value  = level1score.at(qq);
     
     if ( value > bestScore)
     {
     //bestScore is max
     bestScore = value;
     //bestMove is here
     bestMove = qq +1 ;
     cout << "Best Score is " << bestScore << endl;
     cout << "Best Move is  " << bestMove << endl;
     }
    
     }
    /*for (unsigned aa=0; aa < level1score.size(); ++aa){
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
     */
}








int main()
{
    cout << "enter name of image" << endl;
    string pic;
    getline(cin, pic);
    vector<vector<int>> boardLayout = processBoard(pic);
    
    int red = 0, yellow = 0;
    EvaluateBoard(boardLayout, yellow, red);
    int bestMove=0, bestScore=0;
    FindBestMove(boardLayout, bestMove, bestScore);
    return 0;
}
