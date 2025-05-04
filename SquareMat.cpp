
#include "SquareMat.hpp"
        SquareMat::SquareMat(int n) : size(n) {
            data = new double*[size];
            for (int i = 0; i < size; ++i)
                data[i] = new double[size](); 
        }
    
        SquareMat::~SquareMat() {
            for (int i = 0; i < size; ++i)
                delete[] data[i];
            delete[] data;
        }
    
        int SquareMat::getSize() const { return size; }
    
        double* SquareMat::operator[](int row) {
            return data[row]; 
        }
    
        const double* SquareMat::operator[](int row) const {
            return data[row];
        }
        


        SquareMat SquareMat::operator+(const SquareMat& mat) const
        {
            if(mat.getSize()!=size)
                throw std::invalid_argument("Matrix sizes dont match!");

            SquareMat result(size);
            for(int i=0;i<size;i++)
                for(int j=0;j<size;j++)
                    result[i][j]=data[i][j]+mat[i][j];

            return result;
        }

        SquareMat SquareMat::operator-(const SquareMat& mat) const
        {
            if(mat.getSize()!=size)
                throw std::invalid_argument("Matrix sizes dont match!");

            SquareMat result(size);
            for(int i=0;i<size;i++)
                for(int j=0;j<size;j++)
                    result[i][j]=data[i][j]-mat[i][j];

            return result;
        }
        SquareMat SquareMat::operator*(double scalar) const
        {
            SquareMat result(size);
            for(int i=0;i<size;i++)
                for(int j=0;j<size;j++)
                    result[i][j]=data[i][j]*scalar;

            return result;
        }
        SquareMat SquareMat::operator*(const SquareMat& mat) const{
            if (size != mat.getSize())
                throw std::invalid_argument("Matrix sizes dont match!");
        
            SquareMat result(size);
        
            for (int i=0;i<size;i++)
                for (int j=0;j<size;i++)
                    for (int k=0;k<size;k++)
                        result[i][j] += data[i][k] * mat[k][j];
        
            return result;
        }
        SquareMat SquareMat::operator^(int exponent) const {
            if (exponent < 0)
                throw std::invalid_argument("Negative exponents not supported!");
        
            SquareMat result(size);
            for (int i = 0; i < size; ++i)
                result[i][i] = 1;  // identity
        
            if (exponent == 0)
                return result;
        
            SquareMat base = *this;
            while (exponent > 0) {
                result=result*base;
                exponent--;
            }
        
            return result;
        }
        
        SquareMat SquareMat::operator/(double scalar) const
        {
            SquareMat result(size);
            for(int i=0;i<size;i++)
                for(int j=0;j<size;j++)
                    result[i][j]=data[i][j]/scalar;

            return result;
        }
        SquareMat SquareMat::operator%(int scalar) const
        {
            SquareMat result(size);
            for(int i=0;i<size;i++)
                for(int j=0;j<size;j++)
                    result[i][j]= (int)data[i][j] % scalar;

            return result;
        }
        SquareMat& SquareMat::operator+=(const SquareMat& mat)
        {
            if(mat.getSize()!=size)
                throw std::invalid_argument("Matrix sizes dont match!");

            for(int i=0;i<size;i++)
                for(int j=0;j<size;j++)
                    data[i][j]+=mat[i][j];

            return *this;
        }
        SquareMat& SquareMat::operator-=(const SquareMat& mat)
        {
            if(mat.getSize()!=size)
                throw std::invalid_argument("Matrix sizes dont match!");

            for(int i=0;i<size;i++)
                for(int j=0;j<size;j++)
                    data[i][j]-=mat[i][j];

            return *this;
        }
        SquareMat& SquareMat::operator*=(double scalar)
        {

            for(int i=0;i<size;i++)
                for(int j=0;j<size;j++)
                    data[i][j]*=scalar;

            return *this;
        }
        SquareMat& SquareMat::operator*=(const SquareMat& other) {
            *this = *this * other;
            return *this;
        }
        
        SquareMat& SquareMat::operator/=(double scalar)
        {

            for(int i=0;i<size;i++)
                for(int j=0;j<size;j++)
                    data[i][j]/=scalar;

            return *this;
        }
        SquareMat& SquareMat::operator%=(int scalar)
        {

            for(int i=0;i<size;i++)
                for(int j=0;j<size;j++)
                    data[i][j] = (int)data[i][j] % scalar;

            return *this;
        }
        SquareMat& SquareMat::operator~() {
            for (int i = 0; i < size; ++i)
                for (int j = 0; j < size; ++j)
                    data[j][i] = data[i][j];

            return *this;
        }
        
        SquareMat& SquareMat::operator++()
        {
            *this+=1;
        }
        SquareMat& SquareMat::operator--()
        {
            *this-=1;
        }
        double SquareMat::operator!() const {
            if (size == 1)
                return data[0][0];
        
            if (size == 2)
                return data[0][0] * data[1][1] - data[0][1] * data[1][0];
        
            double det = 0;
            for (int col = 0; col < size; ++col) {
                SquareMat minor(size - 1);
                for (int i = 1; i < size; ++i) {
                    int minorCol = 0;
                    for (int j = 0; j < size; ++j) {
                        if (j == col) continue;
                        minor[i - 1][minorCol++] = data[i][j];
                    }
                }
                double cofactor = (col % 2 == 0 ? 1 : -1) * data[0][col];
                det += cofactor * !minor;
            }
            return det;
        }
        bool SquareMat::operator==(const SquareMat& mat) const{
            double sum=0;
            for(int i=0;i<size;i++)
                for(int j=0;j<size;j++)
                {
                    sum+=data[i][j];
                }
            for(int i=0;i<mat.getSize();i++)
                for(int j=0;j<mat.getSize();j++)
                {
                    sum-=data[i][j];
                }
            return sum==0;
        }
        bool SquareMat::operator>=(const SquareMat& mat) const{
            double sum=0;
            for(int i=0;i<size;i++)
                for(int j=0;j<size;j++)
                {
                    sum+=data[i][j];
                }
            for(int i=0;i<mat.getSize();i++)
                for(int j=0;j<mat.getSize();j++)
                {
                    sum-=data[i][j];
                }
            return sum>=0;
        }
        bool SquareMat::operator<=(const SquareMat& mat) const{
            double sum=0;
            for(int i=0;i<size;i++)
                for(int j=0;j<size;j++)
                {
                    sum+=data[i][j];
                }
            for(int i=0;i<mat.getSize();i++)
                for(int j=0;j<mat.getSize();j++)
                {
                    sum-=data[i][j];
                }
            return sum<=0;
        }
        bool SquareMat::operator>(const SquareMat& mat) const{
            double sum=0;
            for(int i=0;i<size;i++)
                for(int j=0;j<size;j++)
                {
                    sum+=data[i][j];
                }
            for(int i=0;i<mat.getSize();i++)
                for(int j=0;j<mat.getSize();j++)
                {
                    sum-=data[i][j];
                }
            return sum>0;
        }
        bool SquareMat::operator<(const SquareMat& mat) const{
            double sum=0;
            for(int i=0;i<size;i++)
                for(int j=0;j<size;j++)
                {
                    sum+=data[i][j];
                }
            for(int i=0;i<mat.getSize();i++)
                for(int j=0;j<mat.getSize();j++)
                {
                    sum-=data[i][j];
                }
            return sum<0;
        }
        bool SquareMat::operator!=(const SquareMat& mat) const{
            double sum=0;
            for(int i=0;i<size;i++)
                for(int j=0;j<size;j++)
                {
                    sum+=data[i][j];
                }
            for(int i=0;i<mat.getSize();i++)
                for(int j=0;j<mat.getSize();j++)
                {
                    sum-=data[i][j];
                }
            return sum!=0;
        }
        std::ostream& operator<<(std::ostream& os,const SquareMat& mat) {
            
            for (int i = 0; i < mat.getSize(); ++i) {
                for (int j = 0; j < mat.getSize(); ++j)
                    os << mat[i][j] << ' ';
                os << '\n';
            }
            return os;
        }
    