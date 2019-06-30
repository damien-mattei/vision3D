// Point3Did Class

// Damien MATTEI


// implementations

template <class T> Point3Did<T>::Point3Did()  : Point3D<T>::Point3D(0 ,0, 0) , id(Point3Did<T>::next_id++) {

#ifdef DISPLAY_CONSTRUCTOR
  cout << "# Point3Did() constructor #" << endl;
#endif

}

template <class T> Point3Did<T>::Point3Did(T x , T y , T z) : Point3D<T>::Point3D(x, y, z) , id(Point3Did<T>::next_id++) {

#ifdef DISPLAY_CONSTRUCTOR
  cout << "# Point3Did(T x , T y , T z) constructor #" << endl;
#endif
}

template <class T> Point3Did<T>::~Point3Did() {

#ifdef DISPLAY_CONSTRUCTOR
  cout << "# Point3Did destructor #" << endl;
#endif

}

// copy constructor
template <class T> Point3Did<T>::Point3Did(const Point3Did<T> &onePoint3Did) // :
  //Point3D<T>::Point3D(onePoint3Did.x, onePoint3Did.y, onePoint3Did.z) , id(onePoint3Did.id) {

 {
   Point3D<T>::x=onePoint3Did.x;
   Point3D<T>::y=onePoint3Did.y;
   Point3D<T>::z=onePoint3Did.z;
   id=onePoint3Did.id;
  
#ifdef DISPLAY_CONSTRUCTOR
  cout << "# Point3Did copy constructor #" << endl;
#endif

}

// assignation operator
  
template <class T> Point3Did<T> & Point3Did<T>::operator=(const Point3Did<T> &onePoint3Did)
  {

#ifdef DISPLAY_ASSIGN
    cout << "# Point3Did assignation operator #" << endl;
#endif
    
    if (this != &onePoint3Did)
      {
	
	id=onePoint3Did.id;
	Point3D<T>::x=onePoint3Did.x;
	Point3D<T>::y=onePoint3Did.y;
	Point3D<T>::z=onePoint3Did.z;
	
	// delete [] tableau;
	
    }

    return *this;
  }



template <class T> ostream&  operator<< (ostream &out, Point3Did<T> &p3did)
{
    
  out << "P3Did_id_" << p3did.id << "("  
    //<< p3d.x << ", "
    //  << p3d.y << ", "
    //  << p3d.z
      << ")" ;
  
  return out;

}

/* we need to specialize the hash function for our class
   because standart hash function works only with basic types
   such as string,int,etc...
*/

// hash function for Point3Did <-> Pixel

template <class T> struct hash_point3did {
  size_t operator()(const Point3Did<T> &p3did ) const
  {
    return hash<int>()(p3did.id);
  }
};

// equality test, mainly used with hash tables
template <class T> struct point3DidEquals : binary_function<const Point3Did<T>&, const Point3Did<T>&, bool> {
  bool operator()(  const Point3Did<T>& lhs, const Point3Did<T>& rhs ) const
  {
    return (lhs.id == rhs.id);
  }  
};     
