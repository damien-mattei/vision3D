// Object Class
// Damien MATTEI


#include "Object.hpp"



// implementations

template <class T> Object<T>::Object()  {

 
#ifdef DISPLAY_CONSTRUCTOR
  cout << "# Object constructor # " << this << endl;
#endif
}

template <class T> Object<T>::Object(string filename) :filename(filename) {

 
#ifdef DISPLAY_CONSTRUCTOR
  cout << "# Object constructor # " << this << endl;
#endif
}

template <class T> Object<T>::~Object() {

#ifdef DISPLAY_CONSTRUCTOR
  cout << "# Object destructor # "  << this << endl;
#endif
  
}


template <class T> void Object<T>::storeVertex(Point3D<T> & p3dRef) {

  vertexVector.push_back(&p3dRef);
  DEBUG(cerr << "Object<T>::storeVertex : one Vertex stored : " << p3dRef << endl;)

}

template <class T> void Object<T>::storeVector(Vector3D<T> & v3dRef) {

  normalVector.push_back(&v3dRef);
  DEBUG(cerr << "Object<T>::storeVector : one Vector stored : " << v3dRef << endl;)

}

// create an instanciation that will be usefull at linking
template class Object<float>;


template <class T> ostream&  operator<< (ostream &out, const Object<T> &obj)
{
    
  out << "Object "
      << &obj // display the adress, without & i should make a recursive call to << operator !!!
      << " filename = "  << obj.filename ;
  
  return out;
  
}

// create an instanciation that will be usefull at linking
template ostream&  operator<< (ostream &, const Object<float> &);
