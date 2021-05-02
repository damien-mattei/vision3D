// Vector3D Class
// Damien MATTEI

#ifndef VECTOR3D_HPP
#define VECTOR3D_HPP

#include "Point3D.hpp"
//#include "Matrix3x3.hpp" // recursive definitions cause error


#include <iostream>
#include <math.h>

using namespace std;

// export not yet implemented in g++
//export template<class T> class Vector3D;
//template<class T> class Vector3D;

//template class Matrix3x3<T>;

//class Matrix3x3<float>;

template <class T> class Vector3D {


public:
  
  T x,y,z; // coords 
  

  Vector3D();

  ~Vector3D();
    
  Vector3D(T x,T y,T z);

  // copy constructor
  Vector3D(const Vector3D<T> &);

  // create vector AB from point A and B
  Vector3D(Point3D<T> & a,Point3D<T> & b);

  // assignation operator
  Vector3D<T> & operator=(const Vector3D<T> &);

  // equality operator
  bool operator== (const Vector3D<T> &);
  
  Vector3D<T>& operator+=(const Vector3D<T> &v);

  
  // dot product - produit scalaire
  T operator*(const Vector3D<T> &v);

  // cross product - produit vectoriel
  Vector3D<T> operator^(const Vector3D<T> &v);

  // compute the norm 
  T norm();

};


template <class T> Vector3D<T> operator+(const Vector3D<T> &u,const Vector3D<T> &v);

template<class T> Vector3D<T> operator*(const Vector3D<T> &v,const T m);

template<class T> Vector3D<T> operator*(const T m,const Vector3D<T> &v);


// matrix multiplication
// m3d a reference &  ???
template<class T> Vector3D<T> operator*(const T m3d[][3],const Vector3D<T> &u);




template<class T> Vector3D<T> operator/(const Vector3D<T> &v,const T d);



template <class T> ostream&  operator<< (ostream &out, Vector3D<T> &v3d);



#endif /* VECTOR3D_HPP */
