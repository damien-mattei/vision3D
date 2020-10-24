// Universe Class
// Damien MATTEI


#include "Universe.hpp"



// implementations

template <class T,class Object_Type> Universe<T,Object_Type>::Universe() {

 
#ifdef DISPLAY_CONSTRUCTOR
  cout << "# Universe constructor # " << this << endl;
#endif
}

template <class T,class Object_Type> Universe<T,Object_Type>::~Universe() {

#ifdef DISPLAY_CONSTRUCTOR
  cout << "# Universe destructor # "  << this << endl;
#endif

}




template <class T,class Object_Type> ostream&  operator<< (ostream &out, Universe<T,Object_Type> &u)
{
    
  out << "Universe("  
      << u
      << ")"
    ;
  
  return out;
  
}


// create a point by checking if it already exist in the universe
template<class T,class Object_Type> Point3D<T> & Universe<T,Object_Type>::createPoint3Dref(T x,T y,T z) {
 
  DEBUG(cerr << "Universe<T>::createPoint3Dref" << endl;)

     
  Point3D<T> & pt3d = *(new Point3D<T>(x,y,z));

  DEBUG(cerr << "Universe<T>::createPoint3Dref : std::find_if ... " << endl;)
  // i check unicity of the point in Universe i.e to save memory and speed
  // i do not want to have two mathematically identical 3D points
  typename list< Point3D<T> *>::iterator iterP3Dptr =
    std::find_if(point3DptrList.begin(), point3DptrList.end(),
		 // lambda in C++
		      [&pt3d](Point3D<T> * pt3d_ptr_lambda_param) {
		                  Point3D<T> & pt3d_lambda_param = *pt3d_ptr_lambda_param;                  
		                  DEBUG(cerr << "Universe<T>::createPoint3Dref : in Lambda" << endl;)
				  //return  *pt3d_ptr_lambda_param == pt3d;
				  return  pt3d_lambda_param == pt3d;
		      }
		 );

  DEBUG(cerr << "Universe<T>::createPoint3Dref : bool found ... " << endl;)
  bool found = (iterP3Dptr != point3DptrList.end());

  
  if (found) {
    
    DEBUG(cerr << "Universe<T>::createPoint3Dref : found ... " << endl;)
    DEBUG(cerr << "Universe<T>::createPoint3Dref : *iterP3Dptr " << *iterP3Dptr << endl;)
    DEBUG(cerr << "Universe<T>::createPoint3Dref : **iterP3Dptr " << **iterP3Dptr << endl;)
      
    delete &pt3d;
    
    //return  static_cast<Point3D<T> &> (*iterP3Dptr); // return the pointer to Point3D
    //return  reinterpret_cast<Point3D<T> &> (*iterP3Dptr); // return the pointer to Point3D
    //return  static_cast<Point3D<T> &> (**iterP3Dptr); // return the pointer to Point3D
    
    return **iterP3Dptr; // return the pointer to Point3D
    
  }
  else { // we have to add the point to the universe
    DEBUG(cerr << "Universe<T>::createPoint3Dptr : NOT found ... " << endl;)
    DEBUG(cerr << "Universe<T>::createPoint3Dref : point3DptrList.push_back(pt3d_ptr);" << endl;)

    point3DptrList.push_back(&pt3d);
    return pt3d;
      
  }

}



// create a point by checking if it already exist in the universe
template<class T,class Object_Type> Point3D<T> * Universe<T,Object_Type>::createPoint3Dptr(T x,T y,T z) {
 
  DEBUG(cerr << "Universe<T>::createPoint3Dptr" << endl;)

  Point3D<T> * pt3d_ptr = new Point3D<T>(x,y,z);
  Point3D<T> & pt3d = *pt3d_ptr;
    
  
  DEBUG(cerr << "Universe<T>::createPoint3Dptr : std::find_if ... " << endl;)
  // i check unicity of the point in Universe i.e to save memory and speed
  // i do not want to have two mathematically identical 3D points
  typename list< Point3D<T> *>::iterator iterP3Dptr =
    std::find_if(point3DptrList.begin(), point3DptrList.end(),
		 // lambda in C++
		      [&pt3d](Point3D<T> * pt3d_ptr_lambda_param) {
		                  Point3D<T> & pt3d_lambda_param = *pt3d_ptr_lambda_param;                  
		                  DEBUG(cerr << "Universe<T>::createPoint3Dptr : in Lambda" << endl;)
				  //return  *pt3d_ptr_lambda_param == pt3d;
				  return  pt3d_lambda_param == pt3d;
		      }
		 );

  DEBUG(cerr << "Universe<T>::createPoint3Dptr : bool found ... " << endl;)
  bool found = (iterP3Dptr != point3DptrList.end());

  
  if (found) {
    
    DEBUG(cerr << "Universe<T>::createPoint3Dptr : found ... " << endl;)
    DEBUG(cerr << "Universe<T>::createPoint3Dptr : *iterP3Dptr " << *iterP3Dptr << endl;)
    DEBUG(cerr << "Universe<T>::createPoint3Dptr : **iterP3Dptr " << **iterP3Dptr << endl;)
      
    delete pt3d_ptr;
     
    //return  static_cast<Point3D<T> &> (*iterP3Dptr); // return the pointer to Point3D
    //return  reinterpret_cast<Point3D<T> &> (*iterP3Dptr); // return the pointer to Point3D
    //return  static_cast<Point3D<T> &> (**iterP3Dptr); // return the pointer to Point3D
    
    return *iterP3Dptr; // return the pointer to Point3D
    
  }
  else { // we have to add the point to the universe
    DEBUG(cerr << "Universe<T>::createPoint3Dptr : NOT found ... " << endl;)
    DEBUG(cerr << "Universe<T>::createPoint3Dptr : point3DptrList.push_back(pt3d_ptr);" << endl;)
    point3DptrList.push_back(pt3d_ptr);
    return pt3d_ptr;
  
      
  }

}

template<class T,class Object_Type> void Universe<T,Object_Type>::createCube(Point3D<T> & p,T s) {

  Point3D<T> & p2 = createPoint3Dref(p.x+s,p.y,p.z);

}

template class Universe<float,Point3D<float>>;
