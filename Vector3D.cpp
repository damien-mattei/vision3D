// Vector3D Class
// Damien MATTEI

#include "Vector3D.hpp"

// implementations

template <class T> Vector3D<T>::Vector3D() : x(0), y(0), z(0) {}

template <class T> Vector3D<T>::Vector3D(T x,T y,T z) : x(x), y(y), z(z) {

#ifdef DISPLAY_CONSTRUCTOR
  cout << "# Vector3D constructor #" << endl;
#endif

}

template <class T> Vector3D<T>::~Vector3D() {

#ifdef DISPLAY_CONSTRUCTOR
  cout << "# Vector3D destructor #" << endl;
#endif

}

// create vector AB from point A and B
template <class T> Vector3D<T>::Vector3D(Point3D<T> & a,Point3D<T> & b)
 : x(b.x - a.x), y(b.y - a.y), z(b.z - a.z) {}

template <class T> ostream&  operator<< (ostream &out, Vector3D<T> &v3d)
{
    
  out << "(" << v3d.x << ", "
      << v3d.y << ", "
      << v3d.z << ")";
  
  return out;

}


// copy constructor
// exist but should NOT be used because one point in Universe should be unique
template <class T> Vector3D<T>::Vector3D(const Vector3D<T> &oneVector3D) {

  x=oneVector3D.x;
  y=oneVector3D.y;
  z=oneVector3D.z;
   
  
#ifdef DISPLAY_CONSTRUCTOR
  cout << "# Vector3D copy constructor # " << &oneVector3D << " => " << this << " " << *this << endl;
#endif

}


// assignation operator
template <class T> Vector3D<T> & Vector3D<T>::operator=(const Vector3D<T> &v)
 {
    
    if( this !=  &v ) {
      x = v.x;
      y = v.y;
      z = v.z;
      
    }
    
    return *this;
    
  }

// equality operator
template <class T> bool Vector3D<T>::operator== (const Vector3D<T> &p3d)  {
  
  return (x==p3d.x) && (y==p3d.y) && (z==p3d.z);
    
}



template <class T> Vector3D<T> & Vector3D<T>::operator+=(const Vector3D<T> &v)
 {
   this->x += v.x; // x += v.x works also
   this->y += v.y;
   this->z += v.z;
   
   return *this;
    
 }


template<class T> Vector3D<T> operator+(const Vector3D<T> &u,const Vector3D<T> &v) {

  return Vector3D<T>(
		     u.x + v.x,
		     u.y + v.y,
		     u.z + v.z
		     );
}

template<class T> Vector3D<T> operator/(const Vector3D<T> &v,const T d) {

  return Vector3D<T>(
		     v.x / d,
		     v.y / d,
		     v.z / d
		     );
}

template<class T> Vector3D<T> * operator|(const Vector3D<T> &v,const T d) {

  return new Vector3D<T>(
			 v.x / d,
			 v.y / d,
			 v.z / d
			 );
}

template<class T> Vector3D<T> operator*(const T m,const Vector3D<T> &v) {

  return Vector3D<T>(
		     m * v.x,
		     m * v.y,
		     m * v.z
		     );
}

template<class T> Vector3D<T> operator*(const Vector3D<T> &v,const T m) {

  // return Vector3D<T>(
  // 		     v.x * m,
  // 		     v.y * m,
  // 		     v.z * m
  // 		     );

  return m*v;
  
}

// dot product - produit scalaire
template<class T> T Vector3D<T>::operator* (const Vector3D<T> &v)  {

  return x * v.x + y * v.y + z * v.z;
  
}

// cross product - produit vectoriel
// should not be returned a reference and first allocate memory for the vector3d ?
template<class T> Vector3D<T> Vector3D<T>::operator^(const Vector3D<T> &v)  {

  return Vector3D<T>(
		     y * v.z - z * v.y,
		     z * v.x - x * v.z,
		     x * v.y - y * v.x
		     );
}

// matrix multiplication


template<class T> Vector3D<T> operator*(const T m3d[][3],const Vector3D<T> &u) {

  return Vector3D<T>(
		     m3d[0][0] * u.x + m3d[0][1] * u.y + m3d[0][2] * u.z,
		     m3d[1][0] * u.x + m3d[1][1] * u.y + m3d[1][2] * u.z,
		     m3d[2][0] * u.x + m3d[2][1] * u.y + m3d[2][2] * u.z 
		     );
}




template<class T> T  Vector3D<T>::norm() {

  //return ( sqrt(x * x + y * y + z * z) );

  Vector3D<T> & v = *this;
  
  return sqrt( v * v ) ; 

}


template class Vector3D<float>;

template Vector3D<float> operator/(const Vector3D<float> &v,const float d);

template  ostream&  operator<< (ostream &out, Vector3D<float> &v3d);

template  Vector3D<float> operator+(const Vector3D<float> &u,const Vector3D<float> &v);

template Vector3D<float> operator*(const Vector3D<float> &v,const float m);

template Vector3D<float> operator*(const float m,const Vector3D<float> &v);

template Vector3D<float> operator*(const float m3d[][3],const Vector3D<float> &u);
