#ifndef VISION3D_HPP
#define VISION3D_HPP

#include "Point3D.hpp"
#include "Matrix3x3.hpp"
#include "Point2D.hpp"
#include "Universe.hpp"
#include "debug.hpp"


#include <iostream>
#include <cmath> // or math.h

#include <unordered_map>
#include <algorithm>    // std::transform

#include <functional>

const double PI = 4.0*atan(1.0);

template <class T> class Vision3D {
  
public:

  // position of eye
  Point3D<T> c;
  
  // position of center of screen
  Point3D<T> s;

  // note: u,v,w have been moved as local variable
  
  // change of basis matrix
  // could be a class with overload * operator
  T m[3][3];

  Matrix3x3<T> * ptrM33;

  Matrix3x3<T> m3x3;
  
  
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

  // pixel expressed in unit of frame reference 
  T pixelInUnit;



  
  // data 

  
  Universe<T> univ;

  // // list of points 2D making the canvas list  
  // list < Point2D<T> > points2d;

  // // list of pixel  
  // list < Point2D<int> > pixels;

  
  // unordered map (hash table without ordering relationship between elements) of Points3D <-> Pixel
  
  // unordered hash table give faster access than ordered map ("performance of data structure depends on hash function a lot but on an average the cost of search, insert and delete from hash table is O(1). ")
  // ref: https://www.geeksforgeeks.org/unordered_map-in-cpp-stl/
  
  // unordered_map< Point3D<float>,
  // 		 Point2D<int>,
  // 		 hash_point3d<float>,
  // 		 point3DEquals<float> > htPointPixel; // old definition DEPRECATED

  unordered_map< Point3D<float> *,
		 Point2D<int> * > htPointersPointPixel; // new definition





  
  Vision3D();

  Vision3D(Point3D<T> c,Point3D<T> s); // c position of eye or camera ,s position of center of screen

  ~Vision3D();

  string display(void);

  void displayConstructor(void);

  void displayDestructor(void);
  
  Point2D<T> projection(Point3D<T> m); // projection on screen

  Point2D<T> * projectionRef(Point3D<T> & p);

  //friend ostream& operator<< (ostream &out, Vision3D &vis3d);

  Point2D<int> convert2Pixel(Point2D<T> p); // convert in relative screen coords

  Point2D<int> * convert2PixelRef(Point2D<T> & p);

  Point2D<int> convert2AbsPixel(Point2D<int> p); // convert in absolute screen coords

  Point2D<int> * convert2AbsPixelRef(Point2D<int> & p);

  Point2D<int> convert2ScreenCoord(Point2D<int> p); // convert in computer screen coords (Origin at left top corner)

  Point2D<int> * convert2ScreenCoordRef(Point2D<int> & p);

  // // compute the projection from Points3D to Points2D for the object,results are points
  // void computePoints3DtoPoints2D(void);
  
  // // compute the pixels from Points2D
  // void computePoints2DtoPixels(void);

  // associate Point3D and Pixels in unordered map (Point3D <-> Pixel)
  // DEPRECATED
  //void associatePt3Pix2InMap(void);

  // associate pointers of Point3D and Pixels in unordered map (Point3D <-> Pixel)
  void associatePt3Pix2PointersInMap(void);

  void associatePt3Pix2PointersInMapWithTransform(void);

  Point2D<int> projectPoint3DtoPixel(Point3D<T>);
  Point2D<int> * projectPoint3DtoPixelRef(Point3D<T> &);

  void setViewField(T viewFieldInDegree) { 
    
    this->viewField = ( viewFieldInDegree / 180 ) * PI;
    
    // as i get the viewField angle i set the half screen sizes
    computeWinHalfX();
    
  }

  // return value of view field in radian
  T getViewField() {
    return this->viewField;
  }
  
  void setHalfScreenSizeY(int winHalfSizeY) { 
    this->winHalfSizeY =  winHalfSizeY;
  }

  int getHalfScreenSizeY() {
    return this->winHalfSizeY;
  }

  void setHalfScreenSizeX(int winHalfSizeX) { 
    
    // real half size in pixels of screen on X
    this->winHalfSizeX =  winHalfSizeX;
    if (winHalfSizeX !=0)
      computePixelInUnit();
    
  }
  
  int getHalfScreenSizeX() {
    return this->winHalfSizeX;
  }
  
  void computeWinHalfX() { 
    // half size on X of screen in units of reference frame
    winHalfX = d * tan(viewField);
  }

  T getWinHalfX()  {
    return this->winHalfX;
  }

  void computePixelInUnit() {
    pixelInUnit = winHalfSizeX / winHalfX;
  }
  
  T getPixelInUnit()  {
    return this->pixelInUnit;
  }

};

template <class T> ostream& operator<< (ostream &out, Vision3D<T> &vis3d);

#endif /* VISION3D_HPP */
