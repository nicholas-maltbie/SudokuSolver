/*
 *  Sudoku Nick, solves the sudoku puzzle but better.
 *  
 *  ---- ---9 8765 4321
 *  0000 0000 0000 0000 = {}
 *
 *  0000 0001 0011 0001 = {9,6,5,1}
 *
 */
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

bool readBit ()

short (* readPuzzle())[9]{
	char filename[100];
	ifstream infile;
	string line;

	cout << "Please enter a Sudoku puzzle file name: ";
	cin >> filename;
	infile.open( filename );
	if (!infile){
		cerr << filename << " could not be opened " << endl;
		exit(1);
	}
	short (*matrix)[9] = new short[9][9];
	for (int i = 0; i < 9; i++){
		getline(infile, line);
		for (int j = 0; j < 9; j++){
			char c = line[j * 2];
			if (c == 'x')
				for (int k = 0; k < 9; k++) matrix[i][j][k] = 1;
			else{
				int l = c - '1';
				for (int k = 0; k < 9; k++) matrix[i][j][k] = 0;
				matrix[i][j][l] = 1;
			}
		}
	}
	infile.close();
	return matrix;

 
