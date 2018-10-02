cmake_minimum_required(VERSION 2.6)
project(zztest-tests)

set(CMAKE_C_COMPILER "${COMPILER}gcc")
set(CMAKE_CXX_COMPILER "${COMPILER}g++")

add_subdirectory(ZZTest)

add_executable(zztest-tests
    main.c
)

target_link_libraries(zztest-tests
    zz-test
)

set_target_properties(zztest-tests
	PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY "${OUTPUT_DIR}"
)