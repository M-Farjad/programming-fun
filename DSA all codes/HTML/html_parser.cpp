// C program for the above approach

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// Function to parse the HTML code
void parser(char* S)
{
	// Store the length of the
	// input string
	int n = strlen(S);
	int start = 0, end = 0;
	int i, j;

	// Traverse the string
	for (i = 0; i < n; i++) {
		// If S[i] is '>', update
		// start to i+1 and break
		if (S[i] == '>') {
			start = i + 1;
			break;
		}
	}

	// Remove the blank spaces
	while (S[start] == ' ') {
		start++;
	}

	// Traverse the string
	for (i = start; i < n; i++) {
		// If S[i] is '<', update
		// end to i-1 and break
		if (S[i] == '<') {
			end = i - 1;
			break;
		}
	}

	// Print the characters in the
	// range [start, end]
	for (j = start; j <= end; j++) {
		printf("%c", S[j]);
	}

	printf("\n");
}

// Driver Code
int main()
{
	// Given Input
	char input1[] = "<h1>This is a statement</h1>";
	char input2[] = "<h1>		 This is a statement with some spaces</h1>";
	char input3[] = "<p> This is a statement with some @ #$ ., / special characters</p>		 ";

	printf("Parsed Statements:\n");

	// Function Call
	parser(input1);
	parser(input2);
	parser(input3);

	return 0;
}


// // C++ program for the
// // above approach
// #include <bits/stdc++.h>
// using namespace std;

// // Function to parse the
// // HTML code
// void parser(char* S)
// {
// 	// Store the length of the
// 	// input string
// 	int n = strlen(S);
// 	int start = 0, end = 0;

// 	// Traverse the string
// 	for (int i = 0; i < n; i++) {
// 		// If S[i] is '>', update
// 		// start to i+1 and break
// 		if (S[i] == '>') {
// 			start = i + 1;
// 			break;
// 		}
// 	}

// 	// Remove the blank space
// 	while (S[start] == ' ') {
// 		start++;
// 	}

// 	// Traverse the string
// 	for (int i = start; i < n; i++) {
// 		// If S[i] is '<', update
// 		// end to i-1 and break
// 		if (S[i] == '<') {
// 			end = i - 1;
// 			break;
// 		}
// 	}

// 	// Print the characters in the
// 	// range [start, end]
// 	for (int j = start; j <= end; j++) {
// 		cout << S[j];
// 	}

// 	cout << endl;
// }

// // Driver Code
// int main()
// {
// 	// Given Input
// 	char input1[] = "<h1>This is a statement</h1>";
// 	char input2[] = "<h1>		 This is a statement with some spaces</h1>";
// 	char input3[] = "<p> This is a statement with some @ #$ ., / special characters</p>		 ";

// 	cout << "Parsed Statements:\n";

// 	// Function Call
// 	parser(input1);
// 	parser(input2);
// 	parser(input3);
// 	return 0;
// }
