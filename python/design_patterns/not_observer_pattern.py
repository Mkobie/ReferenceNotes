# This is a situation where the observer pattern could be applied.

class FileProcessor:
    def __init__(self):
        self.file = None

    def upload_file(self, file_name):
        self.file = file_name
        print(f"File '{self.file}' uploaded.")
        self.notify_upload()

    def process_file(self):
        if not self.file:
            print("No file to process.")
            return

        print(f"Processing file '{self.file}'...")
        success = len(self.file) % 2 == 0
        if success:
            self.notify_success()
        else:
            self.notify_error()

    def notify_upload(self):
        Logger().log(f"File '{self.file}' uploaded.")
        Notifier().notify(f"'{self.file}' uploaded successfully.")

    def notify_success(self):
        Database().save(f"Record for '{self.file}'")
        Notifier().notify(f"'{self.file}' processed successfully.")

    def notify_error(self):
        Logger().log(f"Error processing '{self.file}'.")
        Notifier().notify(f"Error processing '{self.file}'.")

class Logger:
    def log(self, message):
        print(f"Logger: {message}")

class Notifier:
    def notify(self, message):
        print(f"Notifier: {message}")

class Database:
    def save(self, record):
        print(f"Database: Saved {record}")


processor = FileProcessor()
processor.upload_file("document.txt")
processor.process_file()
processor.upload_file("report.pdf")
processor.process_file()
print()
print()


#------------------------------------------
# Observer pattern solution:
#==========================================
# + Reduces existing coupling; improves separation of concerns
# + Makes adding more observers (email notification, analytic trackers) nice (open/closed, extensible, yay interfaces...)

from abc import ABC, abstractmethod

# "eums" to reduce coupling further (otherwise conditional on passed strings...)
class Events:
    FILE_UPLOADED = "file_uploaded"
    FILE_PROCESSED_SUCCESS = "file_processed_success"
    FILE_PROCESSED_ERROR = "file_processed_error"


class Subject(ABC):
    @abstractmethod
    def register_observer(self, observer):
        pass

    @abstractmethod
    def remove_observer(self, observer):
        pass

    @abstractmethod
    def notify_observers(self, event, data):
        pass


class Observer(ABC):
    @abstractmethod
    def update_push(self, event, data):
        pass

    def update_pull(self, subject):
        pass


class FileProcessor(Subject):
    def __init__(self):
        self.file = None
        self.observers = []

    def register_observer(self, observer):
        self.observers.append(observer)

    def remove_observer(self, observer):
        self.observers.remove(observer)

    def notify_observers(self, event, data):
        for observer in self.observers:
            observer.update_push(event, data)

    def upload_file(self, file_name):
        self.file = file_name
        print(f"File '{self.file}' uploaded.")
        self.notify_observers(Events.FILE_UPLOADED, self.file)

    def process_file(self):
        if not self.file:
            print("No file to process.")
            return

        print(f"Processing file '{self.file}'...")
        success = len(self.file) % 2 == 0
        if success:
            self.notify_observers(Events.FILE_PROCESSED_SUCCESS, self.file)
        else:
            self.notify_observers(Events.FILE_PROCESSED_ERROR, self.file)


class Logger(Observer):
    def update_push(self, event, data):
        if event == Events.FILE_UPLOADED:
            print(f"Logger: File '{data}' uploaded.")
        elif event == Events.FILE_PROCESSED_SUCCESS:
            print(f"Logger: File '{data}' processed successfully.")
        elif event == Events.FILE_PROCESSED_ERROR:
            print(f"Logger: Error processing file '{data}'.")


class Notifier(Observer):
    def update_push(self, event, data):
        if event == Events.FILE_UPLOADED:
            print(f"Notifier: '{data}' uploaded successfully.")
        elif event == Events.FILE_PROCESSED_SUCCESS:
            print(f"Notifier: '{data}' processed successfully.")
        elif event == Events.FILE_PROCESSED_ERROR:
            print(f"Notifier: Error processing '{data}'.")


class Database(Observer):
    def update_push(self, event, data):
        if event == Events.FILE_PROCESSED_SUCCESS:
            print(f"Database: Saved record for '{data}'.")


processor = FileProcessor()
logger = Logger()
notifier = Notifier()
database = Database()

# Register observers
processor.register_observer(logger)
processor.register_observer(notifier)
processor.register_observer(database)

# Upload and process files
processor.upload_file("document.txt")
processor.process_file()
