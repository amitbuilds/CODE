#include<math.h>
class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0){
            return 1;
        }
        int m = n ;
        int mask = 0;
        while(m!=0){
            mask = (mask << 1) | 1;
            m = m >> 1;
        }
        return ((~n)&mask);
        // int ans = 0;
        // int i = 0;
        // while(n!=0){
        //     int bit = n&1;
        //     ans = (bit * pow(10,i)) + ans;
        //     n = n>>1;
        //     i++;
        // }
        // int num = 0;
        // int j = 0 ;
        // while(ans!=0){
        //     int digit = ans%10;
        //     if(!digit){
        //         num = num + pow(2,j);
        //     }
        //     ans = ans/10;
        //     j++;
        // }
        // return num;
    }
};