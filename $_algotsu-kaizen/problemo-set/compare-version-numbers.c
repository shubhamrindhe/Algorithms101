int compareVersion(char* version1, char* version2) {
    char c1, c2;
    unsigned short len1 = 0x0, len2 = 0x0;

    do {
        int v1 = 0x0;
        while ((c1 = version1[len1]) && ++len1) {
            if (c1 == '.') break;
            if (v1 == 0x0 && c1 == '0') continue;
            v1 *= 0xA;
            v1 += c1 - '0';
        }

        int v2 = 0x0;
        while ((c2 = version2[len2]) && ++len2) {
            if (c2 == '.') break;
            if (v2 == 0x0 && c2 == '0') continue;
            v2 *= 0xA;
            v2 += c2 - '0';
        }

        // printf("\n %d %d ", v1, v2);

        if (v1 != v2) return v1 < v2 ? -0x1 : 0x1;
    } while (c1 || c2);

    return 0x0;
}
