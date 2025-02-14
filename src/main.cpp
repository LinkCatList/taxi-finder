#include <SFML/Graphics.hpp>

#include <iostream>
#include <thread>
#include <chrono>
#include <memory>
#include <utility>

#include "thread_safe_queue.h"
#include "user.h"
#include "config.h"
#include "car.h"
#include "generate.h"

int main () {
    auto window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "taxi finder");
    window.setFramerateLimit(144);
    Car car("Black Volga", "666", "Abdul", "pics/image-666.png");


    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        window.clear();
        // window.draw(spriteMap);
        window.draw(car.GetSprite());
        window.display();
    }
    // std::shared_ptr<ThreadSafeQueue<User>> pUsersQueue = std::make_shared<ThreadSafeQueue<User>>();

    // std::vector<Car> cars;
    // std::shared_ptr<std::vector<Car>> pCars = std::make_shared<std::vector<Car>>(cars);
    
    // std::mutex carMutex;
    // for (int i = 0; i < CARS_CNT; ++i) {
    //     cars.emplace_back(Generate::GenerateCar());
    // }

    // std::thread t1([pUsersQueue]() {
    //     while (true) {
    //         auto user = Generate::GenerateUser();

    //         pUsersQueue->Push(user);
    //         std::this_thread::sleep_for(std::chrono::seconds(60));
    //     }
    // });

    // std::thread t2([pUsersQueue, pCars, &carMutex]() {
    //     while (true) {
    //         if (pUsersQueue->Empty()) {
    //             std::this_thread::sleep_for(std::chrono::milliseconds(1));
    //             continue;
    //         }

    //         auto user = pUsersQueue->Pop();
    //     }
    // });

    // t1.join();
    // t2.join();
}
