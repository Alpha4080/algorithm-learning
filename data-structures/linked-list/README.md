# Linked-List

## 1. What is Linked-List

链表是一种线性数据结构，每个元素都是一个节点对象，各个节点通过结构体中指针连接。内存地址跟数组不同，无须连续。

我对链表的理解:

> 链表由节点构成，是线性的，第一个节点叫做头节点，最后一个节点叫做尾节点。单向链表中的每个节点保存一个指向下一节点的指针，因此只能沿 next 指针向后遍历；双向链表则同时保存前驱和后继指针，因此可以向前或向后遍历。

创建代码：
```cpp
struct ListNode {
    int val;        //节点值
    ListNode *next; //指向下一个节点的指针
    ListNode(int x) : val(x), next(nullptr){} //构造函数
};
```

## 2.Basic Operation

```cpp

// 初始化链表 
ListNode* n0 = new ListNode(1);
ListNode* n1 = new ListNode(2);
ListNode* n2 = new ListNode(3);

//构建节点之间的引用
n0->next = n1;
n1->next = n2;

//插入节点,时间复杂度为O(1)
void insert(ListNode *n0,ListNode *P){
    ListNode *n1 = n0->next;
    n0->next = P;
    P->next = n1;
}

//删除节点，时间复杂度为O(1)
void remove(ListNode *n0){
    if(n0->next == nullptr || n0 == nullptr){
        return;
    }
    ListNode *P = n0->next;
    n0->next = P->next;
    //释放内存
    delete P;
}

//访问节点，时间复杂度O(n)。访问链表中索引为index的节点
ListNode *access(ListNode *head, int index){
    for(int i = 0; i < index; ++i){
        if(head == nullptr){
            return nullptr;
        }
        head = head->next;
    }
    return head;
}

//查找节点，时间复杂度O(n)，查找其中值为target的节点，输出索引
int find(ListNode *head, int target){
    int index = 0;
    while(head != nullptr){
        if(head->val == target){
            return index;
        }
        head = head->next;
        index++;
    }
    return -1;
}
```

## 3.Problems

| Problem | Difficulty | Key Idea | Status |
| --- | --- | --- | --- |
| B3631 | 入门 | 用 `nxt[x]` 来表示值为x的节点的下一个节点的值| [x] |
|  |  |  |  |
|  |  |  |  |

## 4.What I Learned

链表的本质是维护“节点->下一个节点”的关系，
并不一定使用指针实现，比如B3631用一个数组巧妙地避免了大段冗余的链表代码。
其中用数组模拟链表的方式是：`nxt[x] = y;`
但是此种方式也有其局限性，在 B3631 这种直接用节点值作为数组下标的实现中，节点值需要唯一且值域不能过大。一般的数组模拟链表并不要求节点值本身唯一或范围有限。。