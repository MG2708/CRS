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
    double price;
public:
    DatabaseCar()
    : DatabaseCar(0, 0, 0, "", 0, "", 0, 0) {}

    DatabaseCar(double mxSpeed, double mlg, double flCap, string flType, 
            int yr, string name, double odoReading, double cost)
    : maxSpeed{mxSpeed}, mileage{mlg}, fuelCapacity{flCap}
    , fuelType{flType}, year{yr}, modelName{name}
    , odometerReading{odoReading}, price{cost} {}
};

class Luxury : protected DatabaseCar {
    bool hasUmbrella;
    bool hasFridge;
    bool hasTV;
    double currentSunRoofOpacity;

public:

    Luxury(double mxSpeed, double mlg, double flCap, string flType, 
            int yr, string name, double odoReading, double cost, bool umb, 
            bool fridge, bool tv, double roofOp)
    : DatabaseCar(mxSpeed, mlg, flCap, flType, yr, name, odoReading, cost)
    , hasUmbrella{umb}, hasFridge{fridge}, hasTV{tv}
    , currentSunRoofOpacity{roofOp}{}
    
    Luxury() 
    : Luxury(0, 0, 0, "", 0, "", 0, 0, false, false, false, 0){}

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
    cout << "Its rent price per day is: " << price << " rupees" << endl;
    cout << endl;
}

class Suv : protected DatabaseCar {
    double groundClearance;
    bool allWheelDrive;
    double heightSeatingPos;

public:

    Suv(double mxSpeed, double mlg, double flCap, string flType, 
            int yr, string name, double odoReading, double cost, double GC, 
            bool AWD, double seatingPos)
    : DatabaseCar(mxSpeed, mlg, flCap, flType, yr, name, odoReading, cost)
    , groundClearance{GC}, allWheelDrive{AWD}
    , heightSeatingPos{seatingPos} {}
    
    Suv() 
    : Suv(0, 0, 0, "", 0, "", 0, 0, 0, false, 0){}

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
    cout << "Its gruond clearance level is: " << groundClearance << "mm" << endl;
    cout << "The height of the seat that you would be enjoying is: "
         << heightSeatingPos << "mm" << endl;
    if (allWheelDrive) {
        cout << "Your car is super powerful since it has an all wheel drive!" << endl;
    }
    cout << "Its rent price per day is: " << price << " rupees" << endl;
    cout << endl;
}

class Sedan : protected DatabaseCar
{
    //bool hasRadio;
    double bootSpace;
    double headSpace;
public:
    Sedan(double mxSpeed, double mlg, double flCap, string flType, 
            int yr, string name, double odoReading, double cost, double boot_space
            ,double head_space)
    : DatabaseCar(mxSpeed, mlg, flCap, flType, yr, name, odoReading, cost)
    , bootSpace{boot_space}, headSpace{head_space}{}

    Sedan(): Sedan(0, 0, 0, "", 0, "", 0, 0, 0, 0){}

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
    cout << "The trunk space of the car is: "<< bootSpace << "ltrs" << endl;
    cout << "The head space of the car is: "<< headSpace << "mm" << endl;
    cout << "Its rent price per day is: " << price << " rupees" << endl;
    cout << endl;
}

int welcomeMenu()
{
    int choice_in_wm;
    cout << endl;
    cout << "What type of car you would like to book:"<< endl;
    cout << "1.Luxury "<<endl;
    cout << "2.SUV "<<endl;
    cout << "3.Sedan "<<endl;
    cout << "Enter your choice: "<< endl;
    cin >> choice_in_wm;
    cout << endl;
    if(choice_in_wm<1 || choice_in_wm>3)
    {
        cout << "Please enter a valid number "<<endl;
        cout << endl;
        return(-1);
    }
    else
        return(choice_in_wm);

}

int luxCarSelection() {
    int carChoice{};

    cout << "Choose which car you would like to ride in" << endl;
    cout << "1) BMW X1" << endl;
    cout << "2) Mercedes E-Class E 220d BS4" << endl;
    cout << "3) Mercedes S-Class 5500 W223 BS4" << endl;
    cout << "4) Audi A8L Technology Model" << endl;
    cin >> carChoice;
    cout << endl;

    if(carChoice<1 || carChoice>4)
    {
        cout << "Please enter a valid number "<<endl;
        return -1;
    }
    else
        return carChoice;
}

int suvCarSelection() {
    int carChoice{};

    cout << "Choose which car you would like to ride in" << endl;
    cout << "1) Mahindra XUV 700" << endl;
    cout << "2) Mahindra Scorpio S3" << endl;
    cout << "3) Toyota Fortuner" << endl;
    cout << "4) Kia Seltos FWD" << endl;
    cin >> carChoice;
    cout << endl;

    if(carChoice<1 || carChoice>4)
    {
        cout << "Please enter a valid number "<<endl;
        return -1;
    }
    else
        return carChoice;
}

int sedanCarSelection() {
    int carChoice{};

    cout << "Choose which car you would like to ride in" << endl;
    cout << "1) Maruti Ciaz Alpha" << endl;
    cout << "2) Maruti Ciaz Sigma" << endl;
    cout << "3) Honda City V MT" << endl;
    cout << "4) Honda City V MT" << endl;
    cin >> carChoice;
    cout << endl;

    if(carChoice<1 || carChoice>4)
    {
        cout << "Please enter a valid number "<<endl;
        return -1;
    }
    else
        return carChoice;
}

