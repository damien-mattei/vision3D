// Universe Class
// Damien MATTEI

#ifndef UNIVERSE_HPP
#define UNIVERSE_HPP




template <class T> class Universe {
        
public:
   
  // data 
  list < Point3D<T> *> point3DptrList;
  
  
  Universe();

  ~Universe();
    
  Point3D<T> * createPoint3Dptr(T x,T y,T z); // create a point by checking if it already exist

  Point3D<T> createPoint3D(T x,T y,T z); // create a point by checking if it already exist
  
};

#include "Universe.cpp"

#endif /* UNIVERSE_HPP */
