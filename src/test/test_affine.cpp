#include "test.h"

TEST(Affine, moving) {
  s21::Parser pars;
  std::string filename = "test/obj_test_file/cube.obj";
  pars.OpenFile(filename);

  s21::Affine aff;

  aff.SetMatrix(pars.GetMatrixVertexes());
  std::array<double, 8> expect_array_x = {3.000000, 3.000000, 1.000000,
                                          1.000000, 3.000000, 2.999999,
                                          1.000000, 1.000000};
  std::array<double, 8> expect_array_y = {3.500000, 3.500000, 3.500000,
                                          3.500000, 5.500000, 5.500000,
                                          5.500000, 5.500000};
  std::array<double, 8> expect_array_z = {-4.000000, -2.000000, -2.000000,
                                          -4.000000, -3.999999, -1.999999,
                                          -2.000000, -4.000000};

  aff.MovingX(2);
  aff.MovingY(4.5);
  aff.MovingZ(-3);
  for (auto i = 0; i < aff.GetRows(); i++) {
    EXPECT_NEAR(expect_array_x[i], (aff.GetMatrix())(i + 1, 1), 1e-6);
    EXPECT_NEAR(expect_array_y[i], (aff.GetMatrix())(i + 1, 2), 1e-6);
    EXPECT_NEAR(expect_array_z[i], (aff.GetMatrix())(i + 1, 3), 1e-6);
  }
}

TEST(Affine, rotation_x) {
  s21::Parser pars;
  std::string filename = "test/obj_test_file/cube.obj";
  pars.OpenFile(filename);

  s21::Affine aff;

  aff.SetMatrix(pars.GetMatrixVertexes());
  std::array<double, 8> expect_array_y = {1.325444,  -0.493151, -0.493151,
                                          1.325444,  0.493150,  -1.325445,
                                          -1.325444, 0.493151};

  std::array<double, 8> expect_array_z = {-0.493151, -1.325444, -1.325444,
                                          -0.493151, 1.325444,  0.493150,
                                          0.493151,  1.325444};

  aff.RotationX(2);
  ;
  for (auto i = 0; i < aff.GetRows(); i++) {
    EXPECT_NEAR(expect_array_y[i], (aff.GetMatrix())(i + 1, 2), 1e-6);
    EXPECT_NEAR(expect_array_z[i], (aff.GetMatrix())(i + 1, 3), 1e-6);
  }
}

TEST(Affine, rotation_y) {
  s21::Parser pars;
  std::string filename = "test/obj_test_file/cube.obj";
  pars.OpenFile(filename);

  s21::Affine aff;

  aff.SetMatrix(pars.GetMatrixVertexes());
  std::array<double, 8> expect_array_x = {-1.325444, 0.493151,  1.325444,
                                          -0.493151, -1.325443, 0.493152,
                                          1.325444,  -0.493151};

  std::array<double, 8> expect_array_z = {-0.493151, -1.325444, 0.493151,
                                          1.325444,  -0.493151, -1.325444,
                                          0.493151,  1.325444};

  aff.RotationY(2);

  for (auto i = 0; i < aff.GetRows(); i++) {
    EXPECT_NEAR(expect_array_x[i], (aff.GetMatrix())(i + 1, 1), 1e-6);
    EXPECT_NEAR(expect_array_z[i], (aff.GetMatrix())(i + 1, 3), 1e-6);
  }
}

TEST(Affine, rotation_z) {
  s21::Parser pars;
  std::string filename = "test/obj_test_file/cube.obj";
  pars.OpenFile(filename);

  s21::Affine aff;

  aff.SetMatrix(pars.GetMatrixVertexes());
  std::array<double, 8> expect_array_x = {0.493151,  0.493151,  1.325444,
                                          1.325444,  -1.325444, -1.325444,
                                          -0.493151, -0.493151};
  std::array<double, 8> expect_array_y = {1.325444,  1.325444, -0.493151,
                                          -0.493151, 0.493151, 0.493150,
                                          -1.325444, -1.325444};

  aff.RotationZ(2);

  for (auto i = 0; i < aff.GetRows(); i++) {
    EXPECT_NEAR(expect_array_x[i], (aff.GetMatrix())(i + 1, 1), 1e-6);
    EXPECT_NEAR(expect_array_y[i], (aff.GetMatrix())(i + 1, 2), 1e-6);
  }
}

TEST(Affine, scaling) {
  s21::Parser pars;
  std::string filename = "test/obj_test_file/cube.obj";
  pars.OpenFile(filename);

  s21::Affine aff;

  aff.SetMatrix(pars.GetMatrixVertexes());
  std::array<double, 8> expect_array_x = {2.000000,  2.000000, -2.000000,
                                          -2.000000, 2.000000, 1.999998,
                                          -2.000000, -2.000000};
  std::array<double, 8> expect_array_y = {-2.000000, -2.000000, -2.000000,
                                          -2.000000, 2.000000,  2.000000,
                                          2.000000,  2.000000};
  std::array<double, 8> expect_array_z = {-2.000000, 2.000000,  2.000000,
                                          -2.000000, -1.999998, 2.000002,
                                          2.000000,  -2.000000};

  aff.Scaling(2);
  for (auto i = 0; i < aff.GetRows(); i++) {
    EXPECT_NEAR(expect_array_x[i], (aff.GetMatrix())(i + 1, 1), 1e-6);
    EXPECT_NEAR(expect_array_y[i], (aff.GetMatrix())(i + 1, 2), 1e-6);
    EXPECT_NEAR(expect_array_z[i], (aff.GetMatrix())(i + 1, 3), 1e-6);
  }
}
