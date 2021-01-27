#include <iostream>
#include <eigen3/Eigen/Eigen>

using namespace Eigen;
using namespace std;

int main(){
    MatrixXd m(2,2);
    m(0,0) = 3;
    m(1,0) = 2.5;
    m(0,1) = -1;
    m(1,1) = m(1,0)+m(0,1);
    cout << "Here is the matrix \n" << m << endl;

    VectorXd v(2);
    v(0) = 4;
    v(1) = v(0)-1;
    cout << "Here is the vector v: \n" << v << endl;

    Matrix3f w;
        w << 1,2,3,4,5,6,7,8,9;
        cout << "Here is the matrix w \n" <<  w << endl;
}