// Matrix.h
#ifndef MATRIX_H
#define MATRIX_H

namespace math {
   template<typename _DataType>
   class Matrix;

   template<typename _T>
   Matrix<_T> operator*(const Matrix<_T> &lhs, const Matrix<_T> &rhs){
      // function body defined here
   }

   template<typename _T>
   class Matrix {
   public:
      friend Matrix<_T> operator*(const Matrix<_T> &, const Matrix<_T> &);

      Matrix& operator*=(const Matrix& rhs){
         *this = *this * rhs;
         return *this;
      }
   };
};

#endif
