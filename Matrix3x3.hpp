// Matrix3x3 Class
// Damien MATTEI

#ifndef MATRIX3X3_HPP
#define MATRIX3X3_HPP

#include "Vector3D.hpp"

#include <iostream>
//#include <math.h>

using namespace std;


template <class T> class Matrix3x3 {
  
public:

  T m[3][3];
  

  Matrix3x3();

  ~Matrix3x3();
    
  Matrix3x3(T m00,T m01,T m02,
	    T m10,T m11,T m12,
	    T m20,T m21,T m22);

  
  Matrix3x3(Vector3D<T> & v1,Vector3D<T> & v2,Vector3D<T> & v3);

  Matrix3x3<T> & operator=(const Matrix3x3<T> &);
  
  Matrix3x3<T>& operator+=(const Matrix3x3<T> &mr);

  
  // matrix product
  Matrix3x3<T> operator*(const Matrix3x3<T> &mr);

};


template <class T> Matrix3x3<T> operator+(const Matrix3x3<T> &ml,const Matrix3x3<T> &mr);

template<class T> Matrix3x3<T> operator*(const Matrix3x3<T> &ml,const T k);

template<class T> Matrix3x3<T> operator*(const T k,const Matrix3x3<T> &mr);

template<class T> Matrix3x3<T> operator/(const Matrix3x3<T> &ml,const T d);



template <class T> ostream&  operator<< (ostream &out, Matrix3x3<T> &mr);



#endif /* MATRIX3X3_HPP */
