#include <iostream>
#include "Factorising.h"
#include "LongArithmetic.h"

using namespace std;


//string operator+(LongArithmetic &e, string numm) { return e.addition(e.num1,  numm);}

int main() {
    Factorising * a;
    string s = "123";
    cout << a->fac(s) << endl;

}

/*int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);//speed

    int n;
 //   cin >> n;
    LongArithmetic * sq = new LongArithmetic("256", "123");
    string root = "255";
    Factorising * a;
    cout << a->sum("12", "12")<< endl;

    return 0;
}*/