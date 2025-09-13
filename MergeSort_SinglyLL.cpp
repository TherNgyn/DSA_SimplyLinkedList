#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
};
Node* createNode(int data)
{
    Node* node = new Node();
    node->data = data;
    node->next = NULL;
    return node;
}
struct LinkedList
{
    Node* head;
    Node* tail;
};
void CreateList(LinkedList &list)
{
    list.head = NULL;
    list.tail = NULL;
}
void printList(Node* node){
    while(node!=NULL){
        cout<<node->data<<" ";
        node = node->next;
    }
}
Node* getTail(Node* current){
    while(current!=NULL && current->next!=NULL){
        current=current->next;
    }
    return current;
}
Node* split(Node* head){
    Node* fast = head;
    Node* slow = head;

    // Di chuyển fast với tốc độ gấp đôi so với slow
    while(fast!=nullptr && fast->next != nullptr){
        fast = fast -> next -> next;
        if(fast != nullptr)
        {
            slow = slow -> next;
        }
    }
    // Chia thành 2 nửa
    Node* temp = slow -> next;
    slow -> next = nullptr;
    return temp; // Trả về đầu của nửa sau
}

Node* merge(Node *first, Node* second){
    if(first == nullptr) return second;
    if (second == nullptr) return first;

    if(first->data < second->data){
        first -> next = merge(first->next, second);
        return first;
    }
    else{
        second -> next = merge(first, second->next);
        return second;
    }
}
Node* mergeSort(Node* head){
    if(head==nullptr||head->next==nullptr){
        return head;
    }
    Node* second = split(head);
    head = mergeSort(head);
    second = mergeSort(second);

    return merge(head, second);
}

int main(){
    LinkedList list;
    CreateList(list);
    Node* head = createNode(9);
    head->next = createNode(17);
    head->next->next = createNode(2);
    head->next->next->next = createNode(1);
    head->next->next->next->next = createNode(11);
    head->next->next->next->next->next = createNode(8);

    if(list.head==NULL){
        list.head = head;
        list.tail = head;
    }
    else
    {
        list.tail->next = head;
        list.tail = getTail(head);
    }
    cout<<"Danh sách liên kết trước khi sắp xếp: ";
    printList(list.head);
    cout<<endl;
    cout << "Danh sách liên kết sau khi sắp xếp: ";
    list.head = mergeSort(list.head);
    printList(list.head);
    return 0;
}