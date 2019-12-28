// Vector3D Class
// Damien MATTEI

#ifndef VECTOR3D_HPP
#define VECTOR3D_HPP

#include "Point3D.hpp"

using namespace std;
#include <iostream>
#include <math.h>


// export not yet implemented in g++
//export template<class T> class Vector3D;
//template<class T> class Vector3D;


template <class T>

class Vector3D

{
  
public:
  
  T x,y,z; // coords 
  
  Vector3D<T>& operator=(const Vector3D<T> &v) {
    
    if( this !=  &v ) {
      x = v.x;
      y = v.y;
      z = v.z;
      
    }
    
    return *this;
    
  }


  Vector3D<T>& operator+=(const Vector3D<T> &v) {
    
    this->x += v.x;
    this->y += v.y;
    this->z += v.z;
    
    return *this;
    
  }
  

  Vector3D();

  ~Vector3D();
    
  Vector3D(T x,T y,T z);

  // create vector AB from point A and B
  Vector3D(Point3D<T> a,Point3D<T> b);

  // dot product - produit scalaire
  T operator*(const Vector3D<T> &v);

  // cross product - produit vectoriel
  Vector3D<T> operator^(const Vector3D<T> &v);

  // compute the norm 
  T norm();

};

#include "Vector3D.cpp"

#endif /* VECTOR3D_HPP */
