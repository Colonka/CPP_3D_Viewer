
#include "controller_object.h"
#include "../model/object.h"




namespace s21 {

ControllerObject::ControllerObject(ObjectModel* ptr) {
    our_object_ = ptr;

    std::cout << "CONTROLLER OBJECT CONSTRUCTED\n";
}


ControllerObject::~ControllerObject() {
    //
}

float *ControllerObject::GetVertexCoords() {
    return our_object_->vertex.coords;
}




};  // namespace s21
