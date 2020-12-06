//
// Created by Harrison Hu on 2020/11/30.
//
#ifndef HW4_MATRIX_H
#define HW4_MATRIX_H
#include <iostream>
class matrix {
private:
    int col;
    int row;
    float **pMatrix;
public:
    matrix();
    matrix(int colNum,int rowNum);
    matrix(int colNum, int rowNum,float value);
    matrix(const matrix& copy);
    ~matrix();
    matrix operator + (const matrix& matrix2);
    matrix operator - (const matrix& matrix2);
    matrix operator * (float num);
    matrix operator * (const matrix& matrix2);
    matrix operator = (const matrix& matrix2);
    friend matrix operator *(float num,const matrix& matrix2);
    friend std::ostream & operator << (std::ostream &os, const matrix &matrix2);
    void setmember(int m, int n, float val);
    inline void alloc(int colNum, int rowNum);
    void setCol(int i);
    void setRow(int i);
};


#endif //HW4_MATRIX_H
