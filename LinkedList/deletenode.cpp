#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

bool DeleteNode(ListNode* node) {
    if (node == nullptr || node->next == nullptr) {
        cout << "\n[ERROR] Cannot delete the last node using this method!\n";
        return false;
    }
    node->val = node->next->val;
    ListNode* temp = node->next;
    node->next = node->next->next;
    delete temp;
    return true;
}

void Display(ListNode* head) {
    cout << "\nLinked List: ";
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << "\n";
}

void FreeList(ListNode* head) {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    ListNode* head = new ListNode(1);
    ListNode* one = new ListNode(2);
    ListNode* two = new ListNode(3);
    ListNode* three = new ListNode(4);

    head->next = one;
    one->next = two;
    two->next = three;

    Display(head);

    cout << "\nDeleting node with value 2...";
    DeleteNode(one);
    Display(head);

    cout << "\nTrying to delete last node...";
    DeleteNode(three);
    Display(head);

    FreeList(head);
    return 0;
}
