# CMakeList.txt: QuickCmd 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#

#cmake版本
cmake_minimum_required (VERSION 3.8)

#让cmake自动去寻找Qt5
FIND_PACKAGE(Qt5 COMPONENTS Widgets REQUIRED)
FIND_PACKAGE(glog REQUIRED)
FIND_PACKAGE(jsoncpp REQUIRED)

#采用C++11标准
set(CMAKE_CXX_STANDARD 17)

#添加所有的源文件
SET(QuickCmd_SOURCES 
	main.cpp
	QuickCmd.cpp
	QtCmdButton.cpp
	ConfigManager.cpp
)

#添加所有的头文件
SET(QuickCmd_HEADERS 
	CommonDefine.h
	QuickCmd.h
	QtCmdButton.h
	ConfigManager.h
)

#添加所有的.ui文件
SET(QuickCmd_FORMS 
	QuickCmd.ui
)

#添加资源文件
SET(QuickCmd_RESOURCES 
	QuickCmd.qrc
)
#调用预编译器moc，需要使用 QT5_WRAP_CPP宏
QT5_WRAP_CPP(QuickCmd_HEADERS_MOC ${QuickCmd_HEADERS})
#使用uic处理.ui文件
QT5_WRAP_UI(QuickCmd_FORMS_HEADERS ${QuickCmd_FORMS})
#使用rcc处理.qrc文件
QT5_ADD_RESOURCES(QuickCmd_RESOURCES_RCC ${QuickCmd_RESOURCES})

#这些生成的中间文件都会在build目录下，这样的话，编译器则不能定位由uic程序产生的诸如_ui_mainwindow.h等文件。所以，我们需要把build目录添加到包含目录中
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})

#生成可执行文件
ADD_EXECUTABLE(QuickCmd WIN32
	${QuickCmd_SOURCES} 
	${QuickCmd_HEADERS_MOC} 
    ${QuickCmd_FORMS_HEADERS}
	${QuickCmd_RESOURCES_RCC} 
)

#为target添加需要链接的共享库
TARGET_LINK_LIBRARIES(QuickCmd ${Qt5Widgets_LIBRARIES} jsoncpp_lib glog::glog)
