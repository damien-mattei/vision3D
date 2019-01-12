// Canvas Class
// Damien MATTEI

#ifndef CANVAS_HPP
#define CANVAS_HPP

using namespace std;

#include <iostream>
#include <unordered_map>


// this class is for computing (and displaying,so far i know) 2D canvas 
template <class T> class Canvas {
        
public:
   
  //  // the 3D object
  // Object3D<T> object3d;

  // // the Vision3D object
  // Vision3D<T> vision3d;

 
  Canvas();

  ~Canvas();
    
  //Canvas(Object3D<T> object3d,Vision3D<T> vision3d);

  // Canvas(Vision3D<T> vision3d);

};

#include "Canvas.cpp"

#endif /* CANVAS_HPP */
