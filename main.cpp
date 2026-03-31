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
};

double calculateDisplacement(double bore, double stroke) { // Calculates displacement for each cylinder. Uses equation: PI * (bore/1000)^2 * stroke
    double displacement = M_PI * std::pow(((bore / 1000.0) / 2),2) * (stroke / 1000.0);
    displacement = displacement * 1000000;
    return displacement;
}

double totalDisplacement(double bore, double stroke, int cylinders) {
    return calculateDisplacement(bore,stroke) * cylinders;
}


int main() {
    EngineConfig car1;
    car1.cylinders = 4;
    car1.bore = 86;
    car1.stroke = 86;
    car1.compratio = 10.5;
    car1.redline = 7000;
    car1.idle = 800;

    car1.displacement = calculateDisplacement(car1.bore, car1.stroke);
    car1.totaldisplacement = totalDisplacement(car1.bore, car1.stroke, car1.cylinders);

    std::cout << "==== Engine Configuration ====" << std::endl;
    std::cout << "Cylinders: " << car1.cylinders << std::endl;
    std::cout << "Bore: " << car1.bore << "mm" << std::endl;
    std::cout << "Stroke: " << car1.stroke << "mm" << std::endl;
    std::cout << "Compression Ratio: " << car1.compratio << ":1" << std::endl;
    std::cout << "Redline RPM: " << car1.redline << std::endl;
    std::cout << "Idle RPM: " << car1.idle << std::endl;
    std::cout << "Displacement per Cylinder: " << car1.displacement << "cc" << std::endl;
    std::cout << "Total Displacement: " << car1.totaldisplacement << "cc" << std::endl;
}
