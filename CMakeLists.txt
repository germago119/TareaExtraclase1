cmake_minimum_required(VERSION 3.9)
project(TareaExtraclase1)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_PREFIX_PATH "/Applications/Qt/5.10.1/clang_64")

set( CMAKE_INCLUDE_CURRENT_DIR ON )

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Network REQUIRED)
find_package(Qt5Xml REQUIRED)
find_package(Qt5PrintSupport REQUIRED)
find_package(Qt5OpenGL REQUIRED)
find_package(Qt5Sql REQUIRED)


add_executable(TareaExtraclase1 main.cpp BinarySearchTree.hpp CircularList.hpp DoubleLinkedList.hpp doubleLinkedView.hpp doubleLinkedView.cpp simpleLinkedView.hpp simpleLinkedView.cpp mainwindow.cpp mainwindow.hpp DoubleNode.hpp CircularNode.hpp SimpleNode.hpp SimpleLinkedList.hpp circularView.cpp circularView.hpp TreeNode.hpp treeView.cpp treeView.hpp)

qt5_wrap_ui( UI_HEADERS mainwindow.ui circularView.ui doubleLinkedView.ui simpleLinkedView.ui treeView.ui)
#qt5_wrap_ui(UI_GENERATED_HEADERS ${UI_SOURCES})

#qt5_add_resources( QRCS photos.qrc )

set(SOURCE_FILES main.cpp)

target_link_libraries(TareaExtraclase1 Qt5::Widgets Qt5::Core Qt5::Network Qt5::Sql Qt5::OpenGL)

