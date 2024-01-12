#include "test.h"

TEST(Parser, test_1) {
  s21::Parser pars;
  std::string filename = "test/obj_test_file/cube.obj";
  pars.OpenFile(filename);

  EXPECT_EQ(pars.GetVertexes(), 8);
  EXPECT_EQ(pars.GetPolygons(), 12);

  std::string filename_2 = "test/obj_test_file/Wolf_obj.obj";
  pars.OpenFile(filename_2);

  EXPECT_EQ(pars.GetVertexes(), 1690);
  EXPECT_EQ(pars.GetPolygons(), 1566);
}

TEST(Parser, test_2) {
  s21::Parser pars;
  std::string filename = "nofile.obj";

  EXPECT_ANY_THROW(pars.OpenFile(filename));
}

TEST(Parser, test_3) {
  s21::Parser pars;
  S21Matrix m(4, 3);
  m(1, 1) = -0.55;
  m(1, 2) = 0.67;
  m(1, 3) = 0.15;
  m(2, 1) = 0.53;
  m(2, 2) = 0.5;
  m(2, 3) = 0.43;
  m(3, 1) = 0.93;
  m(3, 2) = -0.57;
  m(3, 3) = 0.78;
  m(4, 1) = -0.45;
  m(4, 2) = -0.35;
  m(4, 3) = 0.11;
  std::vector<std::vector<int>> p;
  std::vector<int> pol = {1, 2, 3};
  p.push_back(pol);
  pol.clear();
  pol = {2, 3, 1, 4};
  p.push_back(pol);
  std::string filename = "test/obj_test_file/test_parcer.txt";
  pars.OpenFile(filename);

  EXPECT_EQ(pars.GetVertexes(), 4);
  EXPECT_EQ(pars.GetPolygons(), 2);
  EXPECT_TRUE(m.EqMatrix(pars.GetMatrixVertexes()));
  std::vector<std::vector<int>> polygons = pars.GetArrayPolygons();
  for (auto i = 0; i < 2; i++) {
    EXPECT_TRUE(polygons[i] == p[i]);
  }
}
