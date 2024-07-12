# twainsave
twainsave is a free, open source version of Dynarithmic Software's [TwainSave](http://www.dynarithmic.com/onlinehelp/twainsave/index.html) command-line program to access TWAIN devices and convert scanned pages to image files (BMP, JPEG, TIFF, etc).  This version is licensed under the Apache 2.0 license.  

Note that this version of TwainSave currently lacks some features of the commercial version of TwainSave.  We are in the process of adding these features to the open source version periodically.  

Currently, close to all of the functionality that is in the commercial version of TwainSave is implemented in the open source version.  

Note that there are two copies of the Twainsave executable files for each architecture (32-bit and 64-bit).  In the <a href="https://github.com/dynarithmic/twainsave/tree/master/binaries/32-bit" target="_blank">32-bit version of Twainsave</a>, you will see **twainsave.exe**, and **twainsave-opensource.exe**, and for the <a href="https://github.com/dynarithmic/twainsave/tree/master/binaries/64-bit" target="_blank">64-bit version of Twainsave</a>, the executable files are **twainsave-opensource.exe** and **twainsave64.exe**.  

The 32-bit **twainsave.exe** is exactly the same as the 32-bit **twainsave-opensource.exe**, likewise the 64-bit **twainsave64.exe** is exactly the same executable as the 64 bit **twainsave-opensource.exe**.  The reason for the similar files is that the original help documentation referred to **twainsave.exe** and **twainsave64.exe** and not **twainsave-opensource.exe**.  

The new documentation for the open source version of TwainSave is basically the same as the commercial version, with some differences.  The documentation is in Windows help (.CHM) format, and will be found in the **32-bit** and **64-bit** executable directories.  In the near future, online HTML documentation will be provided.

----
The current open source Twainsave version is **1.0.8**.

----

# Differences in this version and the commercial version of TwainSave

1) The command-line parameters use the traditional Unix-style double-hyphen option specifier.  So for example, instead of this:
**twainsave -filename test.bmp**

The option for the open source version will be
**twainsave --filename test.bmp**

2) The **--details** listing differs from the commercial version's [**-details**](http://www.dynarithmic.com/onlinehelp/twainsave/_details.htm) setting in two major ways:<br>
    a) The **--details** is in JSON format.  
    b) The output will by default go to the console instead of having to specify a file.  
  
For item b), to output to a file just requires you to run twainsave-opensource and redirect the **--details** output to a file.  For example:  
 
**twainsave --details > details.log**

will write the details to the file **details.log**

3) Running **twainsave.exe** without command-line parameters will default to displaying the TWAIN Select Source dialog box.  If a device is selected, will allow the user to acquire and save the file to a BMP file.  The resulting BMP file will be have a randomly generated file name (using a **.BMP** extension).  

4) Running **twainsave.exe** without a --filename setting, but with a --filetype setting: If a device is selected, the name of the file will be randomly generated, with a file extension that matches the file type specified.

   For example:
   **twainsave --filetype pdf**
   will result in a file created with a random name, with a **.pdf** extension.
   
6)   Note that the random names will have as the filename in a 128-bit GUID format, with leading and trailing **{}**.  For example:

    {6B29FC40-CA47-1067-B31D-00DD010662DA}.pdf

   would be a randomly generated pdf file.

----------

# Building TwainSave from source

If you want to build the source code, the requirements are the same as building the source for the Dynarithmic TWAIN library found [here](https://github.com/dynarithmic/twain_library_source). 

This means that you will need an installation of the Boost C++ libraries, as well as set environment variables that point to the Boost header files and library files.

There is no need to rebuild DTWAIN first, however I would recommend you build DTWAIN first to ensure you have the correct requirements for building TwainSave.    
  
The only addition to the instructions above would be to define the following environment variables before starting Visual Studio:

* DTWAIN_LIBRARY_DIR_32 -- Directory to the 32-bit DTWAIN import libraries.
* DTWAIN_LIBRARY_DIR_64 -- Directory to the 64-bit DTWAIN import libraries.

These directories will usually be the same one you will find dtwain32u.lib, dtwain64u.lib, etc.  The building of TwainSave will be using these environment variables to find the correct DTWAIN import libraries during the build process.

----------

## To-do list

- Implement the **-verbose** and **-verboselog** option.


