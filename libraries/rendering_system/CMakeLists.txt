add_library(rendering_system STATIC src/rendering_system.cpp)

target_include_directories(rendering_system PUBLIC inc)

target_include_directories(rendering_system PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/priv
)

target_link_libraries(rendering_system PUBLIC SDL2::SDL2 SDL2_image::SDL2_image)
