
//Desafio Escale Danilo

#include <string>
#include <iostream>
#include <fstream>
using namespace std;

//Function to evaluate the next position;
void setOrientation(string task, string* orientation){

    int tmp;

    if(*orientation == "N") tmp = 1;
    if(*orientation == "S") tmp = 2;
    if(*orientation == "W") tmp = 3;
    if(*orientation == "E") tmp = 4;

switch (tmp)
{
    case 1:
        if(task == "L"){
            cout << "Rotating from North to West" << endl;
            *orientation = "W";
        }
        if(task == "R"){
            cout << "Rotating from North to East" << endl;
            *orientation = "E";
        }
        break;

    case 2:
        if(task == "L"){
            cout << "Rotating from South to East" << endl;
            *orientation = "E";
        }
        if(task == "R"){
            cout << "Rotating from South to West" << endl;
            *orientation = "W";
        }
        break;

    case 3:
        if(task == "L"){
            cout << "Rotating from West to South" << endl;
            *orientation = "S";
        }
        if(task == "R"){
            cout << "Rotating from West to North" << endl;
            *orientation = "N";
        }
        break;

    case 4:
        if(task == "L"){
            cout << "Rotating from East to North" << endl;
            *orientation = "N";
        }
        if(task == "R"){
            cout << "Rotating from East to South" << endl;
            *orientation = "S";
        }
        break;    
}

}

void setPosition(string orientation, int* posx, int* posy, int xsize, int ysize)
{
    
    int tmp;

    if(orientation == "N") tmp = 1;
    if(orientation == "S") tmp = 2;
    if(orientation == "W") tmp = 3;
    if(orientation == "E") tmp = 4;


    switch(tmp)
    {
        case 1:
            cout << "Moving to North" << endl;
            if(*posy+1 > ysize){
                cout << "This movement exceed the y+ domain" << endl;
            } else {
            *posx = *posx;    
            *posy = *posy + 1;
            }
            break;

        case 2:
            cout << "Moving to South" << endl;
            if(*posy-1 < 0){
                cout << "This movement exceed the y- domain" << endl;
            } else {
                *posx = *posx;
                *posy = *posy - 1;
            }
            break;
        
        case 3:
            cout << "Moving to West" << endl;
            if(*posx-1 < 0){
                cout << "This movement exceed the x- domain" << endl;
            } else {
                *posx = *posx - 1;
                *posy = *posy;
            }
            break;

        case 4:
            cout << "Moving to East" << endl;
            if(*posx+1 > xsize){
               cout << "This movement exceed the x+ domain" << endl;
            } else { 
                *posx = *posx + 1;
                *posy = *posy;
            }
            break;
    }
}

int main()
{

int xsize, ysize;
int posx[2], posy[2];
int size[2];
string orientation[2];
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
           pfile >> posx[Rover] >> posy[Rover] >> orientation[Rover];
           pfile >> task[Rover];
   }
  }}
  pfile.close();

cout << "Grid size: " << xsize << " X " << ysize << endl;

cout << "Position Rover 1: " << posx[0] << " " << posy[0] << " " << orientation[0] << endl;
cout << "Position Rover 2: " << posx[1] << " " << posy[1] << " " << orientation[1] << endl;

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
            setPosition(orientation[Rover-1], &posx[Rover-1], &posy[Rover-1],xsize,ysize);

        }

        if(char1 == "L" || char1 == "R")
        {
            setOrientation(char1, &orientation[Rover-1]);
        }

    }

}

cout << "Final positions" << endl;
cout << "Rover 1:" << " X= " << posx[0] << " Y= " << posy[0] << " Orientation= " << orientation[0] << endl;
cout << "Rover 2:" << " X= " << posx[1] << " Y= " << posy[1] << " Orientation= " << orientation[1] << endl;


}