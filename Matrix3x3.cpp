// Matrix3x3 Class
// Damien MATTEI

#include "Matrix3x3.hpp"

// implementations

template <class T> Matrix3x3<T>::Matrix3x3() {

  m[0][0]=0; m[0][1]=0; m[0][2]=0;
  m[1][0]=0; m[1][1]=0; m[1][2]=0;
  m[2][0]=0; m[2][1]=0; m[2][2]=0;

#ifdef DISPLAY_CONSTRUCTOR
  cout << "# Matrix3x3 constructor "  << this->display() << " #" << endl;
#endif

}


template <class T> Matrix3x3<T>::Matrix3x3(T m00,T m01,T m02,
					   T m10,T m11,T m12,
					   T m20,T m21,T m22) {
  
  m[0][0]=m00; m[0][1]=m01; m[0][2]=m02;
  m[1][0]=m10; m[1][1]=m11; m[1][2]=m12;
  m[2][0]=m20; m[2][1]=m21; m[2][2]=m22; 

#ifdef DISPLAY_CONSTRUCTOR
  cout << "# Matrix3x3 constructor "  << this->display() << " #" << endl;
#endif

}

template <class T> Matrix3x3<T>::~Matrix3x3() {

#ifdef DISPLAY_CONSTRUCTOR
  cout << "# Matrix3x3 destructor "  << this->display() << " #" << endl;
#endif

}

// create Matrix 3x3 from 3 Vector3D
template <class T> Matrix3x3<T>::Matrix3x3(Vector3D<T> & v1,Vector3D<T> & v2,Vector3D<T> & v3) {
  
  m[0][0]=v1.x; m[0][1]=v1.y; m[0][2]=v1.z;
  m[1][0]=v2.x; m[1][1]=v2.y; m[1][2]=v2.z;
  m[2][0]=v3.x; m[2][1]=v3.y; m[2][2]=v3.z;

}

template <class T>  string Matrix3x3<T>::display(void) {

  std::stringstream stream;

  stream << "Matrix3D @" << " 0x" << std::hex << (long)this << endl << *this;
 
  return stream.str();

}


template <class T> ostream&  operator<< (ostream &out, const Matrix3x3<T> &mr)
{
    
  out << "┌ " << mr.m[0][0] << " " << mr.m[0][1] << " "  << mr.m[0][2] <<  endl // "┐" << endl
      << "│ " << mr.m[1][0] << " " << mr.m[1][1] << " "  << mr.m[1][2] <<  endl // "│" << endl
      << "└ " << mr.m[2][0] << " " << mr.m[2][1] << " "  << mr.m[2][2] <<  endl; // "┘" << endl;
  
  return out;

}




// copy constructor
template <class T> Matrix3x3<T>::Matrix3x3(const Matrix3x3<T> &oneMatrix3x3) {

  m[0][0]=oneMatrix3x3.m[0][0]; m[0][1]=oneMatrix3x3.m[0][1]; m[0][2]=oneMatrix3x3.m[0][2];
  m[1][0]=oneMatrix3x3.m[1][0]; m[1][1]=oneMatrix3x3.m[1][1]; m[1][2]=oneMatrix3x3.m[1][2];
  m[2][0]=oneMatrix3x3.m[2][0]; m[2][1]=oneMatrix3x3.m[2][1]; m[2][2]=oneMatrix3x3.m[2][2];
   
  
#ifdef DISPLAY_CONSTRUCTOR
  cout << "# Matrix3x3 copy constructor # "  << endl << oneMatrix3x3 << " " << &oneMatrix3x3 << " => " << this << endl << *this << endl;
#endif

}

// assignation operator
template <class T> Matrix3x3<T> & Matrix3x3<T>::operator=(const Matrix3x3<T> &mr)
 {
    
    if( this !=  &mr ) {

#ifdef DISPLAY_CONSTRUCTOR
      cout << "# Matrix3x3 assignation operator # "  << endl << mr << " " << &mr << " => "   << this << endl << *this << endl;
#endif

      
      m[0][0] = mr.m[0][0]; m[0][1] = mr.m[0][1]; m[0][2] = mr.m[0][2];
      m[1][0] = mr.m[1][0]; m[1][1] = mr.m[1][1]; m[1][2] = mr.m[1][2];
      m[2][0] = mr.m[2][0]; m[2][1] = mr.m[2][1]; m[2][2] = mr.m[2][2];
         
    }
    
    return *this;
    
  }


template <class T> Matrix3x3<T> & Matrix3x3<T>::operator+=(const Matrix3x3<T> &mr)
 {
  
   m[0][0] += mr.m[0][0]; m[0][1] += mr.m[0][1]; m[0][2] += mr.m[0][2];
   m[1][0] += mr.m[1][0]; m[1][1] += mr.m[1][1]; m[1][2] += mr.m[1][2];
   m[2][0] += mr.m[2][0]; m[2][1] += mr.m[2][1]; m[2][2] += mr.m[2][2];
      
   return *this;
    
 }


template<class T> Matrix3x3<T> Matrix3x3<T>::operator+(const Matrix3x3<T> &mr) {

  return Matrix3x3<T>(
		      m[0][0] + mr.m[0][0], m[0][1] + mr.m[0][1], m[0][2] + mr.m[0][2],
		      m[1][0] + mr.m[1][0], m[1][1] + mr.m[1][1], m[1][2] + mr.m[1][2],
		      m[2][0] + mr.m[2][0], m[2][1] + mr.m[2][1], m[2][2] + mr.m[2][2]
		     );
}

// template<class T> Matrix3x3<T> operator+(const Matrix3x3<T> &ml,const Matrix3x3<T> &mr) {

