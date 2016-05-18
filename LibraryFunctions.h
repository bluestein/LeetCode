#pragma once
class LibraryFunctions
{
public:
	// Copying
	char*       strcpy(char* dest, const char* src);
	char*       strncpy(char* dest, const char* src, size_t count);
	void*       memcpy(void* dest, const void* src, size_t count);
	void*       memmove(void* dest, const void* src, size_t count);

	// Comparison
	int         strcmp(const char* lhs, const char* rhs);
	int         strncmp(const char* lhs, const char* rhs, size_t count);
	int         memcmp(const void* lhs, const void* rhs, size_t count);

	//Searching
	const char* strchr(const char* str, int ch);
	const char* strrchr(const char* str, int ch);
	const char* strstr_(const char* str, const char* target);
	const char* strstr(const char* str, const char* target);
	const char* strpbrk(const char* dest, const char* breakset); 
	size_t      strspn(const char* dest, const char* accept);
	size_t      strcspn(const char* dest, const char* reject);

	// Concatenation
	char*       strcat(char* dest, const char* src); 
	char*       strncat(char* dest, const char* src, size_t count);

	// Other
	int         strlen(const char* str);
	void*       memset(void* dest, int ch, size_t count);
};

