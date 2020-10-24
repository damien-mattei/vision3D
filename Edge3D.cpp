// Edge3D Class
// Damien MATTEI

#include "Edge3D.hpp"

// implementations

template <class T> Edge3D<T>::Edge3D() : a(), b() {

#ifdef DISPLAY_CONSTRUCTOR
  cout << "# Edge3D constructor #" << endl;
#endif

}

// create edge AB from point A and B
template <class T> Edge3D<T>::Edge3D(Point3D<T> & a,Point3D<T> & b) : a(&a), b(&b) {

#ifdef DISPLAY_CONSTRUCTOR
  cout << "# constructor "<< this->display() << " #" << endl;
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
  cout <<  "# destructor " << this->display() << endl;
#endif

}


template <class T>  string Edge3D<T>::display(void) {

  std::stringstream stream;

  Point3D<T> & ptEdgeA = *(this->a);
  Point3D<T> & ptEdgeB = *(this->b);
  
  stream << "Edge3D @" << " 0x" << std::hex << (long)this << " "
    //	 <<  " [" << this->a->display() << " <--> " << this->b->display() << "]";
    //  <<  " [" << this->a << " <--> " << this->b << "]";
	 <<  " [" << ptEdgeA << " <--> " << ptEdgeB << "]";
  
  return stream.str();

}



template <class T> ostream&  operator<< (ostream &out, Edge3D<T> &e)
{

  Point3D<T> & ptEdgeA = *(e.a);
  Point3D<T> & ptEdgeB = *(e.b);
  //out << "[" << *(e.a) << "] <--> [" << *(e.b) << "]";
  out << "[" << ptEdgeA << "] <--> [" << ptEdgeB << "]";
      
  
  return out;

}



// copy constructor
// logically should not be used (Edge3D are unique)
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

// equality operator
template <class T> bool Edge3D<T>::operator== (const Edge3D<T> &e)  {


  Point3D<T> & ptEdgeA = *(e.a);
  Point3D<T> & ptEdgeB = *(e.b);
  
  Point3D<T> & ptThisEdgeA = *a;
  Point3D<T> & ptThisEdgeB = *b;
  
  return ((ptThisEdgeA==ptEdgeA) && (ptThisEdgeB==ptEdgeB))
    || ((ptThisEdgeA==ptEdgeB) && (ptThisEdgeB==ptEdgeA));
    
}


// template<class T> T  Edge3D<T>::norm() {

//   return ( sqrt(x * x + y * y + z * z) ); 

// }


template class Edge3D<float>;

template ostream&  operator<< (ostream &out, Edge3D<float> &e);
