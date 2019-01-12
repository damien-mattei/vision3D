// Point3Did Class

// Damien MATTEI


// implementations

template <class T> Point3Did<T>::Point3Did()  : Point3D<T>::Point3D(0 ,0, 0) , id(Point3Did<T>::next_id++) {}

template <class T> Point3Did<T>::Point3Did(T x , T y , T z) : Point3D<T>::Point3D(x, y, z) , id(Point3Did<T>::next_id++) {

#ifdef DISPLAY_CONSTRUCTOR
  cout << "# Point3Did constructor #" << endl;
#endif
}

template <class T> Point3Did<T>::~Point3Did() {

#ifdef DISPLAY_CONSTRUCTOR
  cout << "# Point3D destructor #" << endl;
#endif

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
