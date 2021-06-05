cmake_minimum_required(VERSION 3.17)
project(cpp_data_structures)

set(CMAKE_CXX_STANDARD 14)


add_executable(cpp_data_structures main.cpp Collections/Queue.h Collections/Stack.h Blob.h Log/Log.h Log/Log.cpp Blob.cpp Common/CommonTypes.h Common/CollectionsCommon.h Collections/LinkedList.h Collections/Iterators/LinkedListIterator.h Collections/HashSet.h Collections/Iterators/HashSetIterator.h Util/Sort.cpp Util/Sort.h Util/StringUtils.h)
target_include_directories(cpp_data_structures
        PUBLIC Common Log Util Collections Collections/Iterators)