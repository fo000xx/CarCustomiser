#include <iostream>
#include <string>
#include <iomanip> //for std::setprecision
#include <ios> //for std::fixed

#include "Car.h"
#include "CustPriceSpecs.h"

Car& getCar(int uniqueID);
void convertLower(std::string& s);

//menus pull price/spec changes from CustPriceSpecs.h, prints these and asks the user if they'd like to use them.

void colourSelect(int uniqueID)
{
    while (true)
    {
        std::cout << "Choose a colour: BLACK, RED, WHITE, PINK, GREEN\n";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::string newColour{};
        std::cin >> newColour;
        convertLower(newColour);

        if (newColour == "black" || newColour == "red" || newColour == "white" || newColour == "pink" || newColour == "green")
        {
            getCar(uniqueID).setColour(newColour);
            break;
        }
        else
            std::cout << "Invalid colour, please try again.\n";
    }
}

void racingStripes(int uniqueID)
{
    while (true)
    {
        std::cout << "Would you like to add racing stripes? This will cost: £" << std::setprecision(2) << std::fixed 
        << PriceSpecs::racingStripeCost << " and improve speed by " << std::setprecision(0) << std::fixed 
        << PriceSpecs::racingStripeSpeedInc * 100.00 << "% (Y/N): ";
        
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::string stripeChoice{};
        std::cin >> stripeChoice;

        convertLower(stripeChoice);

        if (stripeChoice == "y" || stripeChoice == "yes")
        {
            getCar(uniqueID).addRacingStripes();
            break;
        }
        else if (stripeChoice == "n" || stripeChoice == "no")
        {
            getCar(uniqueID).removeRacingStripes();
            break;
        }
        else
            std::cout << "Invalid input, please try again\n";
    }

    std::cout << "Choice saved. Your car specs are now: \n";
    getCar(uniqueID).printCar();
}

void paintMenu(int uniqueID)
{
    while (true)
    {
        std::cout << "Would you like to change colour, add custom decals or return to the previous menu? (COLOUR/DECAL/BACK)\n";

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::string paintOption{};
        std::cin >> paintOption;

        convertLower(paintOption);
        if (paintOption == "colour")
            colourSelect(uniqueID);
        else if (paintOption == "decal")
            racingStripes(uniqueID);
        else if (paintOption == "back")
            break;
        else
            std::cout << "Invalid option, please try again\n";
    }
}

void tyreMenu(int uniqueID)
{
    while (true)
    {
        std::cout << "Would you like to use upgraded performance tyres? This will cost: £" << std::setprecision(2) << std::fixed 
        << PriceSpecs::perfTyreCost << ", improve handling by " << std::setprecision(0) << std::fixed 
        << PriceSpecs::perfTyreHandleInc * 100.00 << "% and improve traction by " << std::setprecision(0) << std::fixed 
        << PriceSpecs::perfTyreTracInc * 100.00 << "% (Y/N): ";
        
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::string tyreChoice{};
        std::cin >> tyreChoice;

        convertLower(tyreChoice);

        if (tyreChoice == "y" || tyreChoice == "yes")
        {
            getCar(uniqueID).upgradeTyres();
            break;
        }
        else if (tyreChoice == "n" || tyreChoice == "no")
        {
            getCar(uniqueID).downgradeTyres();
            break;
        }
        else
            std::cout << "Invalid input, please try again\n";
    }

    std::cout << "Choice saved. Your car specs are now: \n";
    getCar(uniqueID).printCar();
}

void engineMenu(int uniqueID)
{
    while (true)
    {
        std::cout << "Would you like to use a tuned engine? This will cost: £" << std::setprecision(2) << std::fixed 
        << PriceSpecs::tuneEngineCost << " and improve speed by " << std::setprecision(0) << std::fixed 
        << PriceSpecs::tuneEngineSpeedInc * 100.00 << "% (Y/N): ";
        
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::string engineChoice{};
        std::cin >> engineChoice;

        convertLower(engineChoice);

        if (engineChoice == "y" || engineChoice == "yes")
        {
            getCar(uniqueID).upgradeEngine();
            break;
        }
        else if (engineChoice == "n" || engineChoice == "no")
        {
            getCar(uniqueID).downgradeEngine();
            break;
        }
        else
            std::cout << "Invalid input, please try again\n";
    }

    std::cout << "Choice saved. Your car specs are now: \n";
    getCar(uniqueID).printCar();
}

