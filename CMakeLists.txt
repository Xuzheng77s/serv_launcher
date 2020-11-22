#cmake minimum version required
cmake_minimum_required(VERSION 3.12...3.19)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
  cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project(serv_launcher VERSION 0.1
                      DESCRIPTION "Minecraft server launcher")

aux_source_directory(src SRCS)
add_executable(launcher ${SRCS})
