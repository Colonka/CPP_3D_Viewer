#include "s21_matrix.h"

S21Matrix::S21Matrix() : rows_(0), cols_(0), matrix_(nullptr) {}

S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
  if (rows < 0 || cols < 0) {
    throw std::logic_error("invalid matrix");
  } else if (rows_ == 0 || cols_ == 0) {
    matrix_ = nullptr;
  } else {
    matrix_ = new double* [rows_] { 0 };
    for (int i = 0; i < rows_; i++) {
      try {
        matrix_[i] = new double[cols_]{0};
      } catch (...) {
        for (int j = 0; j < i; j++) delete[] matrix_[j];
        delete[] matrix_;
        throw;
      }
    }
  }
}

S21Matrix::~S21Matrix() {
  for (int i = 0; i < rows_; i++) {
    delete[] matrix_[i];
  }
  delete[] matrix_;
  rows_ = 0;
  cols_ = 0;
}

S21Matrix::S21Matrix(const S21Matrix& other)
    : rows_(other.rows_), cols_(other.cols_) {
  if (rows_ == 0 || cols_ == 0) {
    matrix_ = nullptr;
  } else {
    matrix_ = new double* [rows_] { 0 };
    for (int i = 0; i < rows_; i++) {
      try {
        matrix_[i] = new double[cols_]{0};
      } catch (...) {
        for (int j = 0; j < i; j++) delete[] matrix_[j];
        delete[] matrix_;
        throw;
      }
    }
  }
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }
}

S21Matrix::S21Matrix(S21Matrix&& other) noexcept {
  rows_ = other.rows_;
  cols_ = other.cols_;
  matrix_ = other.matrix_;
  other.matrix_ = nullptr;
  other.rows_ = 0;
  other.cols_ = 0;
}

int S21Matrix::GetRows() const { return rows_; }

int S21Matrix::GetCols() const { return cols_; }

void S21Matrix::SetRows(int value) {
  if (value < 0) {
    throw std::logic_error("wrong value");
  } else if (rows_ != value) {
    S21Matrix result(value, cols_);
    for (int i = 0; i < result.rows_; i++) {
      for (int j = 0; j < result.cols_; j++) {
        if (i + 1 > rows_) {
          result.matrix_[i][j] = 0;
        } else {
          result.matrix_[i][j] = matrix_[i][j];
        }
      }
    }
    *this = std::move(result);
  }
}

void S21Matrix::SetCols(int value) {
  if (value < 0) {
    throw std::logic_error("wrong value");
  } else if (cols_ != value) {
    S21Matrix result(rows_, value);
    for (int i = 0; i < result.rows_; i++) {
      for (int j = 0; j < result.cols_; j++) {
        if (j + 1 > cols_) {
          result.matrix_[i][j] = 0;
        } else {
          result.matrix_[i][j] = matrix_[i][j];
        }
      }
    }
    *this = std::move(result);
  }
}

bool S21Matrix::EqMatrix(const S21Matrix& other) noexcept {
  if (rows_ != other.rows_ || cols_ != other.cols_) return false;
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      if (std::fabs(matrix_[i][j] - other.matrix_[i][j]) > 1e-06) {
        return false;
      }
    }
  }
  return true;
}

void S21Matrix::SumMatrix(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::logic_error("different matrix dimensions");
  }
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = matrix_[i][j] + other.matrix_[i][j];
    }
  }
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::logic_error("different matrix dimensions");
  }
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = matrix_[i][j] - other.matrix_[i][j];
    }
  }
}

void S21Matrix::MulNumber(const double num) noexcept {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = matrix_[i][j] * num;
    }
  }
}

void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (cols_ != other.rows_)
    throw std::logic_error(
        "the number of columns of the first matrix is not equal to the number "
        "of rows of the second matrix");
  S21Matrix result(rows_, other.cols_);
  for (int i = 0; i < result.rows_; i++) {
    for (int j = 0; j < result.cols_; j++) {
      for (int e = 0; e < cols_; e++) {
        result.matrix_[i][j] += matrix_[i][e] * other.matrix_[e][j];
      }
    }
  }
  *this = std::move(result);
}

S21Matrix S21Matrix::Transpose() {
  S21Matrix result(cols_, rows_);
  for (int i = 0; i < result.rows_; i++) {
    for (int j = 0; j < result.cols_; j++) {
      result.matrix_[i][j] = matrix_[j][i];
    }
  }
  return result;
}

