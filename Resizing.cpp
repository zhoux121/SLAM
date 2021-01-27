#include <iostream>
#include <eigen3/Eigen/Eigen>

using namespace Eigen;
using namespace std;

int main(){
    MatrixXd m(2,5);
    m.resize(4,3);
    cout << "The matrix m is of size " << m.rows() << "x" << m.cols() << endl;
    cout << "it has " << m.size() <<  " coefficients" << endl;

    VectorXd v(2);
    v.resize(5);
    cout << "The vector v is of size " << v.size() << endl;
    cout << "As a matrix, v is of size " << v.rows() << "x" << v.cols() << endl;
    return 0;
    //Note: resize in a same size of the previous one, it doesnt change anything
}