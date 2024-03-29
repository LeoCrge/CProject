**Project Readme**

**Project Name:** CDataframe - Implementation of a Double-Linked List in C

**Team Members:**
- [Insert Team Member 1 Name]
- [Insert Team Member 2 Name]

**Project Description:**
The CDataframe project aims to implement a double-linked list in C language, specifically designed for storing integer data in columns. Each column consists of a title and an array of integers. This structure allows for efficient storage, retrieval, addition, deletion, and movement of columns or rows within the dataframe.

**Project Organization:**
- The project is to be carried out in pairs, with the possibility of one team of three if necessary.
- Teams must be finalized and submitted to teachers by the end of the first project follow-up session.
- Two deposits are required: an intermediate repository containing the project skeleton (.h files), and a final repository containing the entire project before the defense.
- Key dates:
  - Project publication date: Week of 25/03/2024
  - Intermediate deposit date: 04/21/2024 at 23:59
  - Final deposit date: 19/05/2024 at 23:59
  - Defense date: Week of 20/05/2024

**Project Components:**
1. **Double-Linked List Implementation:** Implementation of a double-linked list structure.
2. **CDataframe:** Implementation of a structure for storing integer data in columns.

**CDataframe Components:**

**Part I: CDataframe of Integers**

**4. CDataframe:**
The CDataframe aims to store data in columns, each consisting of a title and an array of integer data. This structure is designed to be both robust and flexible, allowing for easy addition, deletion, or movement of columns or rows.

**4.1. Columns:**
- Each column contains a title (string) and integer-type data.
- For fast access to data, arrays are used. Dynamic memory allocation is utilized to manage data size.
- When the logical size reaches the maximum allocated cells, reallocation is triggered to allocate additional space.

**4.1.1. Create a Column:**
- Dynamically creates an empty column from a given title.
- Initializes the array pointer to NULL.
- Returns a pointer to the created column.

**4.1.2. Inserting a Value in a Column:**
- Inserts a value into a column, triggering reallocation if necessary.
- Returns 1 if the value is successfully added, otherwise 0.

**4.1.3. Free Memory Allocated by a Column:**
- Frees memory allocated to the column and its data array.

**4.1.4. Display the Column Content:**
- Prints the content of a column, displaying row numbers and corresponding values.

**Project Submission:**
- Final delivery is done on Moodle in the form of a .zip archive containing:
  - Project code with all .h and .c files.
  - README.txt file listing programs and usage instructions.

**Assessment:**
- Detailed grading scale will be provided later.
- Final project grade comprises code grade and defense grade.
- Project grade contributes 20% to the "Algorithms and Data Structures 1" course grade.

**Note:** Ensure proper memory management and error handling in all functions for robustness and reliability.

For further inquiries or assistance, please contact the project team members.
