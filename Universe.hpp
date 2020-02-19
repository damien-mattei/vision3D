// Universe Class
// Damien MATTEI

#ifndef UNIVERSE_HPP
#define UNIVERSE_HPP


#include <algorithm> // used by Universe
#include <iostream>

#include <list>

#include "Point3D.hpp"
#include "debug.hpp"

using namespace std;

template <class T> class Universe {
        
public:
   
  // data 
  list < Point3D<T> *> point3DptrList;

  // for deprecated compatibility in Vision3D.cpp
  // the vertex
  list < Point3D<T> > vertexList;
  
  Universe();

  ~Universe();
    
  Point3D<T> & createPoint3Dref(T x,T y,T z); // create a point by checking if it already exist

  Point3D<T> * createPoint3Dptr(T x,T y,T z); // create a point by checking if it already exist
 
};



#endif /* UNIVERSE_HPP */
