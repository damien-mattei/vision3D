#ifndef VISION3D_HPP
#define VISION3D_HPP

#include "Point3D.hpp"
#include "Vector3D.hpp"
#include "Point2D.hpp"
#include "Universe.hpp"

#include "Object3D.hpp"
#include "Object3DList.hpp"

#include <iostream>
#include <cmath> // or math.h
//#include <set>
#include <unordered_map>

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
  //list < Point3D<T> > vertexList;
  
  //set < int > vertexSet;

  Universe<T> univ;

  // list of points 2D making the canvas list  
  list < Point2D<T> > points2d;

  // list of pixel  
  list < Point2D<int> > pixels;

  // the 3D object
  Object3DList<T> object3dlist;

  
  // unordered map (hash table without ordering relationship between elements) of Points3D <-> Pixel
  
  // unordered hash table give faster access ordered map ("performance of data structure depends on hash function a lot but on an average the cost of search, insert and delete from hash table is O(1). ")
  // ref: https://www.geeksforgeeks.org/unordered_map-in-cpp-stl/
  unordered_map<Point3D<float>,Point2D<int>,hash_point3d<float>,point3DEquals<float>> htPointPixel;

  unordered_map<Point3D<float> *,Point2D<int> *> htPointersPointPixel;

  
  Vision3D();

  Vision3D(Point3D<T> c,Point3D<T> s); // c position of eye or camera ,s position of center of screen

  ~Vision3D();

  Point2D<T> projection(Point3D<T> m); // projection on screen

  //friend ostream& operator<< (ostream &out, Vision3D &vis3d);

  Point2D<int> convert2Pixel(Point2D<T> p); // convert in relative screen coords

  Point2D<int> convert2AbsPixel(Point2D<int> p); // convert in absolute screen coords

  Point2D<int> convert2ScreenCoord(Point2D<int> p); // convert in computer screen coords (Origin at left top corner)

  // compute the projection from Points3D to Points2D for the object,results are points
  void computePoints3DtoPoints2D(void);
  
  // compute the pixels from Points2D
  void computePoints2DtoPixels(void);

  // associate Point3D and Pixels in unordered map (Point3D <-> Pixel)
  void associatePt3Pix2InMap(void);

  Point2D<int> projectPoint3DtoPixel(Point3D<T>);
  
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
