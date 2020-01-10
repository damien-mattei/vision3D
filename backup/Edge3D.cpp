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

// create edge AB from point A and B
// template <class T> Edge3D<T>::Edge3D(Point3D<T> & ref_a,Point3D<T> & ref_b) : a(ref_a), b(ref_b) {

// #ifdef DISPLAY_CONSTRUCTOR
//   cout << "# Edge3D constructor by references#" << endl;
// #endif

// }


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



// copy constructor
template <class T> Edge3D<T>::Edge3D(const Edge3D<T> &oneEdge3D) {

  a=oneEdge3D.a;
  b=oneEdge3D.b;
  
#ifdef DISPLAY_CONSTRUCTOR
  cout << "# Edge3D copy constructor #" << endl;
#endif

}


// assignation operator
  
template <class T> Edge3D<T> & Edge3D<T>::operator=(const Edge3D<T> &oneEdge3D)
  {

#ifdef DISPLAY_ASSIGN
    cout << "# Edge3D assignation operator #" << endl;
#endif
    
    if (this != &oneEdge3D)
      {
	
	a=oneEdge3D.a;
	b=oneEdge3D.b;
  
	// delete [] tableau;
	
    }

    return *this;
  }




// template<class T> T  Edge3D<T>::norm() {

//   return ( sqrt(x * x + y * y + z * z) ); 

// }


