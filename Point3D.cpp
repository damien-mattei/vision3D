// Point3D Class
// Damien MATTEI


#include "Point3D.hpp"

// implementations

template <class T> Point3D<T>::Point3D() : x(0) , y(0) , z(0) {

#ifdef CHECK_MEMORY
  cpt_cons++; // for verifying memory allocation/desallocation
#endif
  
#ifdef DISPLAY_CONSTRUCTOR
  cout << "# constructor "  << this->display() << " #" << endl;
#endif
  
}


template <class T> Point3D<T>::Point3D(T x , T y , T z) : x(x) , y(y) , z(z) {

  // this->z =z;

#ifdef CHECK_MEMORY
  cpt_cons++; // for verifying memory allocation/desallocation
#endif
  
#ifdef DISPLAY_CONSTRUCTOR
  cout << "# constructor "  << this->display() << " #" << endl;
#endif

  
}


template <class T> Point3D<T>::~Point3D() {

#ifdef CHECK_MEMORY
  cpt_cons--; // for verifying memory allocation/desallocation
  printf("Point3D<T>::~Point3D() : remaining %i Point3D(s).\n",cpt_cons);
#endif
  
#ifdef DISPLAY_CONSTRUCTOR
  cout << "# destructor " << this->display() << " #" << endl;
  
#endif
  
}


template <class T>  string Point3D<T>::display(void) {

  std::stringstream stream;

  stream << "Point3D @" << " 0x" << std::hex << (long)this << " " << *this;
 
  return stream.str();

}



template <class T> ostream&  operator<< (ostream &out, const Point3D<T> &p3d)
{
    
  out << "Point3D "
      << &p3d // display the adress, without & i should make a recursive call to << operator !!!
      << " ("  << p3d.x << ", " << p3d.y << ", " << p3d.z << ")";
  
  return out;
  
}




// copy constructor
// exist but should NOT be used because one point in Universe should be unique
template <class T> Point3D<T>::Point3D(const Point3D<T> &onePoint3D) {

#ifdef CHECK_MEMORY
  cpt_cons++; // for verifying memory allocation/desallocation
#endif
  
  x=onePoint3D.x;
  y=onePoint3D.y;
  z=onePoint3D.z;
   
  
#ifdef DISPLAY_CONSTRUCTOR
  cout << "# Point3D copy constructor # " << &onePoint3D << " => " << this << " " << *this << endl;
#endif

}


// assignation operator
// same comment as for copy constructor:
// exist but should NOT be used because one point in Universe should be unique
template <class T> Point3D<T> & Point3D<T>::operator=(const Point3D<T> &onePoint3D) {

#ifdef DISPLAY_ASSIGN
    cout << "# Point3D assignation operator #" << endl;
#endif
    
    if (this != &onePoint3D)

      {
	
	Point3D<T>::x=onePoint3D.x; // just for test
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
    return hash<const Point3D<T> *>()(&p3d); // hash code is made with address !!!
  }
};


// equality test, mainly used with hash tables
//template <class T> struct point3DEquals : binary_function<const Point3D<T>&, const Point3D<T>&, bool> { // deprecated in C++17
template <class T> struct point3DEquals  {
  bool operator()(  const Point3D<T>& lhs, const Point3D<T>& rhs ) const
  {
    return (&lhs == &rhs); // i compare the addresses !!!
  }  
};     

// equality operator
template <class T> bool Point3D<T>::operator== (const Point3D<T> &p3d)  {
  
  return (x==p3d.x) && (y==p3d.y) && (z==p3d.z);
    
}

// create an instanciation that will be usefull at linking
template class Point3D<float>;

template ostream&  operator<< (ostream &, const Point3D<float> &);
