#include <iostream>

class Accumulator {
    int m_value;

  public:
    Accumulator() {
        m_value = 0;
    }
    void add(int value) {
        m_value += value;
    }
    friend void reset(Accumulator &accumulator);
};

void reset(Accumulator &acc) {
    acc.m_value = 0;
}

// multifriend

class Humidity;
class Temperature {
    int m_temp;

  public:
    Temperature(int temp = 0) {
        m_temp = temp;
    }
    friend void printWeather(const Temperature &temperature,
                             const Humidity &   humidity);
};

class Humidity {
    int m_humidity;

  public:
    Humidity(int humidity = 0) {
        m_humidity = humidity;
    }

    friend void printWeather(const Temperature &temperature,
                             const Humidity &   humidity);
};

void printWeather(const Temperature &temperature, const Humidity &humidity) {
    std::cout << "T: " << temperature.m_temp
              << " °C and H: " << humidity.m_humidity << " %rh \n";
}

int main() {
    Accumulator acc;
    acc.add(5);
    reset(acc);
    Humidity    hum(10);
    Temperature temp(12);
    printWeather(temp, hum);
}
