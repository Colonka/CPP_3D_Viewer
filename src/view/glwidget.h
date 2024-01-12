#ifndef SRC_GLWIDGET_H
#define SRC_GLWIDGET_H

#include <QOpenGLFunctions>
#include <QOpenGLWidget>
#include <QWidget>

class GLWidget : public QOpenGLWidget, public QOpenGLFunctions {
  Q_OBJECT

 public:
  GLWidget(QWidget* parent = nullptr);
  ~GLWidget();

  // public slots:
  //  void send_obj_slot(obj_info_struct* obj_ptr_from_main);
  //  void send_settings_slot(settings_struct* settings_ptr_from_main);

 private:
  // obj_info_struct* obj_ptr = NULL;
  // settings_struct* settings_ptr = NULL;
  void initializeGL() override;
  void resizeGL(int width, int height) override;
  void paintGL() override;

  /*
    float vertex_arr[24] = {
        0.5, 0.5, -0.5,
        0.5, -0.5, -0.5,
        1.000000, 1.000000, 1.000000,
        1.000000, -1.000000, 1.000000,
        -1.000000, 1.000000, -1.000000,
        -1.000000, -1.000000, -1.000000,
        -1.000000, 1.000000, 1.000000,
        -1.000000, -1.000000, 1.000000
    };
    */
};

#endif  // SRC_GLWIDGET_H
