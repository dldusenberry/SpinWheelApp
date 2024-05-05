# Download and Install wxWidgets and wxCharts

First thing to note is that both wxWidgets and wxcharts recommend building the libraries from source, and these are the instructions I will include in this document. 
However, wxWidgets does provide a few pre-built binaries for most common builds. 

The install instructions I will include on this page are exclusively for Microsoft Windows platforms using Microsoft Visual C++ compiler.
Other supported platforms installation intructions available will be linked, but not explicitly explained in this document.

## wxWidgets
----------------------------------------------------------------

### Supported Platforms
wxWidgets supports:
- MSW: The port for 32-bit and 64-bit Windows variants including Windows XP, Vista, 7, 8, 10 and 11.
- OSX/Cocoa: For delivering Cocoa-based applications on macOS 10.10 and above.
- GTK: The recommended port for Linux and other Unix variants, using GTK+ version 2.6 or higher.
- Others: X11, Motif, and QT
### Supported Compilers
All C++ compilers are supported including:
- Microsoft Visual C++ 2015 or later (up to 2022).
- g++ 4.8 or later (up to 13), including MinGW/MinGW-64/TDM under Windows.
- Clang (up to 16).
  
### System Requirements
Dependent on operating system and compiler for implementation. 
- [wxWidgets Requirements Page](https://docs.wxwidgets.org/3.2.3/page_introduction.html) for all platforms listed here.
- [wxWidgets Platform Details Page](https://docs.wxwidgets.org/3.2.3/page_port.html)
  
For Microsoft Windows the official websites states:

![Screenshot 2024-05-04 211215](https://github.com/dldusenberry/SpinWheelApp/assets/98852855/840822ab-df99-43c6-bf35-12e5dbee5a4a)

![Screenshot 2024-05-04 212425](https://github.com/dldusenberry/SpinWheelApp/assets/98852855/610cd567-0e05-4ead-8e73-2047f0a3a923)

### Links for Official Installation Instructions
Microsoft Windows:

- From Source: [wxMSW Official website](https://docs.wxwidgets.org/3.2.3/plat_msw_install.html), [wxMSW Github](https://github.com/wxWidgets/wxWidgets/blob/master/docs/msw/install.md)
- From Binaries: [wxWidgets Downloads Page](https://www.wxwidgets.org/downloads/), [wxMSW Binaries Instructions](https://docs.wxwidgets.org/3.2.4/plat_msw_binaries.html)
  
Other Platforms:
- [wxOSX/Cocoa Official website](https://docs.wxwidgets.org/3.2.3/plat_osx_install.html), [wxOSX/Cocoa Github](https://github.com/wxWidgets/wxWidgets/blob/master/docs/osx/install.md)
- [wxGTK Official website](https://docs.wxwidgets.org/3.2.3/plat_gtk_install.html), [wxGTK Github](https://github.com/wxWidgets/wxWidgets/blob/master/docs/gtk/install.md)
- [wxX11 Official website](https://docs.wxwidgets.org/3.2.3/plat_x11_install.html), [wxX11 Github](https://github.com/wxWidgets/wxWidgets/blob/master/docs/x11/install.md)
- [wxMotif Official website](https://docs.wxwidgets.org/3.2.3/plat_motif_install.html), wxMotif Github (not available)
- [wxQT Official website](https://docs.wxwidgets.org/3.2.3/plat_qt_install.html), [wxQT Github](https://github.com/wxWidgets/wxWidgets/blob/master/docs/qt/install.md)
### wxMSW Download & Build from Source Instructions
----------------------------------------------------------------

Step 1: Download
----------------------------------------------------------------

- Download the source archive and uncompress it in any directory.
- It is advised to not chose a directory with spaces in the name (i.e. 'C:\Program Files'), I created a new directory and named it 'C:\Libraries'.

![Screenshot 2024-05-04 212654](https://github.com/dldusenberry/SpinWheelApp/assets/98852855/1f969c78-18fa-47aa-ba75-d897b8cb6eb5)

Step 2: Environment Variable
----------------------------------------------------------------

- Search "environment variable" from the Windows Start menu, and click on "Edit the System Environment Variables"
- Click "Environment Variables..." > "New..."
- For "Variable Name:" type `WXWIN`, For "Variable Value:" type the `<directory path>` where you downloaded the files. Mine would be in `C:\Libraries\wxWidgets-3.2.4` 
- Then click "OK".

Step 3: Build the Library - Microsoft Visual C++ Compilation     
----------------------------------------------------------------

### From the IDE

Ready to use project files are provided for VC++ versions 2015, 2017, 2019 and 2022.

Simply open `wx_vcN.sln` (for N=14, 15, 16 or 17) file,
select the appropriate configuration (Debug or Release, static or DLL)
and build the solution. Notice that when building a DLL configuration,
you may need to perform the build several times because the projects
are not always built in the correct order, and this may result in link
errors. Simply do the build again, up to 3 times, to fix this.


### From the command line

wxWidgets can also be built from the command line using the provided makefiles.

This needs to be done from the "Visual Studio Command Prompt" window, which can
be opened using a shortcut installed to the "Start" menu or the "Start" screen
by MSVS installation.

In this window, change directory to `%%WXWIN%\build\msw` and type

        > nmake /f makefile.vc

to build wxWidgets in the default debug configuration as a static library. You
can also do

        > nmake /f makefile.vc BUILD=release

to build a release version or

        > nmake /f makefile.vc BUILD=release SHARED=1 TARGET_CPU=X86

to build a 32 bit release DLL version from an x86 command prompt, or

        > nmake /f makefile.vc BUILD=release SHARED=1 TARGET_CPU=X64

to build a 64 bit release DLL version from an x64 command prompt.

See [Make Parameters](#msw_build_make_params) for more information about the
additional parameters that can be specified on the command line.

To verify your build, change the directory to `%%WXWIN%\samples\minimal` and
run the same nmake command (with the same parameters there), this should create
a working minimal wxWidgets sample.

If you need to rebuild, use "clean" target first or "nmake /a". 

Step 4: Change Compiler and Linker settings
----------------------------------------------------------------


### Using Microsoft Visual C++ IDE         

If you use MSVS for building your project, simply add
`wxwidgets.props` property sheet to (all) your project(s) using wxWidgets
by using "View|Property Manager" menu item to open the property manager
window and then selecting "Add Existing Property Sheet..." from the context
menu in this window.

If you've created a new empty project (i.e. chose "Empty Project" in the
"Create a new project" window shown by MSVS rather than "Windows Desktop"),
you need to change "Linker|System|SubSystem" in the project properties to
"Windows", from the default "Console". You don't need to do anything else.

### Using Other Compilers or Command Line 

We suppose that wxWidgets sources are under the directory `$WXWIN` (notice that
different tool chains refer to environment variables such as WXWIN in
different ways, e.g. MSVC users should use `$``(WXWIN)` instead of just
`$WXWIN`). And we will use `<wx-lib-dir>` as a shortcut for the subdirectory of
`$WXWIN\lib` which is composed from several parts separated by underscore:
first, a compiler-specific prefix (e.g. "vc" for MSVC, "gcc" for g++ or the
value of `COMPILER_PREFIX` if you set it explicitly), then "x64" if building in
64 bits using MSVC (but not any other compilers) and finally either "lib" or
"dll" depending on whether static or dynamic wx libraries are being used.

For example, WXWIN could be "c:\wxWidgets\3.4.5" and `<wx-lib-dir>` could be
`c:\wxWidgets\3.4.5\lib\vc_x64_lib` for 64-bit static libraries built with
MSVC but for shared libraries built with gcc it would be
`c:\wxWidgets\3.4.5\lib\gcc_dll` instead.

Here is what you need to do:

* Add `$WXWIN\include` to the
  - compiler
  - resource compiler
  include paths.
* Append `<wx-lib-dir>\mswu[d]` to the include paths, where "d" should
  be used for debug builds only.
  When using MSVC, there is a simpler alternative which allows to use the
  same compiler options for debug and release builds: just prepend
  `$WXWIN\include\msvc` to the include paths **instead** of the paths above.
* Define the following symbols for the preprocessor:
  - `__WXMSW__` to ensure you use the correct wxWidgets port.
  - `NDEBUG` if you want to build in release mode, i.e. disable asserts.
  - `WXUSINGDLL` if you are using DLL build of wxWidgets.
* Add `<wx-lib-dir>` directory described above to the libraries path.

When using MSVC, using `include\msvc` in the compiler include path has another
advantage: the header found in this directory ensures that all the required
libraries are linked automatically using `#pragma comment(lib)` feature of this
compiler. With the other compilers, or if you don't use `include\msvc` with
MSVC, you also need to:

* Add the list of libraries to link with to the linker input. The exact list
  depends on which libraries you use and whether you built wxWidgets in
  monolithic or default multi-lib mode and basically should include all the
  relevant libraries from the directory above, e.g. `wxmsw34ud_core.lib
  wxbase34ud.lib wxtiffd.lib wxjpegd.lib wxpngd.lib wxzlibd.lib wxregexud.lib
  wxexpatd.lib` for a debug build of an application using the core library of
  wxWidgets 3.4 only (all wxWidgets applications use the base library).


For example, to compile your program with gcc using debug wxWidgets DLLs
you would need to use the following options for the compiler (and `windres`
resource compiler):

    -I$WXWIN/include -I$WXWIN/lib/gcc_dll/mswud -D__WXMSW__ -DWXUSINGDLL

and

    -L$WXWIN/lib/gcc_dll

for the linker.

Finally, please notice that the makefiles and project files provided with
wxWidgets samples show which flags should be used when building applications
using wxWidgets and always work, so in case of a problem, e.g. if the
instructions here are out of date, you can always simply copy a makefile or
project file from `$WXWIN\samples\minimal` or some other sample and adapt it to
your application.


## wxCharts
----------------------------------------------------------------

### Supported Platforms
wxCharts is still in the development phase and currently only supports MSW.

### Links
- [wxCharts Getting Started Page](https://www.wxishiko.com/wxCharts/gettingstarted.html)
- [wxCharts README on Github](https://github.com/wxIshiko/wxCharts/blob/main/README.md)

### MSW Download & Build from Source Instructions
----------------------------------------------------------------

Step 1: Download
----------------------------------------------------------------

- Download the source archive and uncompress it in any directory.
- It is advised to not chose a directory with spaces in the name (i.e. 'C:\Program Files'), I created a new directory and named it 'C:\Libraries'.

![Screenshot 2024-05-04 212654](https://github.com/dldusenberry/SpinWheelApp/assets/98852855/1f969c78-18fa-47aa-ba75-d897b8cb6eb5)

Step 2: Environment Variable
----------------------------------------------------------------

- Search "environment variable" from the Windows Start menu, and click on "Edit the System Environment Variables"
- Click "Environment Variables..." > "New..."
- For "Variable Name:" type `WXCHARTS`, For "Variable Value:" type the `<directory path>` where you downloaded the files. Mine would be in `C:\Libraries\wxCharts` 
- Then click "OK".

Step 3: Build the Library - Microsoft Visual C++ Compilation     
----------------------------------------------------------------

### From the IDE

Ready to use project files are provided for VC++ versions 2013, 2014, 2015 and 2016.

Simply open `wx_vcN.sln` (for N=12, 14, 15, or 16) file,
select the appropriate configuration (Debug or Release)
and build the solution. 

Step 4: Change Compiler and Linker settings
----------------------------------------------------------------
Here is what you need to do:

* Add `$WXCHARTS\include\wx\charts` to the
  - compiler
  - resource compiler
  include paths.
* Add `$WXCHARTS\lib\vc_x64_lib` to the linker
  - additional library directories
