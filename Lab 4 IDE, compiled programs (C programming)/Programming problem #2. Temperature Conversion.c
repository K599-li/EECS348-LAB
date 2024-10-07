#include <stdio.h>

// Function declarations
float celsius_to_fahrenheit(float celsius);
float fahrenheit_to_celsius(float fahrenheit);
float celsius_to_kelvin(float celsius);
float kelvin_to_celsius(float kelvin);
float fahrenheit_to_kelvin(float fahrenheit);
float kelvin_to_fahrenheit(float kelvin);

void categorize_temperature(float celsius);

int main() {
    float temperature, converted_temperature;
    int current_scale, target_scale;

    // Input temperature value
    printf("Enter the temperature: ");
    if (scanf("%f", &temperature) != 1) {
        printf("Invalid input. Please enter a numeric value.\n");
        return 1;
    }

    // Choose the current scale
    printf("Choose the current scale (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
    if (scanf("%d", &current_scale) != 1 || current_scale < 1 || current_scale > 3) {
        printf("Invalid choice. Please enter 1, 2, or 3.\n");
        return 1;
    }

    // Choose the conversion target 
    printf("Convert to (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
    if (scanf("%d", &target_scale) != 1 || target_scale < 1 || target_scale > 3) {
        printf("Invalid choice. Please enter 1, 2, or 3.\n");
        return 1;
    }

    // Prevent converting to the same scale
    if (current_scale == target_scale) {
        printf("Invalid conversion. The target scale must be different from the current scale.\n");
        return 1;
    }

    // Perform the conversion
    switch (current_scale) {
        case 1: // Celsius
            if (target_scale == 2) {
                converted_temperature = celsius_to_fahrenheit(temperature);
            } else if (target_scale == 3) {
                converted_temperature = celsius_to_kelvin(temperature);
            }
            break;
        case 2: // Fahrenheit
            if (target_scale == 1) {
                converted_temperature = fahrenheit_to_celsius(temperature);
            } else if (target_scale == 3) {
                converted_temperature = fahrenheit_to_kelvin(temperature);
            }
            break;
        case 3: // Kelvin
            if (temperature < 0) {
                printf("Invalid temperature. Kelvin cannot be negative.\n");
                return 1;
            }
            if (target_scale == 1) {
                converted_temperature = kelvin_to_celsius(temperature);
            } else if (target_scale == 2) {
                converted_temperature = kelvin_to_fahrenheit(temperature);
            }
            break;
    }

    // Display the converted temperature
    switch (target_scale) {
        case 1:
            printf("Converted temperature: %.2f°C\n", converted_temperature);
            break;
        case 2:
            printf("Converted temperature: %.2f°F\n", converted_temperature);
            break;
        case 3:
            printf("Converted temperature: %.2fK\n", converted_temperature);
            break;
    }

    // Categorize the temperature and provide a weather advisory
    if (target_scale == 1) {
        categorize_temperature(converted_temperature);
    } else if (target_scale == 2) {
        categorize_temperature(fahrenheit_to_celsius(converted_temperature));
    } else if (target_scale == 3) {
        categorize_temperature(kelvin_to_celsius(converted_temperature));
    }

    return 0;
}

// Function definitions
float celsius_to_fahrenheit(float celsius) {
    return (9.0 / 5.0) * celsius + 32;
}

float fahrenheit_to_celsius(float fahrenheit) {
    return (5.0 / 9.0) * (fahrenheit - 32);
}

float celsius_to_kelvin(float celsius) {
    return celsius + 273.15;
}

float kelvin_to_celsius(float kelvin) {
    return kelvin - 273.15;
}

float fahrenheit_to_kelvin(float fahrenheit) {
    return celsius_to_kelvin(fahrenheit_to_celsius(fahrenheit));
}

float kelvin_to_fahrenheit(float kelvin) {
    return celsius_to_fahrenheit(kelvin_to_celsius(kelvin));
}

void categorize_temperature(float celsius) {
    if (celsius < 0) {
        printf("Temperature category: Freezing\n");
        printf("Weather advisory: Wear a heavy coat and stay warm.\n");
    } else if (celsius >= 0 && celsius < 10) {
        printf("Temperature category: Cold\n");
        printf("Weather advisory: Wear a jacket.\n");
    } else if (celsius >= 10 && celsius < 25) {
        printf("Temperature category: Comfortable\n");
        printf("Weather advisory: You should feel comfortable.\n");
    } else if (celsius >= 25 && celsius < 35) {
        printf("Temperature category: Hot\n");
        printf("Weather advisory: Stay hydrated and avoid heavy activity.\n");
    } else {
        printf("Temperature category: Extreme Heat\n");
        printf("Weather advisory: Stay indoors.\n");
    }
}