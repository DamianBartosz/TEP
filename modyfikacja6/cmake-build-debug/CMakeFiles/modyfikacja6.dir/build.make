# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.2.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.2.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\damia\OneDrive\Pulpit\TEP\modyfikacja6

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\damia\OneDrive\Pulpit\TEP\modyfikacja6\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\modyfikacja6.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\modyfikacja6.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\modyfikacja6.dir\flags.make

CMakeFiles\modyfikacja6.dir\main.cpp.obj: CMakeFiles\modyfikacja6.dir\flags.make
CMakeFiles\modyfikacja6.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\damia\OneDrive\Pulpit\TEP\modyfikacja6\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/modyfikacja6.dir/main.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1423~1.281\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\modyfikacja6.dir\main.cpp.obj /FdCMakeFiles\modyfikacja6.dir\ /FS -c C:\Users\damia\OneDrive\Pulpit\TEP\modyfikacja6\main.cpp
<<

CMakeFiles\modyfikacja6.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/modyfikacja6.dir/main.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1423~1.281\bin\Hostx86\x86\cl.exe > CMakeFiles\modyfikacja6.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\damia\OneDrive\Pulpit\TEP\modyfikacja6\main.cpp
<<

CMakeFiles\modyfikacja6.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/modyfikacja6.dir/main.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1423~1.281\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\modyfikacja6.dir\main.cpp.s /c C:\Users\damia\OneDrive\Pulpit\TEP\modyfikacja6\main.cpp
<<

# Object files for target modyfikacja6
modyfikacja6_OBJECTS = \
"CMakeFiles\modyfikacja6.dir\main.cpp.obj"

# External object files for target modyfikacja6
modyfikacja6_EXTERNAL_OBJECTS =

modyfikacja6.exe: CMakeFiles\modyfikacja6.dir\main.cpp.obj
modyfikacja6.exe: CMakeFiles\modyfikacja6.dir\build.make
modyfikacja6.exe: CMakeFiles\modyfikacja6.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\damia\OneDrive\Pulpit\TEP\modyfikacja6\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable modyfikacja6.exe"
	"C:\Program Files\JetBrains\CLion 2019.2.4\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\modyfikacja6.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\mt.exe --manifests  -- C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1423~1.281\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\modyfikacja6.dir\objects1.rsp @<<
 /out:modyfikacja6.exe /implib:modyfikacja6.lib /pdb:C:\Users\damia\OneDrive\Pulpit\TEP\modyfikacja6\cmake-build-debug\modyfikacja6.pdb /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\modyfikacja6.dir\build: modyfikacja6.exe

.PHONY : CMakeFiles\modyfikacja6.dir\build

CMakeFiles\modyfikacja6.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\modyfikacja6.dir\cmake_clean.cmake
.PHONY : CMakeFiles\modyfikacja6.dir\clean

CMakeFiles\modyfikacja6.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\damia\OneDrive\Pulpit\TEP\modyfikacja6 C:\Users\damia\OneDrive\Pulpit\TEP\modyfikacja6 C:\Users\damia\OneDrive\Pulpit\TEP\modyfikacja6\cmake-build-debug C:\Users\damia\OneDrive\Pulpit\TEP\modyfikacja6\cmake-build-debug C:\Users\damia\OneDrive\Pulpit\TEP\modyfikacja6\cmake-build-debug\CMakeFiles\modyfikacja6.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\modyfikacja6.dir\depend

