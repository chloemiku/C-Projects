# C Projects Portfolio

Welcome to my C Projects Portfolio! This repository contains a collection of C programming projects that I have worked on. Each project demonstrates my skills and understanding of various concepts in C programming.

## Table of Contents

- [Introduction](#introduction)
- [Projects](#projects)
  - [Project 1: Blood Type Inheritance Simulation](#project-1-blood-type-inheritance-simulation)
  - [Project 2: Spell Checker](#project-2-spell-checker)
  - [Project 3: JPEG Image Recovery](#project-3-jpeg-image-recovery)
  - [Project 4: Tideman Voteman System](#project-4-tideman-voteman-system)

## Introduction

This repository showcases various C projects that I have completed as part of my learning journey and personal interest in programming. Each project is well-documented and includes a README file explaining the purpose, usage, and features of the project. These projects highlight my ability to write clean, efficient, and well-structured code.

## Projects

### Project 1: Blood Type Inheritance Simulation
This project simulates the genetic inheritance of blood type alleles over multiple generations. It demonstrates my understanding of structs, dynamic memory allocation, and recursion in C.

- **Keywords:**
  - Recursion
  - Linked List
  - Memory Allocation

- **Features**:
  - Simulate inheritance of blood types through multiple generations.
  - Use structs to represent individuals with parents and alleles.
  - Randomly assign alleles to individuals.
  - Print the family tree showing blood types of each member.


### Project 2: Spell Checker
This project performs spell check to .txt file after loading a dictionary of words from disk into memory. In this project, I implemented a dictionary's functionality using a hash table. The program checks if a word is in the dictionary, loads words into the dictionary from a file, and unloads the dictionary from memory.

- **Keywords:**
  - Hash Table
  - Linked List
  - Memory Allocation

- **Features**:
  - Implement a hash table to store words.
  - Check for the existence of a word in the dictionary.
  - Load words from a dictionary file into the hash table.
  - Unload the dictionary from memory, ensuring no memory leaks.


 ### Project 3: JPEG Image Recovery
The JPEG Recovery program is designed to search through a raw memory card file to find and recover JPEG images. The program reads the memory card file in 512-byte blocks and identifies the start of JPEG files by checking for specific header patterns. Once a new JPEG is found, it creates a new file and continues to write the subsequent blocks until the next JPEG header is detected.

- **Keywords:**
  - File Handling
  - Memory Management
  - Error Handling

- **Features**:
  - Handle file by opening memory card file and reads content in fixed-size blocks.
  - Identifies beginning of new JPEG file.
  - Manages buffer operations to ensure smooth file reading and writing.
  - Basic error handling for file operations.

 
### Project 4: Tideman Voteman System
The Tideman Voting System project is a C program that implements the Tideman election method, also known as the ranked pairs method. This program is designed to manage ranked voting and determine the winner based on voters’ preferences. It showcases my ability to handle complex data structures, sorting algorithms, and recursive functions in C.

- **Keywords:**
  - Recursion
  - Linked List
  - Sorting Algorithm

- **Description**

  The Tideman Voting System project handles the following tasks:

  - Ranked Voting Input: Accepts ranked votes from multiple voters, where each voter ranks candidates in order of preference.
  - Preference Recording: Records the number of voters who prefer one candidate over another.
  - Pair Creation: Identifies pairs of candidates where one is preferred over the other and records these pairs.
  - Pair Sorting: Sorts the pairs in decreasing order by the strength of victory.
  - Cycle Detection and Locking: Locks pairs into a directed graph in order, ensuring no cycles are formed, to determine the candidate graph.
  - Winner Determination: Determines and prints the winner of the election based on the locked graph.

- **Features**:
  - Utilizes a 2D array to record preferences between candidates.
  - Uses a struct to store pairs of candidates and dynamically creates an array of these pairs.
  - Implements a recursive function to check for cycles in the candidate graph to maintain the validity of the election.
  - Includes a sorting mechanism to order pairs by the strength of their victory.
  - Efficiently manages and validates user inputs for ranked voting.
