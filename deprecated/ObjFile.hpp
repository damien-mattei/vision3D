// Object Class
// Damien MATTEI


// read .OBJ file from disk

#ifndef OBJFILE_HPP
#define OBJFILE_HPP

//#include "Object.hpp"

#include "Universe.hpp"
#include "Vector3D.hpp"

#include <boost/algorithm/string.hpp>

//using namespace std;
using std::string;

using namespace boost;

#include <iostream>
#include <fstream>

//#include <sstream>
//#include <string>

#include <list>

#include "debug.hpp"


template <typename T,template S> class ObjFile {
        
public:

  string filename;

  Universe<T> * univ;

  ObjFile();

  ObjFile(string,Universe<T> &);

  ~ObjFile();

};

template <class T,class S> ostream&  operator<< (ostream &, const ObjFile<T,S> &);


#endif /* OBJFILE_HPP */
