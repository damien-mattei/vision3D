// Edge3D Class
// Damien MATTEI

#ifndef EDGE3D_HPP
#define EDGE3D_HPP

#include "Point3D.hpp"

using namespace std;
#include <iostream>
#include <math.h>


// export not yet implemented in g++
//export template<class T> class Edge3D;
//template<class T> class Edge3D;


template <class T> class Edge3D {
  
public:
  
  Point3D<T> a,b;
  
  Edge3D();

  ~Edge3D();
    
  // create edge AB from point A and B
  Edge3D(Point3D<T> a,Point3D<T> b);

  //Edge3D(Point3D<T> & ref_a,Point3D<T> & ref_b);

  Edge3D(const Edge3D<T> &);

  Edge3D<T> & operator=(const Edge3D<T> &);
  
  // // compute the norm 
//   T norm();

};

#include "Edge3D.cpp"

#endif /* EDGE3D_HPP */
