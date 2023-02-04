#include <iostream>
#include <map>
#include <string>
#include <string_view>
#include <cassert>

#include "Car.h"
#include "CustPriceSpecs.h"

extern Car hondaCivic;
extern Car fordMustang;
extern Car fordFocus;
extern Car audiTT;
extern Car daewooMatiz;
extern Car fordTransit;

void convertLower(std::string& s);

//validate whether the user has entered a valid model for the chosen make 
bool validateModelInput(std::string_view model, std::string_view make)
{
    if ((make == "audi" && model == "tt") || (make == "daewoo" && model == "matiz")
        || (make == "ford" && (model == "focus" || model == "mustang" || model == "transit"))
        || (make == "honda" && model == "civic"))
        return true;
    return false;
}

bool validateMakeInput(std::string_view choice)
{
    if (choice == "audi" || choice == "daewoo" || choice == "ford" || choice == "honda")
        return true;
    return false;
}

int getUniqueID(std::string_view model)
{  
    //map to map user input to car ID
    std::map<std::string_view, int> carmap{
        {"tt", audiTT.getID()},
        {"matiz", daewooMatiz.getID()},
        {"focus", fordFocus.getID()},
        {"mustang", fordMustang.getID()},
        {"transit", fordTransit.getID()},
        {"civic", hondaCivic.getID()}
    };

    //search the map, if ID is found, return this.
    if (auto search = carmap.find(model); search != carmap.end())
        return search->second;
    assert(false && "Searching for a non-existent car");
}

int userModelChoice(std::string_view make)
{
    std::string modelChoice{};

    std::cout << "Choose your model, enter BACK to return to the previous menu\n";
    while (true)
    {
        //clear any extra input to stop invalidation of future attempts
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        if (make == "audi")
            std::cout << "Available models: TT\n";
        else if (make == "daewoo")
            std::cout << "Available models: Matiz\n";
        else if (make == "ford")
            std::cout << "Available models: Focus, Mustang, Transit\n";
        else if (make == "honda")
            std::cout << "Available models: Civic\n";

        //get input and convert to lowercase for validation
        std::cin >> modelChoice;
        convertLower(modelChoice);

        //leave whileloop if a valid choice is chosen
        if (modelChoice == "back")
            return -1; //-1 is an invalid ID so chosen as won't be against a car
        else if(validateModelInput(modelChoice, make))
            break;
    }
    
    int uniqueID{ getUniqueID(modelChoice) };
    
    return uniqueID;
}

int userMakeChoice()
{  
    //keep the user in this loop until they've entered a valid input
    //input checked using validateInput() function
    std::string makeChoice{};
    while (true)
    {
    std::cout << "Chose the make of car: Audi, Daewoo, Ford, or Honda.\n";
    std::cin >> makeChoice;

    convertLower(makeChoice);

    if (validateMakeInput(makeChoice))
        break;
    }
    
    int uniqueID{ userModelChoice(makeChoice) };
    
    return uniqueID;
}

int userChoice()
{
    //ask the user to choose a base car and assign an ID
    //if the user exits the model selection menu a -1 is returned, allowing them to choose another car
    int uniqueID{};
    while (true)
    {
        uniqueID = userMakeChoice();
        if (uniqueID > 0)
            break;
    }
    return uniqueID;
}