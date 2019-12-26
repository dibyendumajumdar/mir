cmake_minimum_required(VERSION 2.8)
project(mir)

enable_language(C)

message(STATUS "OS type is ${CMAKE_SYSTEM_NAME}")
message(STATUS "System processor is ${CMAKE_HOST_SYSTEM_PROCESSOR}")
message(STATUS "Build type is ${CMAKE_BUILD_TYPE}")

set(TARGET x86_64)

set(MIR_HEADERS 
    mir.h
    mir-gen.h
    mir-varr.h
    mir-dlist.h 
    mir-htab.h 
    mir-hash.h
    mir-bitmap.h
    )

set(MIR_SRCS 
    mir.c
    mir-gen.c
    )

set(C2MIR_SRCS
    c2mir/c2mir.c
    c2mir/c2mir-driver.c
    )

set(LIBS dl)

add_definitions(-D${TARGET})
add_definitions(-DMIR_IO)
add_definitions(-DMIR_SCAN)
# add_definitions(-DMIR_GEN_DEBUG)

include_directories("${CMAKE_SOURCE_DIR}")
include_directories("${CMAKE_SOURCE_DIR}/c2mir")

add_library(c2mir
    ${MIR_HEADERS}
    ${MIR_SRCS}
    ${C2MIR_SRCS})
#target_compile_definitions(c2mir PRIVATE RAVI=1 C2MIR_NO_DRIVER=1)
target_link_libraries(c2mir ${LIBS})

add_executable(c2mirexe
    ${MIR_HEADERS}
    ${MIR_SRCS}
    ${C2MIR_SRCS})
target_link_libraries(c2mirexe ${LIBS})

install(FILES c2mir/c2mir.h ${MIR_HEADERS}
        DESTINATION include/mir)
install(TARGETS c2mir
        RUNTIME DESTINATION bin
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib)
