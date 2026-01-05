#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;
typedef struct List {
    Node* head;
    Node* tail;
    int length;
} List;

// 创建节点
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// 初始化链表
List* initList() {
    List* list = (List*)malloc(sizeof(List));
    list->head = NULL;
    list->tail = NULL;
    list->length = 0;
    return list;
}

// 销毁链表
void destroyList(List* list) {
    if (list == NULL) return;
    Node* current = list->head;
    Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    free(list);
}

// 头插法插入节点
void insertAtHead(List* list, int data) {
    Node* newNode = createNode(data);
    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        newNode->next = list->head;
        list->head->prev = newNode;
        list->head = newNode;
    }
    list->length++;
}

// 尾插法插入节点
void insertAtTail(List* list, int data) {
    Node* newNode = createNode(data);
    if (list->head == NULL) {
        // 空链表
        list->head = newNode;
        list->tail = newNode;
    } else {
        // 非空链表
        newNode->prev = list->tail;
        list->tail->next = newNode;
        list->tail = newNode;
    }
    list->length++;
}

// 在指定位置插入节点
bool insertAtPosition(List* list, int data, int position) {
    if (position < 0 || position > list->length) return false;
    if (position == 0) {
        insertAtHead(list, data);
        return true;
    }
    if (position == list->length) {
        insertAtTail(list, data);
        return true;
    }
    Node* current;
    if (position < list->length / 2) {
        current = list->head;
        for (int i = 0; i < position - 1; i++) current = current->next;
    } else {
        current = list->tail;
        for (int i = list->length - 1; i > position - 1; i--) current = current->prev;
    }
    Node* newNode = createNode(data);
    newNode->next = current->next;
    newNode->prev = current;
    current->next->prev = newNode;
    current->next = newNode;
    list->length++;
    return true;
}

// 删除所有匹配指定值的节点
bool deleteByValue(List* list, int data) {
    if (list == NULL || list->head == NULL) return 0;
    Node* current = list->head;
    Node* temp;
    bool found = false;
    while (current != NULL) {
        if (current->data == data) {
            temp = current;
            if (current == list->head) {
                list->head = current->next;
                if (list->head != NULL) list->head->prev = NULL;
                else list->tail = NULL;
            } else if (current == list->tail) {
                list->tail = current->prev;
                list->tail->next = NULL;
            } else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }
            current = current->next;
            free(temp);
            list->length--;
            found = true;
        } else {
            current = current->next;
        }
    }
    return found;
}

// 删除指定位置节点
bool deleteByPosition(List* list, int position) {
    if (list == NULL || list->head == NULL) return false;
    if (position < 0 || position >= list->length) return false;
    Node* current;
    if (position < list->length / 2) {
        current = list->head;
        for (int i = 0; i < position; i++) {
            current = current->next;
        }
    } else {
        current = list->tail;
        for (int i = list->length - 1; i > position; i--) current = current->prev;
    }
    if (current == list->head) {
        list->head = current->next;
        if (list->head != NULL) list->head->prev = NULL;
        else list->tail = NULL;
    } else if (current == list->tail) {
        list->tail = current->prev;
        list->tail->next = NULL;
    } else {
        current->prev->next = current->next;
        current->next->prev = current->prev;
    }
    free(current);
    list->length--;
    return true;
}

// 查找节点位置
int searchNode(List* list, int data) {
    if (list == NULL || list->head == NULL) return -1;
    Node* current = list->head;
    int position = 0;
    while (current != NULL) {
        if (current->data == data) return position;
        current = current->next;
        position++;
    }
    return -1;
}

// 获取指定位置的节点值
bool getValueAtPosition(List* list, int position, int* value) {
    if (list == NULL || list->head == NULL || position < 0 || position >= list->length) return false;
    Node* current;
    if (position < list->length / 2) {
        current = list->head;
        for (int i = 0; i < position; i++) current = current->next;
    } else {
        current = list->tail;
        for (int i = list->length - 1; i > position; i--) current = current->prev;
    }
    *value = current->data;
    return true;
}

// 更新指定位置的节点值
bool updateValueAtPosition(List* list, int position, int newValue) {
    if (list == NULL || list->head == NULL || 
        position < 0 || position >= list->length) {
        return false;
    }
    Node* current;
    if (position < list->length / 2) {
        current = list->head;
        for (int i = 0; i < position; i++) current = current->next;
    } else {
        current = list->tail;
        for (int i = list->length - 1; i > position; i--) current = current->prev;
    }
    current->data = newValue;
    return true;
}

// 反转链表 - 双向链表反转更高效
void reverseList(List* list) {
    if (list == NULL || list->head == NULL || list->head->next == NULL) {
        return;
    }
    Node* current = list->head;
    Node* temp = NULL;
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    temp = list->head;
    list->head = list->tail;
    list->tail = temp;
}

