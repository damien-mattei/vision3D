// Object Class
// Damien MATTEI


// read .OBJ file from disk

#ifndef OBJFILE_HPP
#define OBJFILE_HPP

//#include "Object.hpp"

#include "Universe.hpp"
#include "Vector3D.hpp"

#include "Panorama.hpp"

#include <boost/algorithm/string.hpp>

//using namespace std;
using std::string;

using namespace boost;

#include <iostream>
#include <fstream>

//#include <sstream>
//#include <string>

#include <list>

#include <assert.h>     /* assert */

#include "debug.hpp"


template <class T,class S> class ObjFile { // NOTE: i replaced typenam by class? no difference seen
        
public:

  string filename;

  Universe<T> * univ;
  Panorama<T> * pan;
  
  ObjFile();

  ObjFile(string,Universe<T> &,Panorama<T> &);

  ~ObjFile();

};

template <class T,class S> ostream&  operator<< (ostream &, const ObjFile<T,S> &);


#endif /* OBJFILE_HPP */
