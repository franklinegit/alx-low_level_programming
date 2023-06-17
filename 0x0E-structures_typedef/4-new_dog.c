#include <stdlib.h>
#include <stdio.h>
#include "dog.h"

char *_strcpy(char *dest, char *src);
int _strlen(char *str);

/**
 * new_dog - creates a new dog.
 * @name: dog's name
 * @age: dog's age
 * @owner: dog's owner
 * Return: Always (0)
 */

dog_t *new_dog(char *name, float age, char *owner)
{
	int len1, len2;
	dog_t *newdog;

	len1 = _strlen(name);
	len2 = _strlen(owner);
	newdog = malloc(sizeof(dog_t));
	if (newdog == NULL)
		return (NULL);
	newdog->name = malloc(sizeof(char) * (len1 + 1));
	if (newdog->name == NULL)
	{
		free(newdog);
		return (NULL);
	}
	newdog->owner = malloc(sizeof(char) * (len2 + 1));
	if (newdog->owner == NULL)
	{
		free(newdog->name);
		free(newdog);
		return (NULL);
	}
	_strcpy(newdog->name, name);
	_strcpy(newdog->owner, owner);
	newdog->age = age;
	return (newdog);
}

/**
 * _strlen - finds length of string
 * @str: string
 * Return: length of string
 */

int _strlen(char *str)
{
	int len = 0;

	while (str[len] != '\0')
		len++;
	return (len);
}

/**
 * _strcpy - copies string
 * @dest: destination buffer
 * @src: string to copy
 * Return: pointer to dest
 */

char *_strcpy(char *dest, char *src)
{
	int i, len;

	len = _strlen(src);
	for (i = 0; i < len; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}
