add_library(fridge_lib cpu.cpp)

target_include_directories(fridge_lib PUBLIC ${CMAKE_SOURCE_DIR}/include)

target_compile_features(fridge_lib PUBLIC cxx_std_20)
