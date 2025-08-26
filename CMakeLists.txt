cmake_minimum_required(VERSION 3.16)

project(SDT_2_Fabric LANGUAGES CXX)

# C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# На будущее: автогенерация moc (если позже появятся QObject-классы)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC OFF)
set(CMAKE_AUTOUIC OFF)

# Qt6 -> Qt5 fallback
set(QT_REQUIRED_COMPONENTS Core)
find_package(Qt6 QUIET COMPONENTS ${QT_REQUIRED_COMPONENTS})
if(NOT Qt6_FOUND)
    find_package(Qt5 REQUIRED COMPONENTS ${QT_REQUIRED_COMPONENTS})
    set(QT_VER 5)
else()
    set(QT_VER 6)
endif()

# ----- Источники -----
set(SRC
    main.cpp

    core/unit.cpp

    factories/factory_cpp.cpp
    factories/factory_cs.cpp
    factories/factory_java.cpp

    cpp/class_cpp.cpp
    cpp/method_cpp.cpp
    cpp/print_cpp.cpp

    cs/class_cs.cpp
    cs/method_cs.cpp
    cs/print_cs.cpp

    java/class_java.cpp
    java/method_java.cpp
    java/print_java.cpp
)

add_executable(${PROJECT_NAME} ${SRC}
    core/unit.cpp core/unit.h cpp/class_cpp.cpp cpp/class_cpp.h cpp/method_cpp.cpp cpp/method_cpp.h cpp/modifiers_cpp.h cpp/print_cpp.cpp cpp/print_cpp.h cs/class_cs.cpp cs/class_cs.h cs/method_cs.cpp cs/method_cs.h cs/modifiers_cs.h cs/print_cs.cpp cs/print_cs.h factories/factory.h factories/factory_cpp.cpp factories/factory_cpp.h factories/factory_cs.cpp factories/factory_cs.h factories/factory_java.cpp factories/factory_java.h java/class_java.cpp java/class_java.h java/method_java.cpp java/method_java.h java/modifiers_java.h java/print_java.cpp java/print_java.h)

# Инклуды для коротких include-путей
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/core
    ${CMAKE_CURRENT_SOURCE_DIR}/factories
    ${CMAKE_CURRENT_SOURCE_DIR}/cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/cs
    ${CMAKE_CURRENT_SOURCE_DIR}/java
)

# Линкуем Qt::Core
if(QT_VER EQUAL 6)
    target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Core)
else()
    target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Core)
endif()

# Консольное приложение на Windows (чтобы было окно консоли)
if(WIN32)
    set_target_properties(${PROJECT_NAME} PROPERTIES WIN32_EXECUTABLE OFF)
endif()

# Предупреждения
if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic)
endif()
