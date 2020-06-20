#ifndef __QS_MATRIX_H
#define __QS_MATRIX_H

#include <vector>
#include <iostream>

template<typename T>
class QSMatrix {
private:
    T** storage;
    unsigned rows;
    unsigned cols;
    void clear_storage(T **storage, int rows);
public:
    template<typename J>
    friend std::ostream &operator<<(std::ostream &out, const QSMatrix<J> &mat);

    template<typename J>
    friend std::istream &operator>>(std::istream &in, QSMatrix<J> &mat);

    QSMatrix(unsigned _rows, unsigned _cols, const T &_initial);

    QSMatrix(const QSMatrix<T> &rhs);

    virtual ~QSMatrix();

    // Перегрузка оператора, для «стандартных» операций с математической матрицей
    QSMatrix<T> &operator=(const QSMatrix<T> &rhs);

    // Матричные математические операцииs
    QSMatrix<T> operator+(const QSMatrix<T> &rhs);

    QSMatrix<T> operator*(const QSMatrix<T> &rhs);

    QSMatrix<T> &operator*=(const QSMatrix<T> &rhs);

    QSMatrix<T> RandomSet();

    // матричные операции
    QSMatrix<T> operator+(const T &rhs);

    QSMatrix<T> operator*(const T &rhs);

    // Векторные операции
    T* operator*(const T* rhs);

    // Доступ к отдельным элементам
    T &operator()(const unsigned &row, const unsigned &col);

    const T &operator()(const unsigned &row, const unsigned &col) const;

    // Доступ к размерам строк и столбцов
    unsigned get_rows() const;

    unsigned get_cols() const;
};

#include "matrix.cpp"

#endif