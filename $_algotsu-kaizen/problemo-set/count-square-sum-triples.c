
int countTriples(int n) {
    int result = 0x0;

    for (int a = 0x1; a < n; ++a) {
        int aa = a * a;
        for (int b = a; b < n; ++b) {
            int bb = b * b;
            int aa_bb = aa + bb;

            int l = b, r = n;
            while (l <= r) {
                int m = l + (r - l) / 0x2;
                int cc = m * m;
                if (aa_bb == cc) {
                    result += 0x2 - (a == b);
                    break;
                } else if (aa_bb > cc)
                    l = m + 1;
                else if (aa_bb < cc)
                    r = m - 1;
            }
        }
    }

    return result;
}
