/*
William Crewe
2287626
crewe@chapman.edu
CPSC350-02
Assignment2
*/

#include <fstream>
#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;

int main()
{
  string decision = "";
  string fileName = "";
  string inputLine = "";
  string temp = "";
  string temp1 = "";

  ifstream file;

  bool invalid = true;

  int i = 0; //iterating through variable
  int counter = 0;
  int dimX = 0; //X dimension for file input
  int dimY = 0; //Y dimension for file input
  int x = 0, y = 0; //random grid generating variables

  double percentage = 0.0;
  double random = 0.0;
  /*
    Setting up array using either random configuration or file input
  */
  cout << "Hello User! Welcome to the Game Of Life!" << endl << "If you would like to use a file input to play, enter 'y' if not," << endl << "To play wit a random configuration, enter any character: ";
  cin >> decision;
  if(decision == "y")
  {
    /*
      User input for filename
    */
    while(invalid)
    {
    cout << "Please enter the input file name for the Game Of Life: " << endl;
    cin >> fileName;
    fileName = fileName + ".txt";
    file.open(fileName);
      if(file.fail())
      {
        cout << "Invalid File Name. When entering file name, do not add .txt to the end" << endl;
      } else {
        invalid = false;
      }
    }
    /*
      Takes file inpput and converts to 2d array based on dimensions from file
    */
    while(getline(file, inputLine))
    {
      cout << inputLine << endl;
      if(counter < 1)
      {
        temp = inputLine;
        dimX = stoi(temp);
      } else if (counter < 2 && counter > 0) {
        temp1 = inputLine;
        dimY = stoi(temp1);
      }
      string grid1[dimX][dimY];
      for(i = 0; i < inputLine.length(); i++)
      {
        if(counter >= 2)
        {
          grid1[counter - 2][i] = inputLine[i];
          //cout << inputLine[i] << endl;
        }
      }
        ++counter;
    }
  } else {
    /*
      Generation of random grid based on user inputed dimensions
    */
    cout << "Enter the percent chance a cell will be filled (Ex: Enter .3 for 30%): ";
    cin >> percentage;
    cout << "Enter the X dimension of the grid: ";
    cin >> x;
    cout << "Enter the Y dimension of the grid: ";
    cin >> y;
    string grid1[x][y];
    cout << "Randomly generating grid..." << endl;
    for(int i = 0; i < x; i++)
    {
      for(int j = 0; j < y; j++)
      {
        random = ((double) rand() / (RAND_MAX));
        if(random <= percentage)
        {
          grid1[i][j] = "X";
          cout << grid1[i][j];
        } else {
          grid1[i][j] = "-";
          cout << grid1[i][j];
        }
      }
      cout << "" << endl;
    }
    cout << "Grid generated!" << endl;
  }
  return 0;
}
