// main for testing Vision3D code

#include <list>


using namespace std;

#define DISPLAY_CONSTRUCTOR 1

#include "Vision3D.hpp"

#include "Vector3D.hpp"

#include "Point3D.hpp"

#include "Point3Did.hpp"

#include "Edge3D.hpp"

#include "Edge2D.hpp"

#include "Object3D.hpp"

#include "Object3DList.hpp"

#include "Canvas.hpp"

#include "CanvasList.hpp"

#include "CubeList.hpp"

#include "Object3DListRef.hpp"

#include "CanvasListRef.hpp"

int main() {
  
  Vision3D<float> vis0;

  list < Point3D<float> > lst0;

   
  cout << " -----------------------------  " << endl;
  
  Point3D<float> pt3d(7,8,9);
  
  cout << "pt3d : " << pt3d << endl;
  
  Point3D<float> pt3dbis(pt3d);
  
  cout << " -----------------------------  " << endl;
  
  cout << "pt3dbis : " << pt3dbis << endl;
  
  //exit(1);
  
#include "cube_def.hpp"
  
  Point3D<float> b(2,2,1.2);
  
  Vector3D<float> v(7.0,8.0,9.0);

  Vector3D<float> c(1.0,1.0,1.0);

  Vector3D<float> r = c + v;

  Vector3D<float> copie = r;

  Point3D<float> c1(-1.0,0.2,0.5);

  
  cout << " b : " <<b << endl;
  cout << " c1 :" << c1 << endl;
  cout << v << endl;

  cout << c << endl;

  cout << r << endl;

  cout << copie << endl;
 
 
  Vision3D<float> vis(c1,b);

  cout << vis << endl;

  cout << "vis.u : " << vis.u << endl;

  cout << "vis.v : " << vis.v << endl;

  cout << "vis.w : " << vis.w << endl;

  vis.setViewField(20); // a view field of twenty degree
  vis.setHalfScreenSizeX(400); // 400 pixels
  vis.setHalfScreenSizeY(300); // 300 pixels

  CanvasList<float> cv(cube,vis);
  cv.computePoints3DtoPoints2D(); // compute the coords
  cv.computePoints2DtoPixels(); // compute the pixels
  
  cv.computePoints3DtoPixels(); // compute the pixels directly from points 3D
  cv.associatePt3Pix2(); // create list of pair of points 3D and Pixels
  cv.associatePt3Pix2InMap();
  cv.displayHTpointPixel(); 

  Vector3D<float> v2 = vis.w * vis.u;

  cout << "v2 : " << v2 << endl;

  float d2 = 2;

  Vector3D<float> f = c/d2;
  cout << f << endl;

  Vector3D<float> md = c*d2;
  cout << md << endl;

  Vector3D<float> mg = d2*c;
  cout << " mg = " << mg << endl;
  
  //cout << (c / ((float) 2)) << endl; /: does not work

  Point3D<float> center1(2,-2,1.2);

  Point3D<float> oeil1(1.0,-1.0,1.0);

  Vision3D<float> vis1(oeil1,center1);

  cout << vis1 << endl;

  Point3D<float> center2(-2,-2,1.2);

  Point3D<float> oeil2(-1.0,-1.0,1.0);

  Vision3D<float> vis2(oeil2,center2);

  cout << vis2 << endl;
  
  Point3D<float> center3(2,-2,-1.2);

  Point3D<float> oeil3(1.0,-1.0,-1.0);

  Vision3D<float> vis3(oeil3,center3);

  cout << vis3 << endl;

  float m3d[3][3] = {
    { 1,0,0 },
    { 0,1,0 },
    { 0,0,1 }
  };

  Vector3D<float> mul = m3d * mg;

  cout << mul << endl;

  Point3D<float> a(c1);

  Edge3D<float> ab(a,b);

  cout << ab << endl;

  Point2D<double> x1(1.5,3.7);

  Point2D<double> x2(2.5,3.4);

  Edge2D<double> x1x2(x1,x2);

  float angle(20.0);

  vis3.setViewField( angle );

  cout << vis3.getViewField() << endl;

  CanvasList<float> scene;

  scene.associatePt3Pix2InMap();

  //Point2D<int> *ptr_p2dint = new Point2D<int>(4,5);

  Object3DListRef<float> cubeRef(vertexCube,edgeCube);

  cubeRef.name = "cube by reference";

  cout << cubeRef.name << endl;

  cubeRef.printName();

  // finding the vertex list
  //list < Point3Did<float> > & vertexList = cube.vertexList;
  list < Point3Did<float> > vertexList = cube.vertexList;

}


