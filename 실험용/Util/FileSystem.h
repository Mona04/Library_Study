#pragma once

class FileSystem
{
public:
	static const std::string GetFileNameFromPath(const std::string& path);
	static const std::string GetIntactFileNameFromPath(const std::string& path);
};