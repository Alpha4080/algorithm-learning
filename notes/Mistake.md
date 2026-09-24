# Mistakes

记录算法学习和 C++ 编程中实际踩过的坑。

---

## 1.Array Out of Bounds

### P1047 校门外的树

**错误**

```cpp
vector<int> trees(L);
for(int i = 0; i <= L; ++i){
    trees[i] = 1;
}

```

- 位置范围是：0 ~ L，一共有 L + 1个位置，因此数组应该开：'vector<int> trees(L+1);'

**What I learned**
数组大小要根据实际可能的下标确定，如果最大下标是L，数组至少需要有 L + 1 个元素。

## 2. Data Range and Integer Type

### B3614 栈

**Problem**

一开始使用：

```cpp
stack<int> st;
int x;
```

但是题目中 `x` 的范围可以达到 `2^64`，`int` 无法存储。

**Solution**

改为：

```cpp
stack<unsigned long long> st;
unsigned long long x;
```

**What I learned**

做题时先检查：

- 数据范围
- 数组下标范围
- 运算结果范围

再决定使用 `int`、`long long` 还是 `unsigned long long`。


## 3.Multiple Test Cases Must Be Independent

### B3614 栈

**Problem**

```cpp
stack<unsigned long long> st;
for(...){
    //多组测试
}
```

这样上一组测试结束后，栈中的元素会保留到下一组。

**What I learned**

多组测试数据时，要检查每组数据使用的状态是否需要重新初始化


## 4.Linked List Is a Logical Structure,Not Necessarily Pointers

### B3631

链表不必：

```cpp
struct ListNode {
    int val;
    ListNode* next;
};
```

其本质只是维护：
当前节点 -> 下一节点

因此可以使用 `nxt[x] = y' 来表示`x`后面是节点`y`
这种数组模拟链表适用于节点值：
- 唯一
- 范围有限

双向链表只需再维护一个`pre[x]`即可

## 5.`cin >>` Stops at Whitespace

### B3614

对于输入： `push 2` 

执行：
`string op;`
`cin >> op;`

得到`op == "push"`

空格后边的 `2`不会一起读入