/*
 *	
 *  Created on: Dec 5, 2021
 *      Author: Selin Turan
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
void toUpper(char src[], char dest[]);
char findMax(char *s);
char findMin(char *s);
void crypto(char src[], char dest[], int key);
#define LEN 22

void main() {

	char src[LEN], dest[LEN], destPass[LEN];
	printf("Enter the character string for encryption: \n");
	fflush(stdout);
	gets(src);
	printf("Entered character string: %s\n", src);


	toUpper(src, dest);
	printf("Capitalized character string: %s\n", dest);

	char max = findMax(dest);
	char min = findMin(dest);
	printf("Character with maximum ASCII value: %c (%d)\n", max, max);
	printf("Character with minimum ASCII value: %c (%d)\n", min, min);

	// The key
	int passKey = max - min;
	printf("Encryption key: %d\n", passKey);

	crypto(dest, destPass, passKey);
	printf("Encrypted character string: %s\n", destPass);

}

// Capitalizes the string
void toUpper(char src[], char dest[]) {
	int i;
	while (src[i] != '\0') {
		if (src[i] >= 'a' && src[i] <= 'z') {
			src[i] = src[i] - 32;
		}
		i++;
	}
	strcpy(dest, src);
}

// Finds the character with the highest ASCII value
char findMax(char *s) {
	int i = 0;
	char max = ' ';
	while (s[i] != '\0') {
		// We work with a predetermined input length, which we've defined above but we can use non-determined input length and utilize strlen() to find it. 
		if (s[i] >= 'A' && s[i] <= 'Z') {
			if (s[i] > max) {
				max = s[i];
			}
		}
		i++;
	}
	return max;
}

// Finds the character with the lowest ASCII value
char findMin(char *s) {
	int i = 0;
	char min = '~';
	while (s[i] != '\0') {
	// Same note as above
		if (s[i] >= 'A' && s[i] <= 'Z') {
			if (s[i] < min) {
				min = s[i];
			}
		}
		i++;
	}
	return min;
}

// Encrypts the string
void crypto(char src[], char dest[], int key) {
	toUpper(src, dest);
	int i;
	while (dest[i] != '\0') {
	// Same note as above
		if (isalnum(dest[i])) {
			dest[i] = dest[i] + key;
		}
		i++;
	}
}
