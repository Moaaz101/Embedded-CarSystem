# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.1.0)
set(toolchainVersion 13_3_Rel1)
set(picotoolVersion 2.1.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
set(PICO_BOARD pico CACHE STRING "Board type")

cmake_minimum_required(VERSION 3.12)

include(pico_sdk_import.cmake)

project(Pico-FreeRTOS)

pico_sdk_init()

add_subdirectory(freertos)

# Add the executable and its source files
add_executable(Pico-FreeRTOS
    ProjectFiles/main.c  # Include source files directly here
    ProjectFiles/drivers/buzzer_driver.c  # Add implementation files for drivers
    ProjectFiles/drivers/led_driver.c
    ProjectFiles/drivers/servo_driver.c
    ProjectFiles/drivers/ultrasonic_driver.c
    ProjectFiles/drivers/touch_driver.c
    ProjectFiles/drivers/ir_driver.c
)

# Add include directories
target_include_directories(Pico-FreeRTOS PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/ProjectFiles/drivers# Directory for your driver headers
)

# Link libraries to the executable
target_link_libraries(Pico-FreeRTOS pico_stdlib freertos hardware_pwm)

