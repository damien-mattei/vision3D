// Point2D Class
// Damien MATTEI


#include "Point2D.hpp"

// implementations



template <class T> Point2D<T>::Point2D() : x(0), y(0) {

#ifdef DISPLAY_CONSTRUCTOR
  cout << "# constructor "  << this->display() << " #" << endl;
#endif

}

template <class T> Point2D<T>::Point2D(T x,T y) : x(x), y(y) {
  
#ifdef DISPLAY_CONSTRUCTOR
  cout << "# constructor "  << this->display() << " #" << endl;
#endif

}

template <class T> Point2D<T>::~Point2D() {

#ifdef DISPLAY_CONSTRUCTOR
  cout << "# destructor " << this->display() << " #" << endl;
#endif

}

template <class T>  string Point2D<T>::display(void) {

  std::stringstream stream;
  //stream << "Point2D@" << std::setfill ('0') << std::setw(sizeof(long)*2) << std::hex << (long)this << "(" << x << "," << y << ")";
  stream << "Point2D @" << " 0x" << std::hex << (long)this << " " << *this;
  //return std::string("Point2D@") + std::to_string((long)this) + std::string("(") + std::to_string(x) + std::string(",") + std::to_string(y) + std::string(")");
  return stream.str();

}


template <class T> ostream&  operator<< (ostream &out, Point2D<T> &p2d)
{
    
  out << "(" << p2d.x << ","
      << p2d.y << ")";
  
  return out;

}


// copy constructor
template <class T> Point2D<T>::Point2D(const Point2D<T> &onePoint2D) {

  x=onePoint2D.x;
  y=onePoint2D.y;
   
  
#ifdef DISPLAY_CONSTRUCTOR
  cout << "# copy constructor Point2D " << &onePoint2D << " => " << this << " " << *this << " #" << endl;
#endif

}



// equality operator
template <class T> bool Point2D<T>::operator== (const Point2D<T> &p2d)  {
  
  return (x==p2d.x) && (y==p2d.y);
    
}


template class Point2D<double>;
template class Point2D<int>;
template class Point2D<float>;

template  ostream&  operator<< (ostream &out, Point2D<double> &p2d);
