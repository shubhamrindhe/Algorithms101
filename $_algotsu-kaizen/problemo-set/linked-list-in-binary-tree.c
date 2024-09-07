/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool check(struct ListNode* item, struct TreeNode* node) {
    if ((item == NULL) != (node == NULL)) return false;
    if (item == NULL && node == NULL) return true;
    if (item->val != node->val) return false;
    if (item->next == NULL) return true;

    bool left_r = node->left != NULL;
    if (left_r) {
        left_r = check(item->next, node->left);
    }

    bool right_r = node->right != NULL;
    if (right_r) {
        right_r = check(item->next, node->right);
    }

    return left_r || right_r;
}

bool isSubPath(struct ListNode* item, struct TreeNode* node) {
    if (item == NULL || node == NULL) return false;
    if (item->val == node->val && check(item, node)) return true;
    return (node->left != NULL && isSubPath(item, node->left)) || (node->right != NULL && isSubPath(item, node->right));
}

// bool recursor(struct ListNode* item, struct TreeNode* node) {
//     if (item == NULL || node == NULL) return false;
//     if (item->val == node->val && check(item, node)) return true;
//     return (node->left != NULL && recursor(item, node->left)) || (node->right != NULL && recursor(item, node->right));
// }

// bool isSubPath(struct ListNode* head, struct TreeNode* root) {
//     if (head == NULL || root == NULL) return false;
//     return recursor(head, root);
// }
