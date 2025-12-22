#pragma once

#include <string>
#include "time_utility.h"

using TrainId = size_t;
using namespace time_utility;

enum class TrainType { 
    PASSENGER, FREIGHT, HIGH_SPEED, SUBWAY, SPECIALIZED
};

class Train {
private:
    TrainId train_id_;
    TrainType train_type_;
    std::string destination_city_;
    std::time_t departure_time_;
    std::time_t journey_duration_;

public:
    Train() = default;

    Train(TrainId id, TrainType type, const std::string& destination,
            std::time_t departure, std::time_t duration)
        : train_id_(id), train_type_(type), destination_city_(destination),
            departure_time_(departure), journey_duration_(duration) {}
    
    TrainId getId() const {
        return train_id_;
    }

    TrainType getType() const {
        return train_type_;
    }

    const std::string& getDestination() const {
        return destination_city_;
    }

    std::time_t getDepartureTime() const {
        return departure_time_;
    }

    std::time_t getJourneyDuration() const {
        return journey_duration_;
    }

    bool operator<(const Train& other) const {
        return departure_time_ < other.departure_time_;
    }
};