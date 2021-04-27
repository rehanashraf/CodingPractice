//
//  LinkedList.cpp
//  lt
//
//  Created by Ashraf, Rehan on 3/17/21.
//

#include "../../include/templates/LinkedList.h"

template <typename T>
LinkedList<T>::LinkedList() {
    head = NULL;
    tail = NULL;
    size = 0;
}

template <typename T>
LinkedList<T>::~LinkedList() {
    
    ListNode<T> *currentNode = NULL, *delNode = NULL;
    if (!isEmpty()) {
        delNode = currentNode = head;
        while (currentNode != NULL) {
            delNode = currentNode;
            currentNode = currentNode->next;
            delete delNode;
        }
    }
}

template <typename T>
void LinkedList<T>::insertNewNode(T) {
    
}

template <typename T>
int LinkedList<T>::getSize() {
    return size;
}

template <typename T>
void LinkedList<T>::print() {
    ListNode<T> *currentNode = head;
    while(currentNode != NULL) {
        cout << currentNode->data << " -> " ;
        currentNode = currentNode->next;
    }
    cout << endl;
}

template <typename T>
ListNode<T>* LinkedList<T>::search(T data) {
    ListNode<T> *retVal = head;
    
    while (retVal != NULL) {
        if (retVal->data == data) {
            break;
        }
        retVal = retVal->next;
    }
    return retVal;
}

template <typename T>
T LinkedList<T>::get(int index) {
    int currentIndex = 0;
    ListNode<T> *currentNode = head;
    
    if (index > size - 1 || index < 0) {
        return NULL;
    }
    
    while (currentNode != NULL) {
        if(currentIndex == index) {
            return *currentNode;
        }
        currentNode = currentNode->next;
        currentIndex++;
    }
    
    return *currentNode;
}

template <typename T>
void LinkedList<T>::addAtIndex(int index, T val) {
    int currentIndex = 0;
    ListNode<T> *currentNode = head, *previousNode = NULL;
    
    if (index < 0) {
        insertBegin(val);
    }
    else if (index >= size) {
        insertEnd(val);
    }
    else {
        while(currentNode != NULL) {
            if(currentIndex == index) {
                previousNode->next = new ListNode<T>(val);
                previousNode->next->next = currentNode;
                size++;
                return;
            }
            previousNode = currentNode;
            currentNode = currentNode->next;
            currentIndex++;
        }
    }
}

template <typename T>
void LinkedList<T>::deleteAtIndex(int index) {
    int currentIndex = 0;
    ListNode<T> *currentNode = head, *previousNode = NULL;
    
    while(currentNode != NULL) {
        if(currentIndex == index) {
            previousNode->next = currentNode->next;
            delete currentNode;
            size--;
            return;
        }
        previousNode = currentNode;
        currentNode = currentNode->next;
        currentIndex++;
    }
}

template <typename T>
void LinkedList<T>::insertBegin(T val) {
    ListNode<T> *temp = new ListNode<T>(val);
    size++;
    temp->next = head;
    head = temp;
}

template <typename T>
void LinkedList<T>::insertEnd(T val) {
    ListNode<T> *temp = new ListNode<T>(val);
    size++;
    tail->next = temp;
    tail = temp;
}
