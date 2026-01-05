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
        list->head = newNode;
        list->tail = newNode;
    } else {
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

// 反转链表
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

int main() {
    List* a;
    int n;
    scanf("%d",&n);
    return 0;
}