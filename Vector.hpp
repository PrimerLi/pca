#include <vector>
#include <cassert>
#include <cmath>

class Vector
{
private:
    int length;
    std::vector<double> array;
public:
    Vector() {length = 0;}
    explicit Vector(int length);
    Vector(const Vector &parameter);
    int getLength() const;
    const Vector & operator= (const Vector &parameter);
    Vector operator* (double scale) const;
    double operator* (const Vector &parameter) const;
    Vector operator+ (const Vector &parameter) const;
    Vector operator- (const Vector &parameter) const;
    double norm() const;
    void normalize();
    double operator[] (int i) const;
    double & operator[] (int i);
    friend Vector operator* (double scale, const Vector &parameter);
};
