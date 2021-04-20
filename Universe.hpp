// Universe Class
// Damien MATTEI

#ifndef UNIVERSE_HPP
#define UNIVERSE_HPP


#include <algorithm> // used by Universe
#include <iostream>

#include <vector>

#include <list>

// Edge3D will include Point3D
#include "Edge3D.hpp"
#include "debug.hpp"

using namespace std;

template <typename T> class Universe {
        
public:
   
  // data

  std::vector< Point3D<T> *> containerPoint3DptrvectorC;
  
  // deprecated
  list < Point3D<T> *> containerPoint3DptrlistC;

  list < Edge3D<T> *> containerEdge3DptrlistC;

  // for deprecated compatibility in Vision3D.cpp
  // the vertex
  list < Point3D<T> > vertexList;
  
  Universe();

  ~Universe();


  // DEPRECATED (for tests)
  Point3D<T> & createPoint3DReference(T x,T y,T z); // create a point by checking if it already exist
  Point3D<T> & createPoint3Dref_BACKUP(T x,T y,T z); // backup because i created macro that builds functions now



  
  // create a Point3D by checking if it already exist in the universe
  template <typename ObjectType, typename... ParamTypes>
  ObjectType & createPoint3DReflistC(ParamTypes ...args);

  // create a Edge3D by checking if it already exist in the universe
  template <typename ObjectType, typename... ParamTypes>
  ObjectType & createEdge3DReflistC(ParamTypes ...args);


  // create a Point3D by checking if it already exist in the universe
  template <typename ObjectType, typename... ParamTypes>
  ObjectType & createPoint3DRefvectorC(ParamTypes ...args);


 
  


  // create an object by checking if it already exist in the universe
  // DEPRECATED
  template <typename ObjectType, typename... ParamTypes>
  ObjectType & createObjectRef(ParamTypes ...args);
  
  Point3D<T> * createPoint3Dptr(T x,T y,T z); // create a point by checking if it already exist

  void createCube(Point3D<T> &,T);

  // for testing
  template <typename myType,typename otherType>
  myType GetMax (myType a, myType b);
 
};



#endif /* UNIVERSE_HPP */
