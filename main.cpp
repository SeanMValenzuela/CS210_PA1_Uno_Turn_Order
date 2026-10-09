#include <iostream>
#include "List.h"
#include "Player.h"

int main() {
    // ---- Part 1: required test harness, do not modify ----
    std::cout << "== List<int>: addAnywhere / deleteAnywhere / reverse =="
              << std::endl;
    std::unique_ptr<List<int>> nums = makeList<int>();
    nums->addFront(new int(10));
    nums->addFront(new int(20));
    nums->addFront(new int(30));
    nums->print();
    nums->addAnywhere(1, new int(99));
    nums->print();
    nums->deleteAnywhere(2);
    nums->print();
    nums->reverse();
    nums->print();

    std::cout << std::endl << "== List<int>: concat ==" << std::endl;
    std::unique_ptr<List<int>> more = makeList<int>();
    more->addFront(new int(2));
    more->addFront(new int(1));
    more->print();
    nums->concat(more.get());
    nums->print();
    more->print();

    // ---- Part 2: your Uno scene goes below ----
    std::cout << "A table forms, four players named Liam, Noel, Bonehead, and Guigsy join the turn order..." << std::endl;
    std::unique_ptr<List<Player>> table = makeList<Player>();
    Player* guigsy = new Player(4, "Guigsy");
    table->addFront(guigsy);
    Player* bonehead = new Player(3, "Bonehead");
    table->addFront(bonehead);
    Player* noel = new Player(2, "Noel");
    table->addFront(noel);
    Player* liam = new Player(1, "Liam");
    table->addFront(liam);
    std::cout << '\n';

    std::cout << "Each player is dealt with 3 cards..." << std::endl;
    guigsy->addCard(new Card("Red", "5"));
    guigsy->addCard(new Card("Blue", "2"));
    guigsy->addCard(new Card("Blue", "3"));

    bonehead->addCard(new Card("Any Color", "Draw Four"));
    bonehead->addCard(new Card("Green", "8"));
    bonehead->addCard(new Card("Red", "0"));

    noel->addCard(new Card("Yellow", "9"));
    noel->addCard(new Card("Blue", "5"));
    noel->addCard(new Card("Blue", "Draw Two"));

    liam->addCard(new Card("Yellow", "1"));
    liam->addCard(new Card("Green", "2"));
    liam->addCard(new Card("Yellow", "Reverse"));
    std::cout << '\n';

    std::cout << "A new player named Whitey pulls up a chair and joins mid-order..." << std::endl;
    Player* whitey = new Player(5, "Whitey");
    table->addAnywhere(3, whitey);
    std::cout << '\n';

    std::cout << "Whitey is dealt 3 cards..." << std::endl;
    whitey->addCard(new Card("Any Color", "Wild Card"));
    whitey->addCard(new Card("Blue", "Reverse"));
    whitey->addCard(new Card("Green", "3"));
    std::cout << '\n';

    std::cout<<"Bonehead plays a card..." << std::endl;
    bonehead->playCard();
    std::cout << '\n';

    std::cout << "Liam plays a reverse card..." << std::endl;
    liam->playCard();
    std::cout << '\n';

    std::cout << "Turn order before reverse: " << std::endl;
    table->print();
    table->reverse();
    std::cout << "Turn order after reverse: " << std::endl;
    table->print();
    std::cout << '\n';

    std::cout << "Noel runs out of cards and steps away from the table..." <<std::endl;
    table->deleteAnywhere(3);
    std::cout << '\n';

    std::cout << "A second table with players named Tony, Gem, Andy, and Joey is formed..." << std::endl;
    std::unique_ptr<List<Player>> table2 = makeList<Player>();
    Player* joey = new Player(9, "Joey");
    table2->addFront(joey);
    Player* andy = new Player(8, "Andy");
    table2->addFront(andy);
    Player* gem = new Player(7, "Gem");
    table2->addFront(gem);
    Player* tony = new Player(6, "Tony");
    table2->addFront(tony);
    std::cout << '\n';

    std::cout << "Joey, Andy, Gem, and Tony are dealt 3 cards each..." << std::endl;
    joey->addCard(new Card("Any Color", "Wild Card"));
    joey->addCard(new Card("Green", "5"));
    joey->addCard(new Card("Yellow", "3"));

    andy->addCard(new Card("Blue", "0"));
    andy->addCard(new Card("Red", "Draw Two"));
    andy->addCard(new Card("Red", "1"));

    gem->addCard(new Card("Blue", "8"));
    gem->addCard(new Card("Green", "4"));
    gem->addCard(new Card("Any Color", "Draw Four"));

    tony->addCard(new Card("Yellow", "6"));
    tony->addCard(new Card("Yellow", "7"));
    tony->addCard(new Card("Red", "Reverse"));
    std::cout << '\n';

    std::cout << "First table: " << std::endl;
    table->print();
    std::cout << "Second table: " << std::endl;
    table2->print();
    std::cout << "The two tables decide to merge into one... " << std::endl;
    table->concat(table2.get());
    std::cout << "First table after merge: " << std::endl;
    table->print();
    std::cout << "Second table after merge: " << std::endl;
    table2->print();
    std::cout << '\n';

    return 0;
}
