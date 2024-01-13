#include "parser.h"

#include <cmath>
#include <iomanip>
// int main() {
//   s21::Parser pars;
//   std::string filename = "../obj_file/cube.obj";
//   pars.OpenFile(filename);
//   return 0;
// }

namespace s21 {

Parser::Parser()
    : vertexes_(0),
      polygons_(0),
      matrix_of_vertexes_(new S21Matrix(1, 3)),
      x_min_(0),
      x_max_(0),
      y_min_(0),
      y_max_(0),
      z_min_(0),
      z_max_(0) {}

Parser::~Parser() {
  if (matrix_of_vertexes_) delete matrix_of_vertexes_;
}

void Parser::OpenFile(const std::string& filename) {
  Clean();
  file_.open(filename);
  if (file_.is_open()) {
    std::cout << "file open"
              << "\n";
    ReadFile();
    file_.close();
  } else {
    std::cout << "file is non opened"
              << "\n";
    throw std::logic_error("File is not open");
  }
}

void Parser::ReadFile() {
  std::string reading_str;
  while (!file_.eof()) {
    std::getline(file_, reading_str);
    std::string_view str = reading_str;
    if (str.find("v ") == 0) {
      vertexes_++;
      matrix_of_vertexes_->SetRows(vertexes_);
      VertexArray(str);
      // std::cout << "\n";
    }
    if (str.find("f ") == 0) {
      polygons_++;
      PolygonArray(str);
      array_of_polygons_.push_back(vector_of_poligons_);
      vector_of_poligons_.clear();
      // std::cout << "\n";
    }
  }
}

void Parser::VertexArray(std::string_view str) {
  int number_cols = 0;
  for (size_t i = 0; i < str.size(); i++) {
    if ((std::isdigit(str[i]) || str[i] == '-') && str[i - 1] == ' ') {
      number_cols++;
      PushVertexPoint(str, &i, number_cols);
    }
  }
}

void Parser::PushVertexPoint(std::string_view str, size_t* pos,
                             int number_cols) {
  std::string number;
  size_t iter = *pos;
  while (std::isdigit(str[iter]) || str[iter] == '.' || str[iter] == '-') {
    number += str[iter];
    iter++;
  }
  *pos = iter;
  double result = std::stold(number);
  // std::cout << std::fixed << std::setprecision(6) << result << " ";
  (*matrix_of_vertexes_)(vertexes_, number_cols) = result;
  FindMinMaxVertex(number_cols, result);
}

void Parser::FindMinMaxVertex(int number_cols, double val) {
  if (number_cols == 1) {
    if (val > x_max_) x_max_ = val;
    if (val < x_min_) x_min_ = val;
  } else if (number_cols == 2) {
    if (val > y_max_) y_max_ = val;
    if (val < y_min_) y_min_ = val;
  } else if (number_cols == 3) {
    if (val > z_max_) z_max_ = val;
    if (val < z_min_) z_min_ = val;
  }
}

void Parser::PolygonArray(std::string_view str) {
  for (size_t i = 0; i < str.size(); i++) {
    if ((std::isdigit(str[i]) || str[i] == '-') && str[i - 1] == ' ') {
      PushPoligonPoint(str, &i);
    }
  }
}

void Parser::PushPoligonPoint(std::string_view str, size_t* pos) {
  std::string number;
  size_t iter = *pos;
  while (std::isdigit(str[iter]) || str[iter] == '-') {
    number += str[iter];
    iter++;
  }
  *pos = iter;
  int result = std::stoi(number);
  if (result < 0) {
    result = vertexes_ + result + 1;
  }
  vector_of_poligons_.push_back(result);
  // std::cout << result << " ";
}

void Parser::Clean() {
  vertexes_ = 0;
  polygons_ = 0;
  matrix_of_vertexes_->SetRows(1);
  matrix_of_vertexes_->SetAnyNum(0);
  x_min_ = 0;
  x_max_ = 0;
  y_min_ = 0;
  y_max_ = 0;
  z_min_ = 0;
  z_max_ = 0;
  array_of_polygons_.clear();
}

};  // namespace s21
