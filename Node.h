//
// Created by kwoodle on 11/14/17.
//

#ifndef STUDY_NODE_H
#define STUDY_NODE_H

#include <iostream>

struct Node {
    explicit Node(int n) : val{n}, next{nullptr} {};
    int val;
    Node *next;

    ~Node() {
//        std::cout<<"Node destructor\n";
    }
};

struct List {
public:
    Node *head;

    List() : head{nullptr} {};

    explicit List(int n) {
        head = new Node(n);
    }

    List(std::initializer_list<int> lst) {
        head = nullptr;
        for (auto i:lst) {
            add(i);
        }
    }

    ~List() {
        Node *cur = head;
        while (cur) {
            Node *next = cur->next;
            delete (cur);
//            std::cout<<"Deleting in Nodes in ~List\n";
            cur = next;
        }
    }

    void add(int n) {
        Node *p = new Node(n);
        Node *cur = head;
        head = p;
        head->next = cur;
    }

    friend std::ostream &operator<<(std::ostream &os, const List &l) {
        Node *cur = l.head;
        while (cur) {
            os << cur->val << ", ";
            cur = cur->next;
        }
        os << "\n";
        return os;
    }
};

#endif //STUDY_NODE_H
