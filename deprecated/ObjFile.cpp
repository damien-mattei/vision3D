// Object Class
// Damien MATTEI


#include "ObjFile.hpp"



// implementations

template <typename T> ObjFile<T>::ObjFile()  {

 
#ifdef DISPLAY_CONSTRUCTOR
  cout << "# ObjFile constructor # " << this << endl;
#endif
}

template <typename T> ObjFile<T>::ObjFile(string filename,Universe<T> & univ) :filename(filename) , univ(&univ) {

 
#ifdef DISPLAY_CONSTRUCTOR
  cout << "# ObjFile constructor # " << this << endl;
#endif

  // open the OBJ file
  ifstream objfile;
  objfile.open (filename);

  std::string line;
  while (std::getline(objfile, line))
    {
      trim( line ); // remove white space at begin and end with Boost
      std::istringstream iss(line);
      //cerr << line << endl;
      std::string type;
      iss >> type;

      cerr << "ObjFile.cpp : ObjFile : type =" << type << endl;
      
      if (type=="#" || type=="" || type=="o") {
	continue;
      }

      
      
      if (type=="v") {
      
	T x,y,z;
      
	iss >> x; iss >> y; iss >> z;
      
	
	cerr << "ObjFile.cpp : ObjFile : vertex : " << "x=" << x << " y=" << y << " z=" << z << endl;

	if(iss.fail()) {
	  cerr << "Read error,bad value in vertex" << endl;
	}
	else {
	  univ.template createPoint3DRefvectorC<Point3D<T>,T,T,T>(x,y,z); // template 
	}
	continue;
      }

      if (type=="vt") {
      
	T x,y;
      
	iss >> x; iss >> y; 
      
	
	cerr << "ObjFile.cpp : ObjFile : texture : " << "x=" << x << " y=" << y << endl;

	if(iss.fail()) {
	  cerr << "Read error,bad value in texture" << endl;
	}
	
	continue;
      }


      if (type=="vn") {
      
	T x,y,z;
      
	iss >> x; iss >> y; iss >> z;
      
	
	cerr << "ObjFile.cpp : ObjFile : normal : " << "x=" << x << " y=" << y << " z=" << z << endl;

	if(iss.fail()) {
	  cerr << "Read error,bad value in normal" << endl;
	}
	else {
	  univ.template createVector3DRefvectorC<Vector3D<T>,T,T,T>(x,y,z);
	}
	continue;
      }
    } // end While

}



template <typename T> ObjFile<T>::~ObjFile() {

#ifdef DISPLAY_CONSTRUCTOR
  cout << "# ObjFile destructor # "  << this << endl;
#endif
  
}



// create an instanciation that will be usefull at linking
template class ObjFile<float>;


template <class T> ostream&  operator<< (ostream &out, const ObjFile<T> &objFR)
{
    
  out << "ObjFile "
      << &objFR // display the adress, without & i should make a recursive call to << operator !!!
      << " filename = " << objFR.filename ;
  
  return out;
  
}

// create an instanciation that will be usefull at linking
template ostream&  operator<< (ostream &, const ObjFile<float> &);
