#include <iostream>

using namespace std;

// Khai báo Node
// (class) hoặc 
//sử dụng dữ liệu có sẵn (struct)
// Phần info
struct Node {
    int data;
    Node* next;
};
// Phần liên kết
// Khởi tạo node mới
Node* createNode(int data)
{
    Node* node1 = new Node();
    node1->data = data;
    node1->next = NULL;
    return node1;
}
// Tạo list node
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
void printList(Node* node)
{
    while(node != NULL)
    {
        cout<< node->data << " ";
        node = node ->next;
        //cout<<endl;
    }
}
Node* gettail(Node* current)
{
    // Duyệt đến node cuối cùng
    while(current!=NULL && current->next!=NULL)
    {
        current = current->next;
    }
    return current;
}

// Phân hoạch thành 2 danh sách con
Node* partition(Node* head, Node *tail)
{
    //1. Chọn một pivot từ danh sách
    Node* pivot = head;

    Node* current = head->next;
    // Tạo node phân hoạch pre
    Node* pre = head; 
    //2. Chia danh sách thành hai danh sach con
    while(current != tail->next)
    {
        if(current->data < pivot->data)
        {
            swap(current->data, pre->next->data);
            pre = pre -> next;
        }
        current = current -> next;
    }
    swap(pivot->data, pre->data);
    // Trả về node phân hoạch như một pivot mới 
    return pre;
    // Kết thúc thì duyệt qua 1 lần độ phức tạp O(n)
}
void quickSortHelper(Node* head, Node* tail)
{
    // Nếu danh sách rỗng/chứa 1 node duy nhất 
    if(head==NULL|| head==tail)
    {
        return;
    }
    // Phân hoạch danh sách và lấy node pivot mới
    Node* pivot = partition(head, tail);
    // Gọi đệ quy sắp xếp danh sách con bên trái của pivot
    quickSortHelper(head, pivot);
    // Gọi đệ quy sắp xếp danh sách con bên phải của pivot
    quickSortHelper(pivot->next, tail);
    // Số lần chia log(n) nếu chia đều (tương tự như chia đôi mảng), độ phức tạp O(n) --> O(nlog(n))
    // Nếu chia lệch thì số lần chia là n lần, mỗi lần chia độ phức tạp O(n) --> O(n^2)
}
Node* quickSort(Node* head)
{
    Node* tail = gettail(head);
    quickSortHelper(head, tail);
    return head;
}
int main()
{
    LinkedList list;
    CreateList(list);
    // Khởi tạo danh sách
    //HEAD --> 9 --> 17 --> 2 --> 1 --> 11 --> 8 
    Node* head = createNode(9);
    head->next = createNode(17);
    head->next->next = createNode(2);
    head->next->next->next = createNode(1);
    head->next->next->next->next = createNode(11);
    head->next->next->next->next->next = createNode(8);

    // Thêm node vào danh sách liên kết
    if (list.head == NULL) {
        list.head = head;
        list.tail = head;
    } else {
        list.tail->next = head;
        list.tail = gettail(head);
    }
    // In ra danh sách liên kết
    cout << "Danh sach lien ket truoc khi sap xep: ";
    printList(list.head);
    cout << endl;
    cout<< "Danh sach lien ket sau khi sap xep: ";
    list.head = quickSort(list.head);
    printList(list.head);
    return 0;
}




