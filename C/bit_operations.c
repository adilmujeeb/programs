/* Fetch the bit at position i from right in the binary representation of a number. */

#include<stdio.h>

int find_bit_val_at_position(int num, int pos) {
    int val = num & ( 1 << (pos-1));
    return (num & ( 1 << (pos-1)))? 1: 0;
}

int is_power_two(int num) {
    /* bitwise AND num with (num-1) will result 0 if power of two else non-zero
     * Ex. 1:
     * num = 4 = 1000
     * num - 1 = 3 = 0101 
     * num & (num -1 ) = 0000
     * Ex. 2: 
     * num = 6 = 0110, num-1 = 5 = 0101
     * num & (num-1) = 0100 
     */
     /* check if num is non-zero and do the bitwise OR with num-1 */

     return (num && !(num & (num-1)));
}

int main() {
    int num = 10, pos = 2;

    printf("bit value at position(%d) in number (%d) is: %d\n", pos, num, find_bit_val_at_position(num, pos));

    /* check if num is power of two */
    num = 8;
    num = 9;
    if(is_power_two(num))
        printf("%d is power of two\n", num);
    else
        printf("%d is not power of two\n", num);

    return 0;
}
