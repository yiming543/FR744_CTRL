# cmake files support debug production
include("${CMAKE_CURRENT_LIST_DIR}/rule.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/file.cmake")

set(FR744_CTRL_default_library_list )

# Handle files with suffix (s|as|asm|AS|ASM|As|aS|Asm), for group default-XC8
if(FR744_CTRL_default_default_XC8_FILE_TYPE_assemble)
add_library(FR744_CTRL_default_default_XC8_assemble OBJECT ${FR744_CTRL_default_default_XC8_FILE_TYPE_assemble})
    FR744_CTRL_default_default_XC8_assemble_rule(FR744_CTRL_default_default_XC8_assemble)
    list(APPEND FR744_CTRL_default_library_list "$<TARGET_OBJECTS:FR744_CTRL_default_default_XC8_assemble>")
endif()

# Handle files with suffix S, for group default-XC8
if(FR744_CTRL_default_default_XC8_FILE_TYPE_assemblePreprocess)
add_library(FR744_CTRL_default_default_XC8_assemblePreprocess OBJECT ${FR744_CTRL_default_default_XC8_FILE_TYPE_assemblePreprocess})
    FR744_CTRL_default_default_XC8_assemblePreprocess_rule(FR744_CTRL_default_default_XC8_assemblePreprocess)
    list(APPEND FR744_CTRL_default_library_list "$<TARGET_OBJECTS:FR744_CTRL_default_default_XC8_assemblePreprocess>")
endif()

# Handle files with suffix [cC], for group default-XC8
if(FR744_CTRL_default_default_XC8_FILE_TYPE_compile)
add_library(FR744_CTRL_default_default_XC8_compile OBJECT ${FR744_CTRL_default_default_XC8_FILE_TYPE_compile})
    FR744_CTRL_default_default_XC8_compile_rule(FR744_CTRL_default_default_XC8_compile)
    list(APPEND FR744_CTRL_default_library_list "$<TARGET_OBJECTS:FR744_CTRL_default_default_XC8_compile>")
endif()


add_executable(${FR744_CTRL_default_image_name} ${FR744_CTRL_default_library_list})
set_target_properties(${FR744_CTRL_default_image_name} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${FR744_CTRL_default_output_dir})

target_link_libraries(${FR744_CTRL_default_image_name} PRIVATE ${FR744_CTRL_default_default_XC8_FILE_TYPE_link})

# Add the link options from the rule file.
FR744_CTRL_default_link_rule(${FR744_CTRL_default_image_name})




