// Object Class
// Damien MATTEI


#include "ObjFile.hpp"



// implementations

template <typename T> ObjFile<T>::ObjFile()  {

 
#ifdef DISPLAY_CONSTRUCTOR
  cout << "# ObjFile constructor # " << this << endl;
#endif
}

template <typename T> ObjFile<T>::ObjFile(string filename) :filename(filename) {

 
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
            
      if (type=="#" || type=="" || type=="o") {
	continue;
      }
      
      T x,y,z;
      
      iss >> x; iss >> y; iss >> z;
      
      cerr << "|" << type << "|" << endl;
      
    }

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
