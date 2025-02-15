#include <SFML/Graphics.hpp>

#include <iostream>
#include <thread>
#include <chrono>
#include <memory>
#include <utility>

#include "thread_safe_queue.h"
#include "map.h"
#include "user.h"
#include "config.h"
#include "car.h"
#include "generate.h"

int main () {
    auto window = sf::RenderWindow(sf::VideoMode({MAP_WIDTH, MAP_HEIGHT}), "taxi finder");
    window.setFramerateLimit(144);

    Map map(MAP_PATH);
    map.Build(JSON_MAP);
    Car car1("Tesla", "132", "Дустрик");
    Car car2("Cadillac", "456", "Забел");
    car1.SetFinish({543, 456});
    car2.SetFinish({681, 73});
    car1.InitStations(map);
    car2.InitStations(map);

    auto points = map.GetPoints();

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        window.clear();
        window.draw(map.GetSprite());
        window.draw(car1.GetSprite());
        window.draw(car2.GetSprite());
        bool flag = car1.OnNextTick();
        if (flag) {
            int index = rand() % points.size();
            while (points[index] == car1.GetPosition()) {
                index = rand() % points.size();
            }
            car1.SetFinish(points[index]);
            car1.InitStations(map);
        }
        flag = car2.OnNextTick();
        if (flag) {
            int index = rand() % points.size();
            while (points[index] == car2.GetPosition()) {
                index = rand() % points.size();
            }
            car2.SetFinish(points[index]);
            car2.InitStations(map);
        }
        window.display();
    }
}
