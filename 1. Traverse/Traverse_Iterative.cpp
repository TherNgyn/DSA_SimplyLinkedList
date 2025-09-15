#include <iostream>
using namespace std;
// Định nghĩa cấu trúc của một node
struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};
// Hàm duyệt qua danh sách liên kết
void traverse(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
int main() {
    // Khởi tạo các node
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    // Duyệt danh sách
    traverse(head);
    return 0;
}
