#include <iostream>
#include <ctime>

using namespace std;

//Eigin Part
#include <eigen3/Eigen/Eigen>
//#include <Eigin/Core>
//Dense Martrix 
//#include <Eigin/Dense>

#define MATRIX_SIZE 50


/****************
 * This Project is use for Eigen Tutoral
 ***************/
int main(int argc, char **argv) {
    //Eigen以矩阵为基础数据单元，他是一个模板类
    //他的前三个参数为（数据类型，行，列）
    //声明一个2*3 matrix float
    Eigen::Matrix<float,2,3>matrix_23;
    
    //同时，Eigen通过typeof提供了许多内置不过底层依旧是Eigen::Matrix
    //Vector3d实质上就是Eigen::Matrix<double,3,1>
    Eigen::Vector3d v_3d;
    
    //Matrix3d 实则上是 Eigen::Matrix<doulbe,3,3>
    Eigen::Matrix3d matrix_33 = Eigen::Matrix3d::Zero(); //初始化为零
    
    //如果不确定矩阵大小，可以使用动态大小的矩阵
    Eigen::Matrix<double, Eigen::Dynamic,Eigen::Dynamic> Matrix_dynamic;
    
    //更简单的,与上面一样效果
    Eigen::MatrixXd Matrix_x;
    
    //对矩阵的操作演示
    //输入的数据
    matrix_23 << 1,2,3,4,5,6;
    //输出数据
    cout << matrix_23 << endl;
    
    cout << "******" << endl;
    
    //用for loop访问矩阵中的元素
    for (int i = 0; i < 1; i++){
        for (int j = 0; j < 2; j++){
            cout << matrix_23(i,j) << endl;
        }
    }
    
    cout << "******" << endl;
    
    v_3d << 3,2,1;
    //矩阵和向量相称（实际上还是矩阵和矩阵）
    //但在这里你不能混合两种不同类型的矩阵，像这样就是错的！报错的小老地
    //Eigen::Matrix<double,2,1> result_wrong_type = matrix_23 * v_3d;
    //cout << result_wrong_type << endl;
    //正确转换为
    Eigen::Matrix<double,2,1> result = matrix_23.cast<double>() * v_3d;
    cout << result << endl;
    cout << "******" << endl;
    
    //同样不能搞错矩阵的维度
    //取消下面的注释 看看报错 结果维度必须正确
    //Eigen::Matrix<double,2,2> result_wrong_type = matrix_23.cast<double>() * v_3d;
    
    //一些矩阵运算
    matrix_33 = Eigen::Matrix3d::Random();
    cout << matrix_33 << endl << endl;
    cout << "******" << endl;
    
    cout << matrix_33.transpose() << endl; //转置
    cout << "******" << endl;
    
    cout << matrix_33.sum() << endl; // Sum of matrix
    cout << "******" << endl;
    
    cout << matrix_33.trace() << endl; //迹
    cout << "******" << endl;
    
    cout << 10 * matrix_33 << endl; //数乘
    cout << "******" << endl;
    
    cout << matrix_33.inverse() << endl; //inverse of matrix
    cout << "******" << endl;
    
    cout << matrix_33.determinant() << endl; //行列式
    cout << "******" << endl;
    
    //特征值
    //实对称矩阵可以保证对角化成功
    Eigen::SelfAdjointEigenSolver<Eigen::Matrix3d> eigen_solver (matrix_33.transpose()*matrix_33);
    cout << "Eigen values = " << endl << eigen_solver.eigenvalues() << endl;
    cout << "Eigen vectors = " << endl << eigen_solver.eigenvectors() << endl;
    cout << "******" << endl;
    
    //解方程
    //我们求解 matrix_NN * x = v_Nd 这个方程
    //N的大小在千百年的宏里定义，矩阵有随机数生成
    //直接求逆自然是最直接，但是求逆运算量太大
    Eigen::Matrix < double, MATRIX_SIZE, MATRIX_SIZE> matrix_NN;
    matrix_NN = Eigen::MatrixXd::Random(MATRIX_SIZE, MATRIX_SIZE);
    Eigen::Matrix<double,MATRIX_SIZE,1> v_Nd;
    v_Nd = Eigen::MatrixXd::Random(MATRIX_SIZE,1);
    
    clock_t time_stt = clock();//计时

    //直接求逆
    Eigen::Matrix<double, MATRIX_SIZE,1> x = matrix_NN.inverse()*v_Nd;
    cout << x << endl;
    cout << "Time use in normal inverse is " << 1000*(clock()-time_stt)/(double)CLOCKS_PER_SEC << "ms" << endl;
    cout << "******" << endl;

    //通常用矩阵分解来求，列入QR分解，速度会更快
    time_stt = clock();
    x = matrix_NN.colPivHouseholderQr().solve(v_Nd);
    cout << x << endl;
    cout << "Time use in Qr compsition is " << 1000*(clock() - time_stt)/(double)CLOCKS_PER_SEC << "ms" << endl;
    cout << "******" << endl;
    
    //列出 LU
    time_stt = clock();
    x = matrix_NN.householderQr().solve(v_Nd);
    cout << x << endl;
    cout << "Time use in house holder QR is " << 1000*(clock() - time_stt)/(double)CLOCKS_PER_SEC << "ms" << endl;
    
    
    return 0;
}
