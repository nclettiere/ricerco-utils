cmake_minimum_required(VERSION 3.10)

project ("ricerco-utils")

## Downloads the neccessary boost libs before building
set(BOOST_URL "https://drive.google.com/uc?export=download&id=1aDLqk2E9p73HpM7v0NKJiuzUaRmfddqn")
set(BOOST_DOWNLOAD_PATH "${CMAKE_SOURCE_DIR}/vendor/boost_lib.zip")
if (NOT EXISTS "${BOOST_DOWNLOAD_PATH}")
    file(DOWNLOAD "${BOOST_URL}" "${BOOST_DOWNLOAD_PATH}")
endif()

add_definitions(-DNAPI_VERSION=3)

execute_process(COMMAND node -p "require('node-addon-api').include"
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        OUTPUT_VARIABLE NODE_ADDON_API_DIR)
string(REPLACE "\n" "" NODE_ADDON_API_DIR ${NODE_ADDON_API_DIR})
string(REPLACE "\"" "" NODE_ADDON_API_DIR ${NODE_ADDON_API_DIR})

set(PROJ_INCL "${CMAKE_SOURCE_DIR}/include/")
set(BOOST_INCL "${CMAKE_SOURCE_DIR}/vendor/boost/")
set(CEREAL_INCL "${CMAKE_SOURCE_DIR}/vendor/cereal/")
set(NLOHMANN_INCL "${CMAKE_SOURCE_DIR}/vendor/nlohmann/")

include_directories(
    ${CMAKE_JS_INC} 
    ${NODE_ADDON_API_DIR} 
    ${PROJ_INCL}
    ${BOOST_INCL} 
    ${CEREAL_INCL} 
    ${NLOHMANN_INCL})

file(GLOB_RECURSE SOURCE_FILES "src/*.cc")

add_library("ricerco-utils" SHARED ${SOURCE_FILES} ${CMAKE_JS_SRC})
set_target_properties("ricerco-utils" PROPERTIES PREFIX "" SUFFIX ".node")

message(STATUS "*************************************************************")
message(STATUS "*   THE SELECTED RUNTIME TO BUILD IS: ${NODE_RUNTIME}")
message(STATUS "*   THE SELECTED RUNTIME VERSION IS: ${NODE_RUNTIMEVERSION}")
message(STATUS "*   THE SELECTED ARCHITECTURE IS: ${NODE_ARCH}")
message(STATUS "*************************************************************")
message(STATUS "*************************************************************")

if (WIN32)
    if (MSVC)
        set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
        if(MSVC_VERSION GREATER_EQUAL 1910 AND MSVC_VERSION LESS 1920)
            ## MSVC version 14.1
            set(BOOST_FS "${CMAKE_SOURCE_DIR}/vendor/boost/libs/win/libboost_filesystem-vc141-mt-s-x64-1_76.lib")
        elseif(MSVC_VERSION GREATER_EQUAL 1920)
            ## MSVC version 14.2
            set(BOOST_FS "${CMAKE_SOURCE_DIR}/vendor/boost/libs/win/libboost_filesystem-vc142-mt-s-x64-1_76.lib")
        else()
            ## No boost lib support for < 14.1 and > 14.2 (for now)
            message(FATAL_ERROR "Ensure that you are using MSVC version EQUAL 1.41 or 1.42 ONLY." )
        endif()

        target_link_libraries("ricerco-utils" 
            ${CMAKE_JS_LIB} 
            ${BOOST_FS} 
            "Shlwapi.lib")
    else()
        message(FATAL_ERROR "This project is meant to be build using MSVC only." )
    endif (MSVC)
endif(WIN32)

## Copies the default directory to the lib folder
add_custom_command(
    TARGET "ricerco-utils"
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    "${CMAKE_SOURCE_DIR}/default/"
    "${CMAKE_BINARY_DIR}/Release/default/")

# Extract Boost libraries before building
if (WIN32)
    add_custom_command(
        TARGET "ricerco-utils"
        PRE_BUILD
        WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/vendor/"
        COMMAND powershell -ExecutionPolicy Bypass -File "../tools/boost/download.ps1"
        DEPENDS "${BOOST_DOWNLOAD_PATH}")
endif (WIN32)