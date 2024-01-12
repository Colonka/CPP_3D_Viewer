#ifndef S21_MATRIX_H_
#define S21_MATRIX_H_

#include <stdlib.h>

#include <cmath>
#include <iostream>
#include <stdexcept>
#include <utility>

class S21Matrix {
 public:
  // Constructor
  S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other) noexcept;

  // Assignment operators
  S21Matrix& operator=(const S21Matrix& other);
  S21Matrix& operator=(S21Matrix&& other) noexcept;

  // Destructor
  ~S21Matrix();

  // operator
  S21Matrix operator+(const S21Matrix& other);
  S21Matrix operator-(const S21Matrix& other);
  S21Matrix operator*(const S21Matrix& other);
  S21Matrix operator*(const double num);
  bool operator==(const S21Matrix& other) noexcept;
  S21Matrix& operator+=(const S21Matrix& other);
  S21Matrix& operator-=(const S21Matrix& other);
  S21Matrix& operator*=(const S21Matrix& other);
  S21Matrix& operator*=(const double num) noexcept;
  double& operator()(int i, int j);
  friend S21Matrix operator*(const double num, S21Matrix& other);

  // Function (matrix operation)
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  bool EqMatrix(const S21Matrix& other) noexcept;
  void MulNumber(const double num) noexcept;
  void MulMatrix(const S21Matrix& other);
  S21Matrix Transpose();
  S21Matrix CalcComplements();
  double Determinant();
  S21Matrix InverseMatrix();
  int GetRows() const;
  int GetCols() const;
  void SetRows(int value);
  void SetCols(int value);
  void SwapRows(int row_max);
  S21Matrix& MatrixMinor();
  S21Matrix GetMatrixWithoutRowAndCol(int i, int j);
  void SetAnyNum(double num) noexcept;
  void SetRundomNum();

  void print_matrix() {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        std::cout << matrix_[i][j];
      }
      std::cout << "\n";
    }
  };

 private:
  // Attributes
  int rows_,
      cols_;         // Rows and columns
  double** matrix_;  // Pointer to the memory where the matrix is allocated
};

#endif  // S21_MATRIX_H_
