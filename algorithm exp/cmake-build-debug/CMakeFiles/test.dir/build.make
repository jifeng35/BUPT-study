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
include CMakeFiles\test.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\test.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\test.dir\flags.make

CMakeFiles\test.dir\test.cpp.obj: CMakeFiles\test.dir\flags.make
CMakeFiles\test.dir\test.cpp.obj: ..\test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\BUPT-study\algorithm exp\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test.dir/test.cpp.obj"
	E:\proflie\VC\Tools\MSVC\14.28.29910\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\test.dir\test.cpp.obj /FdCMakeFiles\test.dir\ /FS -c "E:\BUPT-study\algorithm exp\test.cpp"
<<

CMakeFiles\test.dir\test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test.dir/test.cpp.i"
	E:\proflie\VC\Tools\MSVC\14.28.29910\bin\Hostx86\x86\cl.exe > CMakeFiles\test.dir\test.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "E:\BUPT-study\algorithm exp\test.cpp"
<<

CMakeFiles\test.dir\test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test.dir/test.cpp.s"
	E:\proflie\VC\Tools\MSVC\14.28.29910\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\test.dir\test.cpp.s /c "E:\BUPT-study\algorithm exp\test.cpp"
<<

# Object files for target test
test_OBJECTS = \
"CMakeFiles\test.dir\test.cpp.obj"

# External object files for target test
test_EXTERNAL_OBJECTS =

test.exe: CMakeFiles\test.dir\test.cpp.obj
test.exe: CMakeFiles\test.dir\build.make
test.exe: CMakeFiles\test.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="E:\BUPT-study\algorithm exp\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test.exe"
	"E:\Program Files\CLion 2021.1.1\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\test.dir --rc="D:\Windows Kits\10\bin\10.0.18362.0\x86\rc.exe" --mt="D:\Windows Kits\10\bin\10.0.18362.0\x86\mt.exe" --manifests -- E:\proflie\VC\Tools\MSVC\14.28.29910\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\test.dir\objects1.rsp @<<
 /out:test.exe /implib:test.lib /pdb:"E:\BUPT-study\algorithm exp\cmake-build-debug\test.pdb" /version:0.0 /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\test.dir\build: test.exe

.PHONY : CMakeFiles\test.dir\build

CMakeFiles\test.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\test.dir\cmake_clean.cmake
.PHONY : CMakeFiles\test.dir\clean

CMakeFiles\test.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" "E:\BUPT-study\algorithm exp" "E:\BUPT-study\algorithm exp" "E:\BUPT-study\algorithm exp\cmake-build-debug" "E:\BUPT-study\algorithm exp\cmake-build-debug" "E:\BUPT-study\algorithm exp\cmake-build-debug\CMakeFiles\test.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles\test.dir\depend

