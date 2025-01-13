# This is a situation where one of the factory patterns could be applied.
# - Open/closed: need to modify if adding new type
# - Not SRP
# - Hard to test due to multiple branches

from abc import abstractmethod, ABC

def code_to_refactor():
    class NotificationService:
        def send_notification(self, notification_type, recipient, message):
            if notification_type == "email":
                print(f"Sending email to {recipient}: {message}")
            elif notification_type == "sms":
                print(f"Sending SMS to {recipient}: {message}")
            elif notification_type == "push":
                print(f"Sending Push Notification to {recipient}: {message}")
            else:
                raise ValueError(f"Unknown notification type: {notification_type}")

    # Example usage
    service = NotificationService()
    service.send_notification("email", "user@example.com", "Welcome to our service!")
    service.send_notification("sms", "+123456789", "Your OTP is 1234.")

#------------------------------------------
# Simple factory solution:
#==========================================
# Could use different methods (files) instead of classes to be more OOP

def simple_factory_solution():
    class Email:
        def send_notification(self, recipient, message):
            print(f"Sending email to {recipient}: {message}")
    class Sms:
        def send_notification(self, recipient, message):
            print(f"Sending SMS to {recipient}: {message}")
    class Push:
        def send_notification(self, recipient, message):
            print(f"Sending Push Notification to {recipient}: {message}")

    def get_service(notification_type):
        if notification_type == "email":
            return Email()
        elif notification_type == "sms":
            return Sms()
        elif notification_type == "push":
            return Push()
        else:
            raise ValueError(f"Unknown notification type: {notification_type}")

    service = get_service("email")
    service.send_notification("user@example.com", "Welcome to our simple factory service!")

#------------------------------------------
# Factory method pattern solution:
#==========================================
# Let's assume the client company really wants to make a Notification Service Object for good reasons
# Open/closed
# NotificationServiceClass doesn't know anything about the notification type (beyond what the client class passes it)
# Good SRP

def factory_method_pattern_solution():
    class Notification(ABC):
        @abstractmethod
        def send(self, recipient, message):
            print(f"Sending '{message}' to {recipient}")

    class Email(Notification):
        def send(self, recipient, message):
            print(f"Sending email '{message}' to {recipient}")

    class Sms(Notification):
        def send(self, recipient, message):
            print(f"Sending sms '{message}' to {recipient}")

    class NotificationService(ABC):
        @abstractmethod
        def _create_notification(self, notification_type):
            pass

        def send_notification(self, notification_type, recipient, message):
            notification_type = self._create_notification(notification_type)
            notification_type.send(recipient, message)

    class BasicNotificationService(NotificationService):
        def _create_notification(self, notification_type):
            if notification_type == "email":
                return Email()
            elif notification_type == "sms":
                return Sms()
            else:
                raise ValueError(f"Unknown notification type: {notification_type}")

    service = BasicNotificationService()
    service.send_notification("email", "eg@123.com", "Welcome to our factory method pattern service!")


if __name__ == "__main__":
    code_to_refactor()
    print("-------------")
    simple_factory_solution()
    print("-------------")
    factory_method_pattern_solution()