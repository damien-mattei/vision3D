// CubeList Class
// Damien MATTEI


// class for a 3D object composed of vertex and edges

template <class T> CubeList<T>::CubeList()  {//: Object3DList<T>::Object3DList() {

#ifdef DISPLAY_CONSTRUCTOR
    cout << "# CubeList constructor #" << endl;
#endif

    // definition for cube

    // the vertex
    Point3D<T> cubeP1(0.0, 0.0, 0.0);
    Point3D<float> cubeP2(0.0, 0.0, 1.0);
    Point3D<float> cubeP3(0.0, 1.0, 0.0);
    Point3D<float> cubeP4(0.0, 1.0, 1.0);
    Point3D<float> cubeP5(1.0, 0.0, 0.0);
    Point3D<float> cubeP6(1.0, 0.0, 1.0);
    Point3D<float> cubeP7(1.0, 1.0, 0.0);
    Point3D<float> cubeP8(1.0, 1.0, 1.0);

    // the list of vertex
    
#ifdef REF_OR_PTR
    list < Point3D<float> * > vertexCubeP;
#endif

    list < Point3D<float> > vertexCube;
    
#ifdef REF_OR_PTR
    vertexCubeP.push_back(&cubeP1);
#endif
    
    vertexCube.push_back(cubeP1);
    vertexCube.push_back(cubeP2);
    vertexCube.push_back(cubeP3);
    vertexCube.push_back(cubeP4);
    vertexCube.push_back(cubeP5);
    vertexCube.push_back(cubeP6);
    vertexCube.push_back(cubeP7);
    vertexCube.push_back(cubeP8);
    

    
    // the vertical edges
    Edge3D<float> edgeCubeP1P2(cubeP1,cubeP2);
    Edge3D<float> edgeCubeP3P4(cubeP3,cubeP4);
    Edge3D<float> edgeCubeP5P6(cubeP5,cubeP6);
    Edge3D<float> edgeCubeP7P8(cubeP7,cubeP8);
    
    // the bottom horizontal edges
    Edge3D<float> edgeCubeP1P3(cubeP1,cubeP3);
    Edge3D<float> edgeCubeP3P5(cubeP3,cubeP5);
    Edge3D<float> edgeCubeP5P7(cubeP5,cubeP7);
    Edge3D<float> edgeCubeP7P1(cubeP7,cubeP1);
    
    // the top    horizontal edges
    Edge3D<float> edgeCubeP2P4(cubeP2,cubeP4);
    Edge3D<float> edgeCubeP4P6(cubeP4,cubeP6);
    Edge3D<float> edgeCubeP6P8(cubeP6,cubeP8);
    Edge3D<float> edgeCubeP8P2(cubeP8,cubeP2);

    // the list of edges
    list < Edge3D<float> > edgeCube;

    edgeCube.push_back(edgeCubeP1P2);
    edgeCube.push_back(edgeCubeP3P4);
    edgeCube.push_back(edgeCubeP5P6);
    edgeCube.push_back(edgeCubeP7P8);
    edgeCube.push_back(edgeCubeP1P3);
    edgeCube.push_back(edgeCubeP3P5);
    edgeCube.push_back(edgeCubeP5P7);
    edgeCube.push_back(edgeCubeP7P1);
    edgeCube.push_back(edgeCubeP2P4);
    edgeCube.push_back(edgeCubeP4P6);
    edgeCube.push_back(edgeCubeP6P8);
    edgeCube.push_back(edgeCubeP8P2);
    
    //    Object3DList<float> cube(vertexCube,edgeCube);
    
    Object3DList<T>::vertexList = vertexCube;
    Object3DList<T>::edgeList = edgeCube;

}



template <class T> CubeList<T>::~CubeList() {
  
#ifdef DISPLAY_CONSTRUCTOR
  cout << "# CubeList destructor #" << endl;
#endif
  
}

