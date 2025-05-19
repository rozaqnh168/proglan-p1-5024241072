#include <iostream>
#include <string>

class Character {
private:
  std::string name;
  int health;
  int attackPower;

public:
  Character(std::string name, int health, int attackPower)
    : name(name), health(health), attackPower(attackPower) {}

  void attack(Character& target) {
    target.health -= attackPower;
    if (target.health < 0) target.health = 0;
  }

  bool isAlive() const {
    return health > 0;
  }

  void printStatus() const {
    std::cout << name << " has " << health << " health remaining.\n";
  }

  std::string getName() const {
    return name;
  }
};

int main() {
  int healthFinn, attackFinn;
  int healthIceKing, attackIceKing;
  std::string giliranpertama;
  std::cin >>healthFinn >> attackFinn;
  std::cin >>healthIceKing >> attackIceKing;
  std::cin >> giliranpertama;
  Character finn("Finn", healthFinn, attackFinn);
  Character iceKing("Ice King", healthIceKing, attackIceKing);
  finn.printStatus();
  iceKing.printStatus();
  
  while (finn.isAlive() && iceKing.isAlive()) {
    if (giliranpertama == "finn") {
      std::cout <<"Finn attacks Ice King!\n";
      finn.attack(iceKing);
      iceKing.printStatus();
    if (!iceKing.isAlive()) break;
    std::cout <<"Ice King attacks Finn!\n";
      iceKing.attack(finn);
      finn.printStatus();

   }else {
      std::cout <<"Ice King attacks Finn!\n";
      iceKing.attack(finn);
      finn.printStatus();
    if (!finn.isAlive()) break;
      std::cout <<"Finn attacks Ice King!\n";
      finn.attack(iceKing);
      iceKing.printStatus();
    }
  }
  if (finn.isAlive()) {
    std::cout <<"Finn wins the battle!\n";
  } else {
    std::cout <<"Ice King wins the battle!\n";
  }
  return 0;
}

