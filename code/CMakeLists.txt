set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O3")

## Set Boost paths
SET(CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} /vagrant/boost_1_57_0/bin/include)
SET(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} /vagrant/boost_1_57_0/bin/lib)

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS 4.9)
        message(FATAL_ERROR "GCC version >=4.9 required.")
    endif()
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS 3.3)
        message(FATAL_ERROR "Clang version >=3.3 required.")
    endif()
else()
    message(WARNING "Your compiler (${CMAKE_CXX_COMPILER_ID}) has not been tested on this project. Only Clang and GCC has been tested. Please report any problems at the project page on GitHub.")
endif()

#Only tested with versions 1.55 and 1.56
find_package(Boost 1.41.0 COMPONENTS system thread REQUIRED)
message("Boost include dir: ${Boost_INCLUDE_DIR}")
message("Boost libraries: ${Boost_LIBRARIES}")
include_directories(${Boost_INCLUDE_DIR})

#TODO: add requirement for version 1.0.1g (can it be done in one line?)
find_package(OpenSSL REQUIRED)
message("OpenSSL include dir: ${OPENSSL_INCLUDE_DIR}")
message("OpenSSL SSL libraries: ${OPENSSL_SSL_LIBRARIES}")
message("OpenSSL crypto libraries: ${OPENSSL_CRYPTO_LIBRARIES}")
include_directories(${OPENSSL_INCLUDE_DIR})

find_package(Threads REQUIRED)
message("Threads libraries/flag: ${CMAKE_THREAD_LIBS_INIT}")

add_executable(FacebookREST main.cpp)
target_link_libraries(FacebookREST ${Boost_LIBRARIES})
target_link_libraries(FacebookREST ${OPENSSL_SSL_LIBRARIES})
target_link_libraries(FacebookREST ${OPENSSL_CRYPTO_LIBRARIES})
target_link_libraries(FacebookREST ${CMAKE_THREAD_LIBS_INIT})
