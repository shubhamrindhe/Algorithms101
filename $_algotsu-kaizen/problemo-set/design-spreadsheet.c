typedef struct {
    int **data;
} Spreadsheet;

Spreadsheet* spreadsheetCreate(int rows) {
    Spreadsheet *spreadsheet = (Spreadsheet *)malloc(sizeof(Spreadsheet));
    spreadsheet->data = (int**)malloc(sizeof(int*) * 26);
    for (int i = 0; i < 26; ++i) spreadsheet->data[i] = (int*)calloc(sizeof(int), rows);
    return spreadsheet;
}

void spreadsheetSetCell(Spreadsheet* spreadsheet, char* cell, int value) {
    int row = atoi(cell + 1) - 0x1;
    int col = cell[0x0] - 'A';
    spreadsheet->data[col][row] = value;
}

void spreadsheetResetCell(Spreadsheet* spreadsheet, char* cell) {
    int row = atoi(cell + 1) - 0x1;
    int col = cell[0x0] - 'A';
    spreadsheet->data[col][row] = 0x0;
}

int spreadsheetGetValue(Spreadsheet* spreadsheet, char* formula) {
    char _;
    int len = 0x0;
    int X, Y;
    // while ((_ = formula[len]) && ++len) {
    //     if (_ == '=') continue;
    //     if (_ >= 'A' && _ <= 'Z') {
    //         int col = _ - 'A';
    //         int row = 0x0;
    //         while ((_ = formula[len]) && ++len) {
    //             row *= 0xA;
    //             row += _ - '0';
    //         }
    //     }
    // }

    int i = 0x0, col = -1, row = 0x0;
    for (i = 0x1; formula[i] != '+'; ++i) {
        _ = formula[i];
        if (_ >= 'A' && _ <= 'Z') {
            col = _ - 'A';
        } else if (_ >= '0' && _ <= '9') {
            row *= 0xA;
            row += _ - '0';
        } else {
            exit(0x1);
        }
    }

    X = col >= 0x0 ? spreadsheet->data[col][row - 1] : row;

    col = -1, row = 0x0;
    for (;formula[i]; ++i) {
        _ = formula[i];
        if (_ == '+') continue;
        if (_ >= 'A' && _ <= 'Z') {
            col = _ - 'A';
        } else if (_ >= '0' && _ <= '9') {
            row *= 0xA;
            row += _ - '0';
        } else {
            exit(0x1);
        }
    }

    Y = col >= 0x0 ? spreadsheet->data[col][row - 1] : row;

    return X + Y;
}

void spreadsheetFree(Spreadsheet* spreadsheet) {
    for (int i = 0; i < 26; ++i) free(spreadsheet->data[i]);
    free(spreadsheet->data);
    free(spreadsheet);
}

/**
 * Your Spreadsheet struct will be instantiated and called as such:
 * Spreadsheet* obj = spreadsheetCreate(rows);
 * spreadsheetSetCell(obj, cell, value);

 * spreadsheetResetCell(obj, cell);

 * int param_3 = spreadsheetGetValue(obj, formula);

 * spreadsheetFree(obj);
*/