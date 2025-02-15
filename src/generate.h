#pragma once

#include "car.h"
#include "user.h"
#include "config.h"

#include <string>

namespace Generate {
    std::vector<Car> GenerateCars(const std::string& jsonPath) {
        std::ifstream file(jsonPath);
        auto cars = nlohmann::json::parse(file);
        
        std::vector<Car> generatedCars;
        for (size_t i = 0; i < cars["cars"].size(); ++i) {
            auto car = cars["cars"][i];
            generatedCars.emplace_back(car["car_name"], car["car_number"], car["drivers_name"]);
        }

        return generatedCars;
    }
}
