set(target ComplexTest)

file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../gtest")

add_executable(${target} ${srcs} ${hdrs})
target_link_libraries(${target} gtest ${errorlib})
target_link_libraries(${target} gtest ${stringlib})
target_link_libraries(${target} gtest ${vectorlib})
target_link_libraries(${target} gtest ${matrixlib})
