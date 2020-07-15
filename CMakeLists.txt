cmake_minimum_required(VERSION 2.8)
cmake_policy(SET CMP0048 NEW)
cmake_policy(SET CMP0054 NEW)
cmake_policy(SET CMP0012 NEW)
cmake_policy(SET CMP0023 NEW)

set(PROJECT ImGuiFileDialog)

enable_language(C CXX)
project(${PROJECT} CXX)

include(cmake/3rdparty.cmake)

if(UNIX)
    if(APPLE)
        add_definitions(-DAPPLE)
    else()
        add_definitions(-DLINUX)
    endif()
    add_definitions(-DUNIX)
elseif(WIN32)
    add_definitions(-DWIN32)
	if(MINGW)
		add_definitions(-DMINGW32)
	endif()
    set(DIRENT_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/dirent/include)
    include_directories(${DIRENT_INCLUDE_DIR})
endif()

if(MSVC)
    # Ignore 4055 for glad
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4 /IGNORE:4055")
    add_definitions(-D_USE_MATH_DEFINES)
    add_definitions(-DMSVC)
else ()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -std=c++11")
endif ()

add_definitions(-DCUSTOM_IMGUIFILEDIALOG_CONFIG="../../../CustomImGuiFileDialogConfig.h")
   
file(GLOB CUSTOM_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/CustomImGuiFileDialogConfig.h)
file(GLOB RES_SOURCES 
		${CMAKE_CURRENT_SOURCE_DIR}/CustomFont.cpp 
		${CMAKE_CURRENT_SOURCE_DIR}/CustomFont.h)
file(GLOB IMGUIFILEDIALOG_SOURCES 
		${CMAKE_CURRENT_SOURCE_DIR}/ImGuiFileDialog/*.cpp
		${CMAKE_CURRENT_SOURCE_DIR}/ImGuiFileDialog/*.h)
source_group(src\\Custom FILES ${CUSTOM_SOURCES})
source_group(src\\Res FILES ${RES_SOURCES})
source_group(src\\ImGuiFileDialog FILES ${IMGUIFILEDIALOG_SOURCES})

if (APPLE)
	##set(ICON icon.icns)
	##set_source_files_properties(icon.icns PROPERTIES MACOSX_PACKAGE_LOCATION "Resources")
endif()

if (0)
	add_executable(${PROJECT}
			MACOSX_BUNDLE
			##${ICON}
			${MAIN_SOURCES}
			${CUSTOM_SOURCES}
			${RES_SOURCES}
			${IMGUIFILEDIALOG_SOURCES}
			${IMGUIIMPL_SOURCES}
	)
else()
	add_library(${PROJECT}
			STATIC
			##${ICON}
			${CUSTOM_SOURCES}
			${RES_SOURCES}
			${IMGUIFILEDIALOG_SOURCES}
	)
endif()
if (APPLE)
	set_target_properties(${PROJECT}
			PROPERTIES
			OUTPUT_NAME "ImGuiFileDialog"
			MACOSX_BUNDLE_EXECUTABLE_NAME "ImGuiFileDialog"
			MACOSX_BUNDLE_BUNDLE_NAME "ImGuiFileDialog"
			FOLDER "ImGuiFileDialog"
			##RESOURCE icon.icns
			MACOSX_BUNDLE_SHORT_VERSION_STRING ""
			MACOSX_BUNDLE_LONG_VERSION_STRING ""
			##MACOSX_BUNDLE_ICON_FILE icon.icns
			MACOSX_BUNDLE_INFO_PLIST "${CMAKE_CURRENT_SOURCE_DIR}/MacOSXBundleInfo.plist.in")
elseif(WIN32)
	set_target_properties(${PROJECT} PROPERTIES OUTPUT_NAME "ImGuiFileDialog")
elseif(UNIX)
	set_target_properties(${PROJECT} PROPERTIES OUTPUT_NAME "ImGuiFileDialog")
endif()
set_target_properties(${PROJECT} PROPERTIES CXX_STANDARD 11)

set(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_SOURCE_DIR}")
install(TARGETS ${PROJECT} DESTINATION ${CMAKE_INSTALL_PREFIX})

target_include_directories(${PROJECT_NAME} PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}
		${CMAKE_CURRENT_SOURCE_DIR}/ImGuiFileDialog
)

target_link_libraries(${PROJECT} PRIVATE
       imgui::imgui 
)
