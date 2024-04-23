#include <iostream>
#include <cmath>
using std::endl;

double sum_of_series(int n) {

    double sum {0};

    for (int i = 1; i <= n; i++){
        double pw = pow(i, i);
        sum += 1 / pw;
    }

    return sum;

}

int main(){

    std::cout <<  sum_of_series(5) << endl; 

    return 0;

}
