include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.11.0
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

set(BINARY ${CMAKE_PROJECT_NAME}_test)

add_executable(${BINARY} main-test.cpp TemperatureSensor-test.cpp Cooler-test.cpp Heater-test.cpp app-test.cpp
                        ../src/util.cpp ../src/TemperatureSensor.cpp ../src/TemperatureDevice.cpp ../src/Heater.cpp ../src/Cooler.cpp ../src/app.cpp)

target_link_libraries(${BINARY} PRIVATE GTest::GTest)

add_test(${BINARY}s  ${BINARY})

