	Student Information
=============================
Name: Arvids Jakobsons
Student ID: 0953757
Assignment #3 'Spell Checker'


	Program Information
==============================
Program takes in a file from the start of the program as its "Dictionary". Then you have options you can do from the menu, they are add a word to dictionary, remove a word, spell check another FILE to the dictionary, print out your Hash Table and quit the program. Everything works accordingly and there is also a test main provided to check the functions further to make sure they work properly.

		HASH FUNCTION
==============================
In my program Most of my hashing is done by taking my values as ASCII amounts, this is done in myFunctions HashFunction. Also to prevent multiple of the same words from being entered, I replace them with an * and compare that with the word im trying to enter. To further check my collision i use my lookupData in my remove word to make sure the word exists before continuing. For importing files to my Hash Table I make sure that the words are put to lower case when hashing to make my collision easier.

		Assumptions
==============================
-number of words dont exceed 200.
-the words arent affected by upper and lower case (Hello is the same as hello).
-the user will never enter * as a word.
-key is a char*
