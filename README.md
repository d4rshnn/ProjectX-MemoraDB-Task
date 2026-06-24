# MemoraDB Task

This repository contains my solution for the MemoraDB Project X task.

## Problem Statement

We need to store LeetCode submissions of students in an append-only manner and support the following operations:

1. Add a new submission.
2. Get the latest submission of a student in O(1) time.
3. Traverse a student's submission history from latest to oldest.
4. Find the latest submission before a given date.

The implementation follows the task constraints:

* C++
* No STL
* Simple comments
* Append-only submission history

---

## Project Structure

```text
MemoraDB_Task/
│
├── main.cpp
├── student.cpp
├── student.h
└── README.md
```

* `main.cpp` : Menu-driven interface and program execution.
* `student.h` : Structures and function declarations.
* `student.cpp` : Submission storage and query logic.
* `README.md` : Project documentation.

---

## Approach

Each student stores a pointer to their latest submission.

Each submission stores:

* Problem Name
* Submission Date
* Pointer to Previous Submission

This creates a linked list of submissions for every student.

Example:

```text
Latest
  |
  v
HashMap (26062026)
  |
  v
BinarySearch (25062026)
  |
  v
TwoSum (24062026)
  |
 NULL
```

This allows:

* O(1) latest submission lookup
* Easy history traversal
* Preservation of old submissions

---

## Features

* Add a new submission
* View latest submission
* View complete submission history
* Find latest submission before a given date

---

## Compilation

Open terminal inside the project folder and run:

```bash
g++ main.cpp student.cpp -o memoradb
```
```bash
memoradb
```

---

## Running the Program

Windows:

```bash
.\memoradb.exe
```

Linux/macOS:

```bash
./memoradb
```

---

## Sample Menu

```text
===== MemoraDB Task =====

1. Add Submission
2. Get Latest Submission
3. Show Submission History
4. Find Latest Submission Before Date
5. Exit
```

---

## Concepts Used

* Structures
* Pointers
* Linked Lists
* Dynamic Memory Allocation
* Append-Only Storage

---

## Author

Darshan Mahale

Project X 2026 – MemoraDB Task
