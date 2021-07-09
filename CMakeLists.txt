cmake_minimum_required(VERSION 3.10)

project ("ricerco-utils")

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

if (MSVC)
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
    if(MSVC_VERSION GREATER_EQUAL 1910 AND MSVC_VERSION LESS 1920)
        ## MSVC version 14.1
        set(BOOST_FS "${CMAKE_SOURCE_DIR}/vendor/boost/libs/win/libboost_filesystem-vc141-mt-s-x64-1_76.lib")
    elseif(MSVC_VERSION GREATER_EQUAL 1920)
        ## MSVC version 14.2
        set(BOOST_FS "${CMAKE_SOURCE_DIR}/vendor/boost/libs/win/libboost_filesystem-vc142-mt-s-x64-1_76.lib")
    else()
        ## Not boost lib support for < 14.1 and > 14.2
        message(STATUS "MSVC VERSION IS ${MSVC_VERSION}" )
        message(FATAL_ERROR "Ensure that you are using MSVC version EQUAL 1.41 or 1.42 ONLY." )
    endif()

    target_link_libraries("ricerco-utils" 
        ${CMAKE_JS_LIB} 
        ${BOOST_FS} 
        "Shlwapi.lib")
endif (MSVC)

## Copies the default directory to the lib folder
add_custom_command(
    TARGET "ricerco-utils"
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    "${CMAKE_SOURCE_DIR}/default/"
    "${CMAKE_BINARY_DIR}/Release/default/")
