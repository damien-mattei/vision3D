// Object Class
// Damien MATTEI

/* this class is for loading an object in memory vertex and normal are stored at the same index of 
 * the .obj file allowing consistency for the object but possible redundancy of same vertex and normal
 * not shared by different objects. For this reason program use a general vertex and normal storage
 * and faces in program are made of list where elements point to unique vertexs and normals */

#ifndef OBJECT_HPP
#define OBJECT_HPP

#include "Face3D.hpp"

using namespace std;

#include <iostream>
#include <vector>
#include <list>

#include "debug.hpp"

template <typename T> class Object {
        
public:

  // data

  // the name of file
  string filename;

  std::vector < Point3D<T> *> vertexVector;

  std::vector < Vector3D<T> *> normalVector;

  std::list < Face3D<T> *> faceList; // todo: verify it is pointer or not
  
  Object();

  Object(string);

  ~Object();

  void storeVertex(Point3D<T> &);

};

template <class T> ostream&  operator<< (ostream &, const Object<T> &);

#endif /* OBJECT_HPP */


