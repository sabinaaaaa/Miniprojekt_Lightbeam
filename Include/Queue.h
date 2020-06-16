//
// Created by bgbg5 on 6/9/2020.
//

#ifndef MINIPROJEKT_LIGHTBEAM_QUEUE_H
#define MINIPROJEKT_LIGHTBEAM_QUEUE_H
#include "vertex.h"

class Queue{
public:
    struct node{
        unsigned vertId;
        node* next;
    };
    Queue();
    void enqueue(unsigned int vertId);
    unsigned int dequeue();
    bool isEmpty();
    bool isNotEmpty();
    int getCurrAmt();
    void clear();
    ~Queue();
private:
    int currAmt;
    node* head;
    node* tail;
};

#endif //MINIPROJEKT_LIGHTBEAM_QUEUE_H
