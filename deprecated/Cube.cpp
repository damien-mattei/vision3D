// Cube Class
// Damien MATTEI


// class for a 3D object composed of vertex and edges

template <class T> Cube<T>::Cube() {}

template <class T> Cube<T>::Cube(Universe<T> & univ)  {

  // the vertex
  univ.createPoint3D(0.0, 0.0, 0.0);
  univ.createPoint3D(0.0, 0.0, 1.0);
  univ.createPoint3D(0.0, 1.0, 0.0);
  univ.createPoint3D(0.0, 1.0, 1.0);
  univ.createPoint3D(1.0, 0.0, 0.0);
  univ.createPoint3D(1.0, 0.0, 1.0);
  univ.createPoint3D(1.0, 1.0, 0.0);
  univ.createPoint3D(1.0, 1.0, 1.0);


}

template <class T> Cube<T>::Cube( list < Point3D<T> > vertexList,list < Edge3D<T> > edgeList)
  : vertexList(vertexList) , edgeList(edgeList) {
  
 #ifdef DISPLAY_CONSTRUCTOR
    cout << "# Cube constructor #" << endl;
#endif

}

template <class T> Cube<T>::~Cube() {
  
#ifdef DISPLAY_CONSTRUCTOR
  cout << "# Cube destructor #" << endl;
#endif
  
}

