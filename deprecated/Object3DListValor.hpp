// Object3dListValor Class
// Damien MATTEI

#ifndef OBJECT3DLISTVALOR_HPP
#define OBJECT3DLISTVALOR_HPP

using namespace std;

#include <iostream>

// this class inherit of Object class
template <class T> class Object3DListValor : public Object3D<T> {
        
public:
   
  // the vertex
  list < Point3D<T> > vertexList;

  // the edges
  list < Edge3D<T> > edgeList;

  Object3DListValor();

  ~Object3DListValor();
    
  Object3DListValor( list < Point3D<T> > vertexList,list < Edge3D<T> > edgeList);


};

#include "Object3DListValor.cpp"

#endif /* OBJECT3DLISTVALOR_HPP */
