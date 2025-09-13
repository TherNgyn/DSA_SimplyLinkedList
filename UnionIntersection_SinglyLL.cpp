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
bool isPresent(Node* head, int value){
    Node* cur = head;
    while(cur!=nullptr){
        if(cur->data == value){
            return true;
        }
        cur = cur -> next;
    }
    return false;
}
Node* findUnion(Node* head1, Node* head2){
    Node* result = nullptr;
    Node* tail = nullptr;
    Node* current1 = head1, *current2 = head2;

    // Duyệt list 1
    while(current1!=nullptr){
        if(!isPresent(result, current1->data)){
            Node* newNode = createNode(current1->data);
            if(result == nullptr){
                result = newNode;
                tail = result;
            }
            else{
                tail -> next = newNode;
                tail = newNode;
            }
        }
        current1 = current1 -> next;
    }
    while(current2!=nullptr){
        if(!isPresent(result, current2->data)){
            Node* newNode = createNode(current2->data);
            if(result==nullptr){
                result = newNode;
                tail = result;
            }
            else {
                tail -> next = newNode;
                tail = newNode;
            }
        }
        current2 = current2 -> next;
    }
    return result;
}
Node* findIntersection(Node* head1, Node* head2){
    Node* result = nullptr;
    Node* tail = nullptr;
    Node* current1 = head1, *current2 = head2;

    while(current1!=nullptr){
        if(isPresent(current2, current1->data)&&!isPresent(result, current1->data)){
            Node* newNode = createNode(current1->data);
            if(result == nullptr){
                result = newNode;
                tail = result;
            }
            else{
                tail -> next = newNode;
                tail = newNode;
            }
        }
        current1 = current1 -> next;
    }
    return result;
}

int main(){
    SinglyLinkedList list1;
    SinglyLinkedList list2;
    createList(list1);
    createList(list2);
    list1.head = createNode(10);
    list1.head->next = createNode(15);
    list1.head->next->next = createNode(4);
    list1.head->next->next->next = createNode(20);

    list2.head = createNode(8);
    list2.head->next = createNode(4);
    list2.head->next->next = createNode(2);
    list2.head->next->next->next = createNode(10);

    cout<<"Danh sách liên kết đơn 1: ";
    printList(list1.head);
    cout<<endl;
    cout<<"Danh sách liên kết đơn 2: ";
    printList(list2.head);
    cout<<endl;
    cout<<"Union: ";
    Node* unionList = findUnion(list1.head, list2.head);
    printList(unionList);
    cout<<endl;
    cout<<"Intersection: ";
    Node* intersectionList = findIntersection(list1.head, list2.head);
    printList(intersectionList);

    return 0;
}