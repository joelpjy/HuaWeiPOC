
#ifndef _CHARACTER_INTERFACE_H_
#define _CHARACTER_INTERFACE_H_

#include <vector>
#include <string>

#define EXPORT _declspec(dllexport)

struct CharacterData {
	std::string posPath;
	std::string negPath;
	std::string neutralPath;
	std::string texturePath;
	std::string markIdPath;
	std::string contourIdPath;
};

EXPORT int CharacterAdapter(const CharacterData data, std::string savePath);

#endif
