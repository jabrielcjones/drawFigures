// file name -- drawFigure.cpp
// Jabriel C. Jones
// Draw figures based on data read in from a file.

// ============================== header files ===================================
#include <iostream>                 // for console I/O
#include <sketch.h>                 // for sketch library
#include <cctype>
#include <fstream>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;


// ============================== named constants =============================
   const int MAX_POINTS = 100;
   const int MAX_FIGURES = 100;
   const int  WINDOW_WIDTH = 640;
   const int  WINDOW_HEIGHT = 480;
   const int NAMESIZE = 100;
// ============================== structures ================================

struct Figure
{
   int num_points;
   int x[MAX_POINTS];
   int y[MAX_POINTS];
   char color;
};

// ================================= type definitons ====================================

   typedef Figure FigureType[MAX_FIGURES];

// ============================== function prototypes ==============================

void openFile(ifstream&);
void readFile(ifstream&, FigureType&, int&);
void drawFigures(FigureType&, int&);

int main()
{

   ifstream inFile;
   FigureType figure;
   int num_figures;

   openFile(inFile);
   readFile(inFile, figure, num_figures);
   drawFigures(figure, num_figures);

   startDrawing();
   return 0;
} //function main

void openFile(ifstream& inFile)
/**
   Purpose: Reads in the name of the file and opens it if its valid

   Precondition:  none

   Postcondition: File is opened
**/
{
   char file_name[NAMESIZE];

   do
   {
      cout << "Please enter file name:"<< endl;
      cin  >> file_name;
      inFile.open(file_name);
      
      if(!inFile)
      {
         cout << file_name
              << " could not be opened."
              << endl;
      }
   }while(!inFile); 
}  // end of openFile function

void readFile(ifstream& inFile, FigureType& shape, int& num_figures)
/**
   purpose: Reads in the data from the file and saves the values to the appropriate member variables

   precondition:  File must be opened

   postcondition: Member variables of struct are initialized
**/
{
   int index = 0;
   inFile >> shape[index].num_points;

   do
   {
      for(int i=0; i < shape[index].num_points;i++)   // Reads in the values for the x coordinates and the y coordinates
      {
         inFile >> shape[index].x[i];
         inFile >> shape[index].y[i];
      }

      inFile >> shape[index].color;
      num_figures = index + 1;   // counts the number of figures

      index++;
      inFile >> shape[index].num_points;  // Reads in the number of given coordinates


   }while(shape[index].num_points != 0);  // Reads in coordinates based on the number of given coordinates as long as there are coordinates to read in.

}  // end of readFile function

void drawFigures(FigureType& draw, int& num_figures)
/**
   purpose: Draws figures

   precondition:  struct members must be initialized

   postcondition: Figures are drawn
*/
{
   createWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Draw");

   for(int i = 0; i < num_figures; i++)
   {
      if(toupper(draw[i].color) == 'K')
         setColor(BLACK);
      else if(toupper(draw[i].color) == 'R')
         setColor(RED);
      else if(toupper(draw[i].color) == 'G')
         setColor(GREEN);
      else if(toupper(draw[i].color) == 'B')
         setColor(BLUE);
      else if(toupper(draw[i].color) == 'M')
         setColor(MAGENTA);
      else if(toupper(draw[i].color) == 'Y')
         setColor(YELLOW);
      else if(toupper(draw[i].color) == 'C')
         setColor(CYAN);
      else if(toupper(draw[i].color) == 'P')
         setColor(PURPLE);
      else if(toupper(draw[i].color) == 'O')
         setColor(ORANGE);
      else
         setColor(BLACK);

      moveTo(draw[i].x[0],draw[i].y[0]);
      for(int index = 1; index < draw[i].num_points; index++)
      {
         lineTo(draw[i].x[index], draw[i].y[index]);
      }

      endOfShape();
   }

}  // end of drawFigures function
