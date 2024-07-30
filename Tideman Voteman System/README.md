# Project: Tideman Voting System

The Tideman Voting System project is a C program that implements the Tideman election method, also known as the ranked pairs method. This program is designed to manage ranked voting and determine the winner based on voters’ preferences. It showcases my ability to handle complex data structures, sorting algorithms, and recursive functions in C.

- **Project Description**

    The Tideman Voting System project handles the following tasks:

	- Ranked Voting Input: Accepts ranked votes from multiple voters, where each voter ranks candidates in order of preference.
	- Preference Recording: Records the number of voters who prefer one candidate over another.
	- Pair Creation: Identifies pairs of candidates where one is preferred over the other and records these pairs.
	- Pair Sorting: Sorts the pairs in decreasing order by the strength of victory.
	- Cycle Detection and Locking: Locks pairs into a directed graph in order, ensuring no cycles are formed, to determine the candidate graph.
	- Winner Determination: Determines and prints the winner of the election based on the locked graph.


- **Features:**

	- Preference Matrix: Utilizes a 2D array to record preferences between candidates.
	- Linked List for Pairs: Uses a struct to store pairs of candidates and dynamically creates an array of these pairs.
    - Cycle Detection: Implements a recursive function to check for cycles in the candidate graph to maintain the validity of the election.
	- Sorting Algorithm: Includes a sorting mechanism to order pairs by the strength of their victory.
	- User Input Handling: Efficiently manages and validates user inputs for ranked voting.

This project demonstrates my proficiency in handling arrays, linked lists, recursion, and sorting algorithms in C. It also highlights my capability to implement complex algorithms and ensure data integrity through cycle detection and graph management.