// 获取链表长度
int getLength(List* list) {
    return (list != NULL) ? list->length : 0;
}

// 判断链表是否为空
bool isEmpty(List* list) {
    return (list == NULL || list->head == NULL);
}

// 复制链表
List* copyList(List* list) {
    if (list == NULL) return NULL;
    List* newList = initList();
    if (newList == NULL) return NULL;
    Node* current = list->head;
    while (current != NULL) {
        insertAtTail(newList, current->data);
        current = current->next;
    }
    return newList;
}

// 合并两个升序链表
List* mergeSortedLists(List* list1, List* list2) {
    if (list1 == NULL && list2 == NULL) return NULL;
    if (list1 == NULL) return copyList(list2);
    if (list2 == NULL) return copyList(list1);
    List* mergedList = initList();
    Node* p1 = list1->head;
    Node* p2 = list2->head;
    while (p1 != NULL && p2 != NULL) {
        if (p1->data <= p2->data) {
            insertAtTail(mergedList, p1->data);
            p1 = p1->next;
        } else {
            insertAtTail(mergedList, p2->data);
            p2 = p2->next;
        }
    }
    while (p1 != NULL) {
        insertAtTail(mergedList, p1->data);
        p1 = p1->next;
    }
    while (p2 != NULL) {
        insertAtTail(mergedList, p2->data);
        p2 = p2->next;
    }
    return mergedList;
}

