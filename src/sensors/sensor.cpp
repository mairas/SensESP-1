#include "sensor.h"

std::set<Sensor*> Sensor::sensors_;

Sensor::Sensor(String config_path) : Configurable{config_path}, Enable(10) {
  sensors_.insert(this);
}

NumericSensor::NumericSensor(String config_path)
    : Sensor(config_path), NumericProducer(){};

IntegerSensor::IntegerSensor(String config_path)
    : Sensor(config_path), IntegerProducer(){};

StringSensor::StringSensor(String config_path)
    : Sensor(config_path), StringProducer(){};
