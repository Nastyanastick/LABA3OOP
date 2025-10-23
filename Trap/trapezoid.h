

#include "../Figure/Figure.h"
#include <array>

class Trap : public Figure{

private:
    std::array <std::pair<double, double>, 4> vertices;
public:
    Trap() = default;
    Trap(const std::array<std::pair<double, double>, 4>& v);

    std::pair<double, double> center() const override; //возвращает центр квадрата
    double area() const override; 
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;

    Trap(const Trap& other); //копирование
    Trap& operator = (const Trap& other);
    Trap(Trap&& other) noexcept; //перемещение
    Trap& operator=(Trap&& other) noexcept;

    bool operator==(const Figure& other) const override;
    Figure* copy() const override;

};