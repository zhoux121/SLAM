#include <eigen3/Eigen/Eigen>
#include <iostream>

using namespace std;
using namespace Eigen;
int main(){
    MatrixXf m(4,4);
    m << 1,2,3,4,5,6,7,8,9,10,11,12,13,16,14,15;
    cout << "Block in the middle" << endl;
    cout << m.block<2,2>(1,1) << endl << endl;
    for(int i = 1; i <= 3; ++i){
        cout << "block of the size" << i <<"x" << i <<endl;
        cout << m.block(0,0,i,i) << endl << endl;
    }
    
    // Columns and rows
    cout << "2nd row: " << m.row(1) << endl;

    return 0;
}