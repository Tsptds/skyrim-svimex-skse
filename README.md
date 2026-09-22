# ***Template SKSE Project for Skyrim SE - CommonLibSSE-NG***

## ***Runtime requirements***

- [Skyrim Script Extender (SKSE)](https://skse.silverlock.org/)
- [Address Library for SKSE Plugins](https://www.nexusmods.com/skyrimspecialedition/mods/32444)

## ***Build requirements***

- [CMake](https://cmake.org/)
- [vcpkg](https://vcpkg.io/en/)
- [Visual Studio Community 2022](https://visualstudio.microsoft.com/vs/community/)
- [CommonLibSSE-NG](https://github.com/alandtse/CommonLibVR/tree/ng)

#### ***CommonLibSSE-NG***

CommonLibSSE-NG is used as a git-submodule by default. To use with overlay-ports, remove the submodule and edit vcpkg.json. Add "commonlibsse-ng" as a dependency and remove it's dependencies.

## ***Building***

Edit the CMakeLists.txt to configure plugin information (Project name, author etc.)

In `Developer Command Prompt for VS 2022` or `Developer PowerShell for VS 2022`, run:

~~~
git clone
~~~

then

~~~
git submodule init
git submodule update --remote
~~~

then

~~~
.\_Build.bat
~~~

or

~~~
.\cmake\build.ps1
~~~

or

~~~
cmake -B build -S . --preset release --fresh
cmake --build build --preset release
~~~

Then get the .dll in build/Release, or the .zip (ready to install using mod manager) in build.

## ***File local.cmake***

CMake will use a file named local.cmake (project root), in this file you can add something like:

~~~
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy "bin\\$<CONFIG>\\${PROJECT_NAME}.dll" "C:\\games\\Skyrim\\Data\\SKSE\\Plugins\\${PROJECT_NAME}.dll"
    COMMAND ${CMAKE_COMMAND} -E copy "bin\\$<CONFIG>\\${PROJECT_NAME}.pdb" "C:\\games\\Skyrim\\Data\\SKSE\\Plugins\\${PROJECT_NAME}.pdb"
)
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND "C:\\games\\Skyrim\\skse64_loader.exe" WORKING_DIRECTORY "C:\\games\\Skyrim"
)
~~~

## Credits
- Original template by epinter [SKSE ClibNG Template](https://github.com/epinter/skse-clibng-template)