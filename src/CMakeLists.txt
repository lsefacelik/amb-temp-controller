set(BINARY ${CMAKE_PROJECT_NAME})

add_executable(${BINARY}_out main.cpp TemperatureSensor.cpp TemperatureDevice.cpp Cooler.cpp Heater.cpp util.cpp app.cpp)

add_library(${BINARY}_lib STATIC TemperatureSensor.cpp TemperatureDevice.cpp Cooler.cpp Heater.cpp util.cpp)
