// Object3D Class
// Damien MATTEI

#ifndef OBJECT3D_HPP
#define OBJECT3D_HPP

using namespace std;

#include <iostream>

template <class T> class Object3D {
        
public:
   
  
  // the text name
  string name;

  // some info about object
  string description;

  Object3D();

  Object3D(string name);

  ~Object3D();

  void printName();

};

#include "Object3D.cpp"

#endif /* OBJECT3D_HPP */
