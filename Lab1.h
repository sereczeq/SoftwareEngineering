//
// Created by kubas on 03.03.2021.
//

#ifndef ENGINEERING_LAB1_H
#define ENGINEERING_LAB1_H


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

    }
};


#endif //ENGINEERING_LAB1_H
