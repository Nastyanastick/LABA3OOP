
#include "../Figure/Figure.h"
#include <array>


class Square : public Figure{

private:
    std::array <std::pair<double, double>, 4> vertices;
public:
    Square() = default;
    Square(const std::array<std::pair<double, double>, 4>& v);

    std::pair<double, double> center() const override; //возвращает центр квадрата
    double area() const override; 
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;

    Square(const Square& other); //копирование
    Square& operator = (const Square& other);
    Square(Square&& other) noexcept; //перемещение
    Square& operator=(Square&& other) noexcept;

    bool operator==(const Figure& other) const override;
    Figure* copy() const override;

};