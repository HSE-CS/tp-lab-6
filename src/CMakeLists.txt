set(header_path "${${PROJECT_NAME}_SOURCE_DIR}/include")
set(header ${header_path}/Interfaces.h ${header_path}/Employee.h ${header_path}/Manager.h ${header_path}/Personal.h ${header_path}/Engineer.h ${header_path}/Factory.h ${header_path}/Project.h)
set(src Employee.cpp Personal.cpp Engineer.cpp Manager.cpp Factory.cpp Project.cpp)


add_library(${PROJECT_NAME} SHARED
  ${header}
  ${src})
target_include_directories(${PROJECT_NAME}
  PUBLIC ${CMAKE_CURRENT_BINARY_DIR}
         ${${PROJECT_NAME}_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME}
  pthread)

  
add_executable(${PROJECT_NAME}.info main.cpp)
target_include_directories(${PROJECT_NAME}.info
  PUBLIC ${CMAKE_CURRENT_BINARY_DIR}
         ${${PROJECT_NAME}_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME}.info
  ${PROJECT_NAME})


install(TARGETS ${PROJECT_NAME}
		LIBRARY DESTINATION "${lib_dest}"
    ARCHIVE DESTINATION "${lib_dest}"
    COMPONENT library)
install(TARGETS ${PROJECT_NAME}.info
		RUNTIME DESTINATION "${tool_dest}"
    COMPONENT library)
install(FILES ${header} DESTINATION "${include_dest}")
