cmake_minimum_required(VERSION 3.5)

project(rest_server)

add_executable(rest_server rest_server.cpp)

find_package(PkgConfig REQUIRED)
pkg_check_modules(SYSTEMD REQUIRED libsystemd)

target_include_directories(rest_server PRIVATE ${SYSTEMD_INCLUDE_DIRS})
target_link_libraries(rest_server ${SYSTEMD_LIBRARIES})

install(TARGETS rest_server DESTINATION bin)
install(FILES rest.service DESTINATION ${SYSTEMD_UNITDIR})
