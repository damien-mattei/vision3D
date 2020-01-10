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
  // Vector3D<T> * ptr_w = sc | d; // normalize w
  // w = *ptr_w;
  w = sc /d;
  
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
  v = w ^ u;


  // change of basis matrix

  // T da1,da2,da3;

  // da1 = v.y * w.z - v.z * w.y;
  // da2 = v.z * w.x - v.x * w.z;
  // da3 = v.x * w.y - v.y * w.x;

  Vector3D<T> da = v ^ w;
  
  // T db1,db2,db3;

  // db1 = w.y * u.z - w.z * u.y;
  // db2 = w.z * u.x - w.x * u.z;
  // db3 = w.x * u.y - w.y * u.x;

  Vector3D<T> db = w ^ u;

  // T dc1,dc2,dc3;

  // dc1 = u.y * v.z - u.z * v.y;
  // dc2 = u.z * v.x - u.x * v.z;
  // dc3 = u.x * v.y - u.y * v.x;

  Vector3D<T> dc = u ^ v;
  
  T dau,dbv,dcw;
  // dau = u.x * da1 + u.y * da2 + u.z * da3;
  // dbv = v.x * db1 + v.y * db2 + v.z * db3;
  // dcw = w.x * dc1 + w.y * dc2 + w.z * dc3;

  dau = u * da;
  dbv = v * db;
  dcw = w * dc;

  // m[0][0] = da1 / dau; m[0][1] = da2 / dau; m[0][2] = da3 / dau;
  // m[1][0] = db1 / dbv; m[1][1] = db2 / dbv; m[1][2] = db3 / dbv;
  // m[2][0] = dc1 / dcw; m[2][1] = dc2 / dcw; m[2][2] = dc3 / dcw;

  // Vector3D<T> * daquPtr = da | dau;
  // Vector3D<T> * dbqvPtr = db | dbv;
  // Vector3D<T> * dcqwPtr = dc | dcw;

  // // q mean quotient i.e: daqu -> da Quotient u
  // Vector3D<T> & daqu = *daquPtr;
  // Vector3D<T> & dbqv = *dbqvPtr;
  // Vector3D<T> & dcqw = *dcqwPtr;

  Vector3D<T> daqu = da / dau;
  Vector3D<T> dbqv = db / dbv;
  Vector3D<T> dcqw = dc / dcw;
  
  // m[0][0] = da.x / dau; m[0][1] = da.y / dau; m[0][2] = da.z / dau;
  // m[1][0] = db.x / dbv; m[1][1] = db.y / dbv; m[1][2] = db.z / dbv;
  // m[2][0] = dc.x / dcw; m[2][1] = dc.y / dcw; m[2][2] = dc.z / dcw;

  m[0][0] = daqu.x; m[0][1] = daqu.y; m[0][2] = daqu.z;
  m[1][0] = dbqv.x; m[1][1] = dbqv.y; m[1][2] = dbqv.z;
  m[2][0] = dcqw.x; m[2][1] = dcqw.y; m[2][2] = dcqw.z;
 
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

//  une version avec reference en argument et resultat
template<class T> Point2D<T> * Vision3D<T>::projectionRef(Point3D<T> & p) {

  Point3D<T> pPrim( m[0][0] * p.x + m[0][1] * p.y + m[0][2] * p.z,
		    m[1][0] * p.x + m[1][1] * p.y + m[1][2] * p.z,
		    m[2][0] * p.x + m[2][1] * p.y + m[2][2] * p.z );

  T r = d / (d + pPrim.z);
  
  // screen point
  Point2D<T> * ps = new Point2D<T>(  pPrim.y * r,
				   - pPrim.x * r );

   
#ifdef DEBUG
  std::cout << " Vision3D<T>::projection : ps : " << ps << std::endl;
#endif

  return ps; // warning: ps should be deleted by the calling function

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
		    (int) (p.y * pixelInUnit) );
  
  return pix;

}

template<class T> Point2D<int> * Vision3D<T>::convert2PixelRef(Point2D<T> & p) {

  Point2D<int> * pix = new Point2D<T>( (int) (p.x * pixelInUnit),
				       (int) (p.y * pixelInUnit) );
  
  return pix;  // warning: pix should be deleted by the calling function

}



template<class T> Point2D<int> Vision3D<T>::convert2AbsPixel(Point2D<int> p) {

  Point2D<int> pix( p.x + winHalfSizeX,
		    p.y + winHalfSizeY );
  
  return pix;

}


template<class T> Point2D<int> * Vision3D<T>::convert2AbsPixelRef(Point2D<int> & p) {

  Point2D<int> * pix = new Point2D<T>( p.x + winHalfSizeX,
				       p.y + winHalfSizeY );
  
  return pix;

}



template<class T> Point2D<int> Vision3D<T>::convert2ScreenCoord(Point2D<int> p) {

  Point2D<int> pix( p.x ,
		    2 * winHalfSizeY - p.y );
  
  return pix;

}

template<class T> Point2D<int> * Vision3D<T>::convert2ScreenCoordRef(Point2D<int> & p) {

  Point2D<int> * pix = new Point2D<int>( p.x ,
					 2 * winHalfSizeY - p.y );
  
  return pix; // warning: pix should be deleted by the calling function

}

