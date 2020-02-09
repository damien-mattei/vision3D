// Point2D Class
// Damien MATTEI


//#include "Point2D.hpp"

// implementations

#include <string>       // std::string
#include <iostream>     // std::cout
#include <sstream>      // std::stringstream
#include <iomanip>

template <class T> Point2D<T>::Point2D() : x(0), y(0) {}

template <class T> Point2D<T>::Point2D(T x,T y) : x(x), y(y) {
#ifdef DISPLAY_CONSTRUCTOR
  cout << "# Point2D constructor #" << endl;
#endif
}

template <class T> Point2D<T>::~Point2D() {

#ifdef DISPLAY_CONSTRUCTOR
  cout << "# Point2D destructor #" << endl;
#endif

}

template <class T>  string Point2D<T>::display(void) {

  std::stringstream stream;
  //stream << "Point2D@" << std::setfill ('0') << std::setw(sizeof(long)*2) << std::hex << (long)this << "(" << x << "," << y << ")";
  stream << "Point2D @" << " 0x" << std::hex << (long)this << " " << *this;
  //return std::string("Point2D@") + std::to_string((long)this) + std::string("(") + std::to_string(x) + std::string(",") + std::to_string(y) + std::string(")");
  return stream.str();

}


template <class T> ostream&  operator<< (ostream &out, Point2D<T> &p2d)
{
    
  out << "(" << p2d.x << ","
      << p2d.y << ")";
  
  return out;

}


// equality operator
template <class T> bool Point2D<T>::operator== (const Point2D<T> &p2d)  {
  
  return (x==p2d.x) && (y==p2d.y);
    
}

