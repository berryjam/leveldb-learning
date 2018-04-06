#项目名称
project(leveldb_usage)
#代码路径
aux_source_directory(. DIR_TOOT_SRCS)
#dubug 模式
set (CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -g")
#生成可执行的文件
add_executable(leveldb_usage ${DIR_TOOT_SRCS})

include_directories(/Users/berryjam/Documents/go_workspace/src/github.com/google/leveldb/include)

find_library(LEVELDB libleveldb.a /Users/berryjam/Documents/go_workspace/src/github.com/google/leveldb/build/)

TARGET_LINK_LIBRARIES(leveldb_usage ${LEVELDB})