
#include "../Figure/Figure.h"
#include <memory>
#include <vector>

class Array{
private:
    std::vector<std::unique_ptr<Figure>> figures;
public:
    Array() = default;

    void add(std::unique_ptr<Figure> figure);

    Figure* getFigure(size_t index) const;

    void remove(size_t index);

    size_t size() const;

    double totalArea() const;

    void printAll(std::ostream& os) const;

    Array(const Array& other); //констр копирование
    Array& operator=(const Array& other);//оператор копирования
    Array(Array&& other) noexcept; //конструктор перемещения
    Array& operator=(Array&& other) noexcept; //оператор перемещения

};















