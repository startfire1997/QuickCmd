#pragma once
#include "glog/logging.h"

#define CHECK_FALSE_RETURN(expr, retValue) \
    if (expr == false) { \
        LOG(ERROR) << #expr << "is not true and return."; \
        return retValue; } 
