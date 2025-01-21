project(lib)

set(HEADER_FILE traffic_light.h)
set(SOURCE_FILE traffic_light.cpp)

add_library(traffic_light_lib ${SOURCE_FILE} ${HEADER_FILE})