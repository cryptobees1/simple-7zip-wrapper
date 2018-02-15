#include "7zipInterface.h"


#ifdef __ANDROID__
#include "7zipAndroid/CPP/Common/MyString.h"
#include "7zipAndroid/CPP/7zip/UI/Console/Main7zMain.h"
#else
#include "7zip/CPP/Common/MyString.h"
#include "7zip/CPP/7zip/UI/Console/Main7zMain.h"
#endif

bool R7zip::Encode(const list<wstring>& lInFilePaths, const wstring& sOutArchivePath)
{
   UStringVector vecParts;
   vecParts.Add(UString(L"a"));
   vecParts.Add(UString(sOutArchivePath.c_str()));
   for (list<wstring>::const_iterator it = lInFilePaths.begin(); it != lInFilePaths.end(); it++) {
      vecParts.Add((*it).c_str());
   }
   vecParts.Add(UString(L"-mx0"));
   return R7zipMain::_Main1(vecParts);
}

bool R7zip::Decode(const wstring& sInArchiveFullPath, const wstring& sOutFolder)
{
   UStringVector vecParts;
   vecParts.Add(UString(L"x"));
   if (!sOutFolder.empty()) {
      // Add output directory switch
      wstring sSwitch = L"-o" + sOutFolder;
      vecParts.Add(sSwitch.c_str());
   }
   vecParts.Add(UString(sInArchiveFullPath.c_str()));
   return R7zipMain::_Main1(vecParts);
}

bool R7zip::DecodeSpecificFiles(const wstring& sInArchiveFullPath, const wstring& sOutFolder, const list<wstring>& lWildcards)
{
   UStringVector vecParts;
   vecParts.Add(UString(L"x"));
   if (!sOutFolder.empty()) {
      // Add output directory switch
      wstring sSwitch = L"-o" + sOutFolder;
      vecParts.Add(sSwitch.c_str());
   }
   vecParts.Add(UString(sInArchiveFullPath.c_str()));

   // Add wildcards
   for (list<wstring>::const_iterator it = lWildcards.begin(); it != lWildcards.end(); it++) {
      vecParts.Add((*it).c_str());
   }

   return R7zipMain::_Main1(vecParts);
}

bool R7zip::IsValidArchive(const wstring& sInArchiveFullPath)
{
   UStringVector vecParts;
   vecParts.Add(UString(L"t"));
   vecParts.Add(UString(sInArchiveFullPath.c_str()));
   return R7zipMain::_Main1(vecParts);
}

bool R7zip::IsValid7zArchiveHeaderFormat(const wstring& sInArchiveFullPath)
{
   return R7zipMain::_IsValid7zArchiveHeaderFormat(UString(sInArchiveFullPath.c_str()));
}

