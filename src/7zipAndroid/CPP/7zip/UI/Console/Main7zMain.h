#ifndef __COMMON_MAIN7ZMAIN_H
#define __COMMON_MAIN7ZMAIN_H

#include "../../../Common/MyString.h"

using namespace std;

namespace R7zipMain {
   // ** Do not use the following functions directly, unless you know what you are doing
   bool _Main1(const UStringVector& commandStrings);
   bool _Main2(const UStringVector& commandStrings);
   bool _IsValid7zArchiveHeaderFormat(const UString& sInArchiveFullPath);
};

#endif  // ~ __COMMON_MAIN7ZMAIN_H
