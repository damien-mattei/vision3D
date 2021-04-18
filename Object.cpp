// Object Class
// Damien MATTEI


#include "Object.hpp"



// implementations

template <typename T> Object<T>::Object()  {

 
#ifdef DISPLAY_CONSTRUCTOR
  cout << "# Object constructor # " << this << endl;
#endif
}

template <typename T> Object<T>::Object(string name) :name(name) {

 
#ifdef DISPLAY_CONSTRUCTOR
  cout << "# Object constructor # " << this << endl;
#endif
}

template <typename T> Object<T>::~Object() {

#ifdef DISPLAY_CONSTRUCTOR
  cout << "# Object destructor # "  << this << endl;
#endif
  
}


template <class T> void Object<T>::storeVertex(Point3D<T> & p3dRef) {

  vertexList.push_back(&p3dRef);
  DEBUG(cerr << "Object<T>::storeVertex : one Vertex stored : " << p3dRef << endl;)

}


// create an instanciation that will be usefull at linking
template class Object<float>;


template <class T> ostream&  operator<< (ostream &out, const Object<T> &obj)
{
    
  out << "Object "
      << &obj // display the adress, without & i should make a recursive call to << operator !!!
      << " name = "  << obj.name ;
  
  return out;
  
}

// create an instanciation that will be usefull at linking
template ostream&  operator<< (ostream &, const Object<float> &);
