//https://blog.csdn.net/gogogo_sky/article/details/75208703
#include<iostream>
#include<assert.h>

using namespace std;

struct Node {
    int data;;
    Node *next;

    Node(const int x)
            : data(x), next(NULL) {}
};


//判断两个链表是否带环,如果带环返回指针相遇点（快慢指针法）----时间复杂度O(N)  参数：【链表头结点指针】
Node *CheckCycle(Node *PHead) {
    if (PHead == NULL || PHead->next == NULL)//链表为空或者只有一个结点且next为空，返回NULL
    {
        return NULL;
    }
    Node *slow = PHead;
    Node *fast = PHead;
    while (fast && fast->next) {
        fast = fast->next->next;//快指针每次走两步
        slow = slow->next;//慢指针每次走一步
        //相交，返回相遇结点
        if (fast == slow) {
            return fast;
        }
    }
    //不相交
    return NULL;
}

//求带环链表的环的入口--参数：【链表头指针】+【相遇结点】
Node *GetCycleEntryNode(Node *PHead, Node *meet) {
    assert(PHead && meet);
    Node *Start = PHead;
    Node *Meet = meet;
    while (Start != Meet) {
        Start = Start->next;
        Meet = Meet->next;
    }
    return Meet;
}

//求两个不带环链表的相交点---参数【链表1头结点】+【链表2头结点】
Node *CheckCross(Node *PHead1, Node *PHead2) {
    //1.如果两个链表有一个为空，则返回空
    if (PHead1 == NULL || PHead2 == NULL) {
        return 0;
    }
    //2.两个链表都不为空
    Node *cur1 = PHead1;
    Node *cur2 = PHead2;
    while (cur1->next) {
        cur1 = cur1->next;
    }
    cur1->next = cur2;//将链表1的尾结点连接到链表2的头结点，构成环
    cur1 = PHead1;
    Node *meet = CheckCycle(cur1);//返回快慢指针的相遇点
    //两个链表不相交
    if (meet == NULL) {
        cout << "两个链表不相交" << endl;
        return NULL;
    }
        //两个链表相交
    else {
        Node *tmp = GetCycleEntryNode(cur1, meet);//求链表的环的入口点（即两个非带环链表的相交结点）
        cout << "两个链表相交,相交点值为：" << tmp->data << endl;
        return tmp;
    }

}


//求两个链表的相交结点（1.假设链表可能带环2.链表均不带环）
Node *CheckCross1(Node *PHead1, Node *PHead2) {
    //1.两个链表至少有一个为空
    if (PHead1 == NULL || PHead2 == NULL) {
        return NULL;
    }
    //2.两个链表都不为空,求各自环的相遇点
    Node *MeetNode1 = CheckCycle(PHead1);
    Node *MeetNode2 = CheckCycle(PHead2);
    //如果两个链表有一个不带环，则两个链表不可能相交
    //2.1两个链表都不带环，转化为上面求两个不带环链表的交点问题
    if (MeetNode1 == NULL && MeetNode2 == NULL) {
        return CheckCross(PHead1, PHead2);
    }
    //2.2两个链表一个带环一个不带环,绝对不相交
    if (MeetNode1 == NULL || MeetNode2 == NULL) {
        cout << "一个带环一个不带环的两个链表没有相交点" << endl;
        return NULL;
    }
    //2.3两个链表都带环
    Node *entry1 = GetCycleEntryNode(PHead1, MeetNode1);//求带环链表1的环的入口点
    Node *entry2 = GetCycleEntryNode(PHead2, MeetNode2);//求带环链表2的环的入口点
    //2.3.1两个带环链表在环外相交
    if (entry1 == entry2) {
        Node *EntryNext = entry1->next;//保存入口点下一个结点，方便下面回复链表
        entry1->next = PHead2;
        //将链表1环的入口点连接到链表2的头部；
        //构成一个新环，该新环的入口点，就是两个链表的相交点；
        Node *meet3 = CheckCycle(PHead2);//求新环的相遇点
        Node *NewEntry = GetCycleEntryNode(PHead1, meet3);//求新环的入口点，这个入口点就是两个环的相交点
        entry1->next = EntryNext;//恢复链表1的环
        cout << "两个带环链表的相交点在环外，值为：" << NewEntry->data << endl;
        return NewEntry;
    }
        //2.3.2两个带环链表的环的入口点不一样，那么两个带环链表在环内相交,那么这两个链表的相交点为两个链表的【任意一个的链表的环的入口点】；
    else {
        cout << "两个带环链表的相交点在环外，值为；" << entry1->data << endl;
        return entry1;
    }

}

//测试部分
//1.求两个不带环链表的相交点
void test1() {
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(4);
    Node *node5 = new Node(5);
    Node *node6 = new Node(6);
    Node *node7 = new Node(7);
    Node *node8 = new Node(8);
    Node *node9 = new Node(9);
    Node *node10 = new Node(10);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;
    node7->next = node8;
    node8->next = node9;
    node9->next = node10;
    Node *node11 = new Node(11);
    Node *node22 = new Node(22);
    Node *node33 = new Node(33);
    Node *node44 = new Node(44);
    Node *node55 = new Node(55);
    node11->next = node22;
    node22->next = node33;
    node33->next = node44;
    node44->next = node55;
    node55->next = node4;
    CheckCross1(node1, node11);
}

//2.一个带环，一个不带环的链表的两个链表的相交点
void test2() {
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(4);
    Node *node5 = new Node(5);
    Node *node6 = new Node(6);
    Node *node7 = new Node(7);
    Node *node8 = new Node(8);
    Node *node9 = new Node(9);
    Node *node10 = new Node(10);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;
    node7->next = node8;
    node8->next = node9;
    node9->next = node10;
    node10->next = node5;
    Node *node11 = new Node(11);
    Node *node22 = new Node(22);
    Node *node33 = new Node(33);
    node11->next = node22;
    node22->next = node33;
    CheckCross1(node1, node11);
}

//3.两个带环链表的相交点在环外；
void test3() {
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(4);
    Node *node5 = new Node(5);
    Node *node6 = new Node(6);
    Node *node7 = new Node(7);
    Node *node8 = new Node(8);
    Node *node9 = new Node(9);
    Node *node10 = new Node(10);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;
    node7->next = node8;
    node8->next = node9;
    node9->next = node10;
    node10->next = node5;
    Node *node11 = new Node(11);
    Node *node22 = new Node(22);
    Node *node33 = new Node(33);
    node11->next = node22;
    node22->next = node33;
    node33->next = node4;
    CheckCross1(node1, node11);
}

//4.两个带环链表的相交点在环内
void test4() {
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(4);
    Node *node5 = new Node(5);
    Node *node6 = new Node(6);
    Node *node7 = new Node(7);
    Node *node8 = new Node(8);
    Node *node9 = new Node(9);
    Node *node10 = new Node(10);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;
    node7->next = node8;
    node8->next = node9;
    node9->next = node10;
    node10->next = node3;
    Node *node11 = new Node(11);
    Node *node22 = new Node(22);
    Node *node33 = new Node(33);
    node11->next = node22;
    node22->next = node33;
    node33->next = node4;
    CheckCross1(node1, node11);
}

int main() {
    test1();
    test2();
    test3();
    test4();
    return 0;
}