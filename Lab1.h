//
// Created by kubas on 03.03.2021.
//

#ifndef ENGINEERING_LAB1_H
#define ENGINEERING_LAB1_H

#include <functional>
#include <string>

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

        std::function<bool(int)> isPrime = [](int n) {
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
                while (!isPrime(++a)) {}
            }
        }

    }

    static void DecToP() {
        std::cout << "Input number in decimal and base of system you want to convert to" << std::endl;
        int decimal = 0;
        int base = 0;
        std::cin >> decimal;
        std::cin >> base;
        std::string res;
        while(decimal > 0)
        {
            res = std::to_string(decimal % base) + res;
            decimal /= base;
        }
        std::cout<<"Number in "<<base<<" system is: "<<res<<std::endl;

    }

    //TODO: make sure it works lol
    static void sin()
    {

        std::function<float(float, float)> raiseToPower = [](float number, int power)
        {
            float result = 1;
            while(power > 0)
            {
                result *= number;
                power--;
            }
            return result;
        };

        std::function<int(int)> factorial = [](int number)
        {
            int result = 1;
            while(number > 0)
            {
                result *= number;
                number--;
            }
            return result;
        };

        std::cout << "Input number to calculate sin of and epsilon" << std::endl;
        float x = 0;
        float epsilon = 0;
        std::cin>>x;
        std::cin>>epsilon;

        float result = x;
        float lastResult = epsilon;
        int power = 3;
        std::string sign = "minus";

        while(lastResult - result > epsilon || lastResult - result < -epsilon)
        {
            lastResult = result;
            std::cout<<result<<std::endl;
            float temp = raiseToPower(x, power) / factorial(power);
            if(sign == "plus")
            {
                result += temp;
                sign = "minus";
            }
            else
            {
                result -= temp;
                sign = "plus";
            }
            power++;
        }

        std::cout<<"Sinus of number is approximately equal to: "<<result<<std::endl;
    }

    static void PolynomialNaive()
    {

        std::function<float(float, float)> raiseToPower = [](float number, int power)
        {
            float result = 1;
            while(power > 0)
            {
                result *= number;
                power--;
            }
            return result;
        };

        std::cout<<"Input x"<<std::endl;
        float x= 0;
        std::cin>>x;

        float result = 0;

        bool cont = true;
        while(cont)
        {
            float coefficient = 0;
            int power = 0;
            std::cout<<"Input coefficient and corresponding power of x"<<std::endl;
            std::cin >> coefficient;
            std::cin>>power;

            result += coefficient * raiseToPower(x, power);

            std::cout<<"Do you want to continue? [1-yes/0-no]"<<std::endl;
            std::cin>>cont;
        }
        std::cout<<"Result of your polynomial is: "<<result<<std::endl;
    }

    static void PolynomialHorners()
    {
        std::function<float(float)> polynomial = [&] (float x)
        {
            std::cout<<"Input coefficient"<<std::endl;
            float coefficient = 0;
            std::cin>>coefficient;
            bool cont;
            std::cout<<"Do you want to continue? [1-yes/0-no]"<<std::endl;
            std::cin>>cont;
            if(cont)
            {
                return coefficient + x * polynomial(x);
            }
            else return coefficient;

        };

        std::cout<<"Input x"<<std::endl;
        float x= 0;
        std::cin>>x;
        std::cout<<"The result of polynomial is: "<<polynomial(x)<<std::endl;
    }

};


#endif //ENGINEERING_LAB1_H
