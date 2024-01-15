#include "parser.h"

namespace s21 {

Parser::Parser() : cnt_vertexes_(0), cnt_polygons_(0) {}

Parser::~Parser() {}

void Parser::OpenFile(const std::string& filename) {
  Clean();
  file_.open(filename);
  if (file_.is_open()) {
    ReadFile();
    file_.close();
  } else {
    throw std::logic_error("File is not open");
  }
}

void Parser::ReadFile() {
  std::string reading_str;
  while (!file_.eof()) {
    std::getline(file_, reading_str);
    std::string_view str = reading_str;
    if (str.find("v ") == 0) {
      cnt_vertexes_++;
      VertexArray(str);
      array_of_vertexes_.push_back(struct_vertex_);
    }
    if (str.find("f ") == 0) {
      cnt_polygons_++;
      PolygonArray(str);
      array_of_polygons_.push_back(vector_of_polygons_);
      vector_of_polygons_.clear();
    }
  }
}

void Parser::VertexArray(std::string_view str) {
  int number_cols = 0;
  for (size_t i = 0; i < str.size(); i++) {
    if ((std::isdigit(str[i]) || str[i] == '-') && str[i - 1] == ' ' &&
        number_cols < 4) {
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
  float result = std::stod(number);
  if (number_cols == 1)
    struct_vertex_.x = result;
  else if (number_cols == 2)
    struct_vertex_.y = result;
  else if (number_cols == 3)
    struct_vertex_.z = result;
  FindMinMaxVertex(number_cols, result);
}

void Parser::FindMinMaxVertex(int number_cols, float val) {
  if (number_cols == 1) {
    range_.x_max = std::max(val, range_.x_max);
    range_.x_min = std::min(val, range_.x_min);
  } else if (number_cols == 2) {
    range_.y_max = std::max(val, range_.y_max);
    range_.y_min = std::min(val, range_.y_min);
  } else if (number_cols == 3) {
    range_.z_max = std::max(val, range_.z_max);
    range_.z_min = std::min(val, range_.z_min);
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
    result = cnt_vertexes_ + result + 1;
  }
  vector_of_polygons_.push_back(result);
}

void Parser::Clean() {
  cnt_vertexes_ = 0;
  cnt_polygons_ = 0;
  array_of_vertexes_.clear();
  array_of_polygons_.clear();
  range_.x_min = 0;
  range_.x_max = 0;
  range_.y_min = 0;
  range_.y_max = 0;
  range_.z_min = 0;
  range_.z_max = 0;
}

};  // namespace s21
