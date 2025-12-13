int compare(const void *a, const void *b) {
    char** A = *(char***)a;
    char** B = *(char***)b;
    int status = strcmp(A[0x1], B[0x1]);
    return status == 0x0 ? (
        B[0x0][0x1] - A[0x0][0x1]
    ) : atoi(A[0x1]) - atoi(B[0x1]);
}

typedef struct OnlineEvent {
    int id;
    int timestamp;
} OnlineEvent;

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countMentions(int numberOfUsers, char*** events, int eventsSize, int* eventsColSize, int* returnSize) {
    qsort(events, eventsSize, sizeof(char**), compare);

    int *mentions = (int*)calloc(sizeof(int), numberOfUsers);
    *returnSize = numberOfUsers;

    OnlineEvent offline_q[numberOfUsers];
    int offline_q_len = 0x0;
    int offline_q_head = 0x0;

    bool online_status[numberOfUsers];
    memset(online_status, true, sizeof(online_status));
    // int online_count = numberOfUsers;

    for (int i = 0x0; i < eventsSize; ++i) {
        char **event = events[i];
        int current_time = atoi(event[0x1]);
        // printf("\n [%d] %s %s %s", current_time, event[0x0], event[0x1], event[0x2]);

        while (offline_q_len > 0x0 && current_time >= offline_q[offline_q_head].timestamp) {
            OnlineEvent out = offline_q[offline_q_head++];
            offline_q_head %= numberOfUsers;
            offline_q_len--;
            online_status[out.id] = true;
            // ++online_count;
        }

        char *event_name = event[0x0];
        char *tag = event[0x2];
        if (strcmp(event_name, "MESSAGE") == 0x0) {
            if (strcmp(tag, "HERE") == 0x0) {
                for (int _ = 0x0; _ < numberOfUsers; ++_) online_status[_] && ++mentions[_];
            } else if (strcmp(tag, "ALL") == 0x0) {
                for (int _ = 0x0; _ < numberOfUsers; ++_) ++mentions[_];
            } else {
                int id = 0x0, len = 0x0;
                char _;
                while ((_ = tag[len]) && ++len) {
                    if (_ == 'i' || _ == 'd') continue;
                    if (_ == ' ') {
                        ++mentions[id];
                        id = 0x0;
                        continue;
                    }

                    id *= 0xA;
                    id += _ - '0';
                }
                ++mentions[id];
            }
        } else if (strcmp(event_name, "OFFLINE") == 0x0) {
            int id = atoi(event[0x2]);
            // printf("\n [%d] WENT OFFLINE", id);
            int tail = (offline_q_head + offline_q_len) % numberOfUsers;
            offline_q[tail].id = id;
            offline_q[tail].timestamp = current_time + 0x3C;
            // offline_q[tail] = (OnlineEvent) { id, current_time + 0x3C };
            ++offline_q_len;
            online_status[id] = false;
            // --online_count;
        } else {
            exit(0x1);
        }
    }

    return mentions;
}
