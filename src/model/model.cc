#include "model.h"

namespace s21 {
Model::Model() : parser_(new Parser), affine_(new Affine) {}

Model::~Model() {
  if (parser_) delete parser_;
  if (affine_) delete affine_;
}

void Model::load(const std::string& filename) { parser_->OpenFile(filename); }
}  // namespace s21