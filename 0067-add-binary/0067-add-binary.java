class Solution {
    public String addBinary(String a, String b) {
        // int n = a.length();
        // int m = b.length();
        // string sum = "";
        // while(n!=0 && m!=0){
        //     int x = a[n];
        //     int y = b[m];
        //     int rem = 0;
        //     n--;
        //     m--;
        //     if((x==1 && y==1 && rem==0){
        //         sum.push_back('0');
        //         rem = 1;
        //     }else if(x==1 && y==0 &&rem==0){
        //         sum.push_back('1');
        //     }else if(x==0 && y==0 &&rem==0){
        //         sum.push_back('0');
        //     }
        //     }else if(x==0 && y==1 &&rem==0){
        //         sum.push_back('1');
        //     }
        //     }else if(x==0 && y==0 &&rem==1){
        //         sum.push_back('1');
        //     }
        //     }else{
        //         sum.push_back('1');
        //     }
        // }
        // return sum;
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;
        StringBuilder sum = new StringBuilder();
        while (i >= 0 || j >= 0 || carry == 1) {
            int x = 0;
            if (i >= 0) {
                x = a.charAt(i) - '0';
                i--;
            }
            int y = 0;
            if (j >= 0) {
                y = b.charAt(j) - '0';
                j--;
            }
            int total = x + y + carry;
            sum.append(total % 2); 
            carry = total / 2;      
        }
        return sum.reverse().toString();
    }
}