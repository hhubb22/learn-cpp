# 定义可执行文件列表
set(EXECUTABLES
    hello
    smart-ptr
    lambda
)

set(SOURCES
    hello.cc
    smart_pointer.cc
    lambda.cc
)

# 批量创建可执行文件
list(LENGTH EXECUTABLES exec_count)
math(EXPR exec_count "${exec_count} - 1")

foreach(i RANGE ${exec_count})
    list(GET EXECUTABLES ${i} exec_name)
    list(GET SOURCES ${i} source_file)
    
    add_executable(${exec_name} ${source_file})
    
    # C++ 标准已在根 CMakeLists.txt 中设置，这里不需要重复
    # 但如果某个目标需要特殊的 C++ 标准，可以单独设置
    # target_compile_features(${exec_name} PRIVATE cxx_std_17)
endforeach()
