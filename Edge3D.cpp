// Edge3D Class
// Damien MATTEI


// implementations

template <class T> Edge3D<T>::Edge3D() : a(), b() {}

// create edge AB from point A and B
template <class T> Edge3D<T>::Edge3D(Point3D<T> a,Point3D<T> b) : a(a), b(b) {

#ifdef DISPLAY_CONSTRUCTOR
  cout << "# Edge3D constructor #" << endl;
#endif

}

template <class T> Edge3D<T>::~Edge3D() {

#ifdef DISPLAY_CONSTRUCTOR
  cout << "# Edge3D destructor #" << endl;
#endif

}

template <class T> ostream&  operator<< (ostream &out, Edge3D<T> &e)
{
    
  out << "[" << e.a << "] <--> ["
      << e.b << "]";
  
  return out;

}


// template<class T> T  Edge3D<T>::norm() {

//   return ( sqrt(x * x + y * y + z * z) ); 

// }


