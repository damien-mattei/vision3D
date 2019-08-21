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

template<class T> Point2D<int> Vision3D<T>::projectPoint3DtoPixel(Point3D<T> p) {
  
  convert2ScreenCoord(
		      convert2AbsPixel(
				       convert2Pixel(
						     projection(p))));
}


// compute the 3D -> 2D for the object
// so we got the projected 2D points as result
// nota: this is intermediate calculus that could be used for debugging
template<class T> void Vision3D<T>::computePoints3DtoPoints2D(void)  {
    
  // finding the vertex list
  list < Point3D<T> > vertexList = object3dlist.vertexList;

  // iterate on the list to compute 3D to 2D projection
  // note : i put typename hint because as it is a template definition
  // compiler can not know the type it is until the compiler knows T
  typename list< Point3D<T> >::iterator iterP3D;
  
  for ( iterP3D = vertexList.begin();
	iterP3D != vertexList.end();
	++iterP3D )
    
    points2d.push_back(projection(*iterP3D));
  

}


// compute the pixels, starting from 2D points
// nota: again this is a whole part calculus splitted in two for debugging
template<class T> void Vision3D<T>::computePoints2DtoPixels(void) {
  
  // iterate on the list 2D point list to compute pixels
  // note : i put typename hint because as it is a template definition
  // compiler can not know the type it is until the compiler knows T
  typename list< Point2D<T> >::iterator iterP2D;
  for (iterP2D = points2d.begin(); iterP2D != points2d.end(); ++iterP2D) 
    pixels.push_back(convert2ScreenCoord(convert2AbsPixel(convert2Pixel(*iterP2D))));
    
}


// associate Point3D and Pixels in unordered map (Point3D <-> Pixel)

template<class T> void Vision3D<T>::associatePt3Pix2InMap(void) {

  Point2D<int> pt2;
   
  // finding the vertex list
  list < Point3D<T> > vertexList = object3dlist.vertexList;
  
  // iterate on the list to compute 3D to 2D projection and Pixels calculus
  // note : i put typename hint because as it is a template definition
  // compiler can not know the type it is until the compiler knows T
  typename list< Point3D<T> >::iterator iterP3D;
  
  DEBUG(std::cout << "getViewField() : " << getViewField() << std::endl;
	std::cout << "getHalfScreenSizeX() : " << getHalfScreenSizeX() << std::endl;
	std::cout << "getPixelInUnit() : " << getPixelInUnit() << std::endl;)
  

  
  for (iterP3D = vertexList.begin(); iterP3D != vertexList.end(); ++iterP3D) {


    DEBUG(std::cout << " *iterP3D : " << *iterP3D << std::endl;)
    
    Point2D<float> ptproj = projection(*iterP3D);
    DEBUG(std::cout << " ptproj : " << ptproj << std::endl;)
    Point2D<int> ptc2p = convert2Pixel(ptproj);
    DEBUG(std::cout << " ptc2p : " << ptc2p << std::endl;)


    pt2 = projectPoint3DtoPixel(*iterP3D);
    
    DEBUG(std::cout << " pt2 : " << pt2 << std::endl;)
    htPointPixel[*iterP3D] = pt2;
  }
  
}
