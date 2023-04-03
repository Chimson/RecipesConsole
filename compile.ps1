# Script to compile in Developer Powershell for VS
# enable most optimiazation, exception handler, many warnings, name the executable
# place the obj and exe files in bin 
CL /EHsc /std:c++20 /W4 /Fe".\bin\Recipes.exe" /Fo".\bin\" Recipes.cpp main.cpp 

# run in main directory, so that Recipe_Storage.txt is accessible
# > ./bin/Recipes