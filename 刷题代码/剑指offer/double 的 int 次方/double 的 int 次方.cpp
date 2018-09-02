#include <iostream>
#include <cmath>
using namespace std;
/*
    快速幂可以处理底数为负的情况。
*/
double Power(double base, int exponent) {
    if (exponent == 0) return 1;

    int exponentTemp = exponent;
    exponent = abs(exponent);
    double result = 1,temp = base;

    //快速幂求解 x ^ y
    while(exponent) {
        if (exponent & 1) result *= temp;
        temp *= temp;
        exponent >>= 1;
    }

    return exponentTemp < 0 ? (double) 1 / result : result;
}

double cg_pow(int x,int y) {
    int temp = abs(y);
    long result = 1;
    while(temp) {
        if (temp & 1) result *= x;
        x *= x;
        temp >>= 1;
    }
    cout<<"result:"<<result<<endl;
    return (y < 0) ? (double)1/result : result;
}

int main(void){

    cout<<Power(1.1,2)<<endl;
    cout<<Power(1.1,0)<<endl;
    cout<<Power(2,-3)<<endl;
    cout<<Power(-2,3)<<endl;
    cout<<Power(-2,-3)<<endl;
    cout<<Power(-2,-4)<<endl;
    //cout<<cg_pow(-2,-4)<<endl;
    return 0;
}
