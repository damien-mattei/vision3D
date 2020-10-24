// Object3DList Class
// Damien MATTEI


// class for a 3D object composed of vertex and edges

template <class T> Object3DList<T>::Object3DList() {}

template <class T> Object3DList<T>::Object3DList( list < Point3Did<T> > vertexList,list < Edge3D<T> > edgeList)
  : vertexList(vertexList) , edgeList(edgeList) {
  
 #ifdef DISPLAY_CONSTRUCTOR
    cout << "# Object3DList constructor #" << endl;
#endif

}

template <class T> Object3DList<T>::~Object3DList() {
  
#ifdef DISPLAY_CONSTRUCTOR
  cout << "# Object3DList destructor #" << endl;
#endif
  
}

