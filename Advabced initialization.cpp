#include <iostream>
#include <eigen3/Eigen/Eigen>

using namespace Eigen;
using namespace std;

int main(){
    RowVectorXd vec1(3);
    vec1 << 1,2,3;

    RowVectorXd vec2(4);
    vec2 << 4,5,6,7;

    RowVectorXd vec3(7);
    vec3 << vec1,vec2;

    cout << vec3 <<endl;

    ArrayXXf table(10, 4);
    table.col(0) = ArrayXf::LinSpaced(10, 0, 90);
    table.col(1) = M_PI / 180 * table.col(0);
    table.col(2) = table.col(1).sin();
    table.col(3) = table.col(1).cos();
    std::cout << "  Degrees   Radians      Sine    Cosine\n";
    std::cout << table << std::endl;

    return 0;
}