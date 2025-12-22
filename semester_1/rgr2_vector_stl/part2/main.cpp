#include "time_utility.h"
#include "train.h"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

void checkInputFile(std::ifstream& file_stream) {
    if (!file_stream.is_open()) {
        throw "Ошибка: Не удалось открыть входной файл\n";
    }
    if (file_stream.peek() == std::ifstream::traits_type::eof()) {
        throw "Ошибка: Входной файл пуст\n";
    }
}

void displayTrainInfo(const Train& train) {
    std::cout << "Поезд №" << train.getId()
              << " | Тип: " << static_cast<int>(train.getType())
              << " | Направление: " << train.getDestination()
              << " | Отправление: ";
    PrintTime(train.getDepartureTime());
    std::cout << " | Время в пути: ";
    PrintTime(train.getJourneyDuration());
    std::cout << '\n';
}

std::vector<Train> loadTrainsFromFile(std::ifstream& input_file) {
    using namespace time_utility;
    std::vector<Train> train_list;
    
    TrainId train_id; 
    int type_value; 
    std::string destination;
    size_t dep_hour, dep_minute, travel_hour, travel_minute;

    while (input_file >> train_id >> type_value >> destination 
                      >> dep_hour >> dep_minute >> travel_hour >> travel_minute) {
        try {
            std::time_t departure = SetTime(dep_hour, dep_minute);
            std::time_t travel_time = SetTime(travel_hour, travel_minute);
            
            TrainType train_type = static_cast<TrainType>(type_value);
            train_list.emplace_back(train_id, train_type, destination, departure, travel_time);
        }
        catch (const std::out_of_range& error) {
            std::cerr << "Предупреждение: " << error.what() 
                      << " - поезд №" << train_id << " пропущен\n";
            continue;
        }
    }
    
    return train_list;
}

void showTrainsSortedByDeparture(std::vector<Train>& trains) {
    std::sort(trains.begin(), trains.end());
    for (const Train& train : trains) {
        displayTrainInfo(train);
    }
}

void showTrainsInTimeInterval(const std::vector<Train>& trains, std::time_t start_time, std::time_t end_time) {
    for (const Train& train : trains) {
        std::time_t departure = train.getDepartureTime();
        if (departure >= start_time && departure <= end_time) {
            displayTrainInfo(train);
        }
    }
}

void showTrainsToDestination(const std::vector<Train>& trains, const std::string& target_destination) {
    for (const Train& train : trains) {
        if (train.getDestination() == target_destination) {
            displayTrainInfo(train);
        }
    }
}

void showTrainsFilteredByTypeAndDestination(const std::vector<Train>& trains, int train_type_value, const std::string& target_destination) {
    TrainType target_type = static_cast<TrainType>(train_type_value);
    for (const Train& train : trains) {
        if (train.getType() == target_type && train.getDestination() == target_destination) {
            displayTrainInfo(train);
        }
    }
}

void findAndDisplayFastestTrain(std::vector<Train>& trains, const std::string& target_destination) {
    Train* fastest_train_ptr = nullptr;
    
    for (Train& train : trains) {
        if (train.getDestination() == target_destination) {
            if (!fastest_train_ptr || 
                train.getJourneyDuration() < fastest_train_ptr->getJourneyDuration()) {
                fastest_train_ptr = &train;
            }
        }
    }
    
    if (fastest_train_ptr != nullptr) {
        displayTrainInfo(*fastest_train_ptr);
    } else {
        std::cout << "Поездов до " << target_destination << " не найдено\n";
    }
}

int main() {
    using namespace time_utility;

    std::ifstream data_file("input.txt");
    try {
        checkInputFile(data_file);
    }
    catch (const char* error_msg) {
        std::cerr << error_msg;
        return 1;
    }

    std::vector<Train> trains = loadTrainsFromFile(data_file);
    
    if (trains.empty()) {
        std::cout << "Нет данных о поездах для обработки\n";
        return 0;
    }

    std::cout << "Поезда, отсортированные по времени отправления:\n";
    showTrainsSortedByDeparture(trains);

    std::cout << "\nПоезда в указанном временном диапазоне:\n";
    std::time_t time_start = SetTime(9, 45);
    std::time_t time_end = SetTime(11, 50);
    showTrainsInTimeInterval(trains, time_start, time_end);

    std::cout << "\nПоезда до указанного пункта назначения:\n";
    std::string destination_city = "Minsk";
    showTrainsToDestination(trains, destination_city);

    std::cout << "\nПоезда определенного типа до пункта назначения:\n";
    int train_type = 0;
    showTrainsFilteredByTypeAndDestination(trains, train_type, destination_city);

    std::cout << "\nСамый быстрый поезд до пункта назначения:\n";
    findAndDisplayFastestTrain(trains, destination_city);

    return 0;
}