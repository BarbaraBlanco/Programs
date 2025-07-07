#ifndef TEMPERATURA-EX03_H_INCLUDED
#define TEMPERATURA-EX03_H_INCLUDED

float fahrenheitParaCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5.0 / 9.0;
}

float celsiusParaFahrenheit(float celsius) {
    return celsius * 9.0 / 5.0 + 32;
}


#endif // TEMPERATURA-EX03_H_INCLUDED
