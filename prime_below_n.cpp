#include <iostream>
using std::endl;

int prime_below_target(int target) {

    for (int p = target - 1; p > 1; p--) {

        // exclude all even numbers except 2
        if (p != 2 && p % 2 == 0)
            continue;

        bool isPrime = true;

        // find factors of p exept 1 and p
        // if any factor is found p is not a prime
        for (int f = 2; f < p; f++) {
            if (p % f == 0) {
                isPrime = false;
                break;
            }
        }

        // return prime number
        if (isPrime == true)
            return p;
    }

    // indicate no prime number is found
    return 0;
}

int main() {

    std::cout << prime_below_target(50) << endl;

    return 0;

}
