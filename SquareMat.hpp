#ifndef SQUAREMAT_HPP
#define SQUAREMAT_HPP

#include <iostream> 

class SquareMat {
private:
    int size;
    double** data; // 2D array to support matrix[i][j]

public:
    // Constructors & Destructor
    SquareMat(int n);                                  
    ~SquareMat();                                      

    // Element access
    double* operator[](int row);
    const double* operator[](int row) const;

    // Getters
    int getSize() const;

    // Arithmetic operators
    SquareMat operator+(const SquareMat& mat) const;
    SquareMat operator-(const SquareMat& mat) const;
    SquareMat operator*(const SquareMat& mat) const;       
    SquareMat operator*(double scalar) const;                   
    SquareMat operator/(double scalar) const;                   
    SquareMat operator%(int scalar) const;                      
    SquareMat operator^(int power) const;                       
    // Compound assignment
    SquareMat& operator+=(const SquareMat& mat);
    SquareMat& operator++();
    SquareMat& operator-=(const SquareMat& mat);
    SquareMat& operator--();
    SquareMat& operator*=(const SquareMat& mat);
    SquareMat& operator*=(double scalar);
    SquareMat& operator/=(double scalar);
    SquareMat& operator%=(int scalar);                          
    SquareMat& operator~();
    double operator!() const; 

    // Comparison
    bool operator==(const SquareMat& mat) const;
    bool operator!=(const SquareMat& mat) const;
    bool operator>(const SquareMat& mat) const;
    bool operator<(const SquareMat& mat) const;
    bool operator>=(const SquareMat& mat) const;
    bool operator<=(const SquareMat& mat) const;

    // I/O stream
    friend std::ostream& operator<<(std::ostream& os, const SquareMat& mat);

};

#endif 
