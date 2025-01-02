# Dependency injection: Don't instantiate other classes inside your class.
# Common approaches: constructor injection, setter injection, and method injection.

class Service:
    def serve(self):
        return "Service is running"


class MethodInjection:
    def run(self, service: Service):
        return service.serve()

class ConstructorInjection:
    def __init__(self, service: Service):
        self.service = service

    def run(self):
        return self.service.serve()

class SetterInjection:
    def __init__(self):
        self.service = None

    def set_service(self, service: Service):
        self.service = service

    def run(self):
        return self.service.serve()


if __name__ == "__main__":
    service = Service()

    client1 = MethodInjection()
    print("Method Injection:", client1.run(service))

    client2 = ConstructorInjection(service)
    print("Constructor Injection:", client2.run())

    client3 = SetterInjection()
    client3.set_service(service)
    print("Setter Injection:", client3.run())
