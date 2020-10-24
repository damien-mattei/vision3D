// Object3DList Class
// Damien MATTEI

#ifndef OBJECT3DLIST_HPP
#define OBJECT3DLIST_HPP

using namespace std;

#include <iostream>

// this class inherit of Object class
template <class T> class Object3DList : public Object3D<T> {
        
public:
   
  // the vertex
  list < Point3Did<T> > vertexList;

  // the edges
  list < Edge3D<T> > edgeList;


  Object3DList();

  ~Object3DList();
    
  Object3DList( list < Point3Did<T> > vertexList,list < Edge3D<T> > edgeList);


};

#include "Object3DList.cpp"

#endif /* OBJECT3DLIST_HPP */
