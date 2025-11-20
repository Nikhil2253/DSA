#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val){
        this->val = val;
        this->next = nullptr;
    }
};

int countLength(ListNode* head){
    int n = 0;
    while(head){
        n++;
        head = head->next;
    }
    return n;
}

void bruteForce(ListNode*& head){
    int n = countLength(head);
    if(n <= 1) return;
    int mid = n / 2;
    if(mid == 0){
        head = head->next;
        return;
    }
    ListNode* temp = head;
    for(int i = 0; i < mid - 1; i++){
        temp = temp->next;
    }
    temp->next = temp->next->next;
}

void optimalApproach(ListNode*& head){
    if(head == nullptr || head->next == nullptr) return;
    ListNode* prev = nullptr;
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast && fast->next){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    if(prev == nullptr){
        head = head->next;
    } else {
        prev->next = slow->next;
    }
}

void printList(ListNode* head){
    while(head){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main(){
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);
    head1->next->next->next->next = new ListNode(5);

    bruteForce(head1);
    printList(head1);

    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(3);
    head2->next->next->next = new ListNode(4);
    head2->next->next->next->next = new ListNode(5);

    optimalApproach(head2);
    printList(head2);

    return 0;
}
