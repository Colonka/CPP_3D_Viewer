#ifndef CPP4_3DVIEWER_V2_0_1_SRC_MODEL_MODEL_H_
#define CPP4_3DVIEWER_V2_0_1_SRC_MODEL_MODEL_H_

#include <string>

#include "affine.h"
#include "parser.h"

namespace s21 {
class Model {
 public:
  Model();
  ~Model();

  void load(const std::string& filename);

 private:
  Parser* parser_;
  Affine* affine_;
};
};  // namespace s21

#endif  //  CPP4_3DVIEWER_V2_0_1_SRC_MODEL_MODEL_H_