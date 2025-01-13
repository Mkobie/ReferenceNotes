import datetime
from abc import ABC, abstractmethod

def code_to_refactor():
    class Logger:
        def __init__(self):
            self.filters = []

        def add_filter(self, filter_function):
            self.filters.append(filter_function)

        def log(self, message):
            for filter_func in self.filters:
                if not filter_func(message):
                    return  # Message is filtered out

            self.write(message)

        def write(self, message):
            print(message)


    class TimestampLogger(Logger):
        def __init__(self):
            super().__init__()

        def log(self, message):
            timestamp = datetime.datetime.now().strftime("%Y-%m-%d %H:%M:%S")
            super().log(f"{timestamp} - {message}")


    logger = Logger()

    # Add a filter to ignore messages that contain "DEBUG"
    logger.add_filter(lambda msg: "DEBUG" not in msg)

    logger.log("This is a normal message")
    logger.log("DEBUG: This is a debug message")

    timestamp_logger = TimestampLogger()
    timestamp_logger.log("Logging with a timestamp.")


#------------------------------------------
# Decorator pattern solution:
#==========================================
# + Reduces existing coupling (and complexity!); improves separation of concerns
# + Makes adding more variations easy (open/closed, extensible, yay interfaces...)

def decorator_pattern_solution():
    class Logger(ABC):
        @abstractmethod
        def log(self, message):
            pass


    class BaseLogger(Logger):  # Don't put any decorator "stuff" in here. Separate!!
        def log(self, message):
            print(message)


    class LoggerDecorator(Logger, ABC):
        def __init__(self, logger):
            self.logger = logger


    class WithFilter(LoggerDecorator):
        def __init__(self, logger):
            super().__init__(logger)
            self.filters = []  # Ok to keep stuff inside the concrete decorators, or add fns. Just be careful if order matters.

        def add_filter(self, filter_function):
            self.filters.append(filter_function)

        def log(self, message):
            for filter_func in self.filters:
                if not filter_func(message):
                    return  # Message is filtered out
            self.logger.log(message)

    class WithTimestamp(LoggerDecorator):
        def log(self, message):
            self.logger.log(f"{datetime.datetime.now().strftime("%Y-%m-%d %H:%M:%S")} - {message}")


    logger = BaseLogger()

    logger = WithFilter(logger)
    logger.add_filter(lambda msg: "DEBUG" not in msg)
    logger.log("This is a normal message")
    logger.log("DEBUG: This is a debug message")

    logger = WithTimestamp(logger)
    logger.log("Logging with a timestamp.")

    print(f"Is type Logger? {isinstance(logger, Logger)}")


if __name__ == "__main__":
    code_to_refactor()
    print("-------------")
    decorator_pattern_solution()
