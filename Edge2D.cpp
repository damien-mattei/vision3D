// Edge2D Class
// Damien MATTEI

#include "Edge2D.hpp"

// implementations

template <class T> Edge2D<T>::Edge2D() : a(), b() {

#ifdef DISPLAY_CONSTRUCTOR
  cout << "# constructor "  << this->display() << " #" << endl;
#endif

}

  
// create edge AB from point A and B
//template <class T> Edge2D<T>::Edge2D(Point2D<T> a,Point2D<T> b) : a(a), b(b) {*
  template <class T> Edge2D<T>::Edge2D(Point2D<T> ap,Point2D<T> bp) {

  a = ap;
  b = bp;

#ifdef DISPLAY_CONSTRUCTOR
  cout << "# constructor "  << this->display() << " #" << endl;
#endif

}


template <class T> Edge2D<T>::~Edge2D() {

#ifdef DISPLAY_CONSTRUCTOR
  cout << "# destructor " << this->display() << " #" << endl;
#endif

}


template <class T>  string Edge2D<T>::display(void) {

  std::stringstream stream;

  stream << "Edge2D @" << " 0x" << std::hex << (long)this << " "
	 <<  " [" << this->a.display() << " <--> " << this->b.display() << "]";

  return stream.str();

}



template <class T> ostream&  operator<< (ostream &out, Edge2D<T> &e)
{
    
  out << " [" << e.a << " <--> " << e.b << "]";
  
  return out;

}


// template<class T> T  Edge2D<T>::norm() {

//   return ( sqrt(x * x + y * y + z * z) ); 

// }


template class Edge2D<double>;

template ostream&  operator<< (ostream &out, Edge2D<double> &e);
