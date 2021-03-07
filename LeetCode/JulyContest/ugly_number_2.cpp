/*
Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.
    Example
    Input: n = 10
    Output: 12
    Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    map<long long int, bool> ugly;
    int nthUglyNumber(int n) {
        ugly[1] = 1;
        int size = 1;
        map<long long int, bool>::iterator it = ugly.begin();
        while (true)
        {
            if(!ugly[(*it).first*2])
                {ugly[(*it).first*2] = true; size++;}
            if(!ugly[(*it).first*3])
                {ugly[(*it).first*3] = true; size++;}
            if(!ugly[(*it).first*5])
                {ugly[(*it).first*5] = true; size++;}
            if(size >= 1800) break;
            it++;
        }
        map<long long int, bool>::iterator it2 = ugly.begin() ;
        
        for(int i=1; i<=n-1; it2++, i++);

        return (*it2).first;
    }
};