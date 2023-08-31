#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>

int col_length;

// function to get the file size
int get_file_size(FILE *file_pointer) // takes file as input
{
	// checks if the pointer is not at end
	if (fseek(file_pointer, 0L, SEEK_END) == 0)
	{
		int size = ftell(file_pointer);
		return size;
	}
	else
		return -1;
}

// padding the string with space
int get_arr_size(char buff[], char *delim)
{
	char *token = strtok(buff, delim);
	int i = 0;

	while (token != NULL)
	{
		i++;
		token = strtok(NULL, delim);
	}

	return i;
}

// set background color
void SetBackgroundColor(int BackC)
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	WORD wColor = ((BackC & 0x0F) << 4) + (csbi.wAttributes & 0x0F);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
	return;
}

void make_arr_nice(char *arr[][col_length], int row, int col)
{
	int highest_length = 0;

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (highest_length < strlen(arr[i][j]))
				highest_length = strlen(arr[i][j]);
		}
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			int current_length = (int)strlen(arr[i][j]);
			int padding = highest_length - current_length;
			if (current_length < highest_length)
			{
				char *temp_string = (char *)malloc((highest_length + 1) * sizeof(char *));
				strcpy(temp_string, arr[i][j]);
				for (int len = 0; len < padding; len++)
				{
					strcat(temp_string, " ");
				}
				arr[i][j] = temp_string;
			}
		}
	}
}

int main(void)
{
	const char *file_name = "new_data.csv";

	FILE *file = fopen(file_name, "r");

	// check if file is loaded successfully
	if (file == NULL)
	{
		printf("Unable to get file...\n");
		return 1;
	}

	// get file size
	int BUF_SIZE = get_file_size(file);

	char buffer[BUF_SIZE];

	// go to the beginning of file
	fseek(file, 0L, SEEK_SET);

	size_t newLen = fread(buffer, sizeof(char), BUF_SIZE, file);

	char buf2[BUF_SIZE];

	for (int i = 0; i < BUF_SIZE; i++)
	{
		buf2[i] = buffer[i];
	}

	const int row_length = get_arr_size(buf2, "\n");

	char *pointer[row_length];
	int i = 0;

	char *token = strtok(buffer, "\n");
	while (token != NULL)
	{
		pointer[i] = token;
		token = strtok(NULL, "\n");
		i++;
	}

	char temp[100] = {};
	strcpy(temp, pointer[0]);

	col_length = get_arr_size(pointer[0], ",");
	strcpy(pointer[0], temp);

	// pointer[0] = temp;

	char *arr[row_length][col_length];

	for (int p = 0; p < row_length; p++)
	{
		int j = 0;
		char *token1 = strtok(pointer[p], ",");
		while (token1 != NULL)
		{
			if (j < col_length)
			{
				arr[p][j] = token1;
				token1 = strtok(NULL, ",");
				++j;
			}
		}
	}

	// excluding spacing (making it nicer)
	make_arr_nice(arr, row_length, col_length);

	// prints the array
	for (int i = 0; i < row_length; i++)
	{
		for (int j = 0; j < col_length; j++)
		{
			printf("%s\t", arr[i][j]);
		}
		printf("\n");
	}

	fclose(file);

	return 0;
}