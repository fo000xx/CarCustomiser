#include <iostream>
#include <string_view>
#include <algorithm>
#include <vector>
#include <cctype>
#include <string>
#include <cassert>

#include "Car.h"

//initialise objects for each base car, in global so multiple functions can use them
//start at ID 1, each subsequent car has an ID of ++1
Car hondaCivic{"Honda", "Civic", 30335.00, 70.4, 80.6, 77.3, 88.9, 95.6};
Car fordMustang{"Ford", "Mustang", 47608.50, 85.4, 72.6, 85.3, 73.2, 82.6};
Car fordFocus{"Ford", "Focus", 26730.00, 65.2, 90.3, 71.2, 88.3, 80.4};
Car audiTT{"Audi", "TT", 34830.00, 86.7, 85.9, 70.2, 90.2, 70.1};
Car daewooMatiz{"Daewoo", "Matiz", 890.00, 42.6, 56.7, 50.1, 34.2, 40.1};
Car fordTransit{"Ford", "Transit", 37935.00, 50.3, 40.8, 99.1, 49.6, 95.6};

int userChoice();
void customiseMenu(int uniqueID);

void convertLower(std::string& s)
{
    std::transform(s.begin(), s.end(), s.begin(),
    [](char c){ return std::tolower(c); });
}

//print the specs of all cars
void viewCars()
{
    hondaCivic.printCar();
    std::cout << '\n';
    fordMustang.printCar();
    std::cout << '\n';
    fordFocus.printCar();
    std::cout << '\n';
    audiTT.printCar();
    std::cout << '\n';
    daewooMatiz.printCar();
    std::cout << '\n';
    fordTransit.printCar();
    std::cout << '\n';
}

//used to get the car name based on the uniqueID
Car& getCar(int uniqueID)
{
    switch (uniqueID)
    {
        case 1: return hondaCivic;
        case 2: return fordMustang;
        case 3: return fordFocus;
        case 4: return audiTT;
        case 5: return daewooMatiz;
        case 6: return fordTransit;
        
        default: assert(false && "Default of getCar reached, invalid ID passed");
    }
}

void printChoice(int uniqueID)
{
    getCar(uniqueID).printFullCar();
}

int main() 
{
    int uniqueID{ 0 }; //uniqueID to track the car choice, used throughout.
    //initial prompt
    std::cout << "Hello, welcome to Car Customiser, would you like to VIEW our car specifications or SELECT a car? (VIEW/SELECT)\n";
    std::string firstChoice{};
    std::cin >> firstChoice;
    convertLower(firstChoice);
    
    //initial menu shown on launching the program
    while (true)
    {
        //clear any extra input to stop invalidation of future attempts
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (firstChoice == "view")
        {   viewCars();
            break;
        }
        else if (firstChoice == "select")
        {
            uniqueID = userChoice();
            break;
        }
        else
            std::cout << "Invalid option, please try again.\n";
    }
        
        if (uniqueID == 0)
        {
            std::cout << "Please select a car\n";
            uniqueID = userChoice();
        }

    //select customisation option OR change/view car
    //menu 2
    while (true)
    {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Would you like to CUSTOMISE, CHANGE or SAVE your car, alternatively VIEW all cars? (CUSTOMISE/CHANGE/SAVE/VIEW)\n";
        
        std::string secondChoice{};
        std::cin >> secondChoice;
        convertLower(firstChoice);

        if (secondChoice == "save")
        {
            printChoice(uniqueID);
            return 0;
        }
        else if (secondChoice == "change")
        {
            getCar(uniqueID).resetCar(); //reset previous option back to base values to stop compounding improvements
            uniqueID = userChoice();
        }
        else if (secondChoice == "view")
        {
            viewCars();
        }
        else if (secondChoice == "customise")
        {
            customiseMenu(uniqueID);
        }
    }
    return 0;
}
