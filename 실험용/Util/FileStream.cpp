#include "pch.h"
#include "FileStream.h"

bool FileStream::Open(const std::string& path, const StreamMode& mode, const bool& isBinary)
{
	this->mode = mode;

	switch (mode)
	{
	case StreamMode::Write:
		out.open(path, isBinary ? std::ios::out | std::ios::binary : std::ios::out);
		if (out.fail())
		{
			return false;
		}
		break;
	case StreamMode::Read:
		in.open(path);// ?  std::ios::in | std::ios::binary : std::ios::in, 32);
		if (in.fail())
		{
			return false;
		}		break;
	}

	return true;
}

void FileStream::Close()
{
	switch (mode)
	{
	case StreamMode::Write:
		out.flush();
		out.close();
		break;

	case StreamMode::Read:
		in.clear();
		in.close();
		break;

	default:
		break;
	}
}

void FileStream::Write(const std::string& value)
{
	uint length = static_cast<uint>(value.length());
	Write(length);

	out.write(value.c_str(), length);
}

void FileStream::Write(const std::vector<std::byte>& value)
{
	uint length = static_cast<uint>(value.size());
	Write(length);

	out.write(reinterpret_cast<const char*>(value.data()), sizeof(std::byte) * length);
}

void FileStream::Read(std::string& value)
{
	uint length = ReadUInt();

	value.clear();
	value.shrink_to_fit();
	value.resize(length);

	in.read(value.data(), length);
}

void FileStream::Read(std::vector<std::byte>& value)
{
	uint length = ReadUInt();

	value.clear();
	value.shrink_to_fit();
	value.reserve(length);
	value.resize(length);

	in.read(reinterpret_cast<char*>(value.data()), sizeof(std::byte) * length);
}
