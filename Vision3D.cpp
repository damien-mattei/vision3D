// Vision3D Class
// Damien MATTEI


#include "Vision3D.hpp"


// implementations
template <class T> Vision3D<T>::Vision3D() : c(), s() {}


// c position of eye or camera ,s position of center of screen
template <class T> Vision3D<T>::Vision3D(Point3D<T> c,Point3D<T> s) : c(c), s(s) {

  // compute vector w

  // create SC vector
  Vector3D<T> sc(c,s);
  d = sc.norm(); // compute norm of SC 
  w = sc / d; // normalize w
  
  /* compute vector u
   * knowing u.w = 0
   * and |u| = 1
   */
  u.z = 0;
  u.y = - ( w.x / sqrt(w.x * w.x + w.y * w.y)); // arbitrary taking negative solution for orientation
  u.x = - w.y * u.y / w.x;

  /* compute vector v
   * knowing u ^ v = w
   * i.e: v = w ^ u
   * ( ^ : cross product)
   */
  v = w * u;


  // change of basis matrix

  T da1,da2,da3;

  da1 = v.y * w.z - v.z * w.y;
  da2 = v.z * w.x - v.x * w.z;
  da3 = v.x * w.y - v.y * w.x;

  T db1,db2,db3;

  db1 = w.y * u.z - w.z * u.y;
  db2 = w.z * u.x - w.x * u.z;
  db3 = w.x * u.y - w.y * u.x;

  T dc1,dc2,dc3;

  dc1 = u.y * v.z - u.z * v.y;
  dc2 = u.z * v.x - u.x * v.z;
  dc3 = u.x * v.y - u.y * v.x;

  T dau,dbv,dcw;
  dau = u.x * da1 + u.y * da2 + u.z * da3;
  dbv = v.x * db1 + v.y * db2 + v.z * db3;
  dcw = w.x * dc1 + w.y * dc2 + w.z * dc3;

  m[0][0] = da1 / dau; m[0][1] = da2 / dau; m[0][2] = da3 / dau;
  m[1][0] = db1 / dbv; m[1][1] = db2 / dbv; m[1][2] = db3 / dbv;
  m[2][0] = dc1 / dcw; m[2][1] = dc2 / dcw; m[2][2] = dc3 / dcw;
 
}

template <class T> Vision3D<T>::~Vision3D() {}

template <class T> ostream& operator<< (ostream &out, Vision3D<T> &vis3d)
{
    
  out << "observer : " << vis3d.c 
      << ", center of screen : " << vis3d.s
      << ", u vector: " << vis3d.u
      << ", v vector: " << vis3d.v
      << ", w vector: " << vis3d.w
;
  
  return out;

}


template<class T> Point2D<T> Vision3D<T>::projection(Point3D<T> p) {

  Point3D<T> pPrim( m[0][0] * p.x + m[0][1] * p.y + m[0][2] * p.z,
		    m[1][0] * p.x + m[1][1] * p.y + m[1][2] * p.z,
		    m[2][0] * p.x + m[2][1] * p.y + m[2][2] * p.z );

  T r = d / (d + pPrim.z);
  
  // screen point
  Point2D<T> ps(  pPrim.y * r,
		- pPrim.x * r );

#ifdef DEBUG
  std::cout << " Vision3D<T>::projection : ps : " << ps << std::endl;
#endif

  return ps; 

}


template<class T> Point2D<int> Vision3D<T>::convert2Pixel(Point2D<T> p) {

  Point2D<int> pix( (int) (p.x * pixelInUnit),
		    (int) (p.y * pixelInUnit));
  
  return pix;

}


template<class T> Point2D<int> Vision3D<T>::convert2AbsPixel(Point2D<int> p) {

  Point2D<int> pix( p.x + winHalfSizeX,
		    p.y + winHalfSizeY );
  
  return pix;

}


template<class T> Point2D<int> Vision3D<T>::convert2ScreenCoord(Point2D<int> p) {

  Point2D<int> pix( p.x ,
		    2 * winHalfSizeY - p.y );
  
  return pix;

}

// create a point by checking if it already exist in the universe
template<class T> Point3D<T> * Vision3D<T>::createPoint3D(T x,T y,T z) {

  Point3D<T> pt3d(x,y,z);
  
  typename list< Point3D<T> >::iterator iterP3D = std::find(vertexList.begin(), vertexList.end(), pt3d);
  
  bool found = (iterP3D != vertexList.end());

  // we had to add the point to the universe
  return found ? *iterP3D : &pt3d;
  
  }
