# CSV-Parser-using-C

The primary goal of this program is to read CSV data, align columns, and print the aligned data in a visually appealing tabular format. It aims to enhance the readability of the data when displayed on the console.
This C code reads data from a CSV file, processes the data, and then prints it out in a nicely formatted tabular structure. Here's a summary of what the code does:

1. Includes necessary header files: The code includes header files for standard input/output, string manipulation, and memory allocation.

2. Defines global variables: The code defines a global variable `col_length` to store the number of columns in the data.

3. Defines a function to get file size: The `get_file_size` function takes a file pointer as input and calculates the size of the file using the `fseek` and `ftell` functions.

4. Defines a function to get array size: The `get_arr_size` function takes a string (`buff`) and a delimiter string as input. It tokenizes the input string using the delimiter and returns the number of tokens (array size).

5. Defines a function to adjust array elements' length: The `make_arr_nice` function takes a 2D array of strings (`arr`), the number of rows (`row`), and the number of columns (`col`). It calculates the highest length among the strings in the array and pads the shorter strings with spaces to match the highest length.

6. `main` function: The main part of the code begins with opening a CSV file named "new_data.csv". It checks if the file was opened successfully and handles the error condition if it wasn't.

7. Reading and processing CSV data:
   - The code reads the contents of the file into a buffer, calculates the size of the buffer, and creates a copy of the buffer.
   - The data in the buffer is split into lines using the newline character ("\n"), and each line is stored in the `pointer` array.
   - The first line is used to determine the number of columns (`col_length`) and to parse the column names.
   - The data is then split into a 2D array of strings called `arr`.

8. Formatting the output:
   - The `make_arr_nice` function is called to adjust the lengths of the strings in `arr` to make them evenly aligned.
   - The processed data in `arr` is printed out in a tabular format with columns aligned.

9. Closing the file: The code closes the CSV file after processing.

10. Returning success: The `main` function returns 0 to indicate successful execution.

In summary, this code reads CSV data, processes it, and prints it out in a formatted way, ensuring that the columns are aligned neatly. It involves string manipulation, memory allocation, and file handling operations.

### Screenshots of the work
![image](https://github.com/ram-sapra/CSV-Parser-using-C/assets/143723327/e95b61a8-6c04-40f9-9bbe-f50cd03bdaf1)
![image](https://github.com/ram-sapra/CSV-Parser-using-C/assets/143723327/5eb99b36-47f3-4b90-b645-1382e01907cb)

