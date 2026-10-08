# heap

## 1.What is heap

堆是一种满足特定条件的完全二叉树，主要可分为两种类型：

- 小顶堆：任意节点的值 <= 其子节点的值。
- 大顶堆：任意节点的值 >= 其子节点的值。

特性：

- 最底层节点靠左填充，其他层节点全部填满。
- 根节点称之为“堆顶”，底层靠右的节点称之为“堆底”。
- 大(小)顶堆，堆顶元素的值是最大(小)的。

Priority Queue 是一种抽象的数据结构：
每次优先处理优先级最高的元素。

Heap 是实现 Priority Queue 的常用数据结构。

## 2.Basic Operation

```cpp

//初始化小顶堆
priority_queue<int, vector<int>, greater<int>> minHeap;

//初始化大顶堆
priority_queue<int, vector<int>, less<int>> maxHeap;

//元素入堆
maxHeap.push(1);
maxHeap.push(3);
maxHeap.push(2);
maxHeap.push(5);
maxHeap.push(4);

//获取堆顶元素
int peek = maxHeap.top();

//堆顶元素出堆，会形成一个从大到小的序列
maxHeap.pop(); // 5
maxHeap.pop(); // 4
maxHeap.pop(); // 3
maxHeap.pop(); // 2
maxHeap.pop(); // 1

//获取堆的大小
int size = maxHeap.size();

//判断堆是否为空
bool isEmpty = maxHeap.empty();

//输入列表并建堆
vector<int> input {1,3,2,,5,4};
priority_queue<int, vector<int>,greater<int>> minHeap(input,.begin(),input.end());

```

## 3.Complexity

| 操作 | 时间复杂度 |
|---|---:|
| `top()` | O(1) |
| `size()` | O(1) |
| `empty()` | O(1) |
| `push()` | O(log n) |
| `pop()` | O(log n) |

## Array Representation

堆是完全二叉树，因此节点指针用映射公式来实现。

给定索引 `i` ,左子节点索引为 ` 2i + 1`，右子节点索引是 `2i+2`，父节点索引是 `(i-1)/2`。若索引越界，则表示空节点或者节点不存在。

### 1.映射公式函数

```cpp

/* 获取左子节点的索引 */
int left(int i) {
    return 2 * i + 1;
}

/* 获取右子节点的索引 */
int right(int i) {
    return 2 * i + 2;
}

/* 获取父节点的索引 */
int parent(int i) {
    return (i - 1) / 2; // 向下整除
}

```

### 2.访问堆顶元素

```cpp

/* 访问堆顶元素 */
int peek() {
    return maxHeap[0];
}

```

### 3.元素入堆

将元素先添加到堆底，也就是数组末尾，此时可能不满足堆成立的条件。因此需要修复插入节点到根节点路径上的各个节点，此操作称为堆化(siftup)。

具体操作就是：比较插入节点与其父节点的值，若插入节点值更大就交换二者，循环执行此操作，直到越过根节点或者插入节点的值小于其根节点值。

时间复杂度是O(log n)，因为n个节点，有 `log n` 层，最多执行这么多次操作。

```cpp

/* 元素入堆 */
void push(int val) {
    // 添加节点
    maxHeap.push_back(val);
    // 从底至顶堆化
    siftUp(size() - 1);
}

/* 从节点 i 开始，从底至顶堆化 */
void siftUp(int i) {
    while (true) {
        // 获取节点 i 的父节点
        int p = parent(i);
        // 当“越过根节点”或“节点无须修复”时，结束堆化
        if (p < 0 || maxHeap[i] <= maxHeap[p])
            break;
        // 交换两节点
        swap(maxHeap[i], maxHeap[p]);
        // 循环向上堆化
        i = p;
    }
}

```

### 4.堆顶元素出堆

- 交换堆顶元素与堆底元素。
- 交换完成后，删除堆底元素。
- 从根节点开始，从顶到底执行堆化。

```cpp

/* 元素出堆 */
void pop() {
    // 判空处理
    if (isEmpty()) {
        throw out_of_range("堆为空");
    }
    // 交换根节点与最右叶节点（交换首元素与尾元素）
    swap(maxHeap[0], maxHeap[size() - 1]);
    // 删除节点
    maxHeap.pop_back();
    // 从顶至底堆化
    siftDown(0);
}

/* 从节点 i 开始，从顶至底堆化 */
void siftDown(int i) {
    while (true) {
        // 判断节点 i, l, r 中值最大的节点，记为 ma
        int l = left(i), r = right(i), ma = i;
        if (l < size() && maxHeap[l] > maxHeap[ma])
            ma = l;
        if (r < size() && maxHeap[r] > maxHeap[ma])
            ma = r;
        // 若节点 i 最大或索引 l, r 越界，则无须继续堆化，跳出
        if (ma == i)
            break;
        swap(maxHeap[i], maxHeap[ma]);
        // 循环向下堆化
        i = ma;
    }
}

```

## Application

- 优先队列
- 堆排序
- 获取最大的k个元素