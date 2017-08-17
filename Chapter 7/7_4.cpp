#include<iostream>
#include<vector>
using namespace std;
enum Vehicalsize
{
    Small,Medium,Large
};
class Vehical
{
    public:
    Vehicalsize getSize(){return Size;}
    string getLicense(){return License;}
    protected:
    Vehicalsize Size;
    string License;

};
class Bus : public Vehical
{
    public:
    Bus()
    {
        Size=Large;
    }
};
class Car : public Vehical
{
    public:
    Car()
    {
        Size=Medium;
    }
};
class Motercycle : public Vehical
{
    public:
    Motercycle()
    {
        Size=Small;
    }
};
class ParkingSpot
{
    int Number;
    Vehicalsize spotSize;
    bool istaken;
    public:
    ParkingSpot(int Number,Vehicalsize spotSize):Number(Number),spotSize(spotSize),istaken(false){}
};
class Parkinglot
{
    vector<ParkingSpot> spots;
    public:
    Parkinglot(int number){spots.reserve(number);}

};
int main()
{

}
