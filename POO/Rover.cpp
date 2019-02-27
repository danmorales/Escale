#include "Rover.h"

Rover::Rover() {
	setlocale(LC_ALL,"");
}

string Rover::setOrientation(string task, string orientationtmp){

    int tmp;

    if(orientationtmp == "N") tmp = 1;
    if(orientationtmp == "S") tmp = 2;
    if(orientationtmp == "W") tmp = 3;
    if(orientationtmp == "E") tmp = 4;

    switch (tmp)
    {
        case 1:
            if(task == "L"){
             cout << "Rotating from North to West" << endl;
                this->orientation = "W";
            }
            if(task == "R"){
                cout << "Rotating from North to East" << endl;
                this->orientation = "E";
             }
            break;

        case 2:
            if(task == "L"){
                cout << "Rotating from South to East" << endl;
                this->orientation = "E";
             }
            if(task == "R"){
               cout << "Rotating from South to West" << endl;
               this->orientation = "W";
            }  
            break;

        case 3:
            if(task == "L"){
                cout << "Rotating from West to South" << endl;
                this->orientation = "S";
            }
            if(task == "R"){
                cout << "Rotating from West to North" << endl;
                this->orientation = "N";
            }
            break;

        case 4:
            if(task == "L"){
                cout << "Rotating from East to North" << endl;
                this->orientation = "N";
            }
            if(task == "R"){
                cout << "Rotating from East to South" << endl;
                this->orientation = "S";
            }
            break;    
    } 
    
    return this->orientation;
}

int Rover::setPositionX(string orientation, int pos, int xsize)
{

   int tmp;

    if(orientation == "N") tmp = 1;
    if(orientation == "S") tmp = 2;
    if(orientation == "W") tmp = 3;
    if(orientation == "E") tmp = 4;

    switch(tmp)
    {
        case 1:
            this->posx = pos;    
            break;
        case 2:
            this->posx = pos;
            break;
        case 3:
            if(pos-1 < 0){
                cout << "This movement exceed the x- domain" << endl;
            } else {
                this->posx = pos - 1;
            }
            break;
        case 4:
            if(pos+1 > xsize){
               cout << "This movement exceed the x+ domain" << endl;
            } else { 
                this->posx = pos + 1;
            }
            break;
    }

    return this->posx;
}

int Rover::setPositionY(string orientation, int pos, int ysize)
{
    
    int tmp;

    if(orientation == "N") tmp = 1;
    if(orientation == "S") tmp = 2;
    if(orientation == "W") tmp = 3;
    if(orientation == "E") tmp = 4;

    switch(tmp)
    {
        case 1:
            if(pos+1 > ysize){
                cout << "This movement exceed the y+ domain" << endl;
            } else { 
                this->posy = pos + 1;
            }
            break;
        case 2:
            cout << "Moving to South" << endl;
            if(pos-1 < 0){
                cout << "This movement exceed the y- domain" << endl;
            } else {
                this->posy = pos - 1;
            }
            break;
        case 3:
            this->posy = pos;
            break;
        case 4:
            this->posy = pos;
            break;
    }

    return this->posy;
}

Rover::~Rover()
{
}
