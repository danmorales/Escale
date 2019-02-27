#include <fstream>
#include <string>
#include <iostream>
#include <locale>
using namespace std;

class Rover
{

    public:
        Rover();
        ~Rover();
        string setOrientation(string task, string orientationtmp);
        int setPositionX(string orientation, int pos, int xsize);
        int setPositionY(string orientation, int pos, int ysize);

    private:
        string orientation;
        int posx,posy;
};