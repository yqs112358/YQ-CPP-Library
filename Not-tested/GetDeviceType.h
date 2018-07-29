#ifndef YQ_GET_DEVICE_TYPE_H
#define YQ_GET_DEVICE_TYPE_H

#include <windows.h>
#include <string>
#include "SpitePath.h"
#include "GetThisPath.h"
#include "CheckPath.h"

using std::string;
enum DeviceType
{
	Unknown,
	Fixed,
	CD-ROM,
	Movable,
	Remote,
	NoRootDir,
	Ramdisk
};

DeviceType GetDeviceType(string path="")
{
	if(path.empty())
		path=GetThisPath();
	else
		path=CheckPath(path);
	
	string drive,dir;
	SpitePath(path,&drive,&dir);
	drive+=dir;
	
	UINT res=GetDriveType(drive.c_str());
	switch(res)
	{
		case DRIVE_UNKNOWN:
		      return DeviceType::Unknown;
		      break;
		case DRIVE_FIXED:
		      return DeviceType::Fixed;
		      break;
		case DRIVE_CDROM:
		      return DeviceType::CD-ROM;
		      break;
		case DRIVE_REMOVABLE:
		      return DeviceType::Movable;
		      break;
		      
		case DRIVE_REMOTE:
		      return DeviceType::Remote;
		      break; 
		case DRIVE_NO_ROOT_DIR:
		      return DeviceType::NoRootDir;
		      break;
		case DRIVE_RAMDISK:
		      return DeviceType::Ramdisk;
		      break;
		      
		default:
			return DeviceType::Unknown;
	}
}

#endif
