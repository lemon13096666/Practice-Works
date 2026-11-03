#pragma once
#include <stdexcept>

struct Kinematics {
    // 1. Расчет скорости: v = s / t
    static double velocity(double distance, double time) {
        if(time <= 0.0) {
            throw std::invalid_argument("Время должно быть строго положительным");
        }
        if(distance < 0.0) {
            throw std::invalid_argument("Расстояние не может быть отрицательным");
        }
        return distance / time;
    }

    // 2. Расчет расстояния: s = v * t
    static double distance(double velocity, double time) {
        if(time < 0.0) {
            throw std::invalid_argument("Время не может быть отрицательным");
        }
        if(velocity < 0.0) {
            throw std::invalid_argument("Скорость не может быть отрицательной");
        }
        return velocity * time;
    }

    // 3. Расчет времени: t = s / v
    static double time(double distance, double velocity) {
        if(velocity <= 0.0) {
            throw std::invalid_argument("Скорость должна быть строго больше нуля");
        }
        if(distance < 0.0) {
            throw std::invalid_argument("Расстояние не может быть отрицательным");
        }
        return distance / velocity;
    }

    // 4. Расчет ускорения: a = (v_end - v_start) / t
    static double acceleration(double initialVelocity, double finalVelocity, double time) {
        if(time <= 0.0) {
            throw std::invalid_argument("Время должно быть строго положительным");
        }
        return (finalVelocity - initialVelocity) / time;
    }
};