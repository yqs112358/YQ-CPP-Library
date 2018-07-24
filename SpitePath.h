#pragma once

bool SpitePath(string &fullpath,string &path,string &fname,string &extname)
{
	try{
		if(fullpath.empty())
		{
