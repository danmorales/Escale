#include "Rover.h"
#include <fstream>
#include <string>
#include <iostream>
#include <locale>
using namespace std;

int main()
{

Rover *r = new Rover; 

int xsize, ysize;
int pos[2][2];
int size[2];
string orient[2];
string task[2];
string char1;
string filename;

filename = "Rover.txt";

ifstream pfile;
  pfile.open(filename);
  if (pfile.is_open()) 
  {
  while (!pfile.eof())
  {
   pfile  >> xsize >> ysize;

   for (int Rover=0; Rover<2; Rover++)
   {
           pfile >> pos[Rover][0] >> pos[Rover][1] >> orient[Rover];
           pfile >> task[Rover];
   }
  }}
  pfile.close();

cout << "Grid size: " << xsize << " X " << ysize << endl;

cout << "Position Rover 1: " << pos[0][0] << " " << pos[0][1] << " " << orient[0] << endl;
cout << "Position Rover 2: " << pos[1][0] << " " << pos[1][1] << " " << orient[1] << endl;

cout << "Task 1: " << task[0] << endl;
cout << "Task 2: " << task[1] << endl;

//Computing the numbers of characters for each task

size[0] = task[0].length();
size[1] = task[1].length();

cout << "Size 1= " << size[0] << endl;
cout << "Size 2= " << size[1] << endl;

//Computing main task

for(int Rover=1; Rover<3;Rover++)
{

cout << "Rover: " << Rover << endl; 

    for(int i=0; i<size[Rover-1]; i++)
    {

        char1 = task[Rover-1].at(i);

        if(char1 == "M")
        {
            pos[Rover-1][0] = r->setPositionX(orient[Rover-1], pos[Rover-1][0], xsize);
            pos[Rover-1][1] = r->setPositionY(orient[Rover-1], pos[Rover-1][1], ysize);

        }

        if(char1 == "L" || char1 == "R")
        {

            orient[Rover-1] = r->setOrientation(char1,orient[Rover-1]);
        }

    }

}

cout << "Final positions" << endl;
cout << "Rover 1:" << " X= " << pos[0][0] << " Y= " << pos[0][1] << " Orientation= " << orient[0] << endl;
cout << "Rover 2:" << " X= " << pos[1][0] << " Y= " << pos[1][1] << " Orientation= " << orient[1] << endl;

delete r;

}