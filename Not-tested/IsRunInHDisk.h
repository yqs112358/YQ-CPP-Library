#ifndef YQ_IS_RUN_IN_H_DISK_H
#define YQ_IS_RUN_IN_H_DISK_H

#include <string>
#include "GetDeviceType.h"

inline bool IsRunInHDisk(std::string path="")
{
	return GetDeviceType(path) == DeviceType::Fixed;
}

#endif
