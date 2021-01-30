#include <iostream>
#include <cmath>
#include <eigen3/Eigen/Eigen>

using namespace std;
using namespace Eigen;

int main(int argc, char** argv){
    //
    Matrix3d rotation_matrix = Matrix3d::Identity();
    cout << "Identiry matrix =\n" << rotation_matrix <<endl; 
    cout << "===============================" << endl;
    //rotation vector using AngleAxis, the base of it is not Matrix, but the caluculations are the same
    AngleAxisd rotation_vector(M_PI/4, Vector3d(0,0,1)); //rotation by Z axis 45degree
    cout .precision(3);
    cout << "rotation matrix =\n" << rotation_vector.matrix() << endl; // use matrix() switch vector to matrix
    cout << "===============================" << endl;
    rotation_matrix = rotation_vector.toRotationMatrix();
    //use AngleAxis can use for setting change
    Vector3d v(1,0,0);
    Vector3d v_rotated = rotation_vector * v;
    cout << "(1,0,0) after rotation = " << v_rotated.transpose() << endl;
    cout << "===============================" << endl;
    
    //eular angle: can let rotation matrix directly change to eular angle
    v_rotated = rotation_matrix * v;
    cout << "(1,0,0) after rotation = " << v_rotated.transpose() << endl;
    cout << "===============================" << endl;
    Vector3d euler_angle = rotation_matrix.eulerAngles(2,1,0); // yaw pitch roll
    cout << "Yaw Pitch Roll = " << euler_angle.transpose() << endl;
    cout << "===============================" << endl;

    //eular change matrix using Eigen::Isometry
    Isometry3d T = Isometry3d::Identity(); // this is a 4 by 4 matrix
    T.rotate(rotation_vector); // rotation vector 
    T.pretranslate(Vector3d(1,3,4)); // the shifting vector (1,3,4)
    cout << "Transfor matrix = \n" << T.matrix() << endl;
    cout << "===============================" << endl;

    //use transformation matrix during coordinate change
    Vector3d v_transformed = T*v; // R*v + t
    cout << "v transformed = " << v_transformed.transpose() << endl;
    cout << "===============================" << endl;
    //use affine transformation v_affine
    //use projective transformation Projective3d
    // Quaternion
    // can directly give value from AngleAxis to Quaternion
    Quaterniond q = Quaterniond(rotation_vector);
    cout << "Quaterniond = \n" << q.coeffs() << endl; // NOTE coeffs ordering (i,j,k,w) i j k is imaginary number w is real number
    cout << "===============================" << endl;
    // can also give the rotation matrix value
    q = Quaterniond(rotation_matrix);
    cout << "Quaternion = \n" << q.coeffs() << endl;
    cout << "===============================" << endl;
    //use quaternion rotate a vector
    v_rotated = q*v; // ON math it is qvq^{-1}
    cout << "(1,0,0) after rotation = " << v_rotated.transpose() << endl;
    cout << "===============================" << endl;
    // (3x3) Eigen::Matrix3d
    // (3x1) Eigen::AngleAxisd
    // (3x1) Vector3d
    // (4x1) Eigen::Quaterniond
    // (4x4) Eigen::Isometry3d
    // (4x4) Eigen::Affine3d
    // (4x4) Eigen::Projective3d 
    return 0;
}