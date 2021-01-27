#include <iostream>
#include <eigen3/Eigen/Eigen>

using namespace Eigen;
using namespace std;

int main(){
    // Addition and subtraction
    Matrix2d a;
    a << 1,2,2,3;
    MatrixXd b(2,2);
    b << 2,3,4,5;
    cout << "a + b = \n" << a+b << endl;
    cout << "a - b = \n" << a-b << endl;
    cout << "Doing a+=b: " << endl;
    a+=b;
    cout << "Now a=\n" << a <<endl;
    Vector3d v(1,2,3);
    Vector3d w(1,0,0);
    cout << " v + -w + w =\n" << v - w + w << endl;


    // Scalar multiplication and division
    Matrix2d f;
    f << 1,2,3,4;
    Vector3d g(1,2,3);
    cout << "f *2.5 =\n" << f*2.5 << endl;
    cout << "v * 0.1 = \n" << g*0.1 << endl;
    cout << "Doing f=*5 \n" <<endl;
    f*=5;
    cout << "Now f: \n" << f <<endl;


    //Transposition and conjugation
    MatrixXcf h = MatrixXcf::Random(2,2);
    cout << "Here is the matrix a\n" << h << endl;
    cout << "Here is the matrix a^t" << h.transpose() << endl;
    cout << "Here is conjugate of a\n" << h.conjugate() << endl;
    cout << "Here is the matrix adjoint\n" << h.adjoint() << endl;
    //Note do not 
    /*
    Matrix2i a; a << 1, 2, 3, 4;
    cout << "Here is the matrix a:\n" << a << endl;
 
    a = a.transpose(); // !!! do NOT do this !!!
    cout << "and the result of the aliasing effect:\n" << a << endl
    it display as aliaing effect;
    USE transposeInPlace() can slove this issues
    */

   //Dot product and cross product

   Vector3d r(1,2,3);
   Vector3d t(0,1,2);
   cout << "Dot product: " << r.dot(t) << endl;
   double dp = r.adjoint()*t;
   cout << "Dot product via a matrix product" << dp << endl;
   cout  << "Cross product:\n" << r.cross(t) << endl;

   //Basic arithmetic reduction opertions
   Matrix2d mat;
   mat << 1,2,3,4;
   cout << "Here is mat.sum" << mat.sum() << endl;
   cout << "Here is mat.prod" << mat.prod() << endl;
   cout << "Here is mat.mean" << mat.mean() << endl;
   cout << "Here is mat.minCoeff" << mat.minCoeff() << endl;
   cout << "Here is mat.maxCoeff" << mat.maxCoeff() << endl;
   cout << "Here is mat.trace():" << mat.trace() << endl;
   return 0;
}