#include "affine.h"

namespace s21 {

Affine::Affine() : matrix_(new S21Matrix(1, 3)) {}

Affine::~Affine() {
  if (matrix_) delete matrix_;
}

void Affine::MovingX(double a) {
  for (int i = 1; i <= matrix_->GetRows(); ++i) (*matrix_)(i, 1) += a;
}

void Affine::MovingY(double a) {
  for (int i = 1; i <= matrix_->GetRows(); ++i) (*matrix_)(i, 2) += a;
}

void Affine::MovingZ(double a) {
  for (int i = 1; i <= matrix_->GetRows(); ++i) (*matrix_)(i, 3) += a;
}

void Affine::RotationX(double a) {
  double temp_y = (*matrix_)(1, 2);
  double temp_z = (*matrix_)(1, 3);
  for (int i = 1; i <= matrix_->GetRows(); ++i) {
    temp_y = (*matrix_)(i, 2);
    temp_z = (*matrix_)(i, 3);
    (*matrix_)(i, 2) = std::cos(a) * temp_y - std::sin(a) * temp_z;
    (*matrix_)(i, 3) = std::sin(a) * temp_y + std::cos(a) * temp_z;
  }
}

void Affine::RotationY(double a) {
  double temp_x = (*matrix_)(1, 1);
  double temp_z = (*matrix_)(1, 3);
  for (int i = 1; i <= matrix_->GetRows(); ++i) {
    temp_x = (*matrix_)(i, 1);
    temp_z = (*matrix_)(i, 3);
    (*matrix_)(i, 1) = std::cos(a) * temp_x + std::sin(a) * temp_z;
    (*matrix_)(i, 3) = -std::sin(a) * temp_x + std::cos(a) * temp_z;
  }
}
void Affine::RotationZ(double a) {
  double temp_x = (*matrix_)(1, 1);
  double temp_y = (*matrix_)(1, 2);
  for (int i = 1; i <= matrix_->GetRows(); ++i) {
    temp_x = (*matrix_)(i, 1);
    temp_y = (*matrix_)(i, 2);
    (*matrix_)(i, 1) = std::cos(a) * temp_x - std::sin(a) * temp_y;
    (*matrix_)(i, 2) = std::sin(a) * temp_x + std::cos(a) * temp_y;
  }
}

void Affine::Scaling(double a) { *matrix_ *= a; }

}  // namespace s21
