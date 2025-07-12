set(EXECUTABLE_NAME hello)

add_executable(${EXECUTABLE_NAME} hello.cc)

target_compile_features(${EXECUTABLE_NAME} PRIVATE cxx_std_17)
