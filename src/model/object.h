#ifndef CPP4_3DVIEWER_V2_0_1_SRC_OBJECT_H_
#define CPP4_3DVIEWER_V2_0_1_SRC_OBJECT_H_

#include <iostream>

//  ХРАНИМ ДАННЫЕ В УДОБНЫХ СТРУКТУРАХ
/**
 * @brief Структура данных вершин объекта
 * @param coords указатель на массив координат вершин ([i] - X, [i+1] - Y, [i+2] - Z)
 * @param x_min величина минимального значения по оси Х
 * @param x_max величина максимального значения по оси X
 * @param y_min величина минимального значения по оси Y
 * @param y_max величина максимального значения по оси Y
 * @param z_min величина минимального значения по оси Z
 * @param z_max величина максимального значения по оси Z
 */
typedef struct vertex_t {
  float* coords;
  float x_min;
  float x_max;
  float y_min;
  float y_max;
  float z_min;
  float z_max;
} vertex_struct;

/**
 * @brief Структура данных граней объекта
 * @param f_indices указатель на массив индексов вершин грани
 * @param cnt_indices количество вершин грани
 */
typedef struct facet_t {
  unsigned int* f_indices;
  unsigned int cnt_indices;
} facet_struct;

/**
 * @brief Структура данных для смещений от начального положения
 * @param moveX смещение по оси X
 * @param moveY смещение по оси Y
 * @param moveZ смещение по оси Z
 * @param rotateX угол поворота по оси X
 * @param rotateY угол поворота по оси Y
 * @param rotateZ угол поворота по оси Z
 */
typedef struct position_t {
  float moveX;
  float moveY;
  float moveZ;
  float rotateX;
  float rotateY;
  float rotateZ;
  float scale_ratio;
} position_struct;


//  САМ КЛАСС НАШЕЙ ОТКРЫТОЙ МОДЕЛЬКИ

namespace s21 {
class ObjectModel {
    public:
        ObjectModel();
        ~ObjectModel();

//  private:
        int cnt_facets;
        int cnt_vertex;
        facet_struct* facets;   //  массив структур: массив флоат и количество (если будут неравномерные полигоны, типо в одном указано 3, а в другом 10)
        vertex_struct vertex;   //  тут хранятся вершины, мин-макс
        position_struct position_;  //  тут хранятся смещения

};
};  // namespace s21


#endif  //  CPP4_3DVIEWER_V2_0_1_SRC_OBJECT_H_
