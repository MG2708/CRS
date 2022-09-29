// Honda VTEC
// Toyota hill assist
// Inherit to luxury car, SUV car, etc.
// Luxury, SUV, Sedan, hatchback

#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class databaseCar {
protected:
    double maxSpeed;
    double mileage;
    double fuelCapacity;
    string fuelType;
    int year;
    string modelName;
    double odometerReading;
public:
    databaseCar()
    : databaseCar(0, 0, 0, "", 0, "", 0) {}

    databaseCar(double mxSpeed, double mlg, double flCap, string flType, 
            int yr, string name, double odoReading)
    : maxSpeed{mxSpeed}, mileage{mlg}, fuelCapacity{flCap}
    , fuelType{flType}, year{yr}, modelName{name}
    , odometerReading{odoReading} {}
};

class Luxury : protected databaseCar {
    bool hasUmbrella;
    bool hasFridge;
    bool hasTV;
    double currentSunRoofOpacity;

public:

    Luxury(double mxSpeed, double mlg, double flCap, string flType, 
            int yr, string name, double odoReading, bool umb, 
            bool fridge, bool tv, double roofOp)
    : databaseCar(mxSpeed, mlg, flCap, flType, yr, name, odoReading)
    , hasUmbrella{umb}, hasFridge{fridge}, hasTV{tv}
    , currentSunRoofOpacity{roofOp}{}
    
    Luxury() 
    : Luxury(0, 0, 0, "", 0, "", 0, false, false, false, 0){}

    void getData();
};

void Luxury :: getData() {
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

class Suv : protected databaseCar {
    double groundClearance;
    bool allWheelDrive;
    double heightSeatingPos;

public:

    Suv(double mxSpeed, double mlg, double flCap, string flType, 
            int yr, string name, double odoReading, double GC, 
            bool AWD, double seatingPos)
    : databaseCar(mxSpeed, mlg, flCap, flType, yr, name, odoReading)
    , groundClearance{GC}, allWheelDrive{AWD}
    , heightSeatingPos{seatingPos} {}
    
    Suv() 
    : Suv(0, 0, 0, "", 0, "", 0, 0, false, 0){}

    void getData();
};

void Suv :: getData() {
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

int main() {
    Luxury rollsRoyce(120, 34, 70, "Diesel", 2018, "RoyceDan",
                      123, true, false, true, 0.4);
    
    rollsRoyce.getData();
}
