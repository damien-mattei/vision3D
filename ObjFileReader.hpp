// Object Class
// Damien MATTEI

#ifndef OBJFILEREADER_HPP
#define OBJFILEREADER_HPP

#include "Object.hpp"

using namespace std;

#include <iostream>
#include <list>

#include "debug.hpp"

template <typename T> class ObjFileReader {
        
public:

  string filename;

  ObjFileReader();

  ObjFileReader(string);

  ~ObjFileReader();

};

template <class T> ostream&  operator<< (ostream &, const ObjFileReader<T> &);


#endif /* OBJFILEREADER_HPP */
