#include "Vector.hpp"

Vector::Vector(int length)
{
    this->length = length;
    for (int i = 0; i < length; ++i)
    {
        array.push_back(0);
    }
}

Vector::Vector(const Vector &parameter)
{
    length = parameter.length;
    for (int i = 0; i < length; ++i)
    {
        array.push_back(parameter.array[i]);
    }
}

int Vector::getLength() const
{
    return this->length;
}

const Vector& Vector::operator= (const Vector &parameter)
{
    array.clear();
    this->length = parameter.length;
    for (int i = 0; i < length; ++i)
    {
        array.push_back(parameter.array[i]);
    }
    return *this;
}

Vector Vector::operator* (double scale) const
{
    Vector result(length);
    for (int i = 0; i < length; ++i)
    {
        result.array[i] = array[i]*scale;
    }
    return result;
}

double Vector::operator* (const Vector &parameter) const
{
    double s = 0;
    assert(length == parameter.length);
    for (int i = 0; i < length; ++i)
        s = s + array[i]*parameter.array[i];
    return s;
}

Vector Vector::operator+ (const Vector &parameter) const
{
    Vector result(length);
    assert(length == parameter.length);
    for (int i = 0; i < length; ++i)
    {
        result.array[i] = array[i] + parameter.array[i];
    }
    return result;
}

Vector Vector::operator- (const Vector &parameter) const
{
    Vector result(length);
    assert(length == parameter.length);
    for (int i = 0; i < length; ++i)
    {
        result.array[i] = array[i] - parameter.array[i];
    }
    return result;
}

double Vector::norm() const
{
    assert(length > 0);
    double s = 0;
    for (int i = 0; i < length; ++i)
    {
        s = s + array[i]*array[i];
    }
    return sqrt(s);
}

void Vector::normalize()
{
    assert(length > 0);
    double normOfVector = norm();
    assert(normOfVector > 0);
    for (int i = 0; i < length; ++i)
    {
        array[i] = array[i]/normOfVector;
    }
}

double Vector::operator[] (int i) const
{
    assert(i >= 0 && i < length);
    return array[i];
}

double& Vector::operator[] (int i)
{
    assert(i >= 0 && i < length);
    return array[i];
}

Vector operator* (double scale, const Vector &parameter)
{
    Vector result(parameter.length);
    for (int i = 0; i < parameter.length; ++i)
    {
        result.array[i] = scale*parameter.array[i];
    }
    return result;
}