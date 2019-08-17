// Point3D Class
// Damien MATTEI

#ifndef POINT3D_HPP
#define POINT3D_HPP


#include <iostream>


// class must be forward declared because it contains a friend function template
//export template<class T> class Point3D;
//template<class T> class Point3D;

// friend function also must be forwards declared
//template<class T> ostream& operator<<(ostream& out, const Point3D<T>& p3d);




template <class T> class Point3D {
        
public:
   
  T x,y,z; // coords 

  
  Point3D();

  ~Point3D();
    
  Point3D(T x,T y,T z);
  
  // copy constructor
  Point3D(const Point3D<T> &);

  // assignation operator
  Point3D<T> & operator=(const Point3D<T> &);

  // equality operator
  bool operator== (const Point3D<T> &);

};

#include "Point3D.cpp"

#endif /* POINT3D_HPP */
