#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert Decimal to Hex
char* convertToHex(int num)
{
	char* temp = (char*)malloc(
		sizeof(char)
		* 10); // Allocate memory for temp string

	int i = 0;
	while (num != 0) {
		int rem = num % 16;
		char c;
		if (rem < 10) {
			c = rem + 48;
		}
		else {
			c = rem + 87;
		}
		temp[i++] = c;
		num = num / 16;
	}

	if (i == 0) // if input number is 0, return "0"
	{
		temp[i++] = '0';
	}
	temp[i] = '\0';

	// Reverse the obtained hexadecimal number
	int j, k = strlen(temp) - 1;
	for (j = 0; j < k; j++, k--) {
		char t = temp[j];
		temp[j] = temp[k];
		temp[k] = t;
	}

	return temp;
}

// Function to encrypt the string
char* encryptString(char* S, int N)
{

	char* ans = (char*)malloc(
		sizeof(char)
		* (N * 3)); // Allocate memory for ans string
	ans[0] = '\0'; // Initialize ans string to empty string

	// Iterate the characters of the string
	for (int i = 0; i < N; i++) {

		char ch = S[i];
		int count = 0;
		char* hex;

		// Iterate until S[i] is equal to ch
		while (i < N && S[i] == ch) {

			// Update count and i
			count++;
			i++;
		}

		// Decrement i by 1
		i--;

		// Convert count to hexadecimal representation
		hex = convertToHex(count);

		// Append the character
		int len = strlen(ans);
		ans[len++] = ch;
		ans[len] = '\0';

		// Append the characters frequency in hexadecimal
		// representation
		strcat(ans, hex);
	}

	// Reverse the obtained answer
	int i, j, k = strlen(ans) - 1;
	for (i = 0, j = k; i < j; i++, j--) {
		char t = ans[i];
		ans[i] = ans[j];
		ans[j] = t;
	}

	// Return required answer
	return ans;
}

// Driver Code
int main()
{

	// Given Input
	char S[] = "abc";
	int N = strlen(S);

	// Function Call
	char* result = encryptString(S, N);
	printf("%s", result);

	return 0;
}
