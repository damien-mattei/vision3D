// Universe Class
// Damien MATTEI

#include "Point3D.hpp"
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
template<class T> Point3D<T> * Universe<T>::createPoint3Dptr(T x,T y,T z) {

  Point3D<T> * pt3d_ptr = new Point3D<T>(x,y,z);
  Point3D<T> & pt3d = *pt3d_ptr;

  // i check unicity of the point in Universe i.e to save memory and speed i do not want to have two mathematically identical 3D points
  typename list< Point3D<T> >::iterator iterP3D = std::find(vertexList.begin(), vertexList.end(), pt3d);
  
  bool found = (iterP3D != vertexList.end());

  // we have to add the point to the universe
  if (found) {
      pt3d.~Point3D<T>();
      return &(*iterP3D);
    }
  else {
    cout << "vertexList.push_back(pt3d);" << endl;
    vertexList.push_back(pt3d);
    return pt3d_ptr;
  }

}



// create a point by checking if it already exist in the universe
template<class T> Point3D<T> Universe<T>::createPoint3D(T x,T y,T z) {

  Point3D<T> pt3d = Point3D<T>(x,y,z);

  // i check unicity of the point in Universe i.e to save memory and speed i do not want to have two mathematically identical 3D points
  typename list< Point3D<T> >::iterator iterP3D = std::find(vertexList.begin(), vertexList.end(), pt3d);
  
  bool found = (iterP3D != vertexList.end());

  // we have to add the point to the universe
  if (found) {
    pt3d.~Point3D<T>();
    return *iterP3D;
  }
  else {
    vertexList.push_back(pt3d);
    return pt3d;
  }

}


