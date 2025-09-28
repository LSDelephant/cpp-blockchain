cmake_minimum_required(VERSION 3.10)
project(cpp_blockchain VERSION 0.1 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(OpenSSL REQUIRED)


include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/third_party)


add_executable(node src/main.cpp src/node.cpp src/block.cpp src/blockchain.cpp)
target_link_libraries(node OpenSSL::SSL OpenSSL::Crypto)


add_executable(test_chain tests/chain_test.cpp src/block.cpp src/blockchain.cpp)
target_link_libraries(test_chain OpenSSL::SSL OpenSSL::Crypto)


install(TARGETS node DESTINATION bin)
