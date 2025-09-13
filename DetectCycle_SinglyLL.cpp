#include <iostream>
#include <unordered_set>
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
bool detectLoop_HashSet(Node* head){
    unordered_set<Node*> s;
    while(head!=nullptr){
        // Khi tìm không thấy head --> return s.end()
        if(s.find(head)!=s.end()){
            return true;
        }
        s.insert(head);
        head = head->next;
    }
    return false;
    // Mỗi node duyệt 1 lần --> O(n)
    // Sử dụng set, bộ nhớ phụ trợ --> Space O(n)
}
bool detectLoop_Floyd(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(slow && fast && fast->next){
        slow = slow -> next;
        fast = fast -> next -> next;
        if(slow==fast) return true;
    }
    return false;
    // Mỗi node duyệt 1 lần --> O(n)
    // Sử dụng 2 con trỏ --> Space O(1)
}

int main(){
    SinglyLinkedList singlyll;
    createList(singlyll);
    singlyll.head = createNode(1);
    singlyll.head->next = createNode(3);
    singlyll.head->next->next = createNode(4);
    singlyll.head->next->next->next = singlyll.head -> next -> next;
    
    if(detectLoop_HashSet(singlyll.head)&&detectLoop_Floyd(singlyll.head)){
        cout<<"Danh sách có vòng lặp!"<<endl;
    }
    else{
        cout<<"Danh sách không có vòng lặp!"<<endl;
    }
}