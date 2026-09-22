# Hash Table

## 核心思想

通过哈希函数把 key 映射到数组中的某个位置。

## 基本复杂度

平均：

- 查询 O(1)
- 插入 O(1)
- 删除 O(1)

最坏情况下可能退化到O(n).

## C++ 中的相关容器

- unordered_map
- unordered_set

## 我容易混淆的地方

通过哈希表查找时常根据key查找，而不是value。