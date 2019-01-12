// Edge2D Class
// Damien MATTEI

#ifndef EDGE2D_HPP
#define EDGE2D_HPP

#include "Point2D.hpp"

using namespace std;
#include <iostream>
#include <math.h>


// export not yet implemented in g++
//export template<class T> class Edge2D;
//template<class T> class Edge2D;


template <class T> class Edge2D {
  
public:
  
  Point2D<T> a,b;
  
  Edge2D<T>& operator=(const Edge2D<T> &e) {
    
    if( this !=  &e ) {
      a = e.a;
      b = e.b;
    }
    
    return *this;
    
  }


  Edge2D();

  ~Edge2D();
    
  // create edge AB from point A and B
  Edge2D(Point2D<T> a,Point2D<T> b);

  // // compute the norm 
//   T norm();

};

#include "Edge2D.cpp"

#endif /* EDGE2D_HPP */
