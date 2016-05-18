#include "stdafx.h"
#include "LibraryFunctions.h"

/*
Copies the character string pointed to by src, including the null terminator, to the character array whose first element is pointed to by dest.
The behavior is undefined if the dest array is not large enough. The behavior is undefined if the strings overlap.

Parameters
dest -	pointer to the character array to write to
src  -	pointer to the null-terminated byte string to copy from

Return value
dest
*/
char* LibraryFunctions::strcpy(char* dest, const char* src)
{
	if (dest == nullptr || src == nullptr) throw "Undefined";
	char* cur = dest;
	while (*src != '\0')
	{
		*cur++ = *src++;
	}
	return dest;
}

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
	if (dest == nullptr || src == nullptr) throw "Undefined";
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
Copies count bytes from the object pointed to by src to the object pointed to by dest. 
Both objects are reinterpreted as arrays of unsigned char.
If the objects overlap, the behavior is undefined.
If either dest or src is a null pointer, the behavior is undefined, even if count is zero.
If the objects are not TriviallyCopyable, the behavior of memcpy is not specified and may be undefined.

Parameters
dest  - pointer to the memory location to copy to
src   - pointer to the memory location to copy from
count - number of bytes to copy

Return value
dest

Notes
std::memcpy is the fastest library routine for memory-to-memory copy. 
It is usually more efficient than std::strcpy, which must scan the data it copies or std::memmove, which must take precautions to handle overlapping inputs.
Several C++ compilers transform suitable memory-copying loops to std::memcpy calls.
Where strict aliasing prohibits examining the same memory as values of two different types, std::memcpy may be used to convert the values.
*/
void* LibraryFunctions::memcpy(void* dest, const void* src, size_t count)
{
	if (nullptr == dest || nullptr == src) throw "Undefined";
	void* ret = dest;
	while (count--)
	{
		*(unsigned char*)dest = *(unsigned char*)src;
		dest = (unsigned char*)dest + 1;
		src  = (unsigned char*)src  + 1;
	}
	return ret;
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
	if (nullptr == dest || nullptr == src) throw "Undefined";
	void* ret = dest;
	if (dest <= src || dest >= ((unsigned char*)src + count))
	{
		// Non-Overlapping
		// copy from lower address to higher address
		while (count--)
		{
			*(unsigned char*)dest = *(unsigned char*)src;
			dest = (unsigned char*)dest + 1;
			src = (unsigned char*)src + 1;
		}
	}
	else
	{
		// Overlapping
		// copy from higher address to lower address
		dest = (unsigned char*)dest + count - 1;
		src  = (unsigned char*)src + count - 1;
		while (count--)
		{
			*(unsigned char*)dest = *(unsigned char*)src;
			dest = (unsigned char*)dest - 1;
			src = (unsigned char*)src - 1;
		}
	}
	return ret;
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
	if (lhs == nullptr || rhs == nullptr) throw "Undefined";
	int ret = 0;
	while (*rhs && !(ret = *(unsigned char*)lhs - *(unsigned char*)rhs))
	{
		++lhs, ++rhs;
	}
	if (ret < 0)
	{
		ret = -1;
	}
	else if (ret > 0)
	{
		ret = 1;
	}
	return(ret);
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
	if (lhs == nullptr || rhs == nullptr) throw "Undefined";
	int ret = 0;
	while (count-- && *rhs && !(ret = *(unsigned char*)lhs - *(unsigned char*)rhs))
	{
		++lhs, ++rhs;
	}
	if (ret < 0)
	{
		ret = -1;
	}
	else if (ret > 0)
	{
		ret = 1;
	}
	return(ret);
}

