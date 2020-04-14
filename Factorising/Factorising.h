//
// Created by Ruslan Rozumnyi on 14.04.2020.
//

#ifndef FACTORISING_FACTORISING_H
#define FACTORISING_FACTORISING_H

#include <iostream>
#include <vector>
#include "LongArithmetic.h"

using namespace std;


string operator+(LongArithmetic &num1, string &num2) { return num1.addition(num1.number,  num2);}
string operator*(LongArithmetic &num1, string &num2) { return num1.multiply(num1.number,  num2);}
string operator/(LongArithmetic &num1, int &num2) { return num1.division(num1.number,  num2);}
string operator-(LongArithmetic &num1, string &num2) { return num1.difference(num1.number,  num2);}
int operator%(LongArithmetic &num1, int &num2) { return num1.mod(num1.number,  num2);}

int p[5];
bool checking[5][100000000];
vector<int>simplify;
class Factorising {
public:

    string fac(string &n) {
        int j = -1;
        while (1) {
            j++;
            for (int k = 0; k < 5; k++) {
                 //(n + j * j) % p[k]
                 LongArithmetic _n(n);
                 LongArithmetic _j(to_string(j));
                 string _jj = _j * _j.number;
                 LongArithmetic _n_plus_jj(_n + _jj);

                if (checking[k][_n_plus_jj % p[k]] == 1) {
                    LongArithmetic * Sqrt;
                    T sqrt_this_number = (int) sqrt(n + j * j);

                    if () {
                        T a = sqrt_this_number + j;
                        T b = sqrt_this_number - j;
                        if (a == 1) {
                            return b;
                        } else if (b == 1) {
                            return a;
                        } else {
                            simplify.push_back(fac(sqrt_this_number + j));
                            simplify.push_back(fac(sqrt_this_number - j));
                            return 0;
                        }

                    }
                }
            }
        }


    }



    template<typename T>
    void factorising(T n) {
        p[0] = 37;
        p[1] = 337;
        p[2] = 10007;
        p[3] = 10003;
        p[4] = 100007;


        for (int j = 0; j < 5; j++)
            for (int i = 0; i < 1000000; i++)
                checking[j][i] = 0;

        for (int j = 0; j < 5; j++)
            for (int i = 1; i <= p[j] / 2; i++)
                checking[j][i * i % p[j]] = 1;

        while (n % 2 == 0) {
            n /= 2;
            simplify.push_back(2);
        }
        if (fac(n) == n && n != 1) {
            simplify.push_back(n);
        }

        for (int i = 0; i < simplify.size(); i++)
            simplify[i] != 0 ? cout << simplify[i] << endl : cout << "";
    }
};
#endif //FACTORISING_FACTORISING_H
