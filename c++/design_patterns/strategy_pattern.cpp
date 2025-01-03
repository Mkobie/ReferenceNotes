#include <iostream>

class IFlyBehavior {
public:
    virtual void fly() const = 0;
    virtual ~IFlyBehavior() {}
};

class FlyWithWings : public IFlyBehavior {
public:
    void fly() const {
        std::cout << "I'm flying with wings!" << std::endl;
    }
};

class FlyNoWay : public IFlyBehavior {
public:
    void fly() const {
        std::cout << "I can't fly." << std::endl;
    }
};

class IQuackBehavior {
public:
    virtual void quack() const = 0;
    virtual ~IQuackBehavior() {}
};

class Quack : public IQuackBehavior {
public:
    void quack() const {
        std::cout << "Quack!" << std::endl;
    }
};

class Squeak : public IQuackBehavior {
public:
    void quack() const {
        std::cout << "Squeak!" << std::endl;
    }
};

class MuteQuack : public IQuackBehavior {
public:
    void quack() const {
        std::cout << "..." << std::endl;
    }
};


class Duck {
protected:
    IFlyBehavior* flyBehavior;
    IQuackBehavior* quackBehavior;

public:
    Duck(IFlyBehavior* fb, IQuackBehavior* qb) : flyBehavior(fb), quackBehavior(qb) {}

    virtual ~Duck() {
        delete flyBehavior;
        delete quackBehavior;
    }

    void performFly() const {
        flyBehavior->fly();
    }

    void performQuack() const {
        quackBehavior->quack();
    }

    void setFlyBehavior(IFlyBehavior* fb) {
        delete flyBehavior;
        flyBehavior = fb;
    }

    void setQuackBehavior(IQuackBehavior* qb) {
        delete quackBehavior;
        quackBehavior = qb;
    }

    virtual void display() const = 0;
};

class MallardDuck : public Duck {
public:
    MallardDuck() : Duck(new FlyWithWings(), new Quack()) {}

    void display() const {
        std::cout << "I'm a Mallard Duck!" << std::endl;
    }
};

class RubberDuck : public Duck {
public:
    RubberDuck() : Duck(new FlyNoWay(), new Squeak()) {}

    void display() const {
        std::cout << "I'm a rubber duck!" << std::endl;
    }
};

class DecoyDuck : public Duck {
public:
    DecoyDuck() : Duck(new FlyNoWay(), new MuteQuack()) {}

    void display() const {
        std::cout << "I'm a decoy duck!" << std::endl;
    }
};


int main() {
    std::cout << "--------------------------" << std::endl;
    std::cout << "Strategy pattern" << std::endl;
    std::cout << "==========================" << std::endl;

    Duck* mallard = new MallardDuck();
    Duck* rubber = new RubberDuck();
    Duck* decoy = new DecoyDuck();

    mallard->display();
    mallard->performFly();
    mallard->performQuack();

    std::cout << std::endl;

    rubber->display();
    rubber->performFly();
    rubber->performQuack();

    std::cout << std::endl;

    decoy->display();
    decoy->performFly();
    decoy->performQuack();

    std::cout << "Upgrading the decoy duck's fly behavior..." << std::endl;
    rubber->setFlyBehavior(new FlyWithWings());
    rubber->performFly();

    delete mallard;
    delete rubber;
    delete decoy;

    std::cout << "--------------------------" << std::endl << std::endl;
    return 0;
}
