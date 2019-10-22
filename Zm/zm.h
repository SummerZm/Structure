#ifndef __ZM_H__
#define __ZM_H__

#include <iostream>
#include "inc/random.h"
#include "inc/timing.h"

#define ZM_DEBUG  0
#define zmDebugInfo(str)  std::cout<<"File "<<__FILE__<<" | Func "<<__FUNCTION__<<" | Line "<<__LINE__<<" : "<<str<<std::endl;

#if ZM_DEBUG==1
#define zmDebugInfoResize(capacity1, capacity2)  std::cout<<"File "<<__FILE__<<" | Func "<<__FUNCTION__<<" | Line "<<__LINE__<<" : resize "<<capacity1<<"=>"<<capacity2<<std::endl;
#else
#define zmDebugInfoResize 
#endif

#define zmMalloc malloc
#define zmRealloc realloc

#endif
