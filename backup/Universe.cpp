// Universe Class
// Damien MATTEI


#include "Universe.hpp"

// implementations

template <class T> Universe<T>::Universe() {

 
#ifdef DISPLAY_CONSTRUCTOR
  cout << "# Universe constructor # " << this << endl;
#endif
}

template <class T> Universe<T>::~Universe() {

#ifdef DISPLAY_CONSTRUCTOR
  cout << "# Universe destructor # "  << this << endl;
#endif

}




template <class T> ostream&  operator<< (ostream &out, Universe<T> &u)
{
    
  out << "Universe("  
      << u
      << ")"
    ;
  
  return out;
  
}


// create a point by checking if it already exist in the universe
template<class T> Point3D<T> * Universe<T>::createPoint3D(T x,T y,T z) {

  Point3D<T> * pt3d_ptr = new Point3D<T>(x,y,z);
  Point3D<T> & pt3d = *pt3d_ptr;
  
  typename list< Point3D<T> >::iterator iterP3D = std::find(vertexList.begin(), vertexList.end(), pt3d);
  
  bool found = (iterP3D != vertexList.end());

  // we had to add the point to the universe
  return found ? &(*iterP3D) : &pt3d;
  //return &pt3d;
  //return &(*iterP3D);
  //return found ? *iterP3D : pt3d;
  
  }




