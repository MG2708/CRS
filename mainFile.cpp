// Honda VTEC
// Toyota hill assist
// Inherit to luxury car, SUV car, etc.
// Luxury, SUV, Sedan, hatchback

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;


class DatabaseCar {
protected:
    double maxSpeed;
    double mileage;
    double fuelCapacity;
    string fuelType;
    int year;
    string modelName;
    double odometerReading;
public:
    DatabaseCar()
    : DatabaseCar(0, 0, 0, "", 0, "", 0) {}

    DatabaseCar(double mxSpeed, double mlg, double flCap, string flType, 
            int yr, string name, double odoReading)
    : maxSpeed{mxSpeed}, mileage{mlg}, fuelCapacity{flCap}
    , fuelType{flType}, year{yr}, modelName{name}
    , odometerReading{odoReading} {}
};

class Luxury : protected DatabaseCar {
    bool hasUmbrella;
    bool hasFridge;
    bool hasTV;
    double currentSunRoofOpacity;

public:

    Luxury(double mxSpeed, double mlg, double flCap, string flType, 
            int yr, string name, double odoReading, bool umb, 
            bool fridge, bool tv, double roofOp)
    : DatabaseCar(mxSpeed, mlg, flCap, flType, yr, name, odoReading)
    , hasUmbrella{umb}, hasFridge{fridge}, hasTV{tv}
    , currentSunRoofOpacity{roofOp}{}
    
    Luxury() 
    : Luxury(0, 0, 0, "", 0, "", 0, false, false, false, 0){}

    void displayInfoLux();
};

void Luxury :: displayInfoLux() {
    cout << "Your selected car is: " << modelName << endl;
    cout << "Its max speed is: " << maxSpeed << " km/ph" << endl;
    cout << "The mileage it provides is: " << mileage << " km/L" << endl;
    cout << "Its fuel capacity is: " << fuelCapacity << " L" << endl;
    cout << "The type of fuel is: " << fuelType << endl;
    cout << "This car came to us in the year: " << year << endl;
    cout << "Its current odometer reading is: " << odometerReading << endl;
    if (hasUmbrella) {
        cout << "Your car also has an umbrella holder" << endl;
    }
    if (hasFridge) {
        cout << "Your car also has a fridge for your beverages and meals" << endl;
    }
    if (hasTV) {
        cout << "Your car also has a TV for your priceless entertainment" << endl;
    }
    cout << "The current sun roof opacity of your car is set to "
         << currentSunRoofOpacity << endl;
}

class Suv : protected DatabaseCar {
    double groundClearance;
    bool allWheelDrive;
    double heightSeatingPos;

public:

    Suv(double mxSpeed, double mlg, double flCap, string flType, 
            int yr, string name, double odoReading, double GC, 
            bool AWD, double seatingPos)
    : DatabaseCar(mxSpeed, mlg, flCap, flType, yr, name, odoReading)
    , groundClearance{GC}, allWheelDrive{AWD}
    , heightSeatingPos{seatingPos} {}
    
    Suv() 
    : Suv(0, 0, 0, "", 0, "", 0, 0, false, 0){}

    void displayInfoSuv();
};

void Suv :: displayInfoSuv() {
    cout << "Your selected car is: " << modelName << endl;
    cout << "Its max speed is: " << maxSpeed << " km/ph" << endl;
    cout << "The mileage it provides is: " << mileage << " km/L" << endl;
    cout << "Its fuel capacity is: " << fuelCapacity << " L" << endl;
    cout << "The type of fuel is: " << fuelType << endl;
    cout << "This car came to us in the year: " << year << endl;
    cout << "Its current odometer reading is: " << odometerReading << endl;
    cout << "Its gruond clearance level is: " << groundClearance << endl;
    cout << "The height of the seat that you would be enjoying is: "
         << heightSeatingPos << endl;
    if (allWheelDrive) {
        cout << "Your car is super powerful since it has an all wheel drive!" << endl;
    }
}

class Sedan : protected DatabaseCar
{
    //bool hasRadio;
    double trunkSpace;
    double headSpace;

    Sedan(double mxSpeed, double mlg, double flCap, string flType, 
            int yr, string name, double odoReading, double trunk_space
            ,double head_space)
    : DatabaseCar(mxSpeed, mlg, flCap, flType, yr, name, odoReading)
    , trunkSpace{trunk_space}, headSpace{head_space}{}

    Sedan(): Sedan(0, 0, 0, "", 0, "", 0, 0, 0){}

    void displayInfoSedan(); 
}; 

void Sedan :: displayInfoSedan()
{
    cout << "Your selected car is: " << modelName << endl;
    cout << "Its max speed is: " << maxSpeed << " km/ph" << endl;
    cout << "The mileage it provides is: " << mileage << " km/L" << endl;
    cout << "Its fuel capacity is: " << fuelCapacity << " L" << endl;
    cout << "The type of fuel is: " << fuelType << endl;
    cout << "This car came to us in the year: " << year << endl;
    cout << "Its current odometer reading is: " << odometerReading << endl;
    cout << "The trunk space of the car is: "<< trunkSpace << endl;
    cout << "The head space of the car is: "<< headSpace << endl;

}

int welcomeMenu()
{
    int choice_in_wm;
    cout << "What type of car you would like to book:"<< endl;
    cout << "1.Luxury "<<endl;
    cout << "2.SUV "<<endl;
    cout << "3.Sedan "<<endl;
    cout << "Enter your choice: "<< endl;
    cin >> choice_in_wm;
    if(choice_in_wm<1 || choice_in_wm>3)
    {
        cout << "Please enter a valid number "<<endl;
        return(-1);
    }
    else
    return(choice_in_wm);

}

int main() {

    cout << "Welcome to Car Rental System "<< endl;
    cout<<" Made by: "<<endl;
    cout << "1. Mudit Garg "<< endl;
    cout << "2. Nihar Phansalkar "<< endl;
    cout << "3. Ojaswini Kohale "<< endl;
    cout << "4. P. Karthik Krishna "<< endl;

    for(int i=0;i<1000000000;i++)
    {

    }
    system("cls");

    cout << "Welcome to Car Rental System "<< endl <<endl;

    cout << "Press '1' to book a car"<< endl;
    cout << "Press '2' to exit"<< endl;

    int initialChoice;
    cin >> initialChoice;

    int val_from_wm;
    while(initialChoice==1)
    {
        switch(initialChoice)
        {

            case 1:
                val_from_wm = welcomeMenu();

                while(val_from_wm == -1)
                {
                    val_from_wm = welcomeMenu();
                }
                    
                if(val_from_wm == 1)
                {
                
                }
                else if(val_from_wm == 2)
                {

                }
                else if(val_from_wm == 3)
                {

                }
                
                break;

            case 2:
                initialChoice=2;
                break;
        }

        system("cls");

        cout << "Welcome to Car Rental System "<< endl <<endl;

        cout << "Press '1' to book a car"<< endl;
        cout << "Press '2' to exit"<< endl;
    }
    
}
