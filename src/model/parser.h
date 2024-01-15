#ifndef CPP4_3DVIEWER_V2_0_1_SRC_MODEL_PARSER_H_
#define CPP4_3DVIEWER_V2_0_1_SRC_MODEL_PARSER_H_

#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

namespace s21 {

struct Vertex {
  float x, y, z;
};

struct Range {
  float x_min, x_max;
  float y_min, y_max;
  float z_min, z_max;
};

class Parser {
 public:
  using polygon_t = std::vector<std::vector<int>>;

  Parser();
  ~Parser();

  void OpenFile(const std::string& filename);  // Подумать как искл организовать

  int GetVertexes() { return cnt_vertexes_; }
  int GetPolygons() { return cnt_polygons_; }
  const std::vector<Vertex>& GetArrayVertexes() { return array_of_vertexes_; }
  const polygon_t& GetArrayPolygons() { return array_of_polygons_; }
  Range GetRange() { return range_; }

 private:
  int cnt_vertexes_;                       // счетчик вершин
  int cnt_polygons_;                       // счетчик полигонов
  std::vector<Vertex> array_of_vertexes_;  // массив с координатами вершин
  polygon_t array_of_polygons_;  // массив с координатами полигонов
  Range range_;  // структура с максимумами и минимуми вершин
  std::ifstream file_;
  std::vector<int> vector_of_polygons_;
  Vertex struct_vertex_;

  void ReadFile();  //  подумай отправить в приват
  void PolygonArray(std::string_view str);
  void PushPoligonPoint(std::string_view str, size_t* pos);
  void VertexArray(std::string_view str);
  void PushVertexPoint(std::string_view str, size_t* pos, int number_cols);
  void FindMinMaxVertex(int number_cols, float val);
  void Clean();
};
};  // namespace s21

#endif  // CPP4_3DVIEWER_V2_0_1_SRC_MODEL_PARSER_H_