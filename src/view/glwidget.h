#ifndef SRC_GLWIDGET_H
#define SRC_GLWIDGET_H

#include <QKeyEvent>
#include <QObject>
#include <QOpenGLWidget>
#include <QVector3D>
#include <QWheelEvent>
#include <memory>

#include "../controller/controller.h"
#include "ui/camera.h"
#include "ui/view_settings.h"

class GLWidget : public QOpenGLWidget, public QOpenGLFunctions {
  Q_OBJECT

 public:
  GLWidget(QWidget *parent = nullptr, s21::Controller *controller,
           MainwindowSettings *settings);
  ~GLWidget();

  s21::Model &getModel();
  void loadModel(QString filename);
  void resetModel();
  QImage getImage();
  const Camera &getCamera();
  bool saveImageToFile(QString filename);

 protected:
  void initializeGL() override;
  void paintGL() override;
  void wheelEvent(QWheelEvent *e) override;
  void mousePressEvent(QMouseEvent *e) override;
  void mouseReleaseEvent(QMouseEvent *e) override;
  void mouseMoveEvent(QMouseEvent *e) override;
  void updateObserver(const Subject &s) override;

 private:
  void applyProjectionType();
  void applyBackgroundColor();
  void drawEdges();
  void drawVertex(float x, float y, float z);
  void drawVertices();
  void drawAxes();

 private:
  s21::Controller *controller_;
  MainwindowSettings *settings_;
};

#endif  // SRC_GLWIDGET_H