// 对链表进行冒泡排序
void sortList(List* list) {
    if (list == NULL || list->head == NULL || list->head->next == NULL) {
        return;
    }
    bool swapped;
    Node* ptr1;
    Node* lptr = NULL;
    do {
        swapped = false;
        ptr1 = list->head;
        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

// 排序并移除重复元素
void removeDuplicates(List* list) {
    if (list == NULL || list->head == NULL || list->head->next == NULL) return;
    sortList(list);
    Node* current = list->head;
    while (current->next != NULL) {
        if (current->data == current->next->data) {
            Node* temp = current->next;
            if (temp == list->tail) {
                list->tail = current;
                current->next = NULL;
            } else {
                current->next = temp->next;
                temp->next->prev = current;
            }
            free(temp);
            list->length--;
        } else {
            current = current->next;
        }
    }
}

// 获取链表中间节点值
bool getMiddleValue(List* list, int* value) {
    if (list == NULL || list->head == NULL) {
        return false;
    }
    Node* slow = list->head;
    Node* fast = list->head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    *value = slow->data;
    return true;
}

// 判断链表是否有环
bool hasCycle(List* list) {
    if (list == NULL || list->head == NULL) {
        return false;
    }
    Node* slow = list->head;
    Node* fast = list->head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

// 查找倒数第k个节点
bool findKthFromEnd(List* list, int k, int* value) {
    if (list == NULL || list->head == NULL || k <= 0 || k > list->length) {
        return false;
    }
    if (k == 1) {
        *value = list->tail->data;
        return true;
    }
    Node* current = list->tail;
    for (int i = 1; i < k; i++) {
        current = current->prev;
    }
    *value = current->data;
    return true;
}

// 正向遍历链表并打印
void traverseListForward(List* list) {
    if (list == NULL || list->head == NULL) {
        printf("链表为空\n");
        return;
    }
    Node* cur = list->head;
    printf("正向遍历（长度：%d）: ", list->length);
    while (cur) {
        printf("%d", cur->data);
        if (cur->next != NULL) {
            printf(" <-> ");
        }
        cur = cur->next;
    }
    printf(" -> NULL\n");
}

// 反向遍历链表并打印
void traverseListBackward(List* list) {
    if (list == NULL || list->tail == NULL) {
        printf("链表为空\n");
        return;
    }
    Node* cur = list->tail;
    printf("反向遍历（长度：%d）: ", list->length);
    printf("NULL");
    while (cur) {
        printf(" <- %d", cur->data);
        if (cur->prev != NULL) {
            printf(" <->");
        }
        cur = cur->prev;
    }
    printf("\n");
}

// 打印链表详细信息
void printListInfo(List* list) {
    if (list == NULL) {
        printf("链表不存在\n");
        return;
    }
    
    printf("========== 双向链表信息 ==========\n");
    printf("链表地址: %p\n", (void*)list);
    printf("链表长度: %d\n", list->length);
    printf("是否为空: %s\n", isEmpty(list) ? "是" : "否");
    printf("头节点: %p, 尾节点: %p\n", (void*)list->head, (void*)list->tail);
    
    if (list->head != NULL) {
        printf("头节点数据: %d, 尾节点数据: %d\n", list->head->data, list->tail->data);
    }
    
    if (hasCycle(list)) {
        printf("链表状态: 有环\n");
    } else {
        printf("链表状态: 无环\n");
        traverseListForward(list);
        
        int middleValue;
        if (getMiddleValue(list, &middleValue)) {
            printf("中间节点值: %d\n", middleValue);
        }
    }
    printf("================================\n\n");
}

// 创建测试用的示例链表
List* createSampleList() {
    List* list = initList();
    for (int i = 1; i <= 5; i++) {
        insertAtTail(list, i);
    }
    return list;
}

// 测试双向链表特性
void testBidirectionalTraversal(List* list) {
    printf("=== 测试双向遍历 ===\n");
    if (list == NULL || list->head == NULL) {
        printf("链表为空\n");
        return;
    }
    
    printf("正向遍历: ");
    Node* current = list->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
    
    printf("反向遍历: ");
    current = list->tail;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->prev;
    }
    printf("\n");
}

// 测试函数
void testLinkedList() {
    printf("=== 开始测试双向链表功能 ===\n\n");
    
    // 1. 创建链表
    printf("1. 创建新链表\n");
    List* myList = initList();
    printListInfo(myList);
    
    // 2. 插入节点
    printf("2. 插入节点\n");
    printf("头插法插入 3, 2, 1\n");
    insertAtHead(myList, 3);
    insertAtHead(myList, 2);
    insertAtHead(myList, 1);
    printListInfo(myList);
    testBidirectionalTraversal(myList);
    
    printf("尾插法插入 4, 5, 6\n");
    insertAtTail(myList, 4);
    insertAtTail(myList, 5);
    insertAtTail(myList, 6);
    printListInfo(myList);
    testBidirectionalTraversal(myList);
    
    // 3. 在指定位置插入
    printf("3. 在位置3插入值99\n");
    insertAtPosition(myList, 99, 3);
    printListInfo(myList);
    
    // 4. 搜索节点
    printf("4. 搜索节点\n");
    int searchResult = searchNode(myList, 99);
    if (searchResult != -1) {
        printf("找到值99，位置：%d\n\n", searchResult);
    }
    
    // 5. 获取指定位置的值
    printf("5. 获取位置2的值\n");
    int value;
    if (getValueAtPosition(myList, 2, &value)) {
        printf("位置2的值为：%d\n\n", value);
    }
    
    // 6. 更新值
    printf("6. 将位置3的值更新为88\n");
    updateValueAtPosition(myList, 3, 88);
    printListInfo(myList);
    
    // 7. 删除操作
    printf("7. 删除操作\n");
    printf("删除值为88的节点\n");
    deleteByValue(myList, 88);
    printListInfo(myList);
    
    printf("删除位置0的节点\n");
    deleteByPosition(myList, 0);
    printListInfo(myList);
    
    // 8. 反转链表
    printf("8. 反转链表\n");
    reverseList(myList);
    printListInfo(myList);
    testBidirectionalTraversal(myList);
    
    // 9. 排序链表
    printf("9. 排序链表\n");
    sortList(myList);
    printListInfo(myList);
    
    // 10. 创建第二个链表并合并
    printf("10. 创建第二个链表并合并\n");
    List* list2 = initList();
    for (int i = 7; i <= 10; i++) {
        insertAtTail(list2, i);
    }
    printf("第二个链表：\n");
    printListInfo(list2);
    
    List* mergedList = mergeSortedLists(myList, list2);
    printf("合并后的链表：\n");
    printListInfo(mergedList);
    
    // 11. 去重操作
    printf("11. 去重操作\n");
    printf("在合并链表中插入重复值\n");
    insertAtTail(mergedList, 5);
    insertAtTail(mergedList, 5);
    insertAtTail(mergedList, 5);
    printListInfo(mergedList);
    
    printf("去重后：\n");
    removeDuplicates(mergedList);
    printListInfo(mergedList);
    
    // 12. 查找倒数第k个节点
    printf("12. 查找倒数第3个节点\n");
    int kthValue;
    if (findKthFromEnd(mergedList, 3, &kthValue)) {
        printf("倒数第3个节点的值为：%d\n\n", kthValue);
    }
    
    // 13. 复制链表
    printf("13. 复制链表\n");
    List* copiedList = copyList(mergedList);
    printf("复制的链表：\n");
    printListInfo(copiedList);
    
    // 14. 检查是否有环
    printf("14. 检查链表是否有环\n");
    printf("链表是否有环：%s\n\n", hasCycle(mergedList) ? "是" : "否");
    
    // 清理内存
    destroyList(myList);
    destroyList(list2);
    destroyList(mergedList);
    destroyList(copiedList);
    
    printf("=== 测试完成 ===\n");
}

int main() {
    testLinkedList();
    return 0;
}