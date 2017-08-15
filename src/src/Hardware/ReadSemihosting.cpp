/*
 * ReadSemihosting.cpp
 *
 *  Created on: 14.08.2017
 *      Author: t.linz
 */

#include "ReadSemihosting.h"
#include <unistd.h>
#include "arm/semihosting.h"

std::string ReadString(void) {
  char pLines[2] = {0,0};
  std::string result;
  
  while (((pLines[0] != '\n') && (pLines[0] != '\r'))){
      (void)ReadHost(STDIN_FILENO, pLines, 1);
      result.append(pLines);
  };
  
  if (result.length() > 0){
    return result;
  } else {
    return std::string("");
  }
}

/* Semihost system call parameters */
union param_t{
    int   pdInt;
    void *pdPtr;
};

typedef union param_t param;

size_t ReadHost(int fd, void *buf, size_t count)
{
    param semi_param[3] = {
        { .pdInt = fd },
        { .pdPtr = buf },
        { .pdInt = static_cast<int>(count) }
    };

    return call_host(SEMIHOSTING_SYS_READ, semi_param);
}
