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
int len(Node *head) {
    int dem = 0;
    while (head != NULL) {
        ++dem;
        head = head->next; // cho head chuyển sang node kế tiếp
    }
    return dem;
}

Node* deleteNode(Node* head, int position) {
    // Kiểm tra vị trí hợp lệ
    if (position < 1 || position > len(head)) {
        cout << "Vi tri khong hop le!" << endl;
        return head;
    }

    Node* temp = head;

    // Trường hợp xoá node đầu tiên
    if (position == 1) {
        head = temp->next;
        delete temp;
        return head;
    }

    // Trường hợp xoá tại các vị trí khác
    Node* prev = nullptr;
    // Duyệt đến node trước node cần xoá
    for (int i = 1; i < position - 1; i++) { 
        temp = temp->next;
    }

    prev = temp;
    temp = temp->next;

    // Bỏ qua node cần xoá
    prev->next = temp->next;
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

