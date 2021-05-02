// Face3D Class
// Damien MATTEI


#include "Face3D.hpp"

// implementations

template <class T> Face3D<T>::Face3D() : x(0) , y(0) , z(0) {

#ifdef DISPLAY_CONSTRUCTOR
  cout << "# constructor "  << this->display() << " #" << endl;
#endif
  
}


template <class T> Face3D<T>::Face3D(T x , T y , T z) : x(x) , y(y) , z(z) {

  // this->z =z;

#ifdef DISPLAY_CONSTRUCTOR
  cout << "# constructor "  << this->display() << " #" << endl;
#endif

  
}


template <class T> Face3D<T>::~Face3D() {

#ifdef DISPLAY_CONSTRUCTOR
  cout << "# destructor " << this->display() << " #" << endl;
#endif
  
}


template <class T>  string Face3D<T>::display(void) {

  std::stringstream stream;

  stream << "Face3D @" << " 0x" << std::hex << (long)this << " " << *this;
 
  return stream.str();

}



template <class T> ostream&  operator<< (ostream &out, const Face3D<T> &p3d)
{
    
  out << "Face3D "
      << &p3d // display the adress, without & i should make a recursive call to << operator !!!
      << " ("  << p3d.x << ", " << p3d.y << ", " << p3d.z << ")";
  
  return out;
  
}




// copy constructor
// exist but should NOT be used because one point in Universe should be unique
template <class T> Face3D<T>::Face3D(const Face3D<T> &oneFace3D) {

  x=onePoint3D.x;
  y=onePoint3D.y;
  z=onePoint3D.z;
   
  
#ifdef DISPLAY_CONSTRUCTOR
  cout << "# Face3D copy constructor # " << &oneFace3D << " => " << this << " " << *this << endl;
#endif

}


// assignation operator
// same comment as for copy constructor:
// exist but should NOT be used because one point in Universe should be unique
template <class T> Face3D<T> & Face3D<T>::operator=(const Face3D<T> &oneFace3D) {

#ifdef DISPLAY_ASSIGN
    cout << "# Face3D assignation operator #" << endl;
#endif
    
    if (this != &oneFace3D)

      {
	
	Face3D<T>::x=oneFace3D.x; // just for test
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

// hash function for Face3D <-> Pixel

template <class T> struct hash_point3d {
  size_t operator()(const Face3D<T> &p3d ) const
  {
    return hash<const Face3D<T> *>()(&p3d); // hash code is made with address !!!
  }
};


// equality test, mainly used with hash tables
template <class T> struct point3DEquals : binary_function<const Face3D<T>&, const Face3D<T>&, bool> {
  bool operator()(  const Face3D<T>& lhs, const Face3D<T>& rhs ) const
  {
    return (&lhs == &rhs); // i compare the addresses !!!
  }  
};     

// equality operator
template <class T> bool Face3D<T>::operator== (const Face3D<T> &p3d)  {
  
  return (x==p3d.x) && (y==p3d.y) && (z==p3d.z);
    
}

// create an instanciation that will be usefull at linking
template class Face3D<float>;

template ostream&  operator<< (ostream &out, const Face3D<float> &p3d);
