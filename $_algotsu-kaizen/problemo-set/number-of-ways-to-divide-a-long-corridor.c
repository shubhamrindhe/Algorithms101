#define MOD 1000000007

int numberOfWays(char* corridor) {
    unsigned int len = 0x0;
    char _;

    while ((_ = corridor[len]) && _ == 'P' && ++len);

    bool is_segment = false;
    int plant_count = 0x0, prev_plant_count = 0x0;
    int segment_count = 0x0;
    int result = 0x1;

    while ((_ = corridor[len]) && ++len) {
        if (_ == 'S') {
            // printf("\n %d [%d] = %d", is_section, len, prev_plant_count);
            is_segment = !is_segment;

            if (is_segment) {
                // printf("\n[%d] %d %d\n", len - 1, prev_plant_count, plant_count);
                result = (result * 0x1LL * (prev_plant_count + 1)) % MOD;
                prev_plant_count = plant_count;
                plant_count = 0x0;
            } else {
                ++segment_count;
            }

            continue;
        }

        if (!is_segment) ++plant_count;
        // printf(" (%d, %c)", plant_count, _);
    }

    if (!is_segment && prev_plant_count > 0x0) result = (result * 0x1LL * (prev_plant_count + 1)) % MOD;

    // return is_segment ? 0x0 : (segment_count == 0x1 ? 0x1 : result);
    if (is_segment) {
        return 0x0;
    } else if (segment_count <= 0x1) {
        return segment_count;
    } else {
        return result;
    }
}

// ##....#..#..#....#
