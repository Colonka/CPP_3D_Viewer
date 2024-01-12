#ifndef CPP4_3DVIEWER_V2_0_1_SRC_MODEL_AFFINE_H_
#define CPP4_3DVIEWER_V2_0_1_SRC_MODEL_AFFINE_H_

#include <cmath>

#include "../libs/s21_matrix.h"

namespace s21 {
class Affine {
 public:
  Affine();
  ~Affine();

  void MovingX(double a);
  void MovingY(double a);
  void MovingZ(double a);

  void RotationX(double a);
  void RotationY(double a);
  void RotationZ(double a);

  void Scaling(double a);

  int GetRows() const { return matrix_->GetRows(); }
  int GetCols() const {
    return matrix_->GetCols();
  }  //  А нужно ли под вопросом
  S21Matrix GetMatrix() { return *matrix_; }
  void SetMatrix(S21Matrix other) { *matrix_ = other; }

 private:
  S21Matrix* matrix_;
};
};  // namespace s21

#endif  //  CPP4_3DVIEWER_V2_0_1_SRC_MODEL_AFFINE_H_