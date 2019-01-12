// Point3D Class
// Damien MATTEI

#ifndef POINT3D_HPP
#define POINT3D_HPP

using namespace std;
#include <iostream>
#include <utility>
#include <functional>

// class must be forward declared because it contains a friend function template
//export template<class T> class Point3D;
//template<class T> class Point3D;

// friend function also must be forwards declared
//template<class T> ostream& operator<<(ostream& out, const Point3D<T>& p3d);


template <class T> class Point3D {
        
public:
   
  T x,y,z; // coords 

 
  //friend ostream& operator<<<> (ostream &out, const Point3D<T> &p3d);

  
  bool operator== (const Point3D<T> &p3d)  {
    
    return (x==p3d.x) && (y==p3d.y) && (z==p3d.z);
    
  }


  Point3D();

  ~Point3D();
    
  Point3D(T x,T y,T z);


};

#include "Point3D.cpp"

#endif /* POINT3D_HPP */