int main() {

    Luxury bmwx1(129, 17.5, 51, "Petrol", 
            2018, "BMW X1", 120, 5500, false, 
            false, true, 1.6);
    
    Luxury mercEClass(224, 15.1, 80, "Diesel", 
                    2021, "Mercedes E-Class E 220d BS4",
                    245, 7800, false, false, false, 1.4);
    
    Luxury mercSClass(250, 6.7, 80, "Petrol", 
                    2021, "Mercedes S-Class 5500 W223 BS4",
                    100, 16000, true, true, true, 1.8);
    
    Luxury audiA8(250, 7.92, 80, "Hybrid (Electric + Petrol)",
                2022, "Audi A8L Technology Model", 120, 15000,
                true, true, true, 2);

    Suv xuv700(200, 16, 60, "Diesel", 2022, "Mahindra XUV 700",
            100, 3000, 200, true, 840);

    Suv scorpioS3(160, 15.4, 58, "Diesel", 2021, 
                "Mahindra Scorpio S3", 100, 2400, 180, false,
                840);

    Suv fortuner(186, 13.4, 80, "Petrol", 2020, 
                "Toyota Fortuner", 100, 3800, 225, true,
                820);

    Suv seltos(165, 18.6, 50, "Petrol", 2022, 
                "Kia Seltos FWD", 100, 2500, 190, false,
                800);

    Sedan ciazA(185, 20, 43, "Petrol", 2021, "Maruti Ciaz Alpha",
            100, 2400, 510, 900);

    Sedan ciazS(185, 20.65, 43, "Petrol", 2022, "Maruti Ciaz Sigma",
            100, 2600, 510, 900);

    Sedan hondaCity(195, 17.55, 40, "Diesel", 2022, "Honda City V MT",
            100, 2800, 506, 910);

    Sedan verna(200, 21.5, 45, "Petrol", 2022, "Hyundai Verna SX",
            100, 2500, 480, 860);

    cout << "Welcome to Car Rental System " << endl;
    cout << "Made by: " <<endl;
    cout << "1. Mudit Garg " << endl;
    cout << "2. Nihar Phansalkar " << endl;
    cout << "3. Ojaswini Kohale " << endl;
    cout << "4. P. Karthik Krishna " << endl;

    for(int i=0;i<1000000000;i++)
    {

    }
    // system("cls");
    system("clear");

    cout << "Welcome to Car Rental System " << endl << endl;

    cout << "Press '1' to book a car" << endl;
    cout << "Press '2' to exit" << endl;

    int initialChoice;
    cin >> initialChoice;

    int val_from_wm;
    int luxCarChoice{0}, suvCarChoice{0}, sedanCarChoice{0};

    while(initialChoice==1)
    {
        switch(initialChoice)
        {

            case 1:
                {
                    val_from_wm = welcomeMenu();

                    while(val_from_wm == -1)
                    {
                        val_from_wm = welcomeMenu();
                    }

                    if(val_from_wm == 1)
                    {
                        luxCarChoice = luxCarSelection();
                        while (luxCarChoice == -1) {
                            luxCarChoice = luxCarSelection();
                        }
                        break;
                    }
                    else if(val_from_wm == 2)
                    {
                        suvCarChoice = suvCarSelection();
                        while (suvCarChoice == -1) {
                            suvCarChoice = suvCarSelection();
                        }
                        break;
                    }
                    else if(val_from_wm == 3)
                    {
                        sedanCarChoice = sedanCarSelection();
                        while (sedanCarChoice == -1) {
                            sedanCarChoice = sedanCarSelection();
                        }
                        break;
                    }
                }
                
                break;

            case 2:
                initialChoice=2;
                break;
        }

        if (luxCarChoice) {
            if (luxCarChoice == 1) {
                bmwx1.displayInfoLux();
            }
            else if (luxCarChoice == 2) {
                mercEClass.displayInfoLux();
            }
            else if (luxCarChoice == 3) {
                mercSClass.displayInfoLux();
            }
            else if (luxCarChoice == 4) {
                audiA8.displayInfoLux();
            }
        } 

        if (suvCarChoice) {
            if (suvCarChoice == 1) {
                xuv700.displayInfoSuv();
            }
            else if (suvCarChoice == 2) {
                scorpioS3.displayInfoSuv();
            }
            else if (suvCarChoice == 3) {
                fortuner.displayInfoSuv();
            }
            else if (suvCarChoice == 4) {
                seltos.displayInfoSuv();
            }
        } 

        if (sedanCarChoice) {
            if (sedanCarChoice == 1) {
                ciazA.displayInfoSedan();
            }
            else if (sedanCarChoice == 2) {
                ciazS.displayInfoSedan();
            }
            else if (sedanCarChoice == 3) {
                hondaCity.displayInfoSedan();
            }
            else if (sedanCarChoice == 4) {
                verna.displayInfoSedan();
            }
        } 

        // system("cls");
        // system("clear");

        cout << "Welcome to Car Rental System "<< endl <<endl;

        cout << "Press '1' to book a car"<< endl;
        cout << "Press '2' to exit"<< endl;
        cin >> initialChoice;
    }
    
}
