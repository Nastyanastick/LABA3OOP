
#include "../Figure/Figure.h"
#include <array>


class Rect : public Figure{

private:
    std::array <std::pair<double, double>, 4> vertices;
public:
    Rect() = default;
    Rect(const std::array<std::pair<double, double>, 4>& v);

    std::pair<double, double> center() const override; //возвращает центр квадрата
    double area() const override; 
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;

    Rect(const Rect& other); //копирование
    Rect& operator = (const Rect& other);
    Rect(Rect&& other) noexcept; //перемещение
    Rect& operator=(Rect&& other) noexcept;

    bool operator==(const Figure& other) const override;
    Figure* copy() const override;

};