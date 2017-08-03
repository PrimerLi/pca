#include <cassert>
#include <vector>
#include <iostream>
#include "Vector.hpp"

struct Eigenstruct;

class Matrix
{
private:
    int row;
    int col;
    std::vector<std::vector<double> > matrix;
public:
    Matrix() {}
    explicit Matrix(const std::vector<std::vector<double> > &parameter);
    Matrix(int row, int col);
    Matrix(const Matrix &parameter);
    const Matrix & operator= (const Matrix &parameter);
    ~Matrix();
    int getRow() const;
    int getCol() const;
    Matrix operator* (const Matrix &parameter) const;
    Matrix operator* (double scale) const;
    Vector operator* (const Vector &parameter) const;
    Matrix operator+ (const Matrix &parameter) const;
    Matrix operator- (const Matrix &parameter) const;
    double operator() (int i, int j) const;
    double & operator() (int i, int j);
    Matrix transpose() const;
    double trace() const;
    std::vector<Matrix> QR() const;
    std::vector<double> eigenvalues(double eps = 1.0e-16) const;
    Eigenstruct eigensystem(double eps = 1.0e-16) const;
    void print() const;
    friend std::ostream & operator<< (std::ostream &os, const Matrix &parameter);
};

struct Eigenstruct
{
    int dimension;
    std::vector<double> eigenvalues;
    Matrix O;
    Eigenstruct(int dimension, const std::vector<double> &eigenvalues, const Matrix &O)
    {
        this->dimension = dimension;
        assert(dimension > 0);
        assert(dimension == eigenvalues.size());
        assert(dimension == O.getRow());
        assert(dimension == O.getCol());
        for (int i = 0; i < dimension; ++i)
        {
            this->eigenvalues.push_back(eigenvalues[i]);
        }
        this->O = O;
    }
};