#include <stdio.h>
/* 1. ���� x �ľ���ֵ */
int absVal(int x) {
    int mask = x >> 31;
    return (x ^ mask) + (~mask + 1);
}
/* ��׼���� */
int absVal_standard(int x) {
    return (x < 0) ? -x : x;
}
/* 2. ʵ�� -x */
int negate(int x) {
    return ~x + 1;
}
/* ��׼���� */
int negate_standard(int x) {
    return -x;
}
/* 3. ʵ�� & */
int bitAnd(int x, int y) {
    return ~(~x | ~y);
}
/* ��׼���� */
int bitAnd_standard(int x, int y) {
    return x & y;
}
/* 4. ʵ�� | */
int bitOr(int x, int y) {
    return ~((~x) & (~y));
}
/* ��׼���� */
int bitOr_standard(int x, int y) {
    return x | y;
}
/* 5. ʵ�� ^ */
int bitXor(int x, int y) {
    return ~(~(x & ~y) & ~(~x & y));
}
/* ��׼���� */
int bitXor_standard(int x, int y) {
    return x ^ y;
}
/* 6. �ж�x�Ƿ�Ϊ������������7FFFFFFF�� */
int isTmax(int x) {
    return !((x + 1) ^ (~x)) & !!x;
}
/* ��׼���� */
int isTmax_standard(int x) {
    return x == 0x7FFFFFFF;
}
/* 7. ͳ��x�Ķ����Ʊ�ʾ�� 1 �ĸ��� */
int bitCount(int x) {
    int count = 0;
    while (x) {
        count += x & 1;
        x >>= 1;
    }
    return count;
}
/* ��׼���� */
int bitCount_standard(int x) {
    int count = 0;
    while (x) {
        x &= (x - 1);
        count++;
    }
    return count;
}
/* 8. ������lowbit �� highbit ȫΪ1������λΪ0���� */
int bitMask(int highbit, int lowbit) {
    return (~(~0 << (highbit - lowbit + 1))) << lowbit;
}
/* ��׼���� */
int bitMask_standard(int highbit, int lowbit) {
    return (1 << (highbit + 1)) - (1 << lowbit);
}
/* 9. ��x+y ��������ʱ����1�����򷵻� 0 */
int addOK(int x, int y) {
    int sum = x + y;
    return !((sum ^ x) & (sum ^ y)) >> 31;
}
/* ��׼���� */
int addOK_standard(int x, int y) {
    int sum = x + y;
    return !(x > 0 && y > 0 && sum <= 0) && !(x < 0 && y < 0 && sum >= 0);
}
/* 10. ��x�ĵ�n���ֽ����m���ֽڽ��������ؽ�����Ľ�� */
int byteSwap(int x, int n, int m) {
    int mask = 0xFF;
    int byte_n = (x >> (n << 3)) & mask;
    int byte_m = (x >> (m << 3)) & mask;
    x = x & ~(mask << (n << 3)) | (byte_m << (n << 3));
    x = x & ~(mask << (m << 3)) | (byte_n << (m << 3));
    return x;
}
int main() {
    printf("1. absVal(-1) = %d, \n   absVal_standard(-1) = %d\n", absVal(-1), absVal_standard(-1));
    printf("2. negate(2) = %d, \n   negate_standard(2) = %d\n", negate(2), negate_standard(2));
    printf("3. bitAnd(12, 6) = %d, \n   bitAnd_standard(12, 6) = %d\n", bitAnd(12, 6), bitAnd_standard(12, 6));
    printf("4. bitOr(5, 3) = %d, \n   bitOr_standard(5, 3) = %d\n", bitOr(5, 3), bitOr_standard(5, 3));
    printf("5. bitXor(5, 3) = %d, \n  bitXor_standard(5, 3) = %d\n", bitXor(5, 3), bitXor_standard(5, 3));
    printf("6. isTmax(0x7FFFFFFF) = %d, \n   isTmax_standard(0x7FFFFFFF) = %d\n", isTmax(0x7FFFFFFF), isTmax_standard(0x7FFFFFFF));
    printf("7. bitCount(15) = %d, \n   bitCount_standard(15) = %d\n", bitCount(15), bitCount_standard(15));
    printf("8. bitMask(5, 3) = %X, \n   bitMask_standard(5, 3) = %X\n", bitMask(5, 3), bitMask_standard(5, 3));
    printf("9. addOK(0x7FFFFFFF, 1) = %d, \n   addOK_standard(0x7FFFFFFF, 1) = %d\n", addOK(0x7FFFFFFF, 1), addOK_standard(0x7FFFFFFF, 1));
    printf("10. byteSwap(0x12345678, 1, 3) = %X, \n    byteSwap(0xDEADBEEF, 0, 2) = %X\n", byteSwap(0x12345678, 1, 3), byteSwap(0xDEADBEEF, 0, 2));
    return 0;
}


