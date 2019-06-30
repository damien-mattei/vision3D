#ifndef VISION3D_HPP
#define VISION3D_HPP

#include "Point3D.hpp"
#include "Vector3D.hpp"
#include "Point2D.hpp"

using namespace std;
#include <iostream>
#include <cmath> // or math.h

const double PI = 4.0*atan(1.0);

template <class T> class Vision3D {
  
public:

  // position of eye
  Point3D<T> c;
  
  // position of center of screen
  Point3D<T> s;

  // vectors defining screen frame

  // vector u
  Vector3D<T> u;

  // vector v
  Vector3D<T> v;

  // vector w
  Vector3D<T> w;

  // change of basis matrix
  T m[3][3];

  // distance, norm of SC
  T d;
  
  // angular viewField for vision (in radians)
  T viewField;

  // pixels half-size of screen on Y
  int winHalfSizeY;

  // pixels half-size of screen on X
  int winHalfSizeX;

  // winHalfSizeX in units of internal frame reference
  T winHalfX;

  // pixel expressed in unit of rame reference 
  T pixelInUnit;

  // data 
  list < Point3D<T> > vertexList;
  
  Vision3D();

  Vision3D(Point3D<T> c,Point3D<T> s); // c position of eye or camera ,s position of center of screen

  ~Vision3D();

  Point2D<T> projection(Point3D<T> m); // projection on screen

  //friend ostream& operator<< (ostream &out, Vision3D &vis3d);

  Point2D<int> convert2Pixel(Point2D<T> p); // convert in relative screen coords

  Point2D<int> convert2AbsPixel(Point2D<int> p); // convert in absolute screen coords

  Point2D<int> convert2ScreenCoord(Point2D<int> p); // convert in computer screen coords (Origin at left top corner)

  Point3D<T> * createPoint3D(T x,T y,T z); // create a point by checking if it already exist

  void setViewField(T viewFieldInDegree) { 

    this->viewField = ( viewFieldInDegree / 180 ) * PI;

    // as i get the viewField angle i set the half screen sizes
    computeWinHalfX();
    
 };

  // return value of view field in radian
  T getViewField() {
    return this->viewField;
  };
  
  void setHalfScreenSizeY(int winHalfSizeY) { 
    this->winHalfSizeY =  winHalfSizeY;
 };

  int getHalfScreenSizeY() {
    return this->winHalfSizeY;
  };

  void setHalfScreenSizeX(int winHalfSizeX) { 
    
    // real half size in pixels of screen on X
    this->winHalfSizeX =  winHalfSizeX;
    if (winHalfSizeX !=0)
      computePixelInUnit();
    
  };
  
  int getHalfScreenSizeX() {
    return this->winHalfSizeX;
  };
  
  void computeWinHalfX() { 
    // half size on X of screen in units of reference frame
    winHalfX = d * tan(viewField);
  }

  T getWinHalfX()  {
    return this->winHalfX;
  };

  void computePixelInUnit() {
    pixelInUnit = winHalfSizeX / winHalfX;
  }
  
  T getPixelInUnit()  {
    return this->pixelInUnit;
  };

};

#include "Vision3D.cpp"

#endif /* VISION3D_HPP */
