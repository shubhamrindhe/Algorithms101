
// typedef struct Node {
//     char _;
//     int priority;
//     struct Node *next;
// } Node;

// Node* new_node(char _, int priority, Node* next) {
//     Node* node = (Node *)malloc(sizeof(Node));
//     node->_ = _;
//     node->priority = priority; 
//     node->next = next;
//     return node;
// }

// Node* insert_node(Node* root, Node* node) {
//     if (root == NULL) return node; 
//     if (root->_ < node->_) {
//         node->next = root;
//         return node;
//     } 
//     Node* _ = root;
//     while (
//         _ 
//         && (_->next) 
//         && (_->next->_ > node->_)
//     ) _ = _->next;
//     node->next = _->next;
//     _->next = node;
//     return root;
// }

// void print(Node * node) {
//     Node* _ = node;
//     printf("\n PQ \n");
//     while (_) {
//         printf(" (%d, %d) ", _->priority, _->_);
//         _ = _->next;
//     }
//     printf("\n");
// }

// char* repeatLimitedString(char* s, int repeatLimit) {
//     char _ = '\0';
//     int len = 0;
//     char frequen_c[0x1A] = { '\0' };
//     while ((_ = s[len]) && ++len) ++frequen_c[_ - 'a'];
//     char* result = (char *)calloc(len + 1, sizeof(char));

//     // Node* root = NULL;
//     // for (int i = 0; i < 0x1A; ++i)
//     //     // printf(" (%c, %d) ", 'a' + i, frequen_c[i]);
//     //     if (frequen_c[i]) root = insert_node(root, new_node('a' + i, frequen_c[i], NULL));

//     // print(root);

//     int idx = 0;
//     // Node* node = root;
//     // root = root->next;
//     // node->next = NULL;
//     // do {
//     //     if (root && (root->_ > node->_)) {
//     //         result[idx++] = node->_;
//     //         node->priority--;
//     //     } else {
//     //         for (int i = 0; node->priority > 0 && i < repeatLimit; ++i) {
//     //             result[idx++] = node->_;
//     //             node->priority--;
//     //         }
//     //     }

//     //     Node* nextNode = root;
//     //     if (nextNode == NULL) break;
//     //     root = nextNode->next;
//     //     if (node->priority > 0) root = insert_node(root, node);
//     //     node = nextNode;
//     // } while (node != NULL);

//     while (1) {
//         int maxIdx = -1;
//         int secondIdx = -1;
//         for (int i = 25; i >= 0; i--) {
//             if (frequen_c[i] > 0) {
//                 if (maxIdx == -1) {
//                     maxIdx = i;
//                 } else if (secondIdx == -1) {
//                     secondIdx = i;
//                     break;
//                 }
//             }
//         }
//         if (maxIdx == -1) break;
//         int count = frequen_c[maxIdx] > repeatLimit ? repeatLimit : frequen_c[maxIdx];
//         for (int i = 0; i < count; i++) result[idx++] = 'a' + maxIdx;
//         frequen_c[maxIdx] -= count;
//         if (frequen_c[maxIdx] > 0) {
//             if (secondIdx == -1) break;
//             result[idx++] = 'a' + secondIdx;
//             frequen_c[secondIdx]--;
//         }
//     }

//     return result;
// }


char* repeatLimitedString(char* s, int repeatLimit) {
    int freq[26] = {0};
    int n = strlen(s);
    for (int i = 0; i < n; i++) {
        freq[s[i] - 'a']++;
    }
    char* result = (char*)malloc((n + 1) * sizeof(char));
    int resIdx = 0;
    while (1) {
        int maxIdx = -1;
        int secondIdx = -1;
        for (int i = 25; i >= 0; i--) {
            if (freq[i] > 0) {
                if (maxIdx == -1) {
                    maxIdx = i;
                } else if (secondIdx == -1) {
                    secondIdx = i;
                    break;
                }
            }
        }
        if (maxIdx == -1) {
            break;
        }
        int count = freq[maxIdx] > repeatLimit ? repeatLimit : freq[maxIdx];
        for (int i = 0; i < count; i++) {
            result[resIdx++] = 'a' + maxIdx;
        }
        freq[maxIdx] -= count;
        if (freq[maxIdx] > 0) {
            if (secondIdx == -1) {
                break;
            }
            result[resIdx++] = 'a' + secondIdx;
            freq[secondIdx]--;
        }
    }
    result[resIdx] = '\0';
    return result;
}