cmake_minimum_required(VERSION 3.10)

# Project name
project(IPC_COM)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

# Boost dependency
find_package(Boost REQUIRED COMPONENTS system thread)
include_directories(${Boost_INCLUDE_DIRS})

# Include directories for headers
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/proxy)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/skeleton)

# Define source files for each component
set(DAEMON_SRC
    src/daemon.cpp
    src/service_registry.cpp
)

set(OFFER_SERVICE_API_SRC
    test_app/offerservice_API.cpp
)

set(FIND_SERVICE_API_SRC
    test_app/findservice_API.cpp
)

# Add executables
add_executable(daemon ${DAEMON_SRC})
add_executable(offer_service ${OFFER_SERVICE_API_SRC})
add_executable(find_service ${FIND_SERVICE_API_SRC})

# Link Boost libraries
target_link_libraries(daemon ${Boost_LIBRARIES} rt)
target_link_libraries(offer_service ${Boost_LIBRARIES} rt)
target_link_libraries(find_service ${Boost_LIBRARIES} rt)

# Include directories for each target
target_include_directories(daemon PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(offer_service PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(find_service PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
