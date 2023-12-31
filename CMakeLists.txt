PROJECT(easy_example)
cmake_minimum_required(VERSION 2.8)
##  by woods 2023-11-21


message("================ EasyLab Example  by woods 2023-11-21  =============")


SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build)
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_CURRENT_SOURCE_DIR}/build)
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_CURRENT_SOURCE_DIR}/build)

SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/lib)
SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY})
SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY})



SET(PROTO_CPP_GENERATED_PACK ${CMAKE_CURRENT_SOURCE_DIR}/proto/gen_cpp_headers)
SET(PROTO_PYTHON_GENERATED_PACK ${CMAKE_CURRENT_SOURCE_DIR}/proto/gen_python_headers)
SET(PROTOBUF_FILE ${CMAKE_CURRENT_SOURCE_DIR}/proto/protobuf)



file(MAKE_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
file(MAKE_DIRECTORY ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY})

file(REMOVE_RECURSE ${PROTO_CPP_GENERATED_PACK})
file(REMOVE_RECURSE ${PROTO_PYTHON_GENERATED_PACK})
file(MAKE_DIRECTORY ${PROTO_CPP_GENERATED_PACK})
file(MAKE_DIRECTORY ${PROTO_PYTHON_GENERATED_PACK})


##  ==============================add  grpc dic into the package======================================
#installation/directory  在 build grpc.sh 中定义
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/thirdParty/grpc_source/grpc/installation/directory/include)# 包含 gRPC 头文件路径
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/thirdParty/grpc_source/grpc/installation/directory/lib) # 链接 gRPC 库文件
##  ==============================add  grpc dic into the package======================================




#使用自定义的prto 文件 生成 C++ header 代码

execute_process(
    COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/thirdParty/grpc_source/grpc/installation/directory/bin/protoc
        -I ${PROTOBUF_FILE}
        --cpp_out=. 
        --grpc_out=. 
        --plugin=protoc-gen-grpc=${CMAKE_CURRENT_SOURCE_DIR}/thirdParty/grpc_source/grpc/installation/directory/bin/grpc_cpp_plugin 
        ${PROTOBUF_FILE}/example.proto 
    WORKING_DIRECTORY ${PROTO_CPP_GENERATED_PACK}
)


execute_process(
    COMMAND python -m ${CMAKE_CURRENT_SOURCE_DIR}/thirdParty/grpc_source/grpc/tools/distrib/python/grpcio_tools/grpc_tools/protoc
        -I ${PROTOBUF_FILE}
        --python_out=. 
        --grpc_python_out=. 
        ${PROTOBUF_FILE}/example.proto
    WORKING_DIRECTORY ${PROTO_PYTHON_GENERATED_PACK}
)



include_directories(${PROTO_CPP_GENERATED_PACK})# 包含 生成文件的路径
link_directories(${PROTO_CPP_GENERATED_PACK})



##  ==============================A common method to add source and include======================================
ADD_LIBRARY(easy_example  ${CMAKE_CURRENT_SOURCE_DIR}/src/easy_example.cpp)

target_include_directories(easy_example PUBLIC
${CMAKE_CURRENT_SOURCE_DIR}/include
)
# target_include_directories(easy_example PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include) 
#when PRIVATE , the main.cpp cant find the easy_example.h, cause  the include is the private include of easy_example.


# TARGET_LINK_LIBRARIES(easy_example  gRPC::grpc++)
TARGET_LINK_LIBRARIES(easy_example  grpc++)

ADD_EXECUTABLE(example_exe ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)
TARGET_LINK_LIBRARIES(example_exe easy_example)
##  ==============================A common method to add source and include======================================



IF (WIN32 AND "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
	TARGET_LINK_LIBRARIES(example_exe stdc++)
ENDIF()