void spoilerMenu(int uniqueID)
{
    while (true)
    {
        std::cout << "Would you like to use a rear spoiler? This will cost: £" << std::setprecision(2) << std::fixed 
        << PriceSpecs::spoilerCost << ", increase weight by " << std::setprecision(0) << std::fixed 
        << PriceSpecs::spoilerWeightInc * 100.00 << "% and improve traction by " << std::setprecision(0) << std::fixed 
        << PriceSpecs::spoilerTractInc * 100.00 << "% (Y/N): ";
        
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::string spoilerChoice{};
        std::cin >> spoilerChoice;

        convertLower(spoilerChoice);

        if (spoilerChoice == "y" || spoilerChoice == "yes")
        {
            getCar(uniqueID).addSpoiler();
            break;
        }
        else if (spoilerChoice == "n" || spoilerChoice == "no")
        {
            getCar(uniqueID).removeSpoiler();
            break;
        }
        else
            std::cout << "Invalid input, please try again\n";
    }

    std::cout << "Choice saved. Your car specs are now: \n";
    getCar(uniqueID).printCar();
}

void bonnetMenu(int uniqueID)
{
    while (true)
    {
        std::cout << "Would you like to use a carbon fibre bonnet? This will cost: £" << std::setprecision(2) << std::fixed 
        << PriceSpecs::carbFibreCost << ", decrease weight by " << std::setprecision(0) << std::fixed 
        << PriceSpecs::carbFibreWeightDec * 100.00 << "% and improve speed by " << std::setprecision(0) << std::fixed 
        << PriceSpecs::carbFibreSpeecInc * 100.00 << "% (Y/N): ";
        
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::string bonnetChoice{};
        std::cin >> bonnetChoice;

        convertLower(bonnetChoice);

        if (bonnetChoice == "y" || bonnetChoice == "yes")
        {
            getCar(uniqueID).addCarbonFibre();
            break;
        }
        else if (bonnetChoice == "n" || bonnetChoice == "no")
        {
            getCar(uniqueID).removeCarbonFibre();
            break;
        }
        else
            std::cout << "Invalid input, please try again\n";
    }

    std::cout << "Choice saved. Your car specs are now: \n";
    getCar(uniqueID).printCar();
}

void bodyMenu(int uniqueID)
{
    while (true)
    {
        std::cout << "Would you like to customise the rear or front of the car, or return to the previous menu? (REAR/FRONT/BACK)\n";

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::string paintOption{};
        std::cin >> paintOption;

        convertLower(paintOption);
        if (paintOption == "rear")
            spoilerMenu(uniqueID);
        else if (paintOption == "front")
            bonnetMenu(uniqueID);
        else if (paintOption == "back")
            break;
        else
            std::cout << "Invalid option, please try again\n";
    }
}

void customiseMenu(int uniqueID)
{
    while (true)
    {   
        std::cout << "Would you like to customise the tyres, paint, engine, or body? (TYRES/PAINT/ENGINE/BODY/SAVE)\n";
    
        std::string customiseOption{};
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> customiseOption;
        convertLower(customiseOption);

        if (customiseOption == "tyres")
        {
            tyreMenu(uniqueID);
        }
        else if (customiseOption == "paint")
        {
            paintMenu(uniqueID);
        }
        else if (customiseOption == "engine")
        {
            engineMenu(uniqueID);
        }
        else if (customiseOption == "body")
        {
            bodyMenu(uniqueID);
        }
        else if (customiseOption == "save")
        {
            break;
        }
        else
            std::cout << "Invalid input, please try again\n";
    }
}