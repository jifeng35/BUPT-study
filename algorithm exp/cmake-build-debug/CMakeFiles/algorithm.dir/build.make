# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.19

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "E:\Program Files\CLion 2021.1.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "E:\Program Files\CLion 2021.1.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "E:\BUPT-study\algorithm exp"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "E:\BUPT-study\algorithm exp\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles\algorithm.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\algorithm.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\algorithm.dir\flags.make

CMakeFiles\algorithm.dir\Huffman_Coding.cpp.obj: CMakeFiles\algorithm.dir\flags.make
CMakeFiles\algorithm.dir\Huffman_Coding.cpp.obj: ..\Huffman_Coding.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\BUPT-study\algorithm exp\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/algorithm.dir/Huffman_Coding.cpp.obj"
	E:\proflie\VC\Tools\MSVC\14.28.29910\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\algorithm.dir\Huffman_Coding.cpp.obj /FdCMakeFiles\algorithm.dir\ /FS -c "E:\BUPT-study\algorithm exp\Huffman_Coding.cpp"
<<

CMakeFiles\algorithm.dir\Huffman_Coding.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/algorithm.dir/Huffman_Coding.cpp.i"
	E:\proflie\VC\Tools\MSVC\14.28.29910\bin\Hostx86\x86\cl.exe > CMakeFiles\algorithm.dir\Huffman_Coding.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "E:\BUPT-study\algorithm exp\Huffman_Coding.cpp"
<<

CMakeFiles\algorithm.dir\Huffman_Coding.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/algorithm.dir/Huffman_Coding.cpp.s"
	E:\proflie\VC\Tools\MSVC\14.28.29910\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\algorithm.dir\Huffman_Coding.cpp.s /c "E:\BUPT-study\algorithm exp\Huffman_Coding.cpp"
<<

# Object files for target algorithm
algorithm_OBJECTS = \
"CMakeFiles\algorithm.dir\Huffman_Coding.cpp.obj"

# External object files for target algorithm
algorithm_EXTERNAL_OBJECTS =

algorithm.exe: CMakeFiles\algorithm.dir\Huffman_Coding.cpp.obj
algorithm.exe: CMakeFiles\algorithm.dir\build.make
algorithm.exe: CMakeFiles\algorithm.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="E:\BUPT-study\algorithm exp\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable algorithm.exe"
	"E:\Program Files\CLion 2021.1.1\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\algorithm.dir --rc="D:\Windows Kits\10\bin\10.0.18362.0\x86\rc.exe" --mt="D:\Windows Kits\10\bin\10.0.18362.0\x86\mt.exe" --manifests -- E:\proflie\VC\Tools\MSVC\14.28.29910\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\algorithm.dir\objects1.rsp @<<
 /out:algorithm.exe /implib:algorithm.lib /pdb:"E:\BUPT-study\algorithm exp\cmake-build-debug\algorithm.pdb" /version:0.0 /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\algorithm.dir\build: algorithm.exe

.PHONY : CMakeFiles\algorithm.dir\build

CMakeFiles\algorithm.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\algorithm.dir\cmake_clean.cmake
.PHONY : CMakeFiles\algorithm.dir\clean

CMakeFiles\algorithm.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" "E:\BUPT-study\algorithm exp" "E:\BUPT-study\algorithm exp" "E:\BUPT-study\algorithm exp\cmake-build-debug" "E:\BUPT-study\algorithm exp\cmake-build-debug" "E:\BUPT-study\algorithm exp\cmake-build-debug\CMakeFiles\algorithm.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles\algorithm.dir\depend

