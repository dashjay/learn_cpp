#include <array>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()
#include <iostream>
#include <string>
int getRandomNumber(int min, int max) {
    static constexpr double fraction{1.0 / (RAND_MAX + 1.0)};
    return min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
}
class Creature {
  protected:
    std::string m_name;
    char        m_symbol;
    int         m_health;
    int         m_damage;
    int         m_gold;

  public:
    Creature() = delete;
    Creature(std::string n, char s, int h, int d, int g)
        : m_name{n}
        , m_symbol{s}
        , m_health{h}
        , m_damage{d}
        , m_gold{g} {
    }
    const std::string &getName() const {
        return m_name;
    }
    char getSymbol() const {
        return m_symbol;
    }
    int getHealth() const {
        return m_health;
    }
    int getDamage() const {
        return m_damage;
    }
    int getGold() const {
        return m_gold;
    }
    void reduceHealth(int x) {
        m_health -= x;
    }
    bool isDead() const {
        return m_health <= 0;
    }
    void addGold(int g) {
        m_gold += g;
    }
};

// int main() {
//   Creature o{"orc", 'o', 4, 2, 10};
//   o.addGold(5);
//   o.reduceHealth(1);
//   std::cout << "The " << o.getName() << " has " << o.getHealth()
//             << " health and is carrying " << o.getGold() << " gold.\n";
//   return 0;
//}

class Player : public Creature {
  private:
    int m_level{1};

  public:
    Player(const std::string name)
        : Creature{name, '@', 10, 1, 0} {
    }
    int getLevel() const {
        return m_level;
    }
    bool hasWon() const {
        return m_level >= 20;
    }
    void levelUp() {
        ++m_level;
        ++m_damage;
    }
};

// int main() {
//    std::cout << "Enter your name:\n";
//    std::string name;
//    std::cin >> name;
//    Player p{name};
//    std::cout << "You have " << p.getHealth() << " health and are carrying "
//              << p.getGold() << " gold.\n";
//}
class Monster : public Creature {
  private:
    struct MonsterData {
        std::string_view name;
        char             symbol;
        int              health;
        int              damage;
        int              gold;
    };

  public:
    enum Type { DRAGON, ORC, SLIME, MAX_TYPES };
    static constexpr std::array<MonsterData, Monster::MAX_TYPES> monsterData{
        {{"dragon", 'D', 20, 4, 100},
         {"orc", 'o', 4, 2, 25},
         {"slime", 's', 1, 1, 10}}

    };
    Monster(Type t)
        : Creature{monsterData[ t ].name.data(), monsterData[ t ].symbol,
                   monsterData[ t ].health, monsterData[ t ].damage,
                   monsterData[ t ].gold} {
    }
    static Monster getRandomMonster() {
        return Monster(static_cast<Type>(getRandomNumber(0, MAX_TYPES - 1)));
    }
};

// int main() {
//   Monster m{Monster::ORC};
//   std::cout << "A " << m.getName() << " (" << m.getSymbol()
//             << ") was created.\n";
//
//   return 0;
//}

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::rand();

    for (int i{0}; i < 10; i++) {
        Monster m{Monster::getRandomMonster()};
        std::cout << "A " << m.getName() << "(" << m.getSymbol()
                  << ") was created.\n";
    }
    return 0;
}
