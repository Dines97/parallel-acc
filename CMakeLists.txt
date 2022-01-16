cmake_minimum_required(VERSION 3.16.3)
project(parallel)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_COMPILER "/usr/bin/g++")

find_package(OpenACC REQUIRED)

file(GLOB FILE_NAMES *.cpp)
foreach (file_name ${FILE_NAMES})
	get_filename_component(executable_name ${file_name} NAME_WE)
	add_executable(${executable_name} ${file_name})

	target_compile_options(${executable_name} PRIVATE -O2 -ffast-math -fopenacc -fopt-info-all-omp -fcf-protection=none -foffload=nvptx-none)
endforeach (file_name ${FILE_NAMES})
