cmake_minimum_required(VERSION 3.0.0)
project(nodepp-bluetooth VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(NODEPP_BLUETOOTH_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")

# Search for Nodepp
find_package(nodepp REQUIRED) 
if(NOT nodepp_FOUND)
    message(FATAL_ERROR "Nodepp not found. Please install nodepp.")
endif()

if(NOT WIN32)

    # Search for Bluetooth
    find_library(BLUETOOTH_LIBRARY NAMES bluetooth REQUIRED)
    if(NOT BLUETOOTH_LIBRARY)
        message(FATAL_ERROR "Bluetooth library not found. Please install libbluetooth-dev or equivalent files.")
    endif()

    find_path(BLUETOOTH_INCLUDE_DIR NAMES bluetooth/bluetooth.h)

endif()

if(NOT WIN32)

    set(BLUETOOTH_LINK_DEPS
        nodepp ${BLUETOOTH_LIBRARY}
    )

    target_include_directories(nodepp-bluetooth INTERFACE ${BLUETOOTH_INCLUDE_DIR})

else()
    set(BLUETOOTH_LINK_DEPS nodepp)
endif()

target_link_libraries( nodepp-bluetooth INTERFACE 
    ${BLUETOOTH_LINK_DEPS}
)