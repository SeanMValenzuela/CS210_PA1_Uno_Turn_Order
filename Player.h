#pragma once
#include <ostream>
#include <string>
#include "Stack.h"
#include "Card.h"

class Player {
public:
    Player(int id, const std::string& name)
        : id_(id), name_(name) {}

    bool operator==(const Player& other) const {
        return id_ == other.id_;
    }

    friend std::ostream& operator<<(std::ostream& out, const Player& p) {
        return out << p.id_ << " " << p.name_;
    }

    void addCard(Card* card) {
        hand_.push(card);
    }

    Card* playCard() {
        if (hand_.peek() == nullptr) {
            std::cout << "Hand is empty, no card to play." << std::endl;
            return nullptr;
        }
        std:: cout << *hand_.peek() << std::endl;
        return hand_.pop();
    }

private:
    int id_;
    std::string name_;
    Stack<Card> hand_;
};
