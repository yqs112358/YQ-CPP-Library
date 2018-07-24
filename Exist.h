#ifndef YQ_EXIST_H
#define YQ_EXIST_H

#include <string>
#include "windows.h"

using std::string;

// 判断文件是否存在
bool IsFileExist(const string &csFile)
{
    DWORD dwAttrib = GetFileAttributes(csFile.c_str());
    return dwAttrib != INVALID_FILE_ATTRIBUTES && (dwAttrib & FILE_ATTRIBUTE_DIRECTORY) == 0;
}
// 判断文件夹是否存在
bool IsDirExist(const string &csDir)
{
    DWORD dwAttrib = GetFileAttributes(csDir.c_str());
    return dwAttrib != INVALID_FILE_ATTRIBUTES && (dwAttrib & FILE_ATTRIBUTE_DIRECTORY) != 0;
}
// 判断文件或文件夹是否存在
bool IsPathExist(const string &csPath)
{
    WIN32_FILE_ATTRIBUTE_DATA attrs = { 0 };
    return GetFileAttributesEx(csPath.c_str(), GetFileExInfoStandard, &attrs) != 0;
}

#endif