double S21Matrix::Determinant() {
  if (rows_ != cols_) throw std::logic_error("the matrix is not square");
  double result = 1;
  if (rows_ == 0) return result = 0;
  S21Matrix tmp(*this);
  int row_max = 0;
  for (int i = 1; i < rows_; i++) {
    if (std::fabs(tmp.matrix_[i][0]) > std::fabs(tmp.matrix_[0][0]))
      row_max = i;
  }
  if (row_max != 0) {
    tmp.SwapRows(row_max);
    result *= -1;
  }
  for (int i = 0; i < cols_; i++) {
    for (int j = i + 1; j < rows_; j++) {
      for (int e = i + 1; e < cols_; e++) {
        tmp.matrix_[j][e] +=
            tmp.matrix_[i][e] * (-tmp.matrix_[j][i] / tmp.matrix_[i][i]);
      }
      tmp.matrix_[j][i] +=
          tmp.matrix_[i][i] * (-tmp.matrix_[j][i] / tmp.matrix_[i][i]);
    }
  }
  for (int i = 0; i < rows_; i++) {
    result *= tmp.matrix_[i][i];
  }
  return result;
}

S21Matrix S21Matrix::CalcComplements() {
  if (rows_ != cols_) throw std::logic_error("the matrix is not square");
  S21Matrix result(cols_, rows_);
  if (rows_ == 1) {
    result(1, 1) = 1;
    return result;
  }
  S21Matrix minor_matrix(cols_, rows_);
  minor_matrix.MatrixMinor();
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      result.matrix_[i][j] = pow(-1, i + j) * minor_matrix.matrix_[i][j];
    }
  }
  return result;
}

S21Matrix S21Matrix::InverseMatrix() {
  double determinant = Determinant();
  if (std::fabs(determinant) < 1e-06)
    throw std::logic_error("matrix determinant is 0");
  S21Matrix tmp_1(cols_, rows_);
  S21Matrix tmp_2(cols_, rows_);
  S21Matrix result(cols_, rows_);
  tmp_1 = CalcComplements();
  tmp_2 = tmp_1.Transpose();
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      result.matrix_[i][j] = tmp_2.matrix_[i][j] * (1 / determinant);
    }
  }
  return result;
}

S21Matrix S21Matrix::operator+(const S21Matrix& other) {
  S21Matrix result(*this);
  result.SumMatrix(other);
  return result;
}

S21Matrix S21Matrix::operator-(const S21Matrix& other) {
  S21Matrix result(*this);
  result.SubMatrix(other);
  return result;
}

S21Matrix S21Matrix::operator*(const S21Matrix& other) {
  S21Matrix result(*this);
  result.MulMatrix(other);
  return result;
}

S21Matrix S21Matrix::operator*(const double num) {
  S21Matrix result(*this);
  result.MulNumber(num);
  return result;
}

S21Matrix operator*(const double num, S21Matrix& other) {
  S21Matrix result(other);
  result.MulNumber(num);
  return result;
}

bool S21Matrix::operator==(const S21Matrix& other) noexcept {
  return EqMatrix(other);
}

S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
  if (!EqMatrix(other)) {
    S21Matrix copy(other);
    *this = std::move(copy);
  }
  return *this;
}

S21Matrix& S21Matrix::operator=(S21Matrix&& other) noexcept {
  for (int i = 0; i < rows_; i++) {
    delete[] matrix_[i];
  }
  delete[] matrix_;
  rows_ = other.rows_;
  cols_ = other.cols_;
  matrix_ = other.matrix_;
  other.matrix_ = nullptr;
  other.rows_ = 0;
  other.cols_ = 0;
  return *this;
}

S21Matrix& S21Matrix::operator+=(const S21Matrix& other) {
  SumMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator-=(const S21Matrix& other) {
  SubMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator*=(const S21Matrix& other) {
  MulMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator*=(const double num) noexcept {
  MulNumber(num);
  return *this;
}

double& S21Matrix::operator()(int i, int j) {
  if (i > rows_ || j > cols_ || i < 1 || j < 1) {
    throw std::logic_error("index is outside the matrix");
  }
  return matrix_[i - 1][j - 1];
}

void S21Matrix::SwapRows(int row_max) {
  S21Matrix tmp(*this);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      if (i == 0) matrix_[0][j] = matrix_[row_max][j];
      if (i == row_max) matrix_[row_max][j] = tmp.matrix_[0][j];
    }
  }
}

S21Matrix& S21Matrix::MatrixMinor() {
  S21Matrix tmp(cols_ - 1, rows_ - 1);
  double determinant = 0;
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      tmp = GetMatrixWithoutRowAndCol(i, j);
      determinant = tmp.Determinant();
      matrix_[i][j] = determinant;
    }
  }
  return *this;
}

S21Matrix S21Matrix::GetMatrixWithoutRowAndCol(int i, int j) {
  S21Matrix result(cols_ - 1, rows_ - 1);
  int shift_i = 0;
  int shift_j = 0;
  for (int n = 0; n < result.rows_; n++) {
    if (n == i) shift_i = 1;
    for (int m = 0; m < result.cols_; m++) {
      if (m == j) shift_j = 1;
      result.matrix_[n][m] = matrix_[n + shift_i][m + shift_j];
    }
    shift_j = 0;
  }
  return result;
}

void S21Matrix::SetAnyNum(double num) noexcept {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = num;
    }
  }
}

void S21Matrix::SetRundomNum() {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = rand() % 1000;
    }
  }
}
