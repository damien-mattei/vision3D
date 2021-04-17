// Object Class
// Damien MATTEI

#ifndef OBJECT_HPP
#define OBJECT_HPP

#include "Point3D.hpp"

using namespace std;

#include <iostream>
#include <list>

template <typename T> class Object {
        
public:

// data

// the text name
string name;

list < Point3D<T> *> vertexList;

Object();

Object(string);

~Object();

};

template <class T> ostream&  operator<< (ostream &out, const Object<T> &p3d);

#endif /* OBJECT_HPP */


