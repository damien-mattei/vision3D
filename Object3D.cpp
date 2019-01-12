// Object3D Class
// Damien MATTEI


// class for a 3D object composed of vertex and edges

template <class T> Object3D<T>::Object3D() {
#ifdef DISPLAY_CONSTRUCTOR
  cout << "# Object3D constructor #" << endl;
#endif
}

template <class T> Object3D<T>::Object3D( string name)
  : name(name) {
#ifdef DISPLAY_CONSTRUCTOR
    cout << "# Object3D constructor Object3D<T>::Object3D( string name)c#" << endl;
#endif
  }

template <class T> Object3D<T>::~Object3D() {
  
#ifdef DISPLAY_CONSTRUCTOR
  cout << "# Object3D destructor #" << endl;
#endif
  
}

template <class T> void Object3D<T>::printName() {

  cout << name << endl;

}
