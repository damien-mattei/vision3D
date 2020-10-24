// Point3D Class
// Damien MATTEI

#ifndef POINT3DID_HPP
#define POINT3DID_HPP

using namespace std;
#include <iostream>
#include <utility>
#include <functional>

// class must be forward declared because it contains a friend function template
//export template<class T> class Point3D;
//template<class T> class Point3D;

// friend function also must be forwards declared
//template<class T> ostream& operator<<(ostream& out, const Point3D<T>& p3d);


template <class T> class Point3Did  : public Point3D<T> {
        
public: 

  int id;
  static int next_id;

  //friend ostream& operator<<<> (ostream &out, const Point3D<T> &p3d);

  
  bool operator== (const Point3D<T> &p3d)  {
    
    return id==p3d.id;
    
  }


  Point3Did();

  ~Point3Did();
    
  Point3Did(T x,T y,T z);

  // copy constructor
  Point3Did(const Point3Did &);

  // assignation operator
  Point3Did<T> & operator=(const Point3Did<T> &);


};

template <class T> int Point3Did<T>::next_id = 0;

#include "Point3Did.cpp"

#endif /* POINT3D_HPP */