/*
Reinterprets the objects pointed to by lhs and rhs as arrays of unsigned char and compares the first count characters of these arrays.
The comparison is done lexicographically.
The sign of the result is the sign of the difference between the values of the first pair of bytes (both interpreted as unsigned char) that differ in the objects being compared.

Parameters
lhs, rhs - pointers to the memory buffers to compare
count    - number of bytes to examine

Return value
Negative value if the first differing byte (reinterpreted as unsigned char) in lhs is less than the corresponding byte in rhs.
0 if all count bytes of lhs and rhs are equal.
Positive value if the first differing byte in lhs is greater than the corresponding byte in rhs.

Notes
This function reads object representations, not the object values, and is typically meaningful for trivially-copyable objects only.
For example, memcmp() between two objects of type std::string or std::vector will not compare their contents. 
Even for POD types, if there are any padding bytes, their contents are indeterminate and may be surprising.
*/
int LibraryFunctions::memcmp(const void* lhs, const void* rhs, size_t count)
{
	if (lhs == nullptr || rhs == nullptr) throw "Undefined";
	int ret = 0;
	while (count-- &&  !(ret = *(unsigned char*)lhs - *(unsigned char*)rhs))
	{
		lhs = (char*)lhs + 1;
		rhs = (char*)rhs + 1;
	}
	if (ret < 0)
	{
		ret = -1;
	}
	else if (ret > 0)
	{
		ret = 1;
	}
	return(ret);
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
	if (str == nullptr) return nullptr;
	char c = (char)ch;
	while (*str != '\0' && *str != c)
	{
		str++;
	}
	const char* ret = (*str == c) ? str : nullptr;
	return ret;
}

/*
Finds the last occurrence of ch (after conversion to char) in the byte string pointed to by str.
The terminating null character is considered to be a part of the string and can be found if searching for '\0'.

Parameters
str - pointer to the null-terminated byte string to be analyzed
ch  - character to search for

Return value
Pointer to the found character in str, or null pointer if no such character is found.
*/
const char* LibraryFunctions::strrchr(const char* str, int ch)
{
	if (str == nullptr) return nullptr;
	const char* s = str;
	while (*s != '\0')
	{
		s++;
	}
	for (; *s != (char)ch; s--)
	{
		if (s == str) return nullptr;
	}
	return s;
}

/*
Finds the first occurrence of the byte string target in the byte string pointed to by str.
The terminating null characters are not compared.

Parameters
str    - pointer to the null-terminated byte string to examine
target - pointer to the null-terminated byte string to search for

Return value
Pointer to the first character of the found substring in str, or NULL if no such character is found.
If target points to an empty string, str is returned.
*/
const char* LibraryFunctions::strstr_(const char* str, const char* target)
{
	if (nullptr == str || nullptr == target) throw "Undefined";
	const char* ret = str;
	int len = strlen(target);
	for (; len && (str = strchr(str, *target)) != nullptr; str++)
	{
		if (strncmp(str, target, len) == 0) return str;
	}
	return ret;
}

const char* LibraryFunctions::strstr(const char* str, const char* target)
{
	if (nullptr == str || nullptr == target) throw "Undefined";
	for (; *str; str++)
	{
		const char *s, *t;
		s = str, t = target;
		// Matching process
		while (*s && *t && (*s == *t))
		{
			s++, t++;
		}
		// Found match
		if (*t == '\0')
		{
			return str;
		}
	}
	return nullptr;
}

/*
Scans the null-terminated byte string pointed to by dest for any character from the null-terminated byte string pointed to by breakset,
and returns a pointer to that character.

Parameters
dest     -	pointer to the null-terminated byte string to be analyzed
breakset -	pointer to the null-terminated byte string that contains the characters to search for

Return value
Pointer to the first character in dest, that is also in breakset, or null pointer if no such character exists.

Notes
The name stands for "string pointer break", because it returns a pointer to the first of the separator ("break") characters
*/
const char* LibraryFunctions::strpbrk(const char* dest, const char* breakset)
{
	if (nullptr == dest || nullptr == breakset) throw "Undefined";
	const char *d, *b;
	for (b = breakset; *b != '\0'; b++)
	{

		for (d = dest; *d != '\0'; d++)
		{
			if (*d == *b) return d;
		}
	}
	return nullptr;
}

