// Point3D Class
// Damien MATTEI


//#include "Point3D.hpp"

// implementations

template <class T> Point3D<T>::Point3D() : x(0) , y(0) , z(0) {}

template <class T> Point3D<T>::Point3D(T x , T y , T z) : x(x) , y(y) , z(z) {

  // this->z =z;
#ifdef DISPLAY_CONSTRUCTOR
  cout << "# Point3D constructor #" << endl;
#endif
}

template <class T> Point3D<T>::~Point3D() {

#ifdef DISPLAY_CONSTRUCTOR
  cout << "# Point3D destructor #" << endl;
#endif

}

template <class T> ostream&  operator<< (ostream &out, Point3D<T> &p3d)
{
    
  out << "P3D("  
      << p3d.x << ", "
      << p3d.y << ", "
      << p3d.z
      << ")" ;
  
  return out;
  
};     
