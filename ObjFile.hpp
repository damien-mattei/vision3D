// Object Class
// Damien MATTEI


// read .OBJ file from disk

#ifndef OBJFILE_HPP
#define OBJFILE_HPP

//#include "Object.hpp"
#include "Point3D.hpp"

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

template <typename T> class ObjFile {
        
public:

  string filename;

  ObjFile();

  ObjFile(string);

  ~ObjFile();

};

template <class T> ostream&  operator<< (ostream &, const ObjFile<T> &);


#endif /* OBJFILE_HPP */
