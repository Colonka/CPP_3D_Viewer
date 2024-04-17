# CPP_3D_Viewer

Implementation of CPP_3D_Viewer by OOP and using MVC-pattern, design patterns, SOLID principles.

![CPP_3DViewer](https://github.com/Colonka/CPP_3D_Viewer/assets/128917856/178dfc81-49fe-48fc-9a0d-78d0c0da9cf1)

## Introduction

In this project I've implemented an extended version of the program to view 3D wireframe models by C++ in the object-oriented programming paradigm, implementing the same functions as the previously developed application ([https://github.com/Colonka/s21_calc_V1.0](https://github.com/Colonka/3D_Viewer_V1.0)). 

This app version is implemented by :
- MVC-pattern(The Model-View-Controller (MVC) pattern is a scheme of separating application modules into three macro-components: a model that contains the business logic, a view that is a UI form to interact with the program, and a controller that modifies the model by user action.)
- Patterns:
  - Creational pattern : Singleton (Ensures that the class has only one instance, and provides a global access point to it)
  - Structural pattern : Facade (Provides a unified interface rather than a set of interfaces of some subsystem. The facade defines a higher-level interface that simplifies the use of the subsystem.)
  - Behavioral pattern : Strategy (Defines a family of algorithms, encapsulates each of them and makes them interchangeable. The strategy pattern allows you to change the algorithms independently from the clients that use them.)
- SOLID principles

All detailed information about wireframe models and affine transformations you can find here: [https://github.com/Colonka/s21_calc_V1.0](https://github.com/Colonka/3D_Viewer_V1.0)

## Instructons for running

Being in `src` folder run command `make` and then `make run`.

## Instruction for archiving

Being in `src` folder run command `make dist` that create folder with archived app.

## Instruction for testing

Being in `src` folder run command `make test`

## Instruction for gcov test coverage

Being in `src` folder run command `make gcov_report`

## Documentation

To open library documentation run command `dvi_open`
