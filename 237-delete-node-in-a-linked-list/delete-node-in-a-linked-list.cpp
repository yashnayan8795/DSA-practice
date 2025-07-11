/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val; 
        node->next = node->next->next;
    }
};

// void pop_back(LinkedList &List){
//     if(List.head == nullptr) return; 
//     if(List.head == List.tail) { 
//         delete List.head;
//         List.head = nullptr;
//         List.tail = nullptr;
//         return;
//     }
//     Node* current = List.head;
//     while(current->next != List.tail) {
//         current = current->next;
//     }
//     delete List.tail;
//     List.tail = current;
//     List.tail->next = nullptr;
// }