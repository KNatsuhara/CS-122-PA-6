#pragma once

#include "header.h"
#include "Pre-Header.h"

/**********************************************************
Programmer: Koji Natsuhara
Class: CptS 122, Spring 2020, Lab Section 3
Programming Assignment: Programming Assignment 6: Morse Code Lookup BST
Date: April 8, 2020
Description: This program will create a Binary Searchy Tree which contains nodes of with 
character data and string data. The character will be an alpahabetical letter or number and have
the corresponding morse string contained along with it. This assingment will require us to 
use the BST to convert English characters to morse code.
**********************************************************/

int main()
{
	BSTNode morse; //Constructs the Morse tree

	morse.displayInOrder(); //Prints the tree from left to right
	
	morse.convertString(); //Converts the convert.txt file'

	return 0;
}