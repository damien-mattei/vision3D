// Object Class
// Damien MATTEI


#include "ObjFile.hpp"



// implementations

template <typename T,typename S> ObjFile<T,S>::ObjFile()  {

 
#ifdef DISPLAY_CONSTRUCTOR
  cout << "# ObjFile constructor # " << this << endl;
#endif
}

template <typename T,typename S> ObjFile<T,S>::ObjFile(string filename,Universe<T> & univ) :filename(filename) , univ(&univ) {

 
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
      //cout << line << endl;
      std::string type;
      iss >> type;

      cout << "ObjFile.cpp : ObjFile : type =" << type << endl;
      
      if (type=="#" || type=="" || type=="o") {
	continue;
      }

      
      
      if (type=="v") {
      
	T x,y,z;
      
	iss >> x; iss >> y; iss >> z;
      
	
	cout << "ObjFile.cpp : ObjFile : vertex : " << "x=" << x << " y=" << y << " z=" << z << endl;

	if(iss.fail()) {
	  cerr << "ObjFile.cpp : ObjFile : Read error,bad value in vertex" << endl;
	}
	else {
	  univ.template createPoint3DRefvectorC<Point3D<T>,T,T,T>(x,y,z); // template 
	}
	continue;
      }

      if (type=="vt") {
      
	T x,y;
      
	iss >> x; iss >> y; 
      
	
	cout << "ObjFile.cpp : ObjFile : texture : " << "x=" << x << " y=" << y << endl;

	if(iss.fail()) {
	  cerr << "ObjFile.cpp : ObjFile : Read error,bad value in texture" << endl;
	}
	
	continue;
      }


      if (type=="vn") {
      
	T x,y,z;
      
	iss >> x; iss >> y; iss >> z;
      
	
	cout << "ObjFile.cpp : ObjFile : normal : " << "x=" << x << " y=" << y << " z=" << z << endl;

	if(iss.fail()) {
	  cerr << "ObjFile.cpp : ObjFile : Read error,bad value in normal" << endl;
	}
	else {
	  univ.template createVector3DRefvectorC<Vector3D<T>,T,T,T>(x,y,z);
	}
	continue;
      }

       if (type=="f") {

	 S iv;

	 std::string vertex;
	 iss >> vertex;

	 if(iss.fail()) {
	  cerr << "ObjFile.cpp : ObjFile : Read error,bad value in Face's vertex" << endl;
	  continue;
	 }
	 
	 cout << "ObjFile.cpp : ObjFile : vertex :" << vertex << "." << endl;

	 
	 std::istringstream issv(vertex);
	 issv >> iv;
	 if(issv.fail()) {
	  cerr << "ObjFile.cpp : ObjFile : Read error,bad value in Face's vertex index" << endl;
	  continue;
	 }

	 cout << "ObjFile.cpp : ObjFile : vertex index :" << iv << "." << endl;

	 char separ;
	 issv >> separ;
	 if(issv.fail()) {
	  cerr << "ObjFile.cpp : ObjFile : Read error,bad value in Face's separator" << endl;
	  continue;
	 }
	 cout << "ObjFile.cpp : ObjFile : vertex separator :" << separ << "." << endl;

	 S it;
	 issv >> it;
	 if(issv.fail()) {
	  cerr << "ObjFile.cpp : ObjFile : Read error,bad value in Face's texture index" << endl;
	  continue;
	 }

	 cout << "ObjFile.cpp : ObjFile : texture index :" << it << "." << endl;

	 issv >> separ;
	 if(issv.fail()) {
	  cerr << "ObjFile.cpp : ObjFile : Read error,bad value in Face's separator" << endl;
	  continue;
	 }
	 cout << "ObjFile.cpp : ObjFile : vertex separator :" << separ << "." << endl;

	 S in;
	 issv >> in;
	 if(issv.fail()) {
	  cerr << "ObjFile.cpp : ObjFile : Read error,bad value in Face's normal index" << endl;
	  continue;
	 }

	 cout << "ObjFile.cpp : ObjFile : normal index :" << in << "." << endl;

	 // end one vertex face
	 
       } // end face
      
    } // end While

}



template <typename T,typename S> ObjFile<T,S>::~ObjFile() {

#ifdef DISPLAY_CONSTRUCTOR
  cout << "# ObjFile destructor # "  << this << endl;
#endif
  
}



// create an instanciation that will be usefull at linking
template class ObjFile<float,int>;


template <class T,class S> ostream&  operator<< (ostream &out, const ObjFile<T,S> &objFR)
{
    
  out << "ObjFile "
      << &objFR // display the adress, without & i should make a recursive call to << operator !!!
      << " filename = " << objFR.filename ;
  
  return out;
  
}

// create an instanciation that will be usefull at linking
template ostream&  operator<< (ostream &, const ObjFile<float,int> &);
