# ToDo List Application

This project is a simple console-based ToDo List application written in C++. It allows users to manage their tasks by adding new tasks, viewing all tasks, and marking tasks as completed.

## About the Project

- **Algorithm Author**: Padmaraj Nidagundi, Lecturer at RTU.
- **Implementation**: Developed by Ntoh Batex Bafika (myself) a student of RTU as part of the "Mini Project Using Algorithm to Code" assignment.

## Features

- **Add Task**: Add a new task with a name, due date, and status.
- **View Tasks**: Display all tasks with their details (task name, due date, and status).
- **Mark as Completed**: Update the status of a task to "Completed".
- **Default Due Date**: Automatically sets the due date to the current date if no due date is provided.

## How It Works

The application uses:
- **`std::vector`**: To store tasks as a collection of tuples.
- **`std::tuple`**: To represent each task with three attributes: task name, due date, and status.
- **`<chrono>`**: To fetch the current date for default due dates.

## Code Overview

### Class: `toDoList`

- **Attributes**:
  - `vector<tuple<string, string, string>> tasks`: Stores tasks with their details.
- **Methods**:
  - `add_task(string task, string dueDate, string status)`: Adds a new task to the list.
  - `display_all_Tasks()`: Returns a formatted string of all tasks.
  - `set_status(int index, string status)`: Updates the status of a task.
  - `get_default_due_date()`: Returns the current date in `YYYY-MM-DD` format.

### Main Function

- Displays a menu with options:
  1. Add a task.
  2. View all tasks.
  3. Mark a task as completed.
  4. Exit the application.

## How to Run

1. Clone or download the project files.
2. Open the project folder in your IDE (e.g., Visual Studio Code).
3. Compile the `ToDo.cpp` file using a C++ compiler. For example:
   ```bash
   g++ ToDo.cpp -o ToDo
   ```
4. Run the compiled program:
   ```bash
   ./ToDo
   ```

## Example Usage

### Adding a Task
```
Enter task name: Buy Groceries
Enter status (Pending/Completed): Pending
Enter due date (YYYY-MM-DD) or press Enter for default: 
```

### Viewing Tasks
```
1. Read Newspaper -> Due: 2025-05-08 -> Status: Pending
2. Solve Past Questions -> Due: 2025-05-09 -> Status: Pending
3. Go to the Gym -> Due: 2025-05-07 -> Status: Completed
4. Buy Groceries -> Due: 2025-05-07 -> Status: Pending
```

### Marking a Task as Completed
```
Enter the task number to mark as done: 1
Task marked as done!
```

## References

- [C++ Vectors](https://en.cppreference.com/w/cpp/container/vector)
- [Vector::push_back](https://cplusplus.com/reference/vector/vector/push_back/)
- [Set of Tuples in C++](https://www.geeksforgeeks.org/set-of-tuples-in-c-with-examples/)

## License

This project is licensed under the MIT License. Feel free to use and modify it as needed.