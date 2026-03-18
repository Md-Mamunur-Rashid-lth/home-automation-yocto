cmake_minimum_required(VERSION 3.5)

project(light_service)

add_executable(light_service light_service.cpp)

find_package(PkgConfig REQUIRED)
pkg_check_modules(SYSTEMD REQUIRED libsystemd)

target_include_directories(light_service PRIVATE ${SYSTEMD_INCLUDE_DIRS})
target_link_libraries(light_service ${SYSTEMD_LIBRARIES})

install(TARGETS light_service DESTINATION bin)
install(FILES light.service DESTINATION ${SYSTEMD_UNITDIR})
