
#include "trapezoid.h"
#include <cmath>

Trap::Trap(const std::array<std::pair<double, double>, 4>& v) : vertices(v){}

std::pair<double, double> Trap::center() const {
    double x = 0, y = 0;
    for (const auto& v: vertices){
        x += v.first;
        y += v.second;
    }
    return {x / 4, y / 4};
}

double Trap::area() const {
    double x1 = 0, x2 = 0;

    for (int i = 0; i < 4; i++){
        int j = (i + 1) % 4;
        x1 +=vertices[i].first * vertices[j].second;
        x2 += vertices[j].first * vertices[i].second;
    }
    return std::fabs(x1 - x2) / 2.0;
}

void Trap::print(std::ostream& os) const{
    os << "Trapezoid: ";
    for (const auto& v: vertices){
        os << "(" << v.first << ", " << v.second << " )";
    }
}

void Trap::read(std::istream& is){
    for (int i = 0; i < 4; i++){
        double x, y;
        if (!(is >> x >> y)){
            throw std::runtime_error("Error input for trapezoid");
        }
        vertices[i] = {x, y};
    }
}

Trap::Trap(const Trap& other) : vertices(other.vertices){}

Trap& Trap::operator=(const Trap& other){
    if (this != &other)
        vertices = other.vertices;
    return *this;
}

Trap::Trap(Trap&& other) noexcept : vertices(std::move(other.vertices)){}

Trap& Trap::operator=(Trap&& other) noexcept{
    if (this != &other)
        vertices = std::move(other.vertices);
    return *this;
}

bool Trap::operator==(const Figure& other) const{
    const Trap* otherTrap = dynamic_cast<const Trap*>(&other);
    if (!otherTrap) return false;
    return vertices == otherTrap->vertices;
}

Figure* Trap::copy() const{
    return new Trap(*this);
}

















