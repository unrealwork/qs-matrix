#ifndef __QS_MATRIX_CPP
#define __QS_MATRIX_CPP
#include "matrix.h"
#include <iostream>
// Конструктоор с параметром                                                                                                                                                 
template<typename T>
QSMatrix<T>::QSMatrix(unsigned _rows, unsigned _cols, const T& _initial) {
    mat.resize(_rows);
    for (unsigned i = 0; i<mat.size(); i++) {
        mat[i].resize(_cols, _initial);
    }
    rows = _rows;
    cols = _cols;
}

// Конструктор копирования                                                                                                                                                
template<typename T>
QSMatrix<T>::QSMatrix(const QSMatrix<T>& rhs) {
    mat = rhs.mat;
    rows = rhs.get_rows();
    cols = rhs.get_cols();
}

// Деструктор                                                                                                                                                      
template<typename T>
QSMatrix<T>::~QSMatrix() {}

//перегруженный оператор вывода
template<typename J>
std::ostream& operator<< (std::ostream &out, const QSMatrix<J> &mat)
{
    for (unsigned i = 0; i < mat.get_rows(); i++) {
        for (unsigned j = 0; j < mat.get_cols(); j++) {
            out << mat(i, j) << ", ";
        }
        out << std::endl;
    }
    return out;
}
//перегруженный оператор ввода
template<typename J>
std::istream& operator>> (std::istream &in, QSMatrix<J> &mat)
{
    for (unsigned i = 0; i < mat.get_rows(); i++)
    {
        for (unsigned j = 0; j < mat.get_cols(); j++)
        {
            in >> mat(i, j);
        }
    }
    return in;
}

// Оператор присваивания                                                                                                                                                      
template<typename T>
QSMatrix<T>& QSMatrix<T>::operator=(const QSMatrix<T>& rhs) {
    if (&rhs == this)
        return *this;

    unsigned new_rows = rhs.get_rows();
    unsigned new_cols = rhs.get_cols();

    mat.resize(new_rows);
    for (unsigned i = 0; i<mat.size(); i++) {
        mat[i].resize(new_cols);
    }

    for (unsigned i = 0; i<new_rows; i++) {
        for (unsigned j = 0; j<new_cols; j++) {
            mat[i][j] = rhs(i, j);
        }
    }
    rows = new_rows;
    cols = new_cols;

    return *this;
}

// Сложение двух матриц (добавление)                                                                                                                                            
template<typename T>
QSMatrix<T> QSMatrix<T>::operator+(const QSMatrix<T>& rhs) {
    QSMatrix result(rows, cols, 0.0);

    for (unsigned i = 0; i<rows; i++) {
        for (unsigned j = 0; j<cols; j++) {
            result(i, j) = this->mat[i][j] + rhs(i, j);
        }
    }

    return result;
}

// Левое умножение матрицы н                                                                                                                           
template<typename T>
QSMatrix<T> QSMatrix<T>::operator*(const QSMatrix<T>& rhs) {
    unsigned rows = rhs.get_rows();
    unsigned cols = rhs.get_cols();
    QSMatrix result(rows, cols, 0.0);

    for (unsigned i = 0; i<rows; i++) {
        for (unsigned j = 0; j<cols; j++) {
            for (unsigned k = 0; k<rows; k++) {
                result(i, j) += this->mat[i][k] * rhs(k, j);
            }
        }
    }

    return result;
}

// Суммарное умножение                                                                                                                  
template<typename T>
QSMatrix<T>& QSMatrix<T>::operator*=(const QSMatrix<T>& rhs) {
    QSMatrix result = (*this) * rhs;
    (*this) = result;
    return *this;
}

// Матричное скалярное сложение                                                                                                                                                 
template<typename T>
QSMatrix<T> QSMatrix<T>::operator+(const T& rhs) {
    QSMatrix result(rows, cols, 0.0);

    for (unsigned i = 0; i<rows; i++) {
        for (unsigned j = 0; j<cols; j++) {
            result(i, j) = this->mat[i][j] + rhs;
        }
    }

    return result;
}

// Матричное / скалярное умножение                                                                                                                                       
template<typename T>
QSMatrix<T> QSMatrix<T>::operator*(const T& rhs) {
    QSMatrix result(rows, cols, 0.0);

    for (unsigned i = 0; i<rows; i++) {
        for (unsigned j = 0; j<cols; j++) {
            result(i, j) = this->mat[i][j] * rhs;
        }
    }

    return result;
}

// Умножим матрицу на вектор                                                                                                                                       
template<typename T>
std::vector<T> QSMatrix<T>::operator*(const std::vector<T>& rhs) {
    std::vector<T> result(rhs.size(), 0.0);

    for (unsigned i = 0; i<rows; i++) {
        for (unsigned j = 0; j<cols; j++) {
            result[i] = this->mat[i][j] * rhs[j];
        }
    }

    return result;
}

// Доступ к отдельным элементам                                                                                                                                         
template<typename T>
T& QSMatrix<T>::operator()(const unsigned& row, const unsigned& col) {
    return this->mat[row][col];
}

// Доступ к отдельным элементам (const)                                                                                                                                  
template<typename T>
const T& QSMatrix<T>::operator()(const unsigned& row, const unsigned& col) const {
    return this->mat[row][col];
}

// Получить количество строк матрицы                                                                                                                                    
template<typename T>
unsigned QSMatrix<T>::get_rows() const {
    return this->rows;
}

// Получить количество столбцов матрицы
template<typename T>
unsigned QSMatrix<T>::get_cols() const {
    return this->cols;
}
//Заполняем матрицу рандомными двузначными числами
template<typename T>
QSMatrix<T> QSMatrix<T>::RandomSet() {
    QSMatrix result(rows, cols, 0.0);

    for (unsigned i = 0; i<rows; i++) {
        for (unsigned j = 0; j<cols; j++) {
            result(i,j) = rand()%100;
        }
    }
    return result;
}
#endif