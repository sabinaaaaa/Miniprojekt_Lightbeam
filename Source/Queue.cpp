//
// Created by I. Marinov on 6/9/2020.
//

#include "Queue.h"
/**
 * @brief
 */
Queue::Queue() {
    this->head = nullptr;
    this->tail = nullptr;
    this->currAmt = 0;
}
/**
 * @brief Takes out the fore-most element of the list and returns its value.
 * @return Value of the fore-most element in the list
 */
unsigned int Queue::dequeue() {
    unsigned id= this->head->vertId;
    if (head == tail) {
        delete this->head;
        this->head = this->tail = nullptr;
    } else {
        struct node *temp = this->head->next;
        delete this->head;
        head = temp;
    }
    this->currAmt--;
    return id;
}
/**
 * @brief Adds a new node at the end of the queue
 * @param vertId the vertex thats added to the queue
 */
void Queue::enqueue(unsigned int vertId) {
    struct node *add = new struct node;
    add->vertId = vertId;
    add->next= nullptr;
    if (this->isEmpty()) {
        this->head = add;
        //this->tail=add;
    }else{
        this->tail->next=add;
    }
    this->tail=add;
    this->currAmt++;
}
/**
 * @brief Deletes all of the nodes in the list(queue) and frees their memory.
 */
void Queue::clear() {
    struct node *curr = this->head;
    struct node* save;
    while (curr != nullptr) {
        save=curr->next;
        delete curr;
        curr=save;
        this->currAmt--;
    }
    this->head = nullptr;
    this->tail = nullptr;
}

bool Queue::isEmpty() {
    return this->tail== nullptr && this->head== nullptr;
}
bool Queue::isNotEmpty() {
    return this->tail!= nullptr && this->head!= nullptr;
}
int Queue::getCurrAmt(){
    return this->currAmt;
}
Queue::~Queue() {
    this->clear();
}