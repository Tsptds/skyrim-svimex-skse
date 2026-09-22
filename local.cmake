# add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
#     COMMAND ${CMAKE_COMMAND} -E copy "bin\\$<CONFIG>\\${PROJECT_NAME}.dll" "<The Path to your mod folder>\\SKSE\\Plugins\\${PROJECT_NAME}.dll"
#     COMMAND ${CMAKE_COMMAND} -E copy "bin\\$<CONFIG>\\${PROJECT_NAME}.pdb" "<The Path to your mod folder>\\SKSE\\Plugins\\${PROJECT_NAME}.pdb"
# )

# add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
#     COMMAND "C:\\games\\Skyrim\\skse64_loader.exe" WORKING_DIRECTORY "C:\\games\\Skyrim"
# )