from abc import ABC, abstractmethod

# A weather station that updates multiple displays when the weather data changes.
# Push or pull?
# Push when all observers need the same data in the same format. Simpler for observers.
# Pull when observers have different data requirements. Simpler for subject.

class Subject(ABC):
    @abstractmethod
    def register_observer(self, observer):
        pass

    @abstractmethod
    def remove_observer(self, observer):
        pass

    @abstractmethod
    def notify_observers(self):
        pass


class Observer(ABC):
    @abstractmethod
    def update_push(self, temperature, humidity, pressure):
        pass

    def update_pull(self, subject):
        pass


class WeatherData(Subject):  # Subject is only owner of data: loose coupling
    def __init__(self):
        self._observers = []  # Dynamic
        self._temperature = 0.0
        self._humidity = 0.0
        self._pressure = 0.0  # extensible

    def register_observer(self, observer):
        self._observers.append(observer)

    def remove_observer(self, observer):
        self._observers.remove(observer)

    def notify_observers(self):
        for observer in self._observers:
            observer.update_push(self._temperature, self._humidity, self._pressure)  # Subject PUSHES to observers via a common interface
            observer.update_pull(self)  # vs PULL

    def set_measurements(self, temperature, humidity, pressure):
        self._temperature = temperature
        self._humidity = humidity
        self._pressure = pressure
        self.notify_observers()  # can add logic (e.g. java's "set_changed" functionality) s.t. observers aren't notified for every tiny change, only big enough ones, if desired.


class CurrentConditionsDisplay(Observer):
    def __init__(self, weather_data):
        self._temperature = 0.0
        self._humidity = 0.0
        self._weather_data = weather_data
        self._weather_data.register_observer(self)

    def update_push(self, temperature, humidity, pressure):
        self._temperature = temperature
        self._humidity = humidity
        self.display()

    def update_pull(self, subject):
        self._temperature = subject.get_temperature()
        self._humidity = subject.get_humidity()
        self.display()

    def display(self):
        print(f"Current conditions: {self._temperature}°C and {self._humidity}% humidity")



class StatisticsDisplay(Observer):
    def __init__(self, weather_data):
        self._temperature_readings = []
        self._weather_data = weather_data  # stored s.t. can unregister in the future if desired
        self._weather_data.register_observer(self)

    def update_push(self, temperature, humidity, pressure):
        self._temperature_readings.append(temperature)
        self.display()

    def update_pull(self, subject):
        self._temperature_readings.append(subject.get_temperature())
        self.display()

    def display(self):
        average_temp = sum(self._temperature_readings) / len(self._temperature_readings)
        print(f"Avg/Max/Min temperature = {average_temp:.1f}/{max(self._temperature_readings):.1f}/{min(self._temperature_readings):.1f}")


class ForecastDisplay(Observer):
    def __init__(self, weather_data):
        self._current_pressure = 0.0
        self._last_pressure = 0.0
        self._weather_data = weather_data
        self._weather_data.register_observer(self)

    def update_push(self, temperature, humidity, pressure):
        self._last_pressure = self._current_pressure
        self._current_pressure = pressure
        self.display()

    def display(self):
        if self._current_pressure > self._last_pressure:
            forecast = "Improving weather on the way!"
        elif self._current_pressure == self._last_pressure:
            forecast = "More of the same"
        else:
            forecast = "Watch out for cooler, rainy weather"
        print(f"Forecast: {forecast}")


if __name__ == "__main__":
    weather_data = WeatherData()

    # Note: the observers won't update in any fixed order, so don't depend on it!
    current_display = CurrentConditionsDisplay(weather_data)
    statistics_display = StatisticsDisplay(weather_data)
    forecast_display = ForecastDisplay(weather_data)
    # Better than:
    # temp = getTemp()
    # current_display = CurrentConditionsDisplay.update(temp, humidity, pressure)
    # - DRY: each new display needs update to be written again; main repeats code as per SRP notes.
    # + YAGNI: ok
    # - SRP: main has to manage both state update (get new data) and notification (update displays)
    # - Open/closed: each display update needs to be modified if update data changes.
    # - Decoupled? each display has to know what update data exists.
    # - Runtime flexibility: hardcoding required.
    # + OOP: ok

    print("Updating weather measurements:")
    weather_data.set_measurements(25, 65, 1013)
    weather_data.set_measurements(27, 70, 1010)
    weather_data.set_measurements(22, 90, 1009)
