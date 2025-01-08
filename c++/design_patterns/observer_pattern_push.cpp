#include <iostream>
#include <vector>

// Use push when all observers need all the data fields

class Observer;
class Subject;

class Subject {
public:
    virtual ~Subject() {}
    virtual void registerObserver(Observer* o) = 0;
    virtual void removeObserver(Observer* o) = 0;
    virtual void notifyObservers() = 0;
};

class Observer {
public:
    virtual ~Observer() {}
    virtual void update(float temperature, float humidity, float pressure) = 0;
};

// Concrete implementation of Subject
class WeatherData : public Subject {
private:
    std::vector<Observer*> observers;
    float temperature;
    float humidity;
    float pressure;

public:
    WeatherData() : temperature(0), humidity(0), pressure(0) {}

    void registerObserver(Observer* o) {
        observers.push_back(o);
    }

    void removeObserver(Observer* o) {
        for (std::vector<Observer*>::iterator it = observers.begin(); it != observers.end(); ++it) {
            if (*it == o) {
                observers.erase(it);
                break;
            }
        }
    }

    void notifyObservers() {
        for (size_t i = 0; i < observers.size(); ++i) {
            observers[i]->update(temperature, humidity, pressure);
        }
    }

    // WeatherData specific methods
    void setMeasurements(float temp, float hum, float pres) {
        temperature = temp;
        humidity = hum;
        pressure = pres;
        notifyObservers();  // Notification is placed here in this example
    }
};

// Concrete Observer
class CurrentConditionsDisplay : public Observer {
private:
    float temperature;
    float humidity;
    Subject* weatherData;  // Keep a reference to the subject for future unsubscribe if desired

public:
    explicit CurrentConditionsDisplay(Subject* wd) : temperature(0), humidity(0), weatherData(wd) {
        weatherData->registerObserver(this);  // Register itself as an observer - this could be done elsewhere too
    }

    ~CurrentConditionsDisplay() {
        weatherData->removeObserver(this);  // Unregister itself
    }

    void update(float temp, float hum, float pres) {
        temperature = temp;
        humidity = hum;
        display();
    }

    void display() const {
        std::cout << "Current conditions: " << temperature << "C degrees and " << humidity << "% humidity." << std::endl;
    }
};

int main() {
    std::cout << "--------------------------" << std::endl;
    std::cout << "Observer pattern (push)" << std::endl;
    std::cout << "==========================" << std::endl;

    // Subject
    WeatherData weatherData;

    // Observer(s)
    CurrentConditionsDisplay currentDisplay(&weatherData);

    // Simulate new weather measurements
    weatherData.setMeasurements(25.5, 65.0, 1013.0);
    weatherData.setMeasurements(27.3, 70.0, 1012.5);

    std::cout << "--------------------------" << std::endl << std::endl;
    return 0;
}
