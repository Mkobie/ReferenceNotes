#include <iostream>
#include <string>

class Service {
public:
    std::string serve() {
        return "Service is running";
    }
};

class MethodInjection {
public:
    std::string run(Service* service) {
        return service->serve();
    }
};

class ConstructorInjection {
private:
    Service* service;
public:
    ConstructorInjection(Service* service) : service(service) {}

    std::string run() {
        return service->serve();
    }
};

class SetterInjection {
private:
    Service* service;
public:
    SetterInjection() : service(NULL) {}

    void setService(Service* service) {
        this->service = service;
    }

    std::string run() {
        return service->serve();
    }
};

int main() {
    std::cout << "--------------------------" << std::endl;
    std::cout << "Dependency injection" << std::endl;
    std::cout << "==========================" << std::endl;

    Service service;

    MethodInjection client1;
    std::cout << "Method Injection: " << client1.run(&service) << std::endl;

    ConstructorInjection client2(&service);
    std::cout << "Constructor Injection: " << client2.run() << std::endl;

    SetterInjection client3;
    client3.setService(&service);
    std::cout << "Setter Injection: " << client3.run() << std::endl;

    std::cout << "--------------------------" << std::endl << std::endl;
    return 0;
}
