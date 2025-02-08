链表最为重要的就是先熟悉如何构造链表，链表基础的数据结构的形成
```cpp
struct LinkNode{
    int val ;//当前链表节点的取值
    LinkNode  *next ;//指向下一节点的指针
    LinkNode (int x) : val(x), next(NULL) {} ;//构造函数
};
```
