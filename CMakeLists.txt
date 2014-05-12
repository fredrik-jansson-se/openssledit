project("OpenSSL Config Editor")

cmake_minimum_required(VERSION 2.8)

find_package(Boost REQUIRED
    log
    program_options
    system
    thread
    )

include_directories( ${Boost_INCLUDE_DIR} )

find_package(OpenSSL REQUIRED)

include_directories( ${OPENSSL_INCLUDE_DIR})

set(SOURCE
    ca.cpp
    cfgedit.cpp
    confhelper.cpp
    menu.cpp
    options.cpp
    settings.cpp
    x509_extensions.cpp
    )

file(GLOB_RECURSE INCS "*.h")

add_definitions(
    -pthread
    -Wall
    -Werror
    -Wno-deprecated-register
    -std=c++11
    )

if(APPLE)
    SET( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++" )
    SET( CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -stdlib=libc++" )
    SET( CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -stdlib=libc++" )
    SET( CMAKE_MODULE_LINKER_FLAGS "${CMAKE_MODULE_LINKER_FLAGS} -stdlib=libc++" )
endif()

add_executable(cfgedit ${SOURCE} ${INCS}) 
target_link_libraries(cfgedit ${Boost_LIBRARIES} ${OPENSSL_LIBRARIES})
