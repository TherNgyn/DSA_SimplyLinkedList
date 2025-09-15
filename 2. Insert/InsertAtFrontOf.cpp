#include <iostream>
using namespace std;

// Định nghĩa một node trong danh sách liên kết
class Node {
public:
    int data;
    Node* next;

    // Hàm khởi tạo node
    Node(int x) {
        data = x;
        next = nullptr;
    }
};

// Hàm chèn một node mới vào đầu danh sách
Node* insertAtFront(Node* head, int x) {
    Node* newNode = new Node(x);
    newNode->next = head;
    return newNode;
}

// Hàm in danh sách liên kết
void printList(Node* head) {
    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->data;
        if (curr->next != nullptr) {
            cout << " -> ";
        }
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    // Tạo danh sách liên kết: 2 -> 3 -> 4 -> 5
    Node* head = new Node(2);
    head->next = new Node(3);
    head->next->next = new Node(4);
    head->next->next->next = new Node(5);

    // Thêm một node mới vào đầu danh sách
    int x = 1;
    head = insertAtFront(head, x);

    // In danh sách sau khi thêm node
    printList(head);

    return 0;
}
