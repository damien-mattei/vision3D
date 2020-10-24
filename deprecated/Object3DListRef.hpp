// Object3dListRef Class
// Damien MATTEI

#ifndef OBJECT3DLISTREF_HPP
#define OBJECT3DLISTREF_HPP

using namespace std;

#include <iostream>

// this class inherit of Object class
template <class T> class Object3DListRef : public Object3D<T> {
        
public:
   
  // the vertex
  list < Point3Did<T> > * vertexList;

  // the edges
  list < Edge3D<T> > * edgeList;

  Object3DListRef();

  ~Object3DListRef();
    
  Object3DListRef( list < Point3Did<T> > & vertexList,list < Edge3D<T> > & edgeList);


};

#include "Object3DListRef.cpp"

#endif /* OBJECT3DLISTREF_HPP */
