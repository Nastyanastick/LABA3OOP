
#include "rectangle.h"
#include <cmath>


Rect::Rect(const std::array<std::pair<double, double>, 4>& v) : vertices(v){}

std::pair<double, double> Rect::center() const {
    double x = 0, y = 0;
    for (const auto& v: vertices){
        x += v.first;
        y += v.second;
    }
    return {x / 4, y / 4};
}

double Rect::area() const {
    double side1 = std::sqrt(std::pow(vertices[1].first - vertices[0].first, 2) +
        std::pow(vertices[1].second - vertices[0].second, 2));
        //соседняя сторона
    double side2 = std::sqrt(std::pow(vertices[2].first - vertices[1].first, 2) +
        std::pow(vertices[2].second - vertices[1].second, 2));
    return side1 * side2;
}

void Rect::print(std::ostream& os) const{
    os << "Rectangle: ";
    for (const auto& v: vertices){
        os << "(" << v.first << ", " << v.second << " )";
    }
}

void Rect::read(std::istream& is){
    for (int i = 0; i < 4; i++){
        double x, y;
        if (!(is >> x >> y)){
            throw std::runtime_error("Error input for rectangle");
        }
        vertices[i] = {x, y};
    }
}

Rect::Rect(const Rect& other) : vertices(other.vertices){}

Rect& Rect::operator=(const Rect& other){
    if (this != &other)
        vertices = other.vertices;
    return *this;
}

Rect::Rect(Rect&& other) noexcept : vertices(std::move(other.vertices)){}

Rect& Rect::operator=(Rect&& other) noexcept{
    if (this != &other)
        vertices = std::move(other.vertices);
    return *this;
}

bool Rect::operator==(const Figure& other) const{
    const Rect* otherRect = dynamic_cast<const Rect*>(&other);
    if (!otherRect) return false;
    return vertices == otherRect->vertices;
}

Figure* Rect::copy() const{
    return new Rect(*this);
}


