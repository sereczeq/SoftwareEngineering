//
// Created by kubas on 03.03.2021.
//

#ifndef ENGINEERING_LAB1_H
#define ENGINEERING_LAB1_H

#include <functional>

class Lab1 {
public:
    static void fibonacci() {
        std::cout << "Which number of Fibonacci sequence?" << std::endl;
        int n = 0;
        std::cin >> n;

        int fib = 0;
        int a = 0;
        int b = 1;

        while (n > 0) {
            fib = a + b;
            b = a;
            a = fib;
            n--;
        }
        std::cout << "Your number is: " << fib << std::endl;
    }

    static void isPrime() {
        std::cout << "Number to check if it's prime" << std::endl;
        int n = 0;
        std::cin >> n;
        int a = 2;
        while (n % a != 0) {
            if (a >= n - 1) {
                std::cout << n << " is prime" << std::endl;
                return;
            }
            a++;
        }
        std::cout << n << " is not prime" << std::endl;
    }

    static void productOfPrimes() {
        
        std::function<bool(int)> isPrimeNested = [](int n) {
            int a = 2;
            while (n % a != 0) {
                if (a >= n - 1) {
                    return true;
                }
                a++;
            }
            return false;
        };

        std::cout << "Number to factor" << std::endl;
        int n = 0;
        std::cin >> n;
        int a = 2;
        while (a <= n) {
            if (n % a == 0) {
                std::cout << a << " * ";
                n /= a;
            } else {
                while (!isPrimeNested(++a)) {}
            }
        }

    }
};


#endif //ENGINEERING_LAB1_H
