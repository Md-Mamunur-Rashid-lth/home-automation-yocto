cmake_minimum_required(VERSION 3.5)

project(automation_controller)

add_executable(automation_controller automation_controller.cpp)

find_package(PkgConfig REQUIRED)
pkg_check_modules(SYSTEMD REQUIRED libsystemd)

target_include_directories(automation_controller PRIVATE ${SYSTEMD_INCLUDE_DIRS})
target_link_libraries(automation_controller ${SYSTEMD_LIBRARIES})

install(TARGETS automation_controller DESTINATION bin)
install(FILES automation.service DESTINATION ${SYSTEMD_UNITDIR})
