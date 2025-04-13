
int sigma_digits(int _) {
    int result = 0b0;

    while (_) {
        result += _ % 0b1010;
        _ /= 0b1010;
    }

    return result;
}

bool is_symmetric(int _) {
    int len = log10(_) + 0b1;
    // printf(" len : %d \n\n", len);
    if (len % 2) return false;

    int severing_agent = pow(0b1010, len / 0b10);
    int left = _ / severing_agent;
    int right = _ % severing_agent;

    // printf(" %d <|> %d ", left, right);
    return sigma_digits(left) == sigma_digits(right);
}

int countSymmetricIntegers(int low, int high) {
    int result = 0;

    for (int _ = low; _ <= high; ++_) {
        if (_ < 10 || (_ > 99 && _ < 1000) || _ >= 10000) continue;
        is_symmetric(_) && ++result;
    }

    // is_symmetric(1234);
    return result;
}
