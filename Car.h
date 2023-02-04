#ifndef CAR_H
#define CAR_H

//Car class - make, model, colour, accessories. Price against each that sums total cost
//object for each model - accessories change m_speed, m_handling etc (and m_cost)
#include <string>

class Car
{
private:
    //used to generate IDs for the car objects
    static inline int s_uniqueID{ 1 };
    int m_id{};
    
    //fixed values per object
    const std::string m_make{};
    const std::string m_model{};
    
    //car specs - variable based on customisation
    //oValues are "original" and used to reset the car when removing options
    double m_price{};

    double m_speed{};
    double m_handling{};
    double m_weight{};
    double m_acceleration{};
    double m_traction{};

    double m_oPrice{};

    double m_oSpeed{};
    double m_oHandling{};
    double m_oWeight{};
    double m_oAcceleration{};
    double m_oTraction{};
    
    //customisable options
    std::string m_colour{ "black" };
    bool m_carbonFibre{ 0 };
    bool m_performanceTyres{ 0 };
    bool m_spoiler{ 0 };
    bool m_racingStripes{ 0 };
    bool m_upgradedEngine{ 0 };


public:
    //constructor
    Car(std::string make, std::string model, double price, double speed, double handling, double weight,
        double acceleration, double traction)
            : m_id { s_uniqueID++ } //grab uniqueID and increment
            , m_make{ make }
            , m_model{ model }
            , m_price{ price }, m_oPrice{ price }
            , m_speed{ speed }, m_oSpeed{ speed }
            , m_handling{ handling }, m_oHandling{ handling }
            , m_weight{ weight }, m_oWeight{ weight }
            , m_acceleration{ acceleration }, m_oAcceleration{ acceleration }
            , m_traction{ traction }, m_oTraction{ traction }
        {
        }   

    //get member variables
    int getID() { return m_id; }
    double getPrice() { return m_price; }
    std::string getMake() { return m_make; }
    std::string getModel() { return m_model; }
    double getSpeed() { return m_speed; }
    double getHandling() { return m_handling; }
    double getWeight() { return m_weight; }
    double getAccel() { return m_acceleration; }
    double getTraction() { return m_traction; }
    std::string getColour() { return m_colour; }
    
    //forward declarations for functions defined in Car.cpp
    void printCar();
    void printCustoms();
    void printFullCar();

    void upgradeEngine();
    void downgradeEngine();
    
    void upgradeTyres();
    void downgradeTyres();
    
    void addCarbonFibre();
    void removeCarbonFibre();
    
    void addSpoiler();
    void removeSpoiler();
    
    void addRacingStripes();
    void removeRacingStripes();
    
    void setColour(std::string_view colour);

    void resetCar();
};

#endif