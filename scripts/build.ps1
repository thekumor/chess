mkdir build

#Directories
Copy-Item src/ -Destination build/ -Recurse
Copy-Item vendor/ -Destination build/ -Recurse

# Files
Copy-Item vendor/SDL-3.2.18/lib-win32-x64/SDL3.dll -Destination build/

cd build
cmake ..