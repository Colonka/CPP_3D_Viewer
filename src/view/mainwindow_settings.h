#ifndef CPP_3D_VIEWER_SRC_VIEW_MAINWINDOW_SETTINGS_H_
#define CPP_3D_VIEWER_SRC_VIEW_MAINWINDOW_SETTINGS_H_

#include <QColor>
#include <QString>

class MainwindowSettings {
 public:
  enum class ProjectionType { kParallelProjection, kCentralProjection };
  enum class LineType { kNoLine, kSolidLine, kDashedLine };
  enum class VertexType { kNoVertex, kCircleVertex, kSquareVertex };

  MainwindowSettings();
  void setModelPath(const QString &new_model_path);
  void setBackgroundColor(QColor color);
  void setProjectionType(MainwindowSettings::ProjectionType projType);
  void setEdgeColor(QColor color);
  void setLineType(MainwindowSettings::LineType newLineType);
  void setVertexColor(const QColor &newVertexColor);
  void setVertexType(MainwindowSettings::VertexType newVertexType);
  void setVertexSize(float newVertexSize);
  void setLineWidth(int newLineWidth);

  const QString &getModelPath() const;
  QColor getBackgroundColor() const;
  MainwindowSettings::ProjectionType getProjectionType() const;
  QColor getEdgeColor() const;
  MainwindowSettings::LineType getLineType() const;
  const QColor &getVertexColor() const;
  MainwindowSettings::VertexType getVertexType() const;
  float getVertexSize() const;
  int getLineWidth() const;

 private:
  QString model_path_;
  QColor background_color_;
  QColor edge_color_;
  QColor vertex_color_;
  ProjectionType projection_type_;
  LineType line_type_;
  VertexType vertex_type_;
  float vertex_size_;
  int line_width_;
}

#endif  // CPP_3D_VIEWER_SRC_VIEW_MAINWINDOW_SETTINGS_H_