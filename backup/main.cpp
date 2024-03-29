// main for testing Vision3D code

#include "Face3D.hpp"
#include "ObjFile.hpp"


#include "Edge3D.hpp"

#include "Edge2D.hpp"

#include "Point2D.hpp"

#include "Vision3D.hpp"

#include "Object.hpp"

#include "Panorama.hpp"


//extern template int Universe<float>::GetMax<int>( int,int ) ;


using namespace std;

int main() {

  int x,y;
  x=3;
  y=5;

  
  
  cout << " ----------- test Universe ------------------  " << endl;

 
  // we create twice the same point's coordinates
  Universe<float> univ;

  cout << " ----------- test Pan ------------------  " << endl;
  
  Panorama<float> pan;

  pan.createObject("toto");

  cout << " ----------- end test Pan ------------------  " << endl;

  univ.GetMax <int,float> (x,y);

  cout << " ----------- test ObjFile ------------------  " << endl;

  ObjFile<float,int> objF("./contrib/cube.obj",univ,pan);

  cout << "main : objF = " << objF << endl;

  cout << " ----------- End test ObjFile ------------------  " << endl;

  // DEPRECATED 
  Point3D<float> & tp = univ.createObjectRef<Point3D<float>,float,float,float>(1.0,2.0,3.0);

  cout << "main : tp = " << tp << endl;

  // cout << " ----------- test Object ------------------  " << endl;

  // Object<float> obj0;
  // Object<float> obj("cubby");

  // cout << "main : obj = " << obj << endl;
  
  // obj.storeVertex(tp);
  
  // cout << " ----------- End test Object ------------------  " << endl;
  

  Point3D<float> & tp2 = univ.createObjectRef<Point3D<float>,float,float,float>(1.0,2.0,3.0);

  cout << "tp2 : " << tp2 << endl;

  cout << " creation Cube 0 " << endl;
  univ.createCube(tp,1.5);

  cout << " avec des point3D (il y a construction d'un Point3D supplémentaire par le constructeur de recopie !) " << endl;
 
  Point3D<float> pot = univ.createPoint3DReflistC<Point3D<float>,float,float,float>(7.0,2.0,3.0);
  cout << "pot : " << pot << endl;
  cout << " creation Cube 1  " << endl;
  univ.createCube(pot,1.7);
  
  cout << " avec des references vers des point3D " << endl;

  //Point3D<float> & pt3d_uniq_ref = univ.createPoint3Dref(1,0,0);
  Point3D<float> & pt3d_uniq_ref = univ.createPoint3DReflistC<Point3D<float>,float,float,float>(1,0,0);
  
  cout << "pt3d_uniq_ref : " << pt3d_uniq_ref << endl;

  cout << " avec des references vers des Point3D et un container std::vector" << endl;
  
  Point3D<float> & pt3d_uniq_ref_vector = univ.createPoint3DRefvectorC<Point3D<float>,float,float,float>(7,4,7);
  
  cout << "pt3d_uniq_ref_vector : " << pt3d_uniq_ref_vector << endl;

  
  cout << " avec des references vers des Vector3D et un container std::vector" << endl;
  
  Vector3D<float> & vt3d_uniq_ref_vector = univ.createVector3DRefvectorC<Vector3D<float>,float,float,float>(4,0,7);
  
  cout << "vt3d_uniq_ref_vector : " << vt3d_uniq_ref_vector << endl;
  
  // DEPRECATED
  Point3D<float> & pt3d_uniq_ref2 = univ.createPoint3DReference(1,0,0);
  
  cout << "pt3d_uniq_ref2 : " << pt3d_uniq_ref2 << endl;

  cout << " --------------------------- " << endl;

  cout << " avec des pointeurs vers des point3D " << endl;

  Point3D<float> * pt3d_uniq_ptr = univ.createPoint3Dptr(2,0,0);

  Point3D<float> & pt3d_uniq_ref3 = *pt3d_uniq_ptr;

  cout << "pt3d_uniq_ref3 : " << pt3d_uniq_ref3 << endl;

  Point3D<float> * pt3d_uniq_ptr2 = univ.createPoint3Dptr(2,0,0);

  pt3d_uniq_ref3 = *pt3d_uniq_ptr2;

  cout << "pt3d_uniq_ref3 : " << pt3d_uniq_ref3 << endl;

  cout << "univ =" << univ << endl; 
  
  cout << " ------------- end test Universe -------------------------------  " << endl;
  
  //Vision3D<float> vis0;

  list < Point3D<float> > lst0;

  cout << " ------------- test Face3D -------------------------------  " << endl;
  
  Face3D<float> f1(vt3d_uniq_ref_vector);

  cout << "f1 : " << f1 << endl;

  cout << " ------------- end test Face3D -------------------------------  " << endl;
  
  cout << " -----------------------------  " << endl;
  
  Point3D<float> pt3d(7,8,9);
  
  cout << "pt3d : " << pt3d << endl;
  
  Point3D<float> pt3dbis(pt3d);
  
  cout << " -----------------------------  " << endl;
  
  cout << "pt3dbis : " << pt3dbis << endl;
  
  cout << " creation Cube 2  " << endl;
  univ.createCube(pt3d,1.5);
  
  cerr << endl << endl << "Matrix test: " << endl;
  
  Matrix3x3<float> m33((float) 1.0,(float) 1.0,(float) 1.0,(float) 1.0,(float) 1.0,(float) 1.0,(float) 1.0,(float) 1.0,(float) 1.0);

  Matrix3x3<float> m33res = (float) 3.0 * m33;
  
  Matrix3x3<float> m33res2 = m33 * (float) 5.0;

  Matrix3x3<float> m33res3 = m33 / (float) 5.0;

  cout << "main : m33res3 =" << endl << m33res3 << endl;
  
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

  // cout << "vis.u : " << vis.u << endl;

  // cout << "vis.v : " << vis.v << endl;

  // cout << "vis.w : " << vis.w << endl;

  vis.setViewField(20); // a view field of twenty degree
  vis.setHalfScreenSizeX(400); // 400 pixels
  vis.setHalfScreenSizeY(300); // 300 pixels

  // CanvasList<float> cv(cube,vis);
  // cv.computePoints3DtoPoints2D(); // compute the coords
  // cv.computePoints2DtoPixels(); // compute the pixels
  
  // cv.computePoints3DtoPixels(); // compute the pixels directly from points 3D
  // cv.associatePt3Pix2(); // create list of pair of points 3D and Pixels
  // cv.associatePt3Pix2InMap();
  // cv.displayHTpointPixel(); 

  //Vector3D<float> v2 = vis.w ^ vis.u;

  // cout << "v2 : " << v2 << endl;

  
  
  float d2 = 2;

  //Vector3D<float> f = c/d2;
  //cout << f << endl;

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

  cout << "a :" << a << endl;
  
  Edge3D<float> ab(a,b);

  cout << "ab :" << ab << endl;

  cout << endl;



  
  
  Point2D<double> x1(1.5,3.7);

  cout << "x1:" << x1 << endl;

  cout << "x1=" << x1.display() << endl;

  Point2D<double> x2(2.5,3.4);

  cout << "x2:" << x2 << endl;

  cout << "x2=" << x2.display() << endl;

  Edge2D<double> x1x2(x1,x2);

  cout << "x1x2:" << x1x2 << endl;

  cout << "x1x2=" << x1x2.display() << endl;

  cout << endl;



  
  
  float angle(20.0);

  vis3.setViewField( angle );

  cout << vis3.getViewField() << endl;

  // CanvasList<float> scene;

  // scene.associatePt3Pix2InMap();


}


