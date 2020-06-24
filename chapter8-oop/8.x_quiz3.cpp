#include <array>
#include <iostream>
#include <string>

class Monster {
  public:
    enum Type {
        Dragon,
        Goblin,
        Ogre,
        Orc,
        Skeleton,
        Troll,
        Vampire,
        Zombie,
        MAX_MONSTER_TYPES
    };

  private:
    Type        m_type{};
    std::string m_name{};
    std::string m_roar{};
    int         m_hit_points{};
    std::string getTypeString() {
        switch (m_type) {
        case Type::Dragon:
            return "dragon";
        case Type::Goblin:
            return "goblin";
        case Type::Ogre:
            return "ogre";
        case Type::Orc:
            return "orc";
        case Type::Skeleton:
            return "skeleton";
        case Type::Troll:
            return "troll";
        case Type::Vampire:
            return "vampire";
        case Type::Zombie:
            return "zombie";
        default:
            return "unknown";
        }
    }

  public:
    Monster(Type _t, std::string _name, std::string _roar, int _hit_points)
        : m_type{_t}
        , m_name{_name}
        , m_roar{_roar}
        , m_hit_points{_hit_points} {
    }
    void print() {
        std::printf("%s the %s has %d hit points and says %s", m_name.c_str(),
                    getTypeString().c_str(), m_hit_points, m_roar.c_str());
    }
};

class MonsterGenerator {
  public:
    static constexpr std::array<const char *, 6> s_names{"a", "b", "c",
                                                         "d", "e", "f"};
    static constexpr std::array<const char *, 6> s_roars{"a*", "b*", "c*",
                                                         "d*", "e*", "f*"};
    static int getRandomNumber(int min, int max) {
        static constexpr double fraction{1.0 /
                                         (static_cast<double>(RAND_MAX) + 1.0)};
        return static_cast<int>(std::rand() * fraction * (max - min + 1) + min);
    }

    static Monster generatorMonster() {

        return Monster{static_cast<Monster::Type>(getRandomNumber(
                           0, Monster::Type::MAX_MONSTER_TYPES - 1)),
                       s_names[ getRandomNumber(0, s_names.size() - 1) ],
                       s_roars[ getRandomNumber(0, s_roars.size() - 1) ],
                       getRandomNumber(0, 100)};
    }
};

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::rand();
    Monster r{MonsterGenerator::generatorMonster()};
    r.print();
    return 0;
}
