cmake_minimum_required(VERSION 3.20)
cmake_policy(SET CMP0037 NEW)
PROJECT(OCVWarp)

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake_modules/")

# copy-pasting from https://github.com/hn-88/pan2fulldome/blob/main/CMakeLists.txt
# to build only OCVWarp, nothing else.
find_package(OpenCV REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(FFMPEG REQUIRED libavcodec libavformat libavutil)

include_directories(${FFMPEG_INCLUDE_DIRS})
link_directories(${FFMPEG_LIBRARY_DIRS})
add_definitions(${FFMPEG_CFLAGS_OTHER})

add_executable(OCVWarp OCVWarp.cpp)
target_link_libraries(OCVWarp ${FFMPEG_LIBRARIES})

# #include_directories(~/OpenCVLocal/include/opencv4)
# include_directories(${OpenCV_INCLUDE_DIRS})
# add_executable(OCVWarp OCVWarp.cpp)
# target_link_libraries(OCVWarp ${OpenCV_LIBS})
