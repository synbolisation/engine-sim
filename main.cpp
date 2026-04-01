#include <iostream>
#include <cmath>

struct EngineConfig {
    int cylinders; // Number of Cylinders expressed as whole in
    double bore; // Size of Bore, represented in millimetres
    double stroke; // Size of Stroke, represented in millimetres
    double compratio; // Compression Ratio, represented as decimal. E.g 10.5 = 10.5:1
    int redline; // Redline RPM represented by a whole int
    int idle; // Idle RPM expressed as whole int
    double displacement; // Engine size calculated to decimal Number
    double totaldisplacement;
    double thermalefficiency;
    double horsepower;
};

double calculateDisplacement(double bore, double stroke) { // Calculates displacement for each cylinder. Uses equation: PI * (bore/1000)^2 * stroke
    double displacement = M_PI * std::pow(((bore / 1000.0) / 2),2) * (stroke / 1000.0);
    displacement = displacement * 1000000;
    return displacement;
}

double totalDisplacement(double bore, double stroke, int cylinders) {
    return calculateDisplacement(bore,stroke) * cylinders;
}

double calculateThermalEfficiency(double compratio, double gamma = 1.4) {
    return 1 - (1.0 / std::pow(compratio,gamma - 1.0));
}

double calculateHorsepower(double totaldisplacement, double compratio, int RPM, int cylinders, double gamma = 1.4) {
    double airVolume = totaldisplacement / 1000000.0;
    double airDensity = 1.225;
    double airMass = airVolume * airDensity;
    std::cout << airMass << std::endl;
    double airfuelratio = 14.7;
    double fuelMass = airMass / airfuelratio;
    std::cout << fuelMass << std::endl;
    double calorificValue = 44000000.0;
    double fuelEnergy = fuelMass * calorificValue;
    std::cout << fuelEnergy << std::endl;
    double usefulWork = fuelEnergy * calculateThermalEfficiency(compratio, gamma);
    std::cout << usefulWork << std::endl;


    double cyclesPerSecond = (RPM / 2) / 60.0;
    std::cout << cyclesPerSecond << std::endl;
    double wattPower = usefulWork * cyclesPerSecond;
    std::cout << wattPower << std::endl;
    double horsepower = wattPower / 745.7;
    std::cout << horsepower << std::endl;

    return horsepower;

}


int main() {
    EngineConfig car1;
    car1.cylinders = 4;
    car1.bore = 86;
    car1.stroke = 86;
    car1.compratio = 10.5;
    car1.redline = 7000;
    car1.idle = 800;
    car1.thermalefficiency = calculateThermalEfficiency(car1.compratio);

    car1.displacement = calculateDisplacement(car1.bore, car1.stroke);
    car1.totaldisplacement = totalDisplacement(car1.bore, car1.stroke, car1.cylinders);
    car1.horsepower = calculateHorsepower(car1.totaldisplacement, car1.compratio, car1.redline, car1.cylinders);



    std::cout << "==== Engine Configuration ====" << std::endl;
    std::cout << "Cylinders: " << car1.cylinders << std::endl;
    std::cout << "Bore: " << car1.bore << "mm" << std::endl;
    std::cout << "Stroke: " << car1.stroke << "mm" << std::endl;
    std::cout << "Compression Ratio: " << car1.compratio << ":1" << std::endl;
    std::cout << "Redline RPM: " << car1.redline << std::endl;
    std::cout << "Idle RPM: " << car1.idle << std::endl;
    std::cout << "Displacement per Cylinder: " << car1.displacement << "cc" << std::endl;
    std::cout << "Total Displacement: " << car1.totaldisplacement << "cc" << std::endl;

    std::cout << car1.thermalefficiency << std::endl;
    std::cout << car1.horsepower << "hp" << std::endl;
}
