cmake_minimum_required (VERSION 2.6 FATAL_ERROR)
project (tinylog)

OPTION (BUILD_SHARED_LIBS "Build Shared Libraries" ON)

cmake_policy(SET CMP0015 NEW)

if (MINGW) #for boost libraries & visual leak detector
	link_directories("C:/MinGW/lib")
else()
	link_directories("$ENV{BOOST_ROOT}/stage/lib")
endif()
 
file(GLOB CPP_SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")

add_library(tinylog SHARED ${CPP_SOURCES})
							   
target_include_directories(tinylog   PRIVATE "${PROJECT_SOURCE_DIR}/include"
									PRIVATE "${CMAKE_SOURCE_DIR}/include" 
)					
if (MINGW) #for boost libraries
target_include_directories(tinylog  PRIVATE "C:/MinGW/include")
else()
target_include_directories(tinylog  PRIVATE "$ENV{BOOST_ROOT}")
endif()								   

if (MINGW)
target_link_libraries(tinylog PRIVATE   "boost_system"
									    "boost_thread"	
										"boost_date_time"
											 )	
else()	
#target_link_libraries(tinylog PRIVATE "odbc32.lib")
endif()