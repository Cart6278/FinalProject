# FinalProject - CS 162 C++

This is the final project for CS162 that incorperates what we have learned over the course of the term into a game. The program is coded in C++. This game is called "Free Buckbeak" and is based on the final act of the third Harry Potter book "Harry Potter and the Prisoner of Azkaban". It is text based, with the user given prompts and discriptions of where they are currently located, inventory, steps to completion, and other stats. 

The user at the beginning of the game chooses either to play as Harry Potter or Hermione Granger and then the game starts in the Hospital Wing after the two go back in time. The user then has 15 steps to get from the Hospital Wing to the Pumpkin Patch to save Buckbeak from exicution and take him to the Forbidden Forest. Moving between areas counts as a step. Additonally searching the room for "dead ferrets" costs another step. Collecting "dead ferrets" increases the odds of successfully convincing Buckbeak to fallow you to the Forbidden Forest. The user must also be careful to not be caught by other Professors, Draco Malfoy, or Filtch the caretaker. Being caught by either a Professor or Filtch results in losing the game. If you are seen by Draco you must fight him to move forward. Fighting Draco costs an extra step.

Included is a Makefile to ease compiling. 

Two known issues being worked on:

1)Step counter may not end the game correctly - Currently testing fix (Aug 2020)

2)Validation loop in unknown place. Feedback was given on the assignment that the program entered a validation loop. Feedback did not state where the loop occurred, still searching.
