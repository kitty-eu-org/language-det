#project(language_det)
#cmake_minimum_required(VERSION 2.8)
cmake_minimum_required(VERSION 3.3)
project("language_det" VERSION ${PACKAGE_VERSION})

#project(main_test)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/CMakeLibs)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED on)
if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -fPIC -std=c++11") # set C++ 11
    #    set(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS}  -fPIC -std=c99 -Isrc ")
elseif(COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
    message( STATUS "The comipler ${CMAKE_CXX_COMIPLER} has no C++ 11 suport. Please use a different C++ comipler.")
endif()

#set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
set(CMAKE_CXX_STANDARD 14)
set(USING_CLANG true)
#set(INTERFACE_INCLUDE_DIRECTORIES )
SET( CompilerFlags -Wall)
if (DEFINED USING_CLANG)
    #compiler flags

    SET( CompilerFlags "${CompilerFlags} -stdlib=libstdc++" )
#    SET( CompilerFlags "${CompilerFlags} -Wno-unknown-pragmas" )
#    SET( CompilerFlags "${CompilerFlags} -Wall" )
#    SET( CompilerFlags "${CompilerFlags} -Wextra" )
    message("Compiler use  ${CMAKE_CXX_COMPILER}")
endif()
include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/
        ${CMAKE_CURRENT_SOURCE_DIR}/source
        ${CMAKE_CURRENT_SOURCE_DIR}/pybind11/include
#        /usr/local/anaconda3/envs/customer_service/include/python3.7m/
        /usr/local/lib
        /usr/local/include
)
set(LIB_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/Language.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Detector.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/profiles/Profile.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/profiles/ProfileGroup.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/detection/DetectionRunner.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/ngrams/NGramExtractor.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/profiles/langs/af.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/profiles/langs/ar.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/profiles/langs/bg.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/profiles/langs/bn.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/profiles/langs/ca.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/profiles/langs/cs.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/profiles/langs/cy.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/profiles/langs/da.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/profiles/langs/de.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/profiles/langs/el.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/profiles/langs/en.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/profiles/langs/es.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/profiles/langs/et.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/profiles/langs/fa.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/profiles/langs/fi.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/profiles/langs/fr.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/profiles/langs/gu.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/profiles/langs/he.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/profiles/langs/hi.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/profiles/langs/hr.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/profiles/langs/hu.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/profiles/langs/id.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/profiles/langs/it.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/profiles/langs/ja.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/profiles/langs/kn.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/profiles/langs/ko.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/profiles/langs/lt.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/profiles/langs/lv.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/profiles/langs/mk.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/profiles/langs/ml.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/profiles/langs/mr.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/profiles/langs/ne.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/profiles/langs/nl.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/profiles/langs/no.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/profiles/langs/pa.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/profiles/langs/pl.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/profiles/langs/pt.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/profiles/langs/ro.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/profiles/langs/ru.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/profiles/langs/sk.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/profiles/langs/sl.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/profiles/langs/so.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/profiles/langs/sq.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/profiles/langs/sv.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/profiles/langs/sw.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/profiles/langs/ta.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/profiles/langs/te.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/profiles/langs/th.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/profiles/langs/tl.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/profiles/langs/tr.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/profiles/langs/uk.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/profiles/langs/ur.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/profiles/langs/vi.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/profiles/langs/zh_cn.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/profiles/langs/zh_tw.cpp
        )

add_library(langdetectpp STATIC ${LIB_SOURCES})

target_link_libraries(langdetectpp PRIVATE ${COMMON_LINK_LIBS})


#add_executable(main_test main.cpp)
#add_dependencies(main_test langdetectpp)
#target_link_libraries(language_det PRIVATE ${COMMON_LINK_LIBS})
set(INTERFACE_INCLUDE_DIRECTORIES "/usr/local/anaconda3/envs/customer_service/include/python3.7m/")
add_subdirectory(pybind11)
#message("langdetectpp: ${langdetectpp}")
message(" ${LIB_SOURCES} ${COMMON_LINK_LIBS}")
pybind11_add_module(language_det main.cpp)

set_target_properties(language_det PROPERTIES RUNTIME_OUTPUT_DIRECTORY bin/)
set_target_properties(language_det PROPERTIES OUTPUT_NAME language_det)

target_link_libraries(language_det PRIVATE langdetectpp)

#install(TARGETS thrift_code DESTINATION bin)

target_compile_definitions(language_det  PRIVATE VERSION_INFO=${EXAMPLE_VERSION_INFO})