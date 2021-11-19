

cmake_minimum_required (VERSION 2.6)

project (Main)

#set (CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/out)
set (CMAKE_INSTALL_PREFIX out)

option (USE_COMLIB "use comlib provied implementation" ON)
#option (USE_COMLIB "use comlib provied implementation" OFF)


# lib
if (USE_COMLIB) 
	add_subdirectory (comlib)
endif (USE_COMLIB)

# main
set (Main_VERSION_MAJOR 1)
set (Main_VERSION_MINOR 0)

configure_file(
		"${PROJECT_SOURCE_DIR}/config/MainConfig.h.in"
		"${PROJECT_BINARY_DIR}/config/MainConfig.h"
)

include_directories(
		"${PROJECT_BINARY_DIR}/config"
)

if (USE_COMLIB)
	include_directories(
		"${PROJECT_SOURCE_DIR}/comlib"
	)
	set (COMLIB ${COMLIB} comlib)
endif (USE_COMLIB)



add_executable(main main.cxx)
target_link_libraries (main ${COMLIB})

install (TARGETS main DESTINATION bin)
install (FILES "${PROJECT_BINARY_DIR}/config/MainConfig.h" DESTINATION include)


include (CTest)

macro (do_test arg result)
	add_test(MainComp${arg} main ${arg})
	set_tests_properties (MainComp${arg} PROPERTIES PASS_REGULAR_EXPRESSION ${result})
endmacro (do_test)

add_test(MainRuns main 25)

#add_test(MainComp25 main 25)
#set_tests_properties (MainComp25 PROPERTIES PASS_REGULAR_EXPRESSION "25 is 5")
do_test(25 "25 is 5")
do_test(-25 "-25 is 0")


message (STATUS "Build documentation open")
include (cmake/build_doxygen.cmake)
build_doxygen()


