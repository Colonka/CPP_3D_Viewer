#ifndef CPP4_3DVIEWER_V2_0_1_SRC_MODEL_PARSER_H_
#define CPP4_3DVIEWER_V2_0_1_SRC_MODEL_PARSER_H_

#include <fstream>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

#include "../libs/s21_matrix.h"

namespace s21 {
class Parser {
 public:
  using polygon_t = std::vector<std::vector<int>>;

  Parser();
  ~Parser();

  void OpenFile(std::string filename);  // Подумать как искл организовать
  void ReadFile();  //  подумай отправить в приват

  int GetVertexes() { return vertexes_; }
  int GetPolygons() { return polygons_; }
  S21Matrix GetMatrixVertexes() { return *matrix_of_vertexes_; }
  polygon_t GetArrayPolygons() { return array_of_polygons_; }

 private:
  std::ifstream file_;
  int vertexes_;
  int polygons_;
  S21Matrix* matrix_of_vertexes_;
  std::vector<int> vector_of_poligons_;
  polygon_t array_of_polygons_;
  double x_min_, x_max_;
  double y_min_, y_max_;
  double z_min_, z_max_;

  void PolygonArray(std::string_view str);
  void PushPoligonPoint(std::string_view str, size_t* pos);
  void VertexArray(std::string_view str);
  void PushVertexPoint(std::string_view str, size_t* pos, int number_cols);
  void FindMinMaxVertex(int number_cols, double val);
  void Clean();
};
};  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_1_SRC_MODEL_PARSER_H_