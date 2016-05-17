#pragma once
class LibraryFunctions
{
public:
	char*       strcpy(char* dest, const char* src);
	char*       strncpy(char* dest, const char* src, size_t count);
	int         strcmp(const char* lhs, const char* rhs);
	int         strncmp(const char* lhs, const char* rhs, size_t count);
	const char* strchr(const char* str, int ch);
	const char* strrchr(const char* str, int ch);
	int         strlen(const char* str);
	const char* strstr(const char* str, const char* target);
	char*       strcat(char* dest, const char* src); 
	char*       strncat(char* dest, const char* src, size_t count);
	const char* strpbrk(const char* dest, const char* breakset); 
	size_t      strspn(const char* dest, const char* accept);
	size_t      strcspn(const char* dest, const char* reject);
	void*       memmove(void* dest, const void* src, size_t count);
};

