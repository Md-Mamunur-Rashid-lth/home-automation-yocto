cmake_minimum_required(VERSION 3.5)

project(temperature_service)

add_executable(temperature_service temperature_service.cpp)

find_package(PkgConfig REQUIRED)
pkg_check_modules(SYSTEMD REQUIRED libsystemd)

target_include_directories(temperature_service PRIVATE ${SYSTEMD_INCLUDE_DIRS})
target_link_libraries(temperature_service ${SYSTEMD_LIBRARIES})

install(TARGETS temperature_service DESTINATION bin)

install(FILES temperature.service DESTINATION ${SYSTEMD_UNITDIR})
