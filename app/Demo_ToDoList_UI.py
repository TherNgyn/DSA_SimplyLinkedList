import streamlit as st
import locale

try:
    locale.setlocale(locale.LC_COLLATE, 'Vietnamese_Vietnam.1258')  # Windows
except locale.Error:
    try:
        locale.setlocale(locale.LC_COLLATE, 'vi_VN.UTF-8')  
    except locale.Error:
        locale.setlocale(locale.LC_COLLATE, '')  #

class Node:
    def __init__(self, task=None):
        self.task = task
        self.next = None
# // Thêm task
def add_task(head, task):
    node = Node(task)
    if head is None:
        return node
    curr = head
    while curr.next:
        curr = curr.next
    curr.next = node
    return head
# Xóa 
def delete_task(head, task):
    if head is None:
        return None
    if head.task == task:
        return head.next
    curr = head
    while curr.next and curr.next.task != task:
        curr = curr.next
    if curr.next:
        curr.next = curr.next.next 
    return head
# Chèn 
def insert_taskPos(head, task, pos):
    if pos < 1:
        return head
    if pos == 1:
        newNode = Node(task)
        newNode.next = head
        return newNode
    curr = head
    for i in range(1, pos-1):
        if curr is None:
            return head
        curr=curr.next
    if curr is None:
        return head
    newNode = Node(task)
    newNode.next = curr.next
    curr.next = newNode
    return head

def getMiddle_HareTortoise(head):
    if not head:
        return None
    slow = head
    fast = head.next
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
    return slow

def merge(left, right):
    if not left:
        return right
    if not right:
        return left
    
    if locale.strcoll(left.task.lower(), right.task.lower()) <= 0:
        result = left
        result.next = merge(left.next, right)
    else:
        result = right
        result.next = merge(left, right.next)
    return result

def mergeSort(head):
    if not head or not head.next:
        return head
    middle = getMiddle_HareTortoise(head)
    next_to_middle = middle.next
    middle.next = None
    left = mergeSort(head)
    right = mergeSort(next_to_middle)
    return merge(left, right)
# Đảo danh sách 
def reverseList(head):
    prev = None
    curr = head
    while curr:
        next_temp = curr.next
        curr.next = prev
        prev = curr
        curr = next_temp
    return prev

# Chuyển thành list để hiển thị danh sách
def toList(head):    
    result = []
    curr = head
    while curr:
        result.append(curr.task)
        curr = curr.next
    return result

# Khởi tạo session state để lưu danh sách công việc
if 'todo_head' not in st.session_state:
    st.session_state.todo_head = None

st.title("TO DO LIST APP")
st.write("Quản lý danh sách công việc sử dụng Singly Linked List")

with st.form("add_task_form", clear_on_submit=True):
    col1, col2, col3 = st.columns([3, 1, 1])
    new_task = col1.text_input("Công việc", key="new_task")
    submitted = col2.form_submit_button("Thêm")
    
    if submitted and new_task:
        st.session_state.todo_head = add_task(st.session_state.todo_head, new_task)
        # st.success(f"Đã thêm công việc: {new_task}")

if 'insert_position' not in st.session_state:
    st.session_state.insert_position = 1
# Ban đầu, insertP sẽ là 1 (mặc định)
tasks = toList(st.session_state.todo_head) # Biến task chứa danh sách
with st.form("insert", clear_on_submit=True):
    st.subheader("Chèn công việc vào vị trí: ")
    col1, col2, col3 = st.columns([3,1,1])
    insert = col1.text_input("Công việc: ", key="insert")
    # max = len(tasks) + 1
    pos = col2.number_input("Vị trí", 
                        min_value=1, 
                        max_value=len(tasks) + 1, 
                        value=st.session_state.insert_position, 
                        key="pos")
    #Pos lấy vị trí 1 ban đầu, hiển thị lên view là value 
    insert_submitted = col3.form_submit_button("Chèn")
    
    if insert_submitted and insert:
        st.write(f"Chèn '{insert}' vào vị trí {pos} (index {pos-1})")
        st.session_state.todo_head = insert_taskPos(st.session_state.todo_head, insert, pos)
        st.rerun()
    elif insert_submitted:
        st.warning("Vui lòng nhập công việc trước khi chèn!")

tasks = toList(st.session_state.todo_head)
if not tasks:
    st.info("Chưa có công việc cần làm.")
else:
    st.subheader("Danh sách công việc:")
    for i, task in enumerate(tasks, 1):
        col1, col2 = st.columns([5, 1])
        col1.write(f"{i}. {task}")
        if col2.button("Xóa", key=f"del_{i}"):
            st.session_state.todo_head = delete_task(st.session_state.todo_head, task)
            # st.experimental_rerun()

st.subheader("Chức năng khác")
col1, col2 = st.columns(2)

if col1.button("Đảo ngược danh sách"):
    if st.session_state.todo_head:
        st.session_state.todo_head = reverseList(st.session_state.todo_head)
        #st.success
        #st.experimental_rerun()
    else:
        st.warning("Chưa có công việc cần làm.")

if col2.button("Sắp xếp danh sách theo A - Z"):
    if st.session_state.todo_head:
        st.session_state.todo_head = mergeSort(st.session_state.todo_head)
        #st.experimental_rerun()
    else:
        st.warning("Chưa có công việc cần làm.")

st.markdown("-----"*50)
#st.caption("Ứng dụng sử dụng cấu trúc dữ liệu Danh sách Liên kết Đơn")
#st.caption("Nhóm 6")
st.markdown("""
<div style="
    background-color: #e0f7e6; 
    padding: 10px; 
    border-radius: 10px; 
    text-align: center;
    margin: 20px 0;
">
    <h3 style="color: #2e7d32;">Since 2025</h3>
    <p>Ứng dụng sử dụng cấu trúc dữ liệu Danh sách Liên kết Đơn</p>
    <p><b>Nhóm 6</b></p>
</div> """, unsafe_allow_html=True)