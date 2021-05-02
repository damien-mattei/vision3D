// Face3D Class
// Damien MATTEI

#ifndef FACE3D_HPP
#define FACE3D_HPP


#include <iostream>
#include <sstream>      // std::stringstream
#include <iomanip>

#include <list>

using namespace std;
//using std::stringstream;
//using std::string;


template <class T> class Face3D {
        
public:

  Vector3D<T> * normal;

  list < Point3D<T> *> containerPoint3Dptrlist;
  
  Face3D();

  ~Face3D();
    
  Face3D(Vector3D<T> & normal);  
  
  // copy constructor
  Face3D(const Face3D<T> &);

  std::string display(void);

  // assignation operator
  Face3D<T> & operator=(const Face3D<T> &);

  // equality operator
  bool operator== (const Face3D<T> &);


};

template <class T> std::ostream&  operator<< (std::ostream &out, const Face3D<T> &p3d);

#endif /* FACE3D_HPP */