//   return Matrix3x3<T>(
// 		      ml.m[0][0] + mr.m[0][0], ml.m[0][1] + mr.m[0][1], ml.m[0][2] + mr.m[0][2],
// 		      ml.m[1][0] + mr.m[1][0], ml.m[1][1] + mr.m[1][1], ml.m[1][2] + mr.m[1][2],
// 		      ml.m[2][0] + mr.m[2][0], ml.m[2][1] + mr.m[2][1], ml.m[2][2] + mr.m[2][2]
// 		     );
// }

template<class T> Matrix3x3<T> Matrix3x3<T>::operator/(const T d) {

  return Matrix3x3<T>(
		      m[0][0] / d, m[0][1] / d, m[0][2] / d,
		      m[1][0] / d, m[1][1] / d, m[1][2] / d,
		      m[2][0] / d, m[2][1] / d, m[2][2] / d
		     );
}


// k * M
template<class T> Matrix3x3<T> operator*(const T k,const Matrix3x3<T> &mr) {

  return Matrix3x3<T>(		      
		      mr.m[0][0] * k, mr.m[0][1] * k, mr.m[0][2] * k,
		      mr.m[1][0] * k, mr.m[1][1] * k, mr.m[1][2] * k,
		      mr.m[2][0] * k, mr.m[2][1] * k, mr.m[2][2] * k
		     );
}


// M * k
template<class T> Matrix3x3<T> Matrix3x3<T>::operator*(const T k) {

  return k * (*this);
  // return Matrix3x3<T>(		      
  // 		      m[0][0] * k, m[0][1] * k, m[0][2] * k,
  // 		      m[1][0] * k, m[1][1] * k, m[1][2] * k,
  // 		      m[2][0] * k, m[2][1] * k, m[2][2] * k
  // 		     );
  
}


// template<class T> Matrix3x3<T> operator*(const Matrix3x3<T> &ml,const T k) {

//   return k*ml;
  
// }

// product
template<class T>  Matrix3x3<T> Matrix3x3<T>::operator* (const Matrix3x3<T> &mr)  {

  return Matrix3x3<T>
    (
     m[0][0]*mr.m[0][0]+m[0][1]*mr.m[1][0]+m[0][2]*mr.m[2][0],m[0][0]*mr.m[0][1]+m[0][1]*mr.m[1][1]+m[0][2]*mr.m[2][1],m[0][0]*mr.m[0][2]+m[0][1]*mr.m[1][2]+m[0][2]*mr.m[2][2],
     m[1][0]*mr.m[0][0]+m[1][1]*mr.m[1][0]+m[1][2]*mr.m[2][0],m[1][0]*mr.m[0][1]+m[1][1]*mr.m[1][1]+m[1][2]*mr.m[2][1],m[1][0]*mr.m[0][2]+m[1][1]*mr.m[1][2]+m[1][2]*mr.m[2][2],
     m[2][0]*mr.m[0][0]+m[2][1]*mr.m[1][0]+m[2][2]*mr.m[2][0],m[2][0]*mr.m[0][1]+m[2][1]*mr.m[1][1]+m[2][2]*mr.m[2][1],m[2][0]*mr.m[0][2]+m[2][1]*mr.m[1][2]+m[2][2]*mr.m[2][2]
     );
}


template<class T> Vector3D<T> operator*(const Matrix3x3<T> &m3d,const Vector3D<T> &u) {

  return Vector3D<T>(
		     m3d.m[0][0] * u.x + m3d.m[0][1] * u.y + m3d.m[0][2] * u.z,
		     m3d.m[1][0] * u.x + m3d.m[1][1] * u.y + m3d.m[1][2] * u.z,
		     m3d.m[2][0] * u.x + m3d.m[2][1] * u.y + m3d.m[2][2] * u.z 
		     );
}

template<class T> Vector3D<T> * operator*(const Matrix3x3<T> &m3d,const Vector3D<T> &u) {

  Vector3D<T> * pv3d = new Vector3D<T>(
				       m3d.m[0][0] * u.x + m3d.m[0][1] * u.y + m3d.m[0][2] * u.z,
				       m3d.m[1][0] * u.x + m3d.m[1][1] * u.y + m3d.m[1][2] * u.z,
				       m3d.m[2][0] * u.x + m3d.m[2][1] * u.y + m3d.m[2][2] * u.z 
				       );

  return pv3d;
  
}


template<class T> Point3D<T> operator*(const Matrix3x3<T> &m3d,const Point3D<T> &u) {

  return Point3D<T>(
		     m3d.m[0][0] * u.x + m3d.m[0][1] * u.y + m3d.m[0][2] * u.z,
		     m3d.m[1][0] * u.x + m3d.m[1][1] * u.y + m3d.m[1][2] * u.z,
		     m3d.m[2][0] * u.x + m3d.m[2][1] * u.y + m3d.m[2][2] * u.z 
		     );
}



template class Matrix3x3<float>;

//template Matrix3x3<float> operator/(const Matrix3x3<float> &ml,const float d);

template  ostream&  operator<< (ostream &out, const Matrix3x3<float> &mr);

//template  Matrix3x3<float> operator+(const Matrix3x3<float> &ml,const Matrix3x3<float> &mr);

//template Matrix3x3<float> operator*(const Matrix3x3<float> &ml,const float k);

template Matrix3x3<float> operator*(const float k,const Matrix3x3<float> &mr);

template Vector3D<float> operator*(const Matrix3x3<float> &m3d,const Vector3D<float> &u);

template Point3D<float> operator*(const Matrix3x3<float> &,const Point3D<float> &);
