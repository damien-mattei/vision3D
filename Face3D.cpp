// Face3D Class
// Damien MATTEI


#include "Face3D.hpp"

// implementations

template <class T> Face3D<T>::Face3D() {

#ifdef DISPLAY_CONSTRUCTOR
  cout << "# constructor Face3D #" << endl;
#endif
  
}


template <class T> Face3D<T>::Face3D(Vector3D<T> & normal) : normal(&normal) {

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

template <class T> void Face3D<T>::addVertex(Point3D<T> & p3d) {

  vertexList.push_back(&p3d);

}


template <class T> ostream&  operator<< (ostream &out, const Face3D<T> &f3d)
{

  Vector3D<T> &n_f3d = *(f3d.normal);
    
  out << "Face3D "
      << &f3d // display the adress, without & i should make a recursive call to << operator !!!
      << ", normal : "  << n_f3d;
  
  return out;
  
}




// copy constructor
// exist but should NOT be used because one Face in Universe should be unique
template <class T> Face3D<T>::Face3D(const Face3D<T> &oneFace3D) {

  normal = oneFace3D.normal;

  // copy the pointer to the list of Point3D : WARNING : no deep copy implemented !!!
  vertexList = oneFace3D.vertexList;
   
  
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
	
	Face3D<T>::normal = oneFace3D.normal; // just for test (Face3D<T>)

	// copy the list of Point3D pointer  : WARNING : no deep copy of points implemented !!! because points are unique in universe
	Face3D<T>::vertexList = oneFace3D.vertexList;
	//list < Point3D<T> *> Face3D<T>::vertexList(oneFace3D.vertexList);
	
      }

    return *this;
}


// useless for Face3D

/* we need to specialize the hash function for our class
   because standart hash function works only with basic types
   such as string,int,etc...
*/

// hash function for Face3D <-> Pixel

template <class T> struct hash_face3d {
  size_t operator()(const Face3D<T> &f3d ) const
  {
    return hash<const Face3D<T> *>()(&f3d); // hash code is made with address !!!
  }
};


// equality test, mainly used with hash tables
//template <class T> struct face3DEquals : binary_function<const Face3D<T>&, const Face3D<T>&, bool> {
template <class T> struct face3DEquals  {
  bool operator()(  const Face3D<T>& lhs, const Face3D<T>& rhs ) const
  {
    return (&lhs == &rhs); // i compare the addresses !!!
  }  
};     


// equality operator
template <class T> bool Face3D<T>::operator== (const Face3D<T> &f3d)  {
  
  //return (normal==f3d.normal); // compare only address,works if vectors are REALLY unique
  Vector3D<T> &n = *normal;
  Vector3D<T> &n_f3d = *(f3d.normal);
  // TODO: code a comparaison of all (permutation of ) vertex of face....
  return (n == n_f3d); //  compare 2 vectors component by component (x,y,z)
    
}

// create an instanciation that will be usefull at linking
template class Face3D<float>;

template ostream&  operator<< (ostream &out, const Face3D<float> &f3d);
