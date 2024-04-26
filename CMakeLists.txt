cmake_minimum_required(VERSION 3.10)
project(mipmap_sample)

add_definitions(-Dmipmap_sample_GFLAGS_NAMESPACE=${GFLAGS_NAMESPACE})
add_definitions(-D_CRT_SECURE_NO_WARNINGS)
add_definitions(-DGOOGLE_GLOG_DLL_DECL=)

set(platform "windows")
if (UNIX)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC -std=c++14")
    set(platform "ubuntu")
endif ()

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
find_package(MipMap REQUIRED)

include_directories(${MipMap_INCLUDE_DIR})

add_executable(mipmap_sample mipmap_sample.cc)
target_link_libraries(mipmap_sample PRIVATE ${MipMap_LIBRARIES})

