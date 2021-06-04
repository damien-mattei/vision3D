// Universe Class
// Damien MATTEI

#ifndef PANORAMA_HPP
#define PANORAMA_HPP


#include <iostream>
//#include <sstream>      // std::stringstream in display

#include <vector>

#include <list>

#include <assert.h>     /* assert */

#include "Vector3D.hpp"
#include "Object.hpp"

#include "debug.hpp"

#define MAX_OBJECTS 100

using namespace std;



template <class T> class Panorama { // class can be changed in typename 
        
public:
   
  // data

  // array of all 3D Object read from files .obj
  Object<T> * arrayPtrObject[MAX_OBJECTS];

  static inline int cpt_obj;  // without inline the variable is not seen at link stage 
  
  Panorama();

  ~Panorama();

  Object<T> & createObject(string filename);
  
};

template <class T> std::ostream&  operator<< (std::ostream &out, const Panorama<T> &pan);

#endif /* PANORAMA_HPP */
