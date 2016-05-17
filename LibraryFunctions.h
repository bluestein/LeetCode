#pragma once
class LibraryFunctions
{
public:
	char* strncpy(char* dest, const char* src, size_t count);
	const char* strchr(const char* str, int ch);
	int strcmp(const char* lhs, const char* rhs);
	char* strcat(char* dest, const char* src);
	int strlen(const char* str);
	int strncmp(const char* lhs, const char* rhs, size_t count);
	void* memmove(void* dest, const void* src, size_t count);
};

