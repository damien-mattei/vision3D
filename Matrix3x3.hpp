// Matrix3x3 Class
// Damien MATTEI

#ifndef MATRIX3X3_HPP
#define MATRIX3X3_HPP

// a Matrix can be build with Vectors (not the inverse)
// with template it is not for now possible to include each header in each other
#include "Vector3D.hpp"


template <class T> class Matrix3x3 {
  
public:

  T m[3][3];
  
  // TODO : write accessors
  
  Matrix3x3();

  ~Matrix3x3();
    
  Matrix3x3(T m00,T m01,T m02,
	    T m10,T m11,T m12,
	    T m20,T m21,T m22);

  // copy constructor
  Matrix3x3(const Matrix3x3<T> &);

  string display(void);
  
  Matrix3x3(Vector3D<T> & v1,Vector3D<T> & v2,Vector3D<T> & v3);

  // assignation operator
  Matrix3x3<T> & operator=(const Matrix3x3<T> &);
  
  Matrix3x3<T>& operator+=(const Matrix3x3<T> &mr);

  
  // matrix product
  Matrix3x3<T> operator*(const Matrix3x3<T> &mr);

  Matrix3x3<T> operator+(const Matrix3x3<T> &mr);

  Matrix3x3<T> operator*(const T k);

  Matrix3x3<T> operator/(const T);
  
};


//template <class T> Matrix3x3<T> operator+(const Matrix3x3<T> &ml,const Matrix3x3<T> &mr);

//template<class T> Matrix3x3<T> operator*(const Matrix3x3<T> &ml,const T k);

template<class T> Matrix3x3<T> operator*(const T k,const Matrix3x3<T> &mr);

template<class T> Vector3D<T> operator*(const Matrix3x3<T>&,const Vector3D<T> &u);

template<class T> Vector3D<T> * operator*(const Matrix3x3<T>&,const Vector3D<T> &u);

//template<class T> Matrix3x3<T> operator/(const Matrix3x3<T> &ml,const T d);

template<class T> Point3D<T> operator*(const Matrix3x3<T>&,const Point3D<T> &);

template <class T> ostream&  operator<< (ostream &out, const Matrix3x3<T> &mr);



#endif /* MATRIX3X3_HPP */
