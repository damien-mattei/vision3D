// Object3DListRef Class
// Damien MATTEI


// class for a 3D object composed of vertex and edges (reference version)

template <class T> Object3DListRef<T>::Object3DListRef() {}


template <class T> Object3DListRef<T>::Object3DListRef( list < Point3Did<T> > & vertexList,list < Edge3D<T> > & edgeList)
: vertexList(&vertexList) , edgeList(&edgeList) {


#ifdef DISPLAY_CONSTRUCTOR
    cout << "# Object3DListRef constructor #" << endl;
#endif

}

template <class T> Object3DListRef<T>::~Object3DListRef() {
  
#ifdef DISPLAY_CONSTRUCTOR
  cout << "# Object3DListRef destructor #" << endl;
#endif
  
}

