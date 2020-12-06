//
// Created by Harrison Hu on 2020/11/30.
//

#include "matrix.h"
#include <iostream>
using namespace std;

matrix::matrix() {

}

matrix::matrix(int colNum, int rowNum) {
    col = colNum;
    row = rowNum;
    if (colNum < 0)
        cout << "Error!The column of matrix can't be negative" << endl;
    else if (rowNum < 0)
        cout << "Error!The row of matrix can't be negative！" << endl;
    else {
        alloc(col, row);
        for (int i = 0; i < rowNum; i++)
            for (int j = 0; j < colNum; j++)
                pMatrix[i][j] = 0;
    }
}

matrix::matrix(int colNum, int rowNum,float value) {
    col = colNum;
    row = rowNum;
    if (colNum < 0)
        cout << "Error!The column of matrix can't be negative" << endl;
    else if (rowNum < 0)
        cout << "Error!The row of matrix can't be negative！" << endl;
    else {
        alloc(col, row);
        for (int i = 0; i < rowNum; i++)
            for (int j = 0; j < colNum; j++)
                pMatrix[i][j] = value;
    }
}

matrix::matrix(const matrix &copy) {
    col = copy.col;
    row = copy.row;
    alloc(col, row);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            this->pMatrix[i][j] = copy.pMatrix[i][j];
        }
    }
}

matrix::~matrix() {
    for (int i = 0; i < row; ++i) {
        delete[] pMatrix[i];
    }
    delete[] pMatrix;
}

matrix matrix::operator+(const matrix &matrix2) {
    matrix result;
    if ((this->col == matrix2.col) && (this->row == matrix2.row))
    {
        result.alloc(col, row);
        result.setCol(col);
        result.setRow(row);
        for (int i = 0; i < this->row; i++)
        {
            for (int j = 0; j < this->col; j++)
            {
                result.pMatrix[i][j] = this->pMatrix[i][j] + matrix2.pMatrix[i][j];
            }
        }
        return result;
    }
    else
    {
        cout << "Two matrices cannot be added！" << endl;
    }
}

matrix matrix::operator-(const matrix &matrix2) {
    matrix result;
    if ((this->col == matrix2.col) && (this->row == matrix2.row))
    {
        result.alloc(col, row);
        result.setCol(col);
        result.setRow(row);
        for (int i = 0; i < this->row; i++)
        {
            for (int j = 0; j < this->col; j++)
            {
                result.pMatrix[i][j] = this->pMatrix[i][j] - matrix2.pMatrix[i][j];
            }
        }
        return result;
    }
    else
    {
        cout << "Two matrices cannot be subtracted！" << endl;
    }
}

matrix matrix::operator*(float num) {
    for (int i = 0; i < this->row; i++)
    {
        for (int j = 0; j < this->col; j++)
        {
            this->pMatrix[i][j] = this->pMatrix[i][j] * num;
        }
    }
    return *this;
}

matrix operator *(float num,const matrix& matrix2){
    for (int i = 0; i < matrix2.row; i++)
    {
        for (int j = 0; j < matrix2.col; j++)
        {
            matrix2.pMatrix[i][j] = matrix2.pMatrix[i][j] * num;
        }
    }
    return matrix2;
}

matrix matrix::operator*(const matrix &matrix2) {
    matrix result{ matrix2.col,this->row };
    if (this->col == matrix2.row)
    {
        for (int i = 0; i < this->row; i++)
        {
            for (int j = 0; j < matrix2.col; j++)
            {
                for (int k = 0; k < matrix2.row; k++)
                {
                    result.pMatrix[i][j] += this->pMatrix[i][k] * matrix2.pMatrix[k][j];
                }
            }
        }
        return result;
    }
    else
    {
        cout << "Two matrices cannot be multiplied！" << endl;
    }
}

matrix matrix::operator=(const matrix &matrix2) {
    if (this != &matrix2)
    {
        delete[] pMatrix;
        col = matrix2.col;
        row = matrix2.row;
        alloc(col, row);
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                this->pMatrix[i][j] = matrix2.pMatrix[i][j];
            }
        }
    }
    return *this;
}

std::ostream &operator<<(ostream &os, const matrix &matrix2) {
    for (int i = 0; i < matrix2.row; i++)
    {
        for (int j = 0; j < matrix2.col; j++)
        {
            cout << matrix2.pMatrix[i][j] << "  ";
        }
        cout << endl;
    }
    return os;
}

void matrix::setmember(int m, int n, float val)
{
    if (m>=0&&n>=0&&m<this->row&&n<this->col){
        pMatrix[m][n] = val;
    }
    else
    {
        cout << "Error" << endl;
    }
}

void matrix::alloc(int colNum, int rowNum) {
    pMatrix = (float **)malloc(sizeof(float*)*rowNum);
    for (int i = 0; i < rowNum; i++)
    {
        pMatrix[i] = (float *)malloc(sizeof(float)*colNum);
    }
}

void matrix::setCol(int i) {
    this->col=i;
}

void matrix::setRow(int i) {
    this->row=i;
}

