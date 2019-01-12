// Canvas Class
// Damien MATTEI


// implementations

template <class T> Canvas<T>::Canvas() {
#ifdef DISPLAY_CONSTRUCTOR
  cout << "# Canvas constructor Canvas() #" << endl;
#endif
}

// template <class T> Canvas<T>::Canvas(Object3D<T> object3d,Vision3D<T> vision3d)
//   : object3d(object3d) , vision3d(vision3d) {
// #ifdef DISPLAY_CONSTRUCTOR
//     cout << "# Canvas constructor #" << endl;
// #endif
//   }

// template <class T> Canvas<T>::Canvas(Vision3D<T> vision3d)
//   : vision3d(vision3d) {
// #ifdef DISPLAY_CONSTRUCTOR
//     cout << "# Canvas constructor Canvas(Vision3D<T> vision3d) #" << endl;
// #endif
//   }

template <class T> Canvas<T>::~Canvas() {
  
#ifdef DISPLAY_CONSTRUCTOR
  cout << "# Canvas destructor #" << endl;
#endif
  
}


