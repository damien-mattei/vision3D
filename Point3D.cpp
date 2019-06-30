// Point3D Class
// Damien MATTEI


#include "Point3D.hpp"

// implementations

template <class T> Point3D<T>::Point3D() : x(0) , y(0) , z(0) {}


template <class T> Point3D<T>::Point3D(T x , T y , T z) : x(x) , y(y) , z(z) {

  // this->z =z;
#ifdef DISPLAY_CONSTRUCTOR
  cout << "# Point3D constructor # " << this << endl;
#endif
}

template <class T> Point3D<T>::~Point3D() {

#ifdef DISPLAY_CONSTRUCTOR
  cout << "# Point3D destructor # "  << this << endl;
#endif

}




template <class T> ostream&  operator<< (ostream &out, Point3D<T> &p3d)
{
    
  out << "P3D("  
      << p3d.x << ", "
      << p3d.y << ", "
      << p3d.z
      << ")"
    ;
  
  return out;
  
}


// copy constructor
template <class T> Point3D<T>::Point3D(const Point3D<T> &onePoint3D) {

  x=onePoint3D.x;
  y=onePoint3D.y;
  z=onePoint3D.z;
   
  
#ifdef DISPLAY_CONSTRUCTOR
  cout << "# Point3D copy constructor # " << this  << endl;
#endif

}


// assignation operator
  
template <class T> Point3D<T> & Point3D<T>::operator=(const Point3D<T> &onePoint3D)
  {

#ifdef DISPLAY_ASSIGN
    cout << "# Point3D assignation operator #" << endl;
#endif
    
    if (this != &onePoint3D)
      {
	
	x=onePoint3D.x;
	y=onePoint3D.y;
	z=onePoint3D.z;
	
	// delete [] tableau;
	
    }

    return *this;
  }



/* we need to specialize the hash function for our class
   because standart hash function works only with basic types
   such as string,int,etc...
*/

// hash function for Point3D <-> Pixel

template <class T> struct hash_point3d {
  size_t operator()(const Point3D<T> &p3d ) const
  {
    return hash<int>()(&p3d); // hash code is made with address !!!
  }
};


// equality test, mainly used with hash tables
template <class T> struct point3DEquals : binary_function<const Point3D<T>&, const Point3D<T>&, bool> {
  bool operator()(  const Point3D<T>& lhs, const Point3D<T>& rhs ) const
  {
    return (&lhs == &rhs); // i compare the addresses !!!
  }  
};     

// equality operator
template <class T> bool Point3D<T>::operator== (const Point3D<T> &p3d)  {
    
    return (x==p3d.x) && (y==p3d.y) && (z==p3d.z);
    
  }
