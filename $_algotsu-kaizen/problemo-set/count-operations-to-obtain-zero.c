
int countOperations(int num1, int num2) {
    int result = 0x0;

    while (num1 != 0x0 && num2 != 0x0) {
        ++result;

        if (num1 == num2) break;
        else if (num1 > num2) num1 -= num2;
        else if (num2 > num1) num2 -= num1;
    }

    return result;
}