/*
Returns the length of the maximum initial segment (span) of the byte string pointed to by dest,
that consists of only the characters found in byte string pointed to by accept.

Parameters
dest   - pointer to the null-terminated byte string to be analyzed
accept - pointer to the null-terminated byte string that contains the characters to search for

Return value
The length of the maximum initial segment that contains only characters from byte string pointed to by accept
*/
size_t LibraryFunctions::strspn(const char* dest, const char* accept)
{
	if (nullptr == dest || nullptr == accept) throw "Undefined";
	size_t ret = 0;
	for (; *dest != '\0'; dest++)
	{
		const char* a = accept;
		for (; *a != '\0'; a++)
		{
			if (*dest == *a)
			{
				++ret;
				break;
			}
		}
		if (*a == '\0') return ret;
	}
	return ret;
}

/*
Returns the length of the maximum initial segment of the byte string pointed to by dest,
that consists of only the characters not found in byte string pointed to by reject.
The function name stands for "complementary span"

Parameters
dest   - pointer to the null-terminated byte string to be analyzed
reject - pointer to the null-terminated byte string that contains the characters to search for

Return value
The length of the maximum initial segment that contains only characters not found in the byte string pointed to by reject
*/
size_t LibraryFunctions::strcspn(const char* dest, const char* reject)
{
	if (nullptr == dest || nullptr == reject) throw "Undefined";
	size_t ret = 0;
	for (; *dest != '\0'; dest++)
	{
		const char* r = reject;
		for (; *r != '\0'; r++)
		{
			if (*dest == *r)
			{
				return ret;
			}
		}
		if (*r == '\0') ++ret;
	}
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
	if (dest == nullptr || src == nullptr) throw "Undefined";
	char* cur = dest;
	while (*cur != '\0') ++cur;
	while (*src != '\0') *cur++ = *src++;
	*cur = '\0';
	return dest;
}

/*
Appends a byte string pointed to by src to a byte string pointed to by dest. 
At most count characters are copied. The resulting byte string is null-terminated.
The destination byte string must have enough space for the contents of both dest and src plus the terminating null character, 
except that the size of src is limited to count.
The behavior is undefined if the strings overlap.

Parameters
dest  -	pointer to the null-terminated byte string to append to
src   -	pointer to the null-terminated byte string to copy from
count -	maximum number of characters to copy

Return value
dest
*/
char* LibraryFunctions::strncat(char* dest, const char* src, size_t count)
{
	if (dest == nullptr || src == nullptr) throw "Undefined";
	char* cur = dest;
	while (*cur != '\0') ++cur;
	while (count-- && *src != '\0') *cur++ = *src++;
	*cur = '\0';
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
	if (str == nullptr) throw "Undefined";
	int len = 0;
	while (*str++ != '\0') ++len;
	return len;
}

/*
Converts the value ch to unsigned char and copies it into each of the first count characters of the object pointed to by dest. 
If the object is not trivially-copyable (e.g., scalar, array, or a C-compatible struct), the behavior is undefined. 
If count is greater than the size of the object pointed to by dest, the behavior is undefined.

Parameters
dest  - pointer to the object to fill
ch    - fill byte
count - number of bytes to fill

Return value
dest

Notes
std::memset may be optimized away (under the as-if rules) if the object modified by this function is not accessed again for the rest of its lifetime. For that reason, this function cannot be used to scrub memory (e.g. to fill an array that stored a password with zeroes).
*/
void* LibraryFunctions::memset(void* dest, int ch, size_t count)
{
	if (dest == nullptr) throw "Undefined";
	void * ret = dest;
	while (count--)
	{
		*(unsigned char *)dest = (unsigned char)ch;
		dest = (unsigned char *)dest + 1;
	}
	return(ret);
}
