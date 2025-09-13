#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};
Node* createNode(int data){
    Node* node = new Node();
    node->data = data;
    node->next = NULL;
    return node;
}
struct SinglyLinkedList{
    Node* head;
    Node* tail;
};
void createList(SinglyLinkedList &list){
    list.head = NULL;
    list.tail = NULL;
}
void printList(Node* node){
    while(node!=NULL){
        cout<<node->data<<" ";
        node = node -> next;
    }
}
Node* reverseList_Iterative(Node* head){
    Node* cur = head;
    Node* pre = nullptr;
    Node* next = nullptr;
    while(cur!=nullptr){
        next = cur -> next;
        cur -> next = pre;
        pre = cur;
        cur = next;
    }
    return pre;
    // Mỗi node duyệt qua 1 lần, độ phức tạp O(n)
    // Không sử dụng bộ nhớ phụ, độ phức tạp O(1)
}
Node* reverseList_Recursion(Node* head){
    if(head==nullptr||head->next==nullptr){
        return head;
    }
    Node *newHead = reverseList_Recursion(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
    // Mỗi node duyệt qua 1 lần, độ phức tạp O(n)
    // Sử dụng bộ nhớ phụ do stack của đệ quy, độ phức tạp O(n)
}

int main(){
    SinglyLinkedList singlyll;
    createList(singlyll);
    singlyll.head = createNode(1);
    singlyll.head->next = createNode(2);
    singlyll.head->next->next = createNode(3);
    singlyll.head->next->next->next = createNode(4);
    cout<<"Danh sách liên kết đơn trước khi đảo ngược: ";
    printList(singlyll.head);
    cout<<endl;
    cout<<"Danh sách liên kết đơn sau khi đảo ngược dùng Iterative: ";
    singlyll.head = reverseList_Iterative(singlyll.head);
    printList(singlyll.head);
    cout<<endl;
    cout<<"Danh sách liên kết đơn sau khi đảo ngược dùng Đệ quy: ";
    singlyll.head = reverseList_Recursion(singlyll.head);
    printList(singlyll.head);
    return 0;
}

