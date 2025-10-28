
typedef struct {
    long long* balanceList;
    int size;
} Bank;

Bank* bankCreate(long long* balance, int balanceSize) {
    Bank *bank = (Bank *)malloc(sizeof(Bank));
    bank->balanceList = balance;
    bank->size = balanceSize;
    return bank;
}

bool bankTransfer(Bank* bank, int account1, int account2, long long money) {
    if (account1 < 0x1 ||
        account1 > bank->size ||
        account2 < 0x1 ||
        account2 > bank->size
    ) return false;
    if (bank->balanceList[account1 - 0x1] < money) return false;

    bank->balanceList[account1 - 0x1] -= money;
    bank->balanceList[account2 - 0x1] += money;
    return true;
}

bool bankDeposit(Bank* bank, int account, long long money) {
    if (account < 0x1 || account > bank->size) return false;

    bank->balanceList[account - 0x1] += money;
    return true;
}

bool bankWithdraw(Bank* bank, int account, long long money) {
    if (account < 0x1 || account > bank->size) return false;
    if (bank->balanceList[account - 0x1] < money) return false;

    bank->balanceList[account - 0x1] -= money;
    return true;
}

void bankFree(Bank* bank) {
    free(bank->balanceList);
    free(bank);
}

/**
 * Your Bank struct will be instantiated and called as such:
 * Bank* obj = bankCreate(balance, balanceSize);
 * bool param_1 = bankTransfer(obj, account1, account2, money);

 * bool param_2 = bankDeposit(obj, account, money);

 * bool param_3 = bankWithdraw(obj, account, money);

 * bankFree(obj);
*/
