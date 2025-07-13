int cmp(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

int matchPlayersAndTrainers(int* players, int playersSize, int* trainers, int trainersSize) {
    qsort(players, playersSize, sizeof(int), cmp);
    qsort(trainers, trainersSize, sizeof(int), cmp);

    // for (int _ = 0; _ < playersSize; ++_) printf(" %d ", players[_]);
    // printf("\n");
    // for (int _ = 0; _ < trainersSize; ++_) printf(" %d ", trainers[_]);
    register int pidx = 0, tidx = 0, result = 0;

    while (pidx < playersSize && tidx < trainersSize) {
        if (players[pidx] <= trainers[tidx]) {
            ++result;
            ++tidx;
        }

        ++pidx;
    }

    return result;
}
