// Panorama Class
// Damien MATTEI


#include "Panorama.hpp"



// implementations

template <class T> Panorama<T>::Panorama() {

 
#ifdef DISPLAY_CONSTRUCTOR
  cout << "# Panorama constructor # " << this << endl;
#endif
}

template <class T> Panorama<T>::~Panorama() {

  
  
#ifdef DISPLAY_CONSTRUCTOR
  cout << "# Panorama destructor # "  << this << endl;
#endif

}



template <class T> ostream&  operator<< (ostream &out, const Panorama<T> &pan)
{
  
  out << "Panorama("  
      << &pan
      << ")"
    ;
  
  return out;
  
}


template <class T> Object<T> & Panorama<T>::createObject(string filename) {

  assert(MAX_OBJECTS > ++cpt_obj);

  Object<T> * ptrObject = new Object<T>(filename);

  arrayPtrObject[cpt_obj] = ptrObject;

  Object<T> & refObject = *ptrObject;
  
  return refObject;
  

}



// create an instanciation that will be usefull at linking
template class Panorama<float>;

template ostream&  operator<< (ostream &, const Panorama<float> &);
