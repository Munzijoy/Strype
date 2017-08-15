//----------------------------------------------------------------------------
// Copyright: HIMA - Paul Hildebrandt GmbH + Co KG
//
// $Id: $
//----------------------------------------------------------------------------
#ifndef IN_READSEMIHOSTING_H_FIRST
#define IN_READSEMIHOSTING_H_FIRST
//----------------------------------------------------------------------------
//

//----------------- include files --------------------------------------------
#include <string>

//----------------- declarations ---------------------------------------------
std::string ReadString(void);
size_t ReadHost(int fd, void *buf, size_t count);

#endif
