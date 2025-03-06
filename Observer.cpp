#include <iostream>
#include <vector>

// Интерфейс наблюдателя
class Observer {
public:
    virtual void update(float temperature, float humidity, float pressure) = 0;
};

// Субъект (WeatherStation)
class WeatherStation {
private:
    float temperature;
    float humidity;
    float pressure;
    std::vector<Observer*> observers;
public:
    void registerObserver(Observer* observer) {
        observers.push_back(observer);
    }
    void removeObserver(Observer* observer) {
        // При необходимости можно реализовать логику удаления
    }
    void notifyObservers() {
        for (Observer* observer : observers) {
            observer->update(temperature, humidity, pressure);
        }
    }
    void setMeasurements(float temp, float hum, float press) {
        temperature = temp;
        humidity = hum;
        pressure = press;
        notifyObservers();
    }
};

// Конкретный наблюдатель
class Display : public Observer {
public:
    void update(float temperature, float humidity, float pressure) {
        std::cout << "Display: Temperature = " << temperature << "°C, Humidity = " << humidity << "%, Pressure = " << pressure << " hPa" << std::endl;
    }
};

int main() {
    WeatherStation weatherStation;
    // Создание дисплеев
    Display display1;
    Display display2;
    // Регистрация дисплеев как наблюдателей
    weatherStation.registerObserver(&display1);
    weatherStation.registerObserver(&display2);
}
