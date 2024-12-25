bool checkIfExist(int* arr, int arrSize) {
    bool neg[1001] = { 0 };
    bool pos[1001] = { 0 };

    for (int i = 0; i < arrSize; ++i) {
        int num = arr[i];
        if (num > 0) {
            pos[num] = true;
        } else if (num < 0) {
            neg[-1 * num] = true;
        } else {
            if (pos[num]) return true;
            pos[num] = true;
        }
    }

    for (int i = 0; i < arrSize; ++i) {
        int num = arr[i];
        int isEvan = num % 2 == 0;
        if (num > 0) {
            if (isEvan && pos[num / 2]) return true;
        } else if (num < 0) {
            if (isEvan && neg[(-1 * num) / 2]) return true;
        }
    }

    return false;
}
