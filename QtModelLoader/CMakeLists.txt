cmake_minimum_required(VERSION 3.3 FATAL_ERROR)

foreach(p
    CMP0071 # 3.10: Let AUTOMOC and AUTOUIC process GENERATED files
    )
  if(POLICY ${p})
    cmake_policy(SET ${p} NEW)
  endif()
endforeach()

PROJECT( ModelLoader )

# The CMake build process might generate some new files in the current
# directory. This makes sure they can be found.
set( CMAKE_INCLUDE_CURRENT_DIR ON )


# This allows CMake to run one of Qt's build tools called moc
# if it is needed. moc.exe can be found in Qt's bin directory.
# We'll look at what moc does later.
set( CMAKE_AUTOMOC ON )
set( CMAKE_AUTOUIC ON )

# Find the Qt widgets package. This locates the relevant include and
# lib directories, and the necessary static libraries for linking.
find_package( Qt5Widgets )

set( UIS mainwindow.ui )
qt5_wrap_ui( UI_Srcs ${UIS} )

set( ICONS Icons/icons.qrc )
qt5_add_resources( QRC_Srcs ${ICONS} )


# Also link to VTK
find_package( VTK REQUIRED )
include( ${VTK_USE_FILE} )

add_subdirectory(LibraryCode)
include_directories(LibraryCode)

# Define the executable output and its sources
add_executable( ModelLoader MACOSX_BUNDLE
				main.cpp mainwindow.cpp 
				mainwindow.h 
				mainwindow.ui
				${UI_Srcs}
				${QRC_Srcs}
				)

# Tell CMake that the executable depends on the Qt::Widget libraries.
target_link_libraries( ModelLoader Qt5::Widgets )

# Tell CMake that the executable depends on the VTK libraries
target_link_libraries( ModelLoader ${VTK_LIBRARIES} )

target_link_libraries( ModelLoader ModelLib )

install(TARGETS ModelLoader ModelLib
RUNTIME DESTINATION bin
LIBRARY DESTINATION lib
ARCHIVE DESTINATION lib/static)

set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR})

if(WIN32)
	set(CPACK_GENERATOR "NSIS")
else()
	set(CPACK_GENERATOR "ZIP")
endif()
include(CPack)

set(CMAKE_INSTALL_UCRT_LIBRARIES ON)

#NSIS installer configuration
set(CPACK_NSIS_CONTACT "Contact - Group 20 (Arron, TJ, Warrit, Anastasia)")
set(CPACK_NSIS_PACKAGE_NAME "Model_Loader")
set(CPACK_NSIS_DISPLAY_NAME "Group 20 Model Loader")

install(DIRECTORY dll/ DESTINATION bin)