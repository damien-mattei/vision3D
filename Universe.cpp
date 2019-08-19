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

  cout << "Universe<T>::createPoint3Dptr" << endl;
  Point3D<T> * pt3d_ptr = new Point3D<T>(x,y,z);
  Point3D<T> & pt3d = *pt3d_ptr;


  cout << "Universe<T>::createPoint3Dptr : std::find_if ... " << endl;
  // i check unicity of the point in Universe i.e to save memory and speed i do not want to have two mathematically identical 3D points
  typename list< Point3D<T> *>::iterator iterP3Dptr = std::find_if(point3DptrList.begin(), point3DptrList.end(),
								   [&pt3d](Point3D<T> * pt3d_ptr_lambda_param)
								   { cout << "Universe<T>::createPoint3Dptr : in Lambda" << endl;
								     return  *pt3d_ptr_lambda_param == pt3d; });

  cout << "Universe<T>::createPoint3Dptr : bool found ... " << endl;
  bool found = (iterP3Dptr != point3DptrList.end());

  // we have to add the point to the universe
  if (found) {
      pt3d.~Point3D<T>();
      return *iterP3Dptr; // return the pointer to Point3D
    }
  else {
    cout << "Universe<T>::createPoint3Dptr : point3DptrList.push_back(pt3d_ptr);" << endl;
    point3DptrList.push_back(pt3d_ptr);
    return pt3d_ptr;
  }

}




