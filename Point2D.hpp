// Point2D Class
// Damien MATTEI

#ifndef POINT2D_HPP
#define POINT2D_HPP


#include <string>       // std::string
#include <iostream>     // std::cout
#include <sstream>      // std::stringstream
#include <iomanip>

using namespace std;

template <class T> class Point2D {
  
public:
  
  T x,y; // coords 
  
  Point2D();
  
  ~Point2D();
  
  Point2D(T x,T y);
  
  // copy constructor
  Point2D(const Point2D<T> &);

  string display(void);
  
  // equality operator
  bool operator== (const Point2D<T> &);
  
  //friend ostream&  operator<< (ostream &out, Point2D<T> &p2d);

};

template <class T>  ostream&  operator<< (ostream &out, Point2D<T> &p2d);

#endif /* POINT2D_HPP */
