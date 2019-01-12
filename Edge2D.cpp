// Edge2D Class
// Damien MATTEI


// implementations

template <class T> Edge2D<T>::Edge2D() : a(), b() {}

// create edge AB from point A and B
template <class T> Edge2D<T>::Edge2D(Point2D<T> a,Point2D<T> b) : a(a), b(b) {

#ifdef DISPLAY_CONSTRUCTOR
  cout << "# Edge2D constructor #" << endl;
#endif

}

template <class T> Edge2D<T>::~Edge2D() {

#ifdef DISPLAY_CONSTRUCTOR
  cout << "# Edge2D destructor #" << endl;
#endif

}

template <class T> ostream&  operator<< (ostream &out, Edge2D<T> &e)
{
    
  out << "[" << e.a << "] <--> ["
      << e.b << "]";
  
  return out;

}


// template<class T> T  Edge2D<T>::norm() {

//   return ( sqrt(x * x + y * y + z * z) ); 

// }