// functional programming style :-)
template<class T> Point2D<int> Vision3D<T>::projectPoint3DtoPixel(Point3D<T> p) {
  
  return convert2ScreenCoord(
			     convert2AbsPixel(
					      convert2Pixel(
							    projection(p))));
}

// une version avec pointeurs,  liberer les variables intermédiaires, donc decomposee en etapes d'affectations aussi
// less functional programming :-( but a little more fast
template<class T> Point2D<int> * Vision3D<T>::projectPoint3DtoPixelRef(Point3D<T> & p) {

  // screen point
  Point2D<T> * ps = projectionRef(p);
  Point2D<int> * pix = convert2PixelRef(ps);
  delete ps;
  Point2D<int> * pixAbs = convert2AbsPixelRef(pix);
  delete pix; 
  Point2D<int> * pixScreenCoord = convert2ScreenCoordRef(pixAbs);
  delete pixAbs;
  return pixScreenCoord;
		  
}


// // compute the 3D -> 2D for the object
// // so we got the projected 2D points as result
// // nota: this is intermediate calculus that could be used for debugging
// template<class T> void Vision3D<T>::computePoints3DtoPoints2D(void)  {
    
//   // finding the vertex list
//   list < Point3D<T> > vertexList = univ.vertexList;

//   // iterate on the list to compute 3D to 2D projection
//   // note : i put typename hint because as it is a template definition
//   // compiler can not know the type it is until the compiler knows T
//   typename list< Point3D<T> >::iterator iterP3D;
  
//   for ( iterP3D = vertexList.begin();
// 	iterP3D != vertexList.end();
// 	++iterP3D )
    
//     points2d.push_back(projection(*iterP3D));
  

// }


// // compute the pixels, starting from 2D points
// // nota: again this is a whole part calculus splitted in two for debugging
// template<class T> void Vision3D<T>::computePoints2DtoPixels(void) {
  
//   // iterate on the list 2D point list to compute pixels
//   // note : i put typename hint because as it is a template definition
//   // compiler can not know the type it is until the compiler knows T
//   typename list< Point2D<T> >::iterator iterP2D;
//   for (iterP2D = points2d.begin(); iterP2D != points2d.end(); ++iterP2D) 
//     pixels.push_back(convert2ScreenCoord(convert2AbsPixel(convert2Pixel(*iterP2D))));
    
// }


// associate Point3D and Pixels in unordered map (Point3D <-> Pixel)
// DEPRECATED new version use pointers instead of copying objects
template<class T> void Vision3D<T>::associatePt3Pix2InMap(void) {

  Point2D<int> pt2;
   
  // finding the vertex list
  list < Point3D<T> > vertexList = univ.vertexList;
  
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



// associate Point3D and Pixels in unordered map (Point3D <-> Pixel)
// pointers and reference version

template<class T> void Vision3D<T>::associatePt3Pix2PointersInMap(void) {

  Point2D<int> * ptr_pt2;
   
  // finding the vertex list
  list < Point3D<T> *> vertexPtrList = univ.point3DptrList;
  
  // iterate on the list to compute 3D to 2D projection and Pixels calculus
  // note : i put typename hint because as it is a template definition
  // compiler can not know the type it is until the compiler knows T
  typename list< Point3D<T> *>::iterator iterPtrP3D;
  
  DEBUG(std::cout << "getViewField() : " << getViewField() << std::endl;
	std::cout << "getHalfScreenSizeX() : " << getHalfScreenSizeX() << std::endl;
	std::cout << "getPixelInUnit() : " << getPixelInUnit() << std::endl;)
  

  
  for (iterPtrP3D = vertexPtrList.begin(); iterPtrP3D != vertexPtrList.end(); ++iterPtrP3D) {

    Point3D<T> * ptrP3D = *iterPtrP3D;
    Point3D<T> & refP3D = *ptrP3D;
    
    DEBUG(std::cout << " **iterPtrP3D : " << **iterPtrP3D << std::endl;)

    // seems to be for debug only
    Point2D<float> ptproj = projection(**iterPtrP3D);
    DEBUG(std::cout << " ptproj : " << ptproj << std::endl;)
    Point2D<int> ptc2p = convert2Pixel(ptproj);
    DEBUG(std::cout << " ptc2p : " << ptc2p << std::endl;)


    //pt2 = projectPoint3DtoPixel(**iterPtrP3D);
    //pt2 = projectPoint3DtoPixel(*ptrP3D);

    // a pointer returned from projection & co
    ptr_pt2 = projectPoint3DtoPixelRef(refP3D);
    
    Point2D<int> & ref_pt2 = *ptr_pt2;
    DEBUG(std::cout << " ref_pt2 : " << ref_pt2 << std::endl;)

    //htPointersPointPixel[*iterPtrP3D] = &pt2;
    //htPointersPointPixel[*ptrP3D] = &pt2;
    //htPointersPointPixel[refP3D] = &pt2;

    htPointersPointPixel[ptrP3D] = ptr_pt2;
    
  }
  
}


