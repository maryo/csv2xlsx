cmake_minimum_required(VERSION 3.4)
project(csv2xlsx VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_STANDARD 99)

if(MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif()

if(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    if(TARGET_ARCH STREQUAL "arm64")
        set(CMAKE_OSX_ARCHITECTURES "arm64")
    endif()
endif()

find_package(Threads REQUIRED)
include(cmake/external_zlib.cmake)
include(cmake/external_libxlsxwriter.cmake)
include(cmake/external_argtable3.cmake)

enable_testing()

ADD_SUBDIRECTORY(libcsv)

ADD_LIBRARY(libcsv2xlsx src/libcsv2xlsx.c src/libcsv2xlsx.h)
add_dependencies(libcsv2xlsx libxlsxwriter argtable3)
TARGET_INCLUDE_DIRECTORIES(libcsv2xlsx PUBLIC libcsv ${LIBXLSXWRITER_INCLUDE_DIRS} ${ARGTABLE3_INCLUDE_DIRS} ${ZLIB_INCLUDE_DIRS})

if(NOT MSVC)
    list(APPEND EXTRA_LIBS m)
endif()

TARGET_LINK_LIBRARIES(libcsv2xlsx PRIVATE csv ${LIBXLSXWRITER_LIBRARY} ${ZLIB_LIBRARIES} ${ARGTABLE3_LIBRARY} ${EXTRA_LIBS})

ADD_EXECUTABLE(csv2xlsx src/csv2xlsx.c)
TARGET_LINK_LIBRARIES(csv2xlsx PUBLIC libcsv2xlsx ${ARGTABLE3_LIBRARY} ${ARGTABLE3_LIBRARY})
target_compile_definitions(csv2xlsx PRIVATE CSV2XLSX_VERSION=${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH})
install(TARGETS csv2xlsx RUNTIME DESTINATION bin)

ADD_TEST(NAME csv2xlsx COMMAND csv2xlsx ${CMAKE_CURRENT_SOURCE_DIR}/libcsv/test/test1.csv -o test1.xlsx)
ADD_TEST(NAME csv2xlsx_2 COMMAND csv2xlsx ${CMAKE_CURRENT_SOURCE_DIR}/src/genes.csv -o genes.xlsx)

install(FILES README.md LICENSE DESTINATION .)
SET(CPACK_GENERATOR "ZIP")
SET(CPACK_PACKAGE_VERSION_MAJOR ${PROJECT_VERSION_MAJOR})
SET(CPACK_PACKAGE_VERSION_MINOR ${PROJECT_VERSION_MINOR})
SET(CPACK_PACKAGE_VERSION_PATCH ${PROJECT_VERSION_PATCH})
SET(CPACK_INCLUDE_TOPLEVEL_DIRECTORY FALSE)
SET(CPACK_PACKAGE_CHECKSUM "SHA256")
INCLUDE(CPack)
