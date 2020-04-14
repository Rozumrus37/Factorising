//
// Created by Ruslan Rozumnyi on 14.04.2020.
//

#ifndef FACTORISING_LONGARITHMETIC_H
#define FACTORISING_LONGARITHMETIC_H

#include <iostream>
#include <vector>

using namespace std;

class LongArithmetic {
public:
    string number;
    LongArithmetic(string number) {
        this->number = number;
    }
    string addition(string a, string b) {
        string &A = b.length() > a.length() ? b : a;
        if (b.length() > a.length()) {
            string t = a;
            a = b;
            b = t;
        }
        vector<int> num;
        int b_len = b.length() - 1;
        int carry = 0;
        for (int i = a.length() - 1; i >= 0; i--) {
            int sum;
            if (b_len >= 0) {
                sum = (a[i] - '0') + (b[b_len] - '0');
            } else {
                sum = a[i] - '0';
            }
            sum += carry;
            if (sum <= 9) {
                num.push_back(sum);
                carry = 0;
            } else {
                num.push_back(sum % 10);
                carry = sum / 10;
            }
            b_len--;

        }

        string result = "";
        if (carry != 0) result += carry + '0';


        for (int i = a.length() - 1; i >= 0; i--) {
            result += (num[i] + '0');
        }
        return result;
    }

    string multiply(string num1, string num2) {
        int len1 = num1.size();
        int len2 = num2.size();
        if (len1 == 0 || len2 == 0)
            return "0";

        vector<int> result(len1 + len2, 0);

        int i_n1 = 0;
        int i_n2 = 0;

        for (int i = len1 - 1; i >= 0; i--) {
            int carry = 0;
            int n1 = num1[i] - '0';
            i_n2 = 0;
            for (int j = len2 - 1; j >= 0; j--) {
                int n2 = num2[j] - '0';
                int sum = n1 * n2 + result[i_n1 + i_n2] + carry;
                carry = sum / 10;
                result[i_n1 + i_n2] = sum % 10;
                i_n2++;
            }

            if (carry > 0)
                result[i_n1 + i_n2] += carry;
            i_n1++;
        }

        int i = result.size() - 1;
        while (i >= 0 && result[i] == 0)
            i--;

        if (i == -1)
            return "0";

        string s = "";

        while (i >= 0)
            s += to_string(result[i--]);

        return s;
    }

    int mod(string num, int num2) {
        int res = 0;
        for (int i = 0; i < num.length(); i++)
            res = (res*10 + (int)num[i] - '0') % num2;
        return res;
    }

    string difference(string str1, string str2)
    {

        string &A = str2.length() > str1.length() ? str2 : str1;

        string str = "";

        int n1 = str1.length(), n2 = str2.length();


        reverse(str1.begin(), str1.end());
        reverse(str2.begin(), str2.end());

        int carry = 0;

        for (int i=0; i<n2; i++) {
            int sub = ((str1[i]-'0')-(str2[i]-'0')-carry);
            if (sub < 0) {
                sub = sub + 10;
                carry = 1;
            } else
                carry = 0;

            str.push_back(sub + '0');
        }

        for (int i=n2; i<n1; i++) {
            int sub = ((str1[i]-'0') - carry);

            if (sub < 0){
                sub = sub + 10;
                carry = 1;
            }else
                carry = 0;

            str.push_back(sub + '0');
        }
        reverse(str.begin(), str.end());
        return str;
    }


    string square_root(string &n) {
        string left = "0", right = n, ans;
        while(less_equal(left, right)) {
            string mid = division(addition(left, right), 2);
            string mid_pow2 = multiply(mid, mid);
            if(mid_pow2 == n)
                return mid;
            if(less_equal(mid_pow2, n)) {
                left = addition(mid, "1");
                ans = mid;
            } else
                right = difference(mid, "1");
        }
        return ans;


    }

    bool is_perfect(string &n) {
        if(multiply(square_root(n), square_root(n)) == n)
            return 1;
        else return 0;
    }
    bool less_equal(string a, string b) {
        if(a.length() < b.length() || a == b) {
            return 1;
        }
        if(b.length() < a.length()) {
            return 0;
        }
        for(int i = 0; i < a.length(); i++) {
            if(a[i] < b[i]) return 1;
            else if(a[i] > b[i]) return 0;
        }

       return 1;
    }

    string division(string num1, int num2) {
        string ans;

        int idx = 0;
        int temp = num1[idx] - '0';
        while (temp < num2)
            temp = temp * 10 + (num1[++idx] - '0');

        while (num1.size() > idx){
            ans += (temp / num2) + '0';
            temp = (temp % num2) * 10 + num1[++idx] - '0';
        }
        if (ans.length() == 0)
            return "0";
        return ans;
    }

};


#endif //FACTORISING_LONGARITHMETIC_H
