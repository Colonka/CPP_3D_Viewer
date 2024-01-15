#include "mainwindow_settings.h"

MainwindowSettings::MainwindowSettings() {
  background_color_ = Qt::black;
  edge_color_ = Qt::darkGreen;
  vertex_color_ = Qt::yellow;
  projection_type_ = MainwindowSettings::ProjectionType::kParallelProjection;
  line_type_ = MainwindowSettings::LineType::kSolidLine;
  vertex_type_ = MainwindowSettings::VertexType::kNoVertex;
  vertex_size_ = 4;
  line_width_ = 1;
}

MainwindowSettings::ProjectionType MainwindowSettings::getProjectionType()
    const {
  return projection_type_;
}

MainwindowSettings::VertexType MainwindowSettings::getVertexType() const {
  return vertex_type_;
}

float MainwindowSettings::getVertexSize() const { return vertex_size_; }

void MainwindowSettings::setBackgroundColor(QColor color) {
  background_color_ = color;
}

void MainwindowSettings::setProjectionType(
    MainwindowSettings::ProjectionType projType) {
  projection_type_ = projType;
}

void MainwindowSettings::setEdgeColor(QColor color) { edge_color_ = color; }

QColor MainwindowSettings::getBackgroundColor() const {
  return background_color_;
}

QColor MainwindowSettings::getEdgeColor() const { return edge_color_; }

MainwindowSettings::LineType MainwindowSettings::getLineType() const {
  return line_type_;
}

void MainwindowSettings::setLineType(MainwindowSettings::LineType newLineType) {
  line_type_ = newLineType;
}

const QString &MainwindowSettings::getModelPath() const { return model_path_; }

void MainwindowSettings::setModelPath(const QString &new_model_path) {
  model_path_ = new_model_path;
}

int MainwindowSettings::getLineWidth() const { return line_width_; }

void MainwindowSettings::setLineWidth(int newLineWidth) {
  line_width_ = newLineWidth;
}

void MainwindowSettings::setVertexSize(float newVertexSize) {
  vertex_size_ = newVertexSize;
}

void MainwindowSettings::setVertexType(
    MainwindowSettings::VertexType newVertexType) {
  vertex_type_ = newVertexType;
}

const QColor &MainwindowSettings::getVertexColor() const {
  return vertex_color_;
}

void MainwindowSettings::setVertexColor(const QColor &newVertexColor) {
  vertex_color_ = newVertexColor;
}