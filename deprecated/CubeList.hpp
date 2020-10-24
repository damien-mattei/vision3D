// CubeList Class
// Damien MATTEI

#ifndef CUBELIST_HPP
#define CUBELIST_HPP

using namespace std;

#include <iostream>

// this class inherit of ObjectList class
template <class T> class CubeList : public Object3DList<T> {
        
public:
   
  CubeList();

  ~CubeList();
    
};

#include "CubeList.cpp"

#endif /* CUBELIST_HPP */
