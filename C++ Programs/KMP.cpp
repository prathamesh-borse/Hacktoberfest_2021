#include <bits/stdc++.h>
using namespace std; 

void computing_lps_arr(char* pattrn, int M, int* lps) // Filling lps[] for given pattrn[0..M-1] 
{ 
	int len = 0; // length of the previous longest prefix suffix(lps)
	lps[0] = 0;  // lps[0] is always 0 
	
	int i = 1; 
	while (i < M)  // the loop calculates lps[i] for i = 1 to M-1 
	{ 
		if (pattrn[i] == pattrn[len]) 
		{ 
			len++; 
			lps[i] = len; 
			i++; 
		} 
		else // (pattrn[i] != pattrn[len]) 
		{  
			if (len != 0) 
			{ 
				len = lps[len - 1];  // keep in mind that we do not increment i here 
			} 
			else // if (len == 0) 
			{ 
				lps[i] = 0; 
				i++; 
			} 
		} 
	} 
} 

void kmp_algorithm(char* pattrn, char* str)  // Prints occurrences of pattrn[] in str[]
{ 
	int M = strlen(pattrn); 
	int N = strlen(str); 
	
	int lps[M]; // create lps[] that will hold the longest prefix suffix values for pattern
	
	computing_lps_arr(pattrn, M, lps);  // Preprocess the pattern (calculate lps[] array) 
	int i = 0;       // index for str[] 
	int j = 0;      // index for pattrn[] 
	while (i < N) 
	{ 
		if (pattrn[j] == str[i]) 
		{ 
			j++; 
			i++; 
		} 
		if (j == M) 
		{ 
			cout<<"\nPattern found at index "<<i-j<<endl;
			j = lps[j - 1]; 
		} 
		else if (i < N && pattrn[j] != str[i])   // mismatch after j matches
		{ 
			if (j != 0)  // Don't match lps[0..lps[j-1]] characters,they will match automatically 
				j = lps[j - 1]; 
			else
				i = i + 1; 
		} 
	} 
} 

int main() 
{ 
	char str[] = "banananobano"; 
	char pattrn[] = "nano"; 

	kmp_algorithm(pattrn, str); 

	return 0; 
} 
