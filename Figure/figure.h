#ifndef FIGURE_H
#define FIGURE_H

#include <utility>
#include <iostream>
//вариант 34


class Figure{
public:
    virtual ~Figure() = default; //чтобы не было утечек памяти после удаления

    virtual std::pair <double, double> center() const = 0;

    virtual double area() const = 0; //площадь

    virtual void print(std::ostream& os) const = 0;
    virtual void read(std::istream& is) = 0;

    virtual operator double() const {return area();}

    virtual Figure* copy() const = 0;
    virtual bool operator == (const Figure& other) const = 0;
};

std::ostream& operator << (std::ostream& os, const Figure& figure);
std::istream& operator >> (std::istream& is, Figure& figure);

#endif