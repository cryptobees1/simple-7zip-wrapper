// CabRegister.cpp

#include "7zStdAfx.h"

#include "../../Common/RegisterArc.h"

#include "CabHandler.h"

namespace NArchive {
namespace NCab {

REGISTER_ARC_I(
  "Cab", "cab", 0, 8,
  NHeader::kMarker,
  0,
  NArcInfoFlags::kFindSignature,
  NULL)

}}
