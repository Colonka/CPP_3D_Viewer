#include "object.h"

namespace s21 {

ObjectModel::ObjectModel() {
    cnt_vertex = 0;
    cnt_facets = 0;
    facets = NULL;
    vertex.coords = NULL;


    //  ПРОСТО ПРИМЕР :
    vertex.coords = new float[24]{
        0.5, 0.5, -0.5,
        0.5, -0.5, -0.5,
        1.000000, 1.000000, 1.000000,
        1.000000, -1.000000, 1.000000,
        -1.000000, 1.000000, -1.000000,
        -1.000000, -1.000000, -1.000000,
        -1.000000, 1.000000, 1.000000,
        -1.000000, -1.000000, 1.000000};
    cnt_vertex = 8;

    //


    std::cout << "OBJECT CONSTRUCTED\n";
}


ObjectModel::~ObjectModel() {
  //  delete ...;
}


};  // namespace s21
