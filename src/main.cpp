#include "model/.h"

#include <QApplication>

#include "model/model.h"
#include "view/mainwindow.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  s21::Model model;
  s21::Controller controller(&model);
  MainWindow w;
  w.show();
  return a.exec();
}
