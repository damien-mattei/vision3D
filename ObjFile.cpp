// Object Class
// Damien MATTEI


#include "ObjFile.hpp"



// implementations

template <class T,class S> ObjFile<T,S>::ObjFile()  {

 
#ifdef DISPLAY_CONSTRUCTOR
  cout << "# ObjFile constructor # " << this << endl;
#endif
}

template <class T,class S> ObjFile<T,S>::ObjFile(string filename,Universe<T> & univ,Panorama<T> & pan) :filename(filename) , univ(&univ),pan(&pan) {

 
#ifdef DISPLAY_CONSTRUCTOR
  cout << "# ObjFile constructor # " << this << endl;
#endif

  // open the OBJ file
  ifstream objfile;
  objfile.open (filename);
  assert(objfile.is_open()); // abort program otherwise

  //Object<T> & refObject = pan.template createObject<T>(filename);

  Object<T> & refObject = pan.createObject(filename);
  
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
	  // store the point in universe
	  Point3D<T> & refP3d = univ.template createPoint3DRefvectorC<Point3D<T>,T,T,T>(x,y,z); // template
	  // now we must store it also in the object
	  refObject.storeVertex(refP3d);
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
	  Vector3D<T> & refV3d = univ.template createVector3DRefvectorC<Vector3D<T>,T,T,T>(x,y,z);
	  // now we must store it also in the object
	  refObject.storeVector(refV3d);
	}
	continue;
      }

      // # Polygonal face element (see below)
      // f 1 2 3
      // f 3/1 4/2 5/3
      // f 6/4/1 3/5/3 7/6/5
      // f 7//1 8//2 9//3
      
	if (type=="f") {

	  // Face3D must created in Universe
	  //Face3D<T> & refF3d = 
	  
	  S iv;

	  // vertex 
	  std::string vertex;
	  iss >> vertex; // searching an indice

	  if(iss.fail()) {
	    cerr << "ObjFile.cpp : ObjFile : Read error,bad value in Face's vertex" << endl;
	    continue;
	  }
	 
	  cout << "ObjFile.cpp : ObjFile : vertex :" << vertex << "." << endl;

	 
	  std::istringstream issv(vertex);
	  issv >> iv; // reading a type number
	  if(issv.fail()) {
	    cerr << "ObjFile.cpp : ObjFile : Read error,bad value in Face's vertex index" << endl;
	    continue;
	  }

	  cout << "ObjFile.cpp : ObjFile : vertex index :" << iv << "." << endl;
	  // todo: case space or slash ....
	  char separ;
	  issv >> separ;
	  if(issv.fail()) {
	    cerr << "ObjFile.cpp : ObjFile : Read error,bad value in Face's separator" << endl;
	    continue;
	  }
	  cout << "ObjFile.cpp : ObjFile : vertex separator :" << separ << "." << endl;

	  // texture
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



template <class T,class S> ObjFile<T,S>::~ObjFile() {

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
