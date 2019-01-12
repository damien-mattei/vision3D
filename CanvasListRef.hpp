// CanvasListRef Class
// Damien MATTEI

#ifndef CANVASLISTREF_HPP
#define CANVASLISTREF_HPP

using namespace std;

#include <iostream>
#include <unordered_map>


// this class is for computing (and displaying,so far i know) 2D canvas 
template <class T> class CanvasListRef : public Canvas<T> {
        
public:


  // the Vision3D object
  Vision3D<T> * vision3d;
  
  // list of points 2D making the CanvasListRef  
  list < Point2D<T> > points2d;

  // the 3D object
  Object3DListRef<T> * object3dlist;


  // list of pixel  
  list < Point2D<int> > pixels;

  // list of pair (Point3Did <-> Pixel)
  list < pair < Point3Did<T> , Point2D<int> > > listPt3Pix2;

  // map (hash table with ordering relationship between elements) of Points3Did <-> Pixel
  unordered_map<Point3Did<float>,Point2D<int>,hash_point3did<float>,point3DidEquals<float>> htPointPixel;

  
  // list of lines (edges) in 2D that are the projection of edges made of 3D points
  list < Edge2D<T> > listEdge2d;
 
  CanvasListRef();

  ~CanvasListRef();

  CanvasListRef(Object3DListRef<T> & object3dlist,Vision3D<T> & vision3d);

  // compute the projection from Points3D to Points2D for the object,results are points
  void computePoints3DtoPoints2D(void);

  // compute the pixels from Points2D
  void computePoints2DtoPixels(void);

  // compute the Pixels from Points3D for the object
  void computePoints3DtoPixels(void);
  

  // associate Point3Did and Pixels in list of pair (Point3Did <-> Pixel)
  // not usefull instead we need an hash table
  void associatePt3Pix2(void);

  // associate Point3Did and Pixels in unordered map (Point3Did <-> Pixel)
  void associatePt3Pix2InMap(void);

  // display contents of hash table (Point3Did <-> Pixel)
  void displayHTpointPixel(void);

};

#include "CanvasListRef.cpp"

#endif /* CANVASLISTREF_HPP */
