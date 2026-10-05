//
// Created by Sean Valenzuela on 9/17/26.
//

# pragma once

#include "Node.h"
#include "List.h"
template <typename T>
class LinkedList : public List<T> {
public:
    LinkedList() : head_(nullptr) {}
    void addFront(T* value) override {
        Node<T>* fresh = new Node<T>(value);
        fresh->next = head_;
        head_ = fresh;
    }
    void deleteFront() override {
        if (head_ == nullptr) {
            std::cout << "LinkedList is empty." << std::endl;
            return;
        }
        Node<T>* doomed = head_;
        head_ = head_->next;
        delete doomed->data;
        delete doomed;
    }
    bool search(T* value) const override {
        Node<T>* current = head_;
        while (current != nullptr) {
            if (*current->data == *value) return true;
            current = current->next;
        }
        return false;
    }
    void print() const override {
        Node<T>* current = head_;
        while (current != nullptr) {
            std::cout << *current->data << ",";
            current = current->next;
        }
        std::cout << std::endl;
    }
    void addAnywhere(int position, T* value) override {
        if (position < 0) {
            std::cout << "Invalid position." << std::endl;
            return;
        }
        int count = 0;
        Node <T>* current = head_;
        if (position == 0) {
            addFront(value);
            return;
        } else {
            while (count != position - 1) {
                if (current == nullptr) {
                    std::cout << "Invalid position." << std::endl;
                    return;
                }current = current->next;
                count++;
            }
        }
        Node <T>* newNode = new Node<T>(value);
        newNode->next = current->next;
        current->next = newNode;
    }
    ~LinkedList() override {
        while (head_ != nullptr) {
            Node<T>* doomed = head_;
            head_ = head_->next;
            delete doomed->data;
            delete doomed;
        }
    }
private:
    Node<T>* head_;
};