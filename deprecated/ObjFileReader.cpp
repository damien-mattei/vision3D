// Object Class
// Damien MATTEI


#include "ObjFileReader.hpp"



// implementations

template <typename T> ObjFileReader<T>::ObjFileReader()  {

 
#ifdef DISPLAY_CONSTRUCTOR
  cout << "# ObjFileReader constructor # " << this << endl;
#endif
}

template <typename T> ObjFileReader<T>::ObjFileReader(string filename) :filename(filename) {

 
#ifdef DISPLAY_CONSTRUCTOR
  cout << "# ObjFileReader constructor # " << this << endl;
#endif
}

template <typename T> ObjFileReader<T>::~ObjFileReader() {

#ifdef DISPLAY_CONSTRUCTOR
  cout << "# ObjFileReader destructor # "  << this << endl;
#endif
  
}



// create an instanciation that will be usefull at linking
template class ObjFileReader<float>;


template <class T> ostream&  operator<< (ostream &out, const ObjFileReader<T> &objFR)
{
    
  out << "ObjFileReader "
      << &objFR // display the adress, without & i should make a recursive call to << operator !!!
      << " filename = " << objFR.filename ;
  
  return out;
  
}

// create an instanciation that will be usefull at linking
template ostream&  operator<< (ostream &, const ObjFileReader<float> &);
