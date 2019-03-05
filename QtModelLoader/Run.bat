cd C:\Users\tyler\Group20ProjectWork\QtModelLoader\Build
set PATH=%PATH%;C:\Qt\5.11.1\msvc2017_64\bin;C:\VTK\MSVC2017\bin
"C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvarsall.bat" amd64
msbuild ModelLoader.sln
cd Debug
START ModelLoader.exe