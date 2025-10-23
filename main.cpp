#include <iostream>
#include <memory>
#include "Trap/trapezoid.h"
#include "Square/square.h"
#include "Rect/rectangle.h"
#include "Array/Array.h"

void printMenu() {
    std::cout << "\n=== Figures ===" << std::endl;
    std::cout << "1. Add Trapezoid" << std::endl;
    std::cout << "2. Add Square" << std::endl;
    std::cout << "3. Add Rectangle" << std::endl;
    std::cout << "4. Print All Figures" << std::endl;
    std::cout << "5. Remove Figure" << std::endl;
    std::cout << "6. Calculate Total Area" << std::endl;
    std::cout << "7. Print Figure Center" << std::endl;
    std::cout << "8. Exit" << std::endl;
    std::cout << "Choose option: ";
}

int main() {
    Array figures;
    int choice;
    
    while (true) {
        printMenu();
        std::cin >> choice;
        
        try {
            switch (choice) {
                case 1: {
                    std::cout << "Enter 4 vertices (x1 y1 x2 y2 x3 y3 x4 y4): ";
                    auto trapezoid = std::make_unique<Trap>();
                    std::cin >> *trapezoid;
                    figures.add(std::move(trapezoid));
                    std::cout << "Trapezoid added successfully!" << std::endl;
                    break;
                }
                case 2: {
                    std::cout << "Enter 4 vertices (x1 y1 x2 y2 x3 y3 x4 y4): ";
                    auto square = std::make_unique<Square>();
                    std::cin >> *square;
                    figures.add(std::move(square));
                    std::cout << "Square added successfully!" << std::endl;
                    break;
                }
                case 3: {
                    std::cout << "Enter 4 vertices (x1 y1 x2 y2 x3 y3 x4 y4): ";
                    auto rectangle = std::make_unique<Rect>();
                    std::cin >> *rectangle;
                    figures.add(std::move(rectangle));
                    std::cout << "Rectangle added successfully!" << std::endl;
                    break;
                }
                case 4: {
                    std::cout << "\nAll Figures:" << std::endl;
                    figures.printAll(std::cout);
                    break;
                }
                case 5: {
                    std::cout << "Enter index to remove: ";
                    size_t index;
                    std::cin >> index;
                    figures.remove(index);
                    std::cout << "Figure removed successfully!" << std::endl;
                    break;
                }
                case 6: {
                    double total = figures.totalArea();
                    std::cout << "Total area of all figures: " << total << std::endl;
                    break;
                }
                case 7: {
                    std::cout << "Enter figure index: ";
                    size_t index;
                    std::cin >> index;
                    Figure* figure = figures.getFigure(index);
                    auto center = figure->center();
                    std::cout << "Center: (" << center.first << ", " << center.second << ")" << std::endl;
                    break;
                }
                case 8: {
                    std::cout << "Exit..." << std::endl;
                    return 0;
                }
                default: {
                    std::cout << "Invalid option!" << std::endl;
                    break;
                }
            }
        } catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
    
    return 0;
}