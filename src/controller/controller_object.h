#ifndef CPP4_3DVIEWER_V2_SRC_CONTROLLER_CONTROLLER_OBJECT_H_
#define CPP4_3DVIEWER_V2_SRC_CONTROLLER_CONTROLLER_OBJECT_H_


#include "../model/object.h"


#include <iostream>



namespace s21 {

class ControllerObject {
    public:
        ControllerObject(ObjectModel*);
        ~ControllerObject();


    float* GetVertexCoords();
//  private:
    ObjectModel* our_object_;

};



};  // namespace s21

#endif  //  CPP4_3DVIEWER_V2_SRC_CONTROLLER_CONTROLLER_OBJECT_H_
