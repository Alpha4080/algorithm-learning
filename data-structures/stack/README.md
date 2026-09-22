# Stack

## 1. What is Stack?

栈是一种数据只能从一端进入和出来的数据结构。

核心特点：LIFO = last in first out

我对栈的理解：

> 栈里最新放进去的元素会最先被取出，
> 所以适合处理撤销、括号匹配、嵌套结构这类“最近的事情先处理”的问题。

---

## 2. Basic Operations

| Operation | C++ STL | Meaning | Time Complexity | Why? |
| --- | --- | --- | --- | --- |
| Push | `st.push(x)` | 将 x 压入栈顶 | O(1) | 只操作栈顶 |
| Pop | `st.pop()` | 将栈顶元素弹出栈 | O(1) | 只删除栈顶元素 |
| Top | `st.top()` | 访问栈顶元素 | O(1) | 直接访问栈顶 |
| Empty | `st.empty()` | 检查栈是否为空 | O(1) | 只需要检查当前元素数量 |
| Size | `st.size()` | 返回栈中的元素个数 | O(1) | 容器会维护元素数量 |

---

## 3. C++ Usage

```cpp
#include <stack>

stack<int> st;

st.push(10);
st.push(20);

cout << st.top(); //20

st.pop;

cout << st.top(); //10

cout << st.size();
if(st.empty()){
    //stack is empty
}

// TODO:自己补充常见操作

```

## 4. Implementation

### Array-based Stack

- 基本思路：将数组的尾部视为栈顶
- push：在数组尾部添加元素
- pop：在数组尾部删除元素
- 优点：入栈出栈操作都在预先分配好的内存里进行，平均时间效率较高
- 缺点：数组扩容可能造成空间浪费；如果入栈时超过数组容量会触发扩容机制，导致时间复杂度降低为O(n)

### Linked-list-based Stack

- 基本思路：将链表的头节点视为栈顶，尾节点视为栈底。
- push：在链表头部插入节点
- pop：删除链表头节点
- 优点：链表扩容十分灵活，时间效率更稳定。
- 缺点：入栈操作需要初始化节点对象并修改指针，时间效率相对较低。节点占用的空间相对较大

## 5. When Should I Use a Stack?

目前我知道的应用：
- 撤销操作
- 括号匹配
- 浏览器前进与后退
- 程序内存管理

> 判断一个问题可能使用栈的特征：需要优先处理最近加入、尚未处理的元素，或者存在嵌套关系时，可以考虑栈

## 6. Common Mistakes

### Mistake 1

问题：
原因：
正确理解：

## 7.Problems

| Problem | Difficulty | Key Idea | Status |
| --- | --- | --- | --- |
| B3614 【模板】栈 | 入门 |  | [ ] |
| P1739 表达式括号匹配 | 入门 |  | [ ] |
| P1449 后缀表达式 | 普及- |  | [ ] |

## 8.Summary