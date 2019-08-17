// Point2D Class
// Damien MATTEI

#ifndef POINT2D_HPP
#define POINT2D_HPP

using namespace std;
#include <iostream>


template <class T> class Point2D {
        
public:
   
  T x,y; // coords 

  Point2D();

  ~Point2D();
    
  Point2D(T x,T y);

  // equality operator
  bool operator== (const Point2D<T> &);

};

#include "Point2D.cpp"

#endif /* POINT2D_HPP */
