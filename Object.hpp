// Object Class
// Damien MATTEI

#ifndef OBJECT_HPP
#define OBJECT_HPP

#include "Point3D.hpp"

using namespace std;

#include <iostream>
#include <list>

#include "debug.hpp"

template <typename T> class Object {
        
public:

  // data

  // the text name
  string name;

  list < Point3D<T> *> vertexList;

  Object();

  Object(string);

  ~Object();

  void storeVertex(Point3D<T> &); // TODO verifier si c'est pas mieux un pointeur

};

template <class T> ostream&  operator<< (ostream &, const Object<T> &);

#endif /* OBJECT_HPP */


