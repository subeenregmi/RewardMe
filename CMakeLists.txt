cmake_minimum_required(VERSION 3.26.4)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(RewardMe)
add_executable(app src/main.cpp src/button.cpp)

target_include_directories(app PUBLIC ${PROJECT_SOURCE_DIR}/includes)

include(FetchContent)

FetchContent_Declare(
  SFML
  GIT_REPOSITORY https://github.com/SFML/SFML.git
  GIT_TAG        69ea0cd863aed1d4092b970b676924a716ff718b # release-2.6.1
)

FetchContent_MakeAvailable(SFML)
target_link_libraries(app PUBLIC sfml-graphics)
