
#include "Array.h"

void Array::add(std::unique_ptr<Figure> figure){
    figures.push_back(std::move(figure));
}

Figure* Array::getFigure(size_t index) const {
    if (index >= figures.size())
        throw std::out_of_range("Incorrect index");
    return figures[index].get();
}

void Array::remove(size_t index){
    if (index >= figures.size())
        throw std::out_of_range("Incorrect index");
    figures.erase(figures.begin() + index);
}

size_t Array::size() const{
    return figures.size();
}

double Array::totalArea() const{
    double res = 0;
    for (const auto& f: figures)
        res += f->area();
    return res;
}

void Array::printAll(std::ostream& os) const{
    for (size_t i = 0; i < figures.size(); i++){
        os << "Figure " << i << ": " << *figures[i] << std::endl;
    }
}

Array::Array(const Array& other){
    figures.reserve(other.figures.size());
    for(const auto& f: other.figures){
        figures.push_back(std::unique_ptr<Figure>(f->copy()));
    }
}

Array& Array::operator=(const Array& other){
    if (this != &other){
        figures.clear();
        figures.reserve(other.figures.size());
        for(const auto& f: other.figures){
            figures.push_back(std::unique_ptr<Figure>(f->copy()));
        }
    }
    return *this;
}

Array::Array(Array&& other) noexcept: figures(std::move(other.figures)){}

Array& Array::operator=(Array&& other){
    if (this != &other)
        figures = std::move(other.figures);
    return *this;
}








