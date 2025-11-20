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

ListNode* bruteForce(ListNode* head){
    int n = countLength(head);
    int mid = n / 2;

    ListNode* temp = head;
    for(int i = 0; i < mid; i++){
        temp = temp->next;
    }
    return temp;
}

ListNode* optimalApproach(ListNode* head){
    if(!head || !head->next) return head;

    ListNode* slow = head;
    ListNode* fast = head;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

void printList(ListNode* head){
    while(head){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    printList(head);

    ListNode* bruteMid = bruteForce(head);
    cout << "Middle (Brute Force): " << bruteMid->val << endl;

    ListNode* optimalMid = optimalApproach(head);
    cout << "Middle (Optimal): " << optimalMid->val << endl;

    return 0;
}
