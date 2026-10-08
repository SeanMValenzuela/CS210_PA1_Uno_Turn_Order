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
    table->addFront(new Player(4, "Guigsy"));
    table->addFront(new Player(3, "Bonehead"));
    table->addFront(new Player(2, "Noel"));
    table->addFront(new Player(1, "Liam"));
    std::cout << '\n';

    std::cout << "A new player named Whitey pulls up a chair and joins mid-order..." << std::endl;
    table->addAnywhere(3, new Player(5, "Whitey"));
    std::cout << '\n';

    std::cout << "Someone plays a reverse card..." << std::endl;
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
    table2->addFront(new Player(4, "Joey"));
    table2->addFront(new Player(3, "Andy"));
    table2->addFront(new Player(2, "Gem"));
    table2->addFront(new Player(1, "Tony"));
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
