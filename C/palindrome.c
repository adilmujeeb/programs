#include<stdio.h>
#define false -1
#define true 0

int isPalindrome(int x) {
        int temp, orig_num;
        if (x < 0) {
            return false;
        }
        orig_num = x;
        temp = 0;
        while (x > 0) {
            temp *= 10;
            temp += x % 10;
            x = x / 10;
        }
        if (orig_num == temp)
            return true;
        else 
            return false;
}

int main(){
 printf("%d",isPalindrome(1001));
 return 0;
}
