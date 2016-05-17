#include "stdafx.h"
#include "LibraryFunctions.h"

/*
Copies at most count characters of the character array pointed to by src(including the terminating null character, 
but not any of the characters that follow the null character) to character array pointed to by dest.
If count is reached before the entire array src was copied, the resulting character array is not null - terminated.
If, after copying the terminating null character from src, count is not reached, additional null characters are written to dest until the total of count characters have been written.
The behavior is undefined if the character arrays overlap, if either dest or src is not a pointer to a character array(including if dest or src is a null pointer), 
if the size of the array pointed to by dest is less than count, or if the size of the array pointed to by src is less than count and it does not contain a null character.

Parameters
dest  - pointer to the character array to copy to
src   - pointer to the byte string to copy from
count - maximum number of characters to copy

Return value
dest
*/
char* LibraryFunctions::strncpy(char* dest, const char* src, size_t count)
{
	if (dest == nullptr || src == nullptr) throw "Invalid Arguments";
	char* cur = dest;
	while (count--)
	{
		if (*src != '\0')
		{
			*cur++ = *src++;
		}
		else
		{
			*cur++ = *src;
		}
	}
	if (*src != '\0')
	{
		*cur = '\0';
	}
	return dest;
}

/*
Finds the first occurrence of the character static_cast<char>(ch) in the byte string pointed to by str.
The terminating null character is considered to be a part of the string.

Parameters
str	- pointer to the null-terminated byte string to be analyzed
ch  - character to search for

Return value
Pointer to the found character in str, or a null pointer if no such character is found.
*/
const char* LibraryFunctions::strchr(const char* str, int ch)
{
	if (str != nullptr)
	{
		for (; *str != '\0'; str++)
		{
			if (*str == (char)ch) return str;
		}
	}
	return nullptr;
}

/*
Compares two null - terminated byte strings lexicographically.
The sign of the result is the sign of the difference between the values of the first pair of characters(both interpreted as unsigned char) that differ in the strings being compared.
The behavior is undefined if lhs or rhs are not pointers to null - terminated strings.

Parameters
lhs, rhs - pointers to the null-terminated byte strings to compare

Return value
Negative value if lhs appears before rhs in lexicographical order.
Zero if lhs and rhs compare equal.
Positive value if lhs appears after rhs in lexicographical order.
*/
int LibraryFunctions::strcmp(const char* lhs, const char* rhs)
{
	if (lhs == nullptr || rhs == nullptr) throw "Invalid Arguments";
	int ret = 0;
	while (!(ret = *(unsigned char*)lhs - *(unsigned char*)rhs) && *rhs)
	{
		++lhs, ++rhs;
	}
	if (ret < 0)
		ret = -1;
	else if (ret > 0)
		ret = 1;
	return ret;
}

/*
Compares at most count characters of two null-terminated byte strings.The comparison is done lexicographically.
The sign of the result is the sign of the difference between the values of the first pair of characters (both interpreted as unsigned char) that differ in the strings being compared.
The behavior is undefined if lhs or rhs are not pointers to null-terminated strings.

Parameters
lhs, rhs - pointers to the null-terminated byte strings to compare
count    - maximum number of characters to compare

Return value
Negative value if lhs appears before rhs in lexicographical order.
Zero if lhs and rhs compare equal.
Positive value if lhs appears after rhs in lexicographical order.
*/
int LibraryFunctions::strncmp(const char* lhs, const char* rhs, size_t count)
{
	if (lhs == nullptr || rhs == nullptr) throw "Invalid Arguments";
	int ret = 0;
	while (!(ret = *(unsigned char*)lhs - *(unsigned char*)rhs) && *rhs && count--)
	{
		++lhs, ++rhs;
	}
	if (ret < 0)
		ret = -1;
	else if (ret > 0)
		ret = 1;
	return ret;
}

/*
Appends a copy of the character string pointed to by src to the end of the character string pointed to by dest.
The character src[0] replaces the null terminator at the end of dest.The resulting byte string is null - terminated.
The behavior is undefined if the destination array is not large enough for the contents of both src and dest and the terminating null character.
The behavior is undefined if the strings overlap.

Parameters
dest - pointer to the null-terminated byte string to append to
src	 - pointer to the null-terminated byte string to copy from

Return value
dest
*/
char* LibraryFunctions::strcat(char* dest, const char* src)
{
	if (dest == nullptr || src == nullptr) throw "Invalid Arguments";
	char* cur = dest;
	while (*cur != '\0') ++cur;
	while (*src != '\0') *cur++ = *src++;
	return dest;
}

/*
Returns the length of the given byte string, that is, the number of characters in a character array whose first element is pointed to by str up to and not including the first null character. 
The behavior is undefined if there is no null character in the character array pointed to by str.

Parameters
str	- pointer to the null-terminated byte string to be examined

Return value
The length of the null-terminated string str.
*/
int LibraryFunctions::strlen(const char* str)
{
	if (str == nullptr) throw "Invalid Arguments";
	int len = 0;
	while (*str++ != '\0') ++len;
	return len;
}

/*
Copies count characters from the object pointed to by src to the object pointed to by dest. Both objects are reinterpreted as arrays of unsigned char.
The objects may overlap: copying takes place as if the characters were copied to a temporary character array and then the characters were copied from the array to dest.
If the objects are not TriviallyCopyable, the behavior of memmove is not specified and may be undefined.

Parameters
dest  -	pointer to the memory location to copy to
src   -	pointer to the memory location to copy from
count -	number of bytes to copy

Return value
dest
*/
void* LibraryFunctions::memmove(void* dest, const void* src, size_t count)
{
	if (nullptr == dest || nullptr == src) return nullptr;
	char *d = (char*)dest;
	const char *s = (char*)src;
	if (d != s && count != 0)
	{
		if (d > s) // copy backward
		{
			while (count--) {
				*(d + count) = *(s + count);
			}
		}
		else { // copy forward
			while (count--)
			{
				*d++ = *s++;
			}
		}
	}
	return dest;
}
