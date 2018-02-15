#ifndef __7ZIP_INTERFACE_H
#define __7ZIP_INTERFACE_H

// ----- Om: Our modifications to the 7zipAndroid code    -----
// [Om, 2018.02.02]: Compiled p7zip v16.02. Modified /CPP/UI/Console/Main.cpp to Main7zMain.cpp/h
//                      This removed and commented out the stuffs we didn't need. Also provided the right interface for our code
// [Om, 2018.02.07]: Implemented IsValid7zArchiveHeaderFormat function in Main7zMain.cpp/h
// [Om, 2018.02.08]: /CPP/Common/StringConvert.cpp Line-8: Changed global_use_utf16_conversion to 1.
// ------------------------------------------------------------

// ----- Om: Our modifications to the 7zip (Windows) code -----
// [Om, 2018.01.31]: Compiled 7zip v18.00. Modified /CPP/UI/Console/Main.cpp to Main7zMain.cpp/h
//                      This removed and commented out the stuffs we didn't need. Also provided the right interface for our code
//                      Renamed /CPP/7zip/UI/Common/Update.h/cpp to UpdateMain.h/cpp due to file-name conflict
//                      Renamed /CPP/Windows/System.h/ccp to WinSystem.h/cpp due to file-name conflict
//                      Also adjusted the #include files accordingly. Commented out a lot of unneeded code from UpdateMain.cpp
// [Om, 2018.02.07]: Implemented IsValid7zArchiveHeaderFormat function in Main7zMain.cpp/h
// ------------------------------------------------------------


#include	<list>
#include	<string>

using namespace std;

namespace R7zip {

   // ** Encode an archive
   // lInFilePaths - lists of input full filepath name and extension, or/and input folder paths
   // sOutArchivePath - Full path of the output archive (full/folder/path/name.extension)
   bool Encode(const list<wstring>& lInFilePaths, const wstring& sOutArchivePath);

   // ** Decode an archive
   // sInArchiveFullPath - Full path of the input archive
   // sOutFolder - Full path of the output folder
   bool Decode(const wstring& sInArchiveFullPath, const wstring& sOutFolder);

   // ** Decode specific files from archive
   // lWildcards - It can be list of file names or wildcards. Note: Specify the relative folder path if needed.
   // Valid wildcard examples:
   //    folder/path/7z.cpp   - Finds and extracts the 7z.h file in the folder/path/ directory
   //    *.cpp - all files with extension .cpp
   bool DecodeSpecificFiles(const wstring& sInArchiveFullPath, const wstring& sOutFolder, const list<wstring>& lWildcards);

   // Validate archive
   bool IsValidArchive(const wstring& sInArchiveFullPath);

   // Returns true if it has a valid 7zip header format
   bool IsValid7zArchiveHeaderFormat(const wstring& sInArchiveFullPath);
};

#endif  // ~ __7ZIP_INTERFACE_H
