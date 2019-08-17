// CanvasList Class
// Damien MATTEI


// implementations

template <class T> CanvasList<T>::CanvasList() {
#ifdef DISPLAY_CONSTRUCTOR
  cout << "# CanvasList constructor CanvasList() #" << endl;
#endif
}

template <class T> CanvasList<T>::CanvasList(Object3DList<T> object3dlist,Vision3D<T> vision3d)
  : vision3d(vision3d), object3dlist(object3dlist)  { 
#ifdef DISPLAY_CONSTRUCTOR
    cout << "# CanvasList constructor CanvasList(Object3DList<T> object3dlist,Vision3D<T> vision3d) #" << endl;
#endif
}

template <class T> CanvasList<T>::~CanvasList() {
  
#ifdef DISPLAY_CONSTRUCTOR
  cout << "# CanvasList destructor #" << endl;
#endif
  
}



// compute the 3D -> 2D for the object
// so we got the projected 2D points as result
// nota: this is intermediate calculus that could be used for debugging
template<class T> void CanvasList<T>::computePoints3DtoPoints2D(void)  {
    
  // finding the vertex list
  list < Point3Did<T> > vertexList = object3dlist.vertexList;

  // iterate on the list to compute 3D to 2D projection
  // note : i put typename hint because as it is a template definition
  // compiler can not know the type it is until the compiler knows T
  typename list< Point3Did<T> >::iterator iterP3Did;
  for (iterP3Did = vertexList.begin(); iterP3Did != vertexList.end(); ++iterP3Did) {
    points2d.push_back(vision3d.projection(*iterP3Did));
  }

}

// compute the pixels, starting from 2D points
// nota: again this is a whole part calculus splitted in two for debugging
template<class T> void CanvasList<T>::computePoints2DtoPixels(void) {
  
  // iterate on the list 2D point list to compute pixels
  // note : i put typename hint because as it is a template definition
  // compiler can not know the type it is until the compiler knows T
  typename list< Point2D<T> >::iterator iterP2D;
  for (iterP2D = points2d.begin(); iterP2D != points2d.end(); ++iterP2D) {
    pixels.push_back(
		     vision3d.convert2ScreenCoord(
						  vision3d.convert2AbsPixel(
									    vision3d.convert2Pixel(*iterP2D))));
  }
  
}

// compute the Pixels from Points3D for the object
template<class T> void CanvasList<T>::computePoints3DtoPixels(void)   {
  // deprecated function, see associatePt3Pix2InMap
  
  // finding the vertex list
  list < Point3Did<T> > vertexList = object3dlist.vertexList;
  
  // iterate on the list to compute 3D to 2D projection and Pixels calculus
  // note : i put typename hint because as it is a template definition
  // compiler can not know the type it is until the compiler knows T
  typename list< Point3Did<T> >::iterator iterP3Did;
  for (iterP3Did = vertexList.begin(); iterP3Did != vertexList.end(); ++iterP3Did) {
    pixels.push_back(vision3d.convert2ScreenCoord(
			      vision3d.convert2AbsPixel(
				       vision3d.convert2Pixel(
						vision3d.projection(*iterP3Did)))));
  }
  
}
  

// associate Point3Did and Pixels in list of pair (Point3Did <-> Pixel)
// not usefull instead we use an hash table, see the next function !
template<class T> void CanvasList<T>::associatePt3Pix2(void) {

  // finding the vertex list
  list < Point3Did<T> > vertexList = object3dlist.vertexList;

  // the iterators on the three lists
  typename list < pair < Point3Did<T> , Point2D<int> > >::iterator iterListPt3Pix2;
  typename list< Point3Did<T> >::iterator iterP3Did;
  // iterator on Pixel list
  typename list< Point2D<int> >::iterator iterPixel;

  for (iterP3Did = vertexList.begin(),iterPixel = pixels.begin(),iterListPt3Pix2 = listPt3Pix2.begin();
       iterP3Did != vertexList.end();
       ++iterP3Did,++iterPixel,++iterListPt3Pix2) {
    listPt3Pix2.push_back(make_pair(*iterP3Did,*iterPixel));
  }
  
}


 // associate Point3Did and Pixels in unordered map (Point3Did <-> Pixel)
template<class T> void CanvasList<T>::associatePt3Pix2InMap(void) {

  Point2D<int> pt2;
   
  // finding the vertex list
  list < Point3Did<T> > vertexList = object3dlist.vertexList;
  
  // iterate on the list to compute 3D to 2D projection and Pixels calculus
  // note : i put typename hint because as it is a template definition
  // compiler can not know the type it is until the compiler knows T
  typename list< Point3Did<T> >::iterator iterP3Did;
  
#ifdef DEBUG
  std::cout << "vision3d.getViewField() : " << vision3d.getViewField() << std::endl;
  std::cout << "vision3d.getHalfScreenSizeX() : " << vision3d.getHalfScreenSizeX() << std::endl;
  std::cout << "vision3d.getPixelInUnit() : " << vision3d.getPixelInUnit() << std::endl;
  
#endif
  
  for (iterP3Did = vertexList.begin(); iterP3Did != vertexList.end(); ++iterP3Did) {

#ifdef DEBUG
    std::cout << " *iterP3Did : " << *iterP3Did << std::endl;
    
    Point2D<float> ptproj = vision3d.projection(*iterP3Did);
    std::cout << " ptproj : " << ptproj << std::endl;
    Point2D<int> ptc2p = vision3d.convert2Pixel(ptproj);
    std::cout << " ptc2p : " << ptc2p << std::endl;
#endif

    pt2 = vision3d.convert2ScreenCoord(
		     vision3d.convert2AbsPixel(
			       vision3d.convert2Pixel(
				        vision3d.projection(*iterP3Did))));
    std::cout << " pt2 : " << pt2 << std::endl;
    htPointPixel[*iterP3Did] = pt2;
  }
  
}

// display contents of hash table (Point3Did <-> Pixel)
template<class T> void CanvasList<T>::displayHTpointPixel(void) {

  // finding the vertex list
  list < Point3Did<T> > vertexList = object3dlist.vertexList;
  
  // iterate on the list to compute 3D to 2D projection and Pixels calculus
  // note : i put typename hint because as it is a template definition
  // compiler can not know the type it is until the compiler knows T
  typename list< Point3Did<T> >::iterator iterP3Did;
  for (iterP3Did = vertexList.begin(); iterP3Did != vertexList.end(); ++iterP3Did) {
    std::cout << *iterP3Did << " -> " << htPointPixel[*iterP3Did] << std::endl;
  }

}
