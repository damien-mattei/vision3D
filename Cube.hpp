// Cube Class
// Damien MATTEI

#ifndef CUBE_HPP
#define CUBE_HPP

#include "Universe.hpp"

using namespace std;

#include <iostream>

// this class inherit of Object class
template <class T> class Cube : public Object3D<T> {
        
public:
   
  // the vertex
  list < Point3D<T> > vertexList;

  // the edges
  list < Edge3D<T> > edgeList;


  Cube();

  Cube(Universe<T> &);

  ~Cube();
    
  Cube( list < Point3D<T> > vertexList,list < Edge3D<T> > edgeList);


};

#include "Cube.cpp"

#endif /* CUBE_HPP */
