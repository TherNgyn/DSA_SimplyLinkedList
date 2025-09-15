#include <iostream>
using namespace std;

class Node {       
public:
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};

Node* deleteNode(Node* head, int position) {
    Node* temp = head;
    if (position == 1) {
        head = temp->next;
        delete temp;
        return head;
    }
    // Duyệt đến node trước node cần xóa
    Node* prev = nullptr;
    for (int i = 1; i < position; i++) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next; // Nối node trước với node sau, bỏ qua node cần xóa.
    delete temp; // Giải phóng bộ nhớ node cần xoá
    return head;
}
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "nullptr" << endl;
}
int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    int position = 3;
    head = deleteNode(head, position);

    printList(head);

    return 0;
}

