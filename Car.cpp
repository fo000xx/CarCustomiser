#include <iostream>
#include <iomanip> //for std::setprecision
#include <ios> //for std::fixed
#include <algorithm> //for std::min

#include "Car.h"
#include "CustPriceSpecs.h"

void convertLower(std::string& s);

void Car::printCar()
{
    std::cout << "Make: " << m_make << " Model: " << m_model << " Price: £" << std::setprecision(2) << std::fixed << m_price
        << "\nSpecifications:" << std::setprecision(1) << std::fixed << "\nSpeed: " << std::min(100.00, m_speed) << "\nHandling: " 
        << std::min(100.00, m_handling) << "\nWeight: " << std::min(100.00, m_weight) << "\nAcceleration: " 
        << std::min(100.00, m_acceleration) << "\nTraction: " << std::min(100.00, m_traction) << '\n'; 
}

void Car::printCustoms()
{
    std::cout << "\nCustomisables:\n"
        << "Upgraded Engine: " << (m_upgradedEngine == 1 ? "Yes\n" : "No\n")
        << "Upgraded Tyres: " << (m_performanceTyres == 1 ? "Yes\n" : "No\n")
        << "Carbon Fibre Bonnet: " << (m_carbonFibre == 1 ? "Yes\n" : "No\n")
        << "Rear Spoiler: " << (m_spoiler == 1 ? "Yes\n" : "No\n")
        << "Racing Stripes: " << (m_racingStripes == 1 ? "Yes\n" : "No\n")
        << "Paint Colour: " << m_colour << '\n';
}

void Car::printFullCar()
{
    printCar();
    printCustoms();
}

//adding increases the associated values by a %
void Car::upgradeEngine() 
{   
    m_upgradedEngine = 1; 
    m_price += PriceSpecs::tuneEngineCost; 
    m_speed += (m_oSpeed * PriceSpecs::tuneEngineSpeedInc); 
}
void Car::downgradeEngine() 
{ 
    m_upgradedEngine = 0; 
    m_price -= PriceSpecs::tuneEngineCost; 
    m_speed -= (m_oSpeed * PriceSpecs::tuneEngineSpeedInc); 
}

void Car::upgradeTyres() 
{ 
    m_performanceTyres = 1; 
    m_price += PriceSpecs::perfTyreCost; 
    m_handling += (m_oHandling * PriceSpecs::perfTyreHandleInc);
    m_traction += (m_oTraction * PriceSpecs::perfTyreTracInc); 
}

void Car::downgradeTyres() 
{ 
    m_performanceTyres = 0; 
    m_price -= PriceSpecs::perfTyreCost; 
    m_handling -= (m_oHandling * PriceSpecs::perfTyreHandleInc); 
    m_traction -= (m_oTraction * PriceSpecs::perfTyreTracInc);
}

void Car::addCarbonFibre() 
{ 
    m_carbonFibre = 1; 
    m_price += PriceSpecs::carbFibreCost; 
    m_weight -= (m_oWeight * PriceSpecs::carbFibreWeightDec); 
    m_speed += (m_oSpeed * PriceSpecs::carbFibreSpeecInc); 
}

void Car::removeCarbonFibre() 
{ 
    m_carbonFibre = 0; 
    m_price -= PriceSpecs::carbFibreCost; 
    m_weight += (m_oWeight * PriceSpecs::carbFibreWeightDec); 
    m_speed -= (m_oSpeed * PriceSpecs::carbFibreSpeecInc); 
}

void Car::addSpoiler() 
{ 
    m_spoiler = 1; 
    m_price += PriceSpecs::spoilerCost; 
    m_weight += (m_oWeight * PriceSpecs::spoilerWeightInc); 
    m_traction += (m_oTraction * PriceSpecs::spoilerTractInc); 
}

void Car::removeSpoiler() 
{ 
    m_spoiler = 0; 
    m_price -= PriceSpecs::spoilerCost; 
    m_weight -= (m_oWeight * PriceSpecs::spoilerWeightInc); 
    m_traction -= (m_oTraction * PriceSpecs::spoilerTractInc); 
}

void Car::addRacingStripes() 
{ 
    m_racingStripes = 1; 
    m_price += PriceSpecs::racingStripeCost; 
    m_speed += (m_oSpeed * PriceSpecs::racingStripeSpeedInc); 
}

void Car::removeRacingStripes() 
{ 
    m_racingStripes = 0; 
    m_price -= PriceSpecs::racingStripeCost; 
    m_speed -= (m_oSpeed * PriceSpecs::racingStripeSpeedInc); 
}

void Car::setColour(std::string_view colour) { m_colour = colour; }

void Car::resetCar()
{
    if (m_upgradedEngine == 1)
        downgradeEngine();
    if (m_performanceTyres == 1)
        downgradeTyres();
    if (m_carbonFibre == 1)
        removeCarbonFibre();
    if (m_spoiler == 1)
        removeSpoiler();
    if (m_racingStripes == 1)
        removeRacingStripes();
    
    setColour("black");
}

