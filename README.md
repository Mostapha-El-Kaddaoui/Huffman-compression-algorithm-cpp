# Huffman Encoding Program

## Overview

This program implements Huffman encoding and decoding in C++. Huffman encoding is a lossless data compression algorithm that assigns variable-length codes to input characters, with shorter codes assigned to more frequent characters. This program reads text from a file, compresses it using Huffman encoding, and then decodes the compressed text back to its original form.

## Features

- **Huffman Encoding:** Compresses the input text using Huffman coding.
- **Huffman Decoding:** Decodes the compressed text back to its original form.
- **File Input/Output:** Reads input text from a file and writes the compressed and decompressed text to an output file.

## Class Structure

### `noeud`

Represents a node in the Huffman tree. Each node contains:
- `caract`: The character or combined characters.
- `occ`: The frequency of the character(s).
- `bit`: The Huffman bit (0 or 1).
- `next_ptr`: Pointer to the next node in the list.
- `parent_noeud`: Pointer to the parent node in the Huffman tree.

### `Huffman`

Manages the Huffman tree and encoding/decoding process. Contains:
- `head`: Pointer to the head of the list of nodes.
- `append(string caract, int occ)`: Adds a new node to the list.
- `trace()`: Prints the characters and their frequencies.
- `trace_g()`: Generates the Huffman codes for each character.
- `two_min()`: Finds the two nodes with the smallest frequencies and combines them into a new node.

## Functions

### `ex_in_arr(char find_c)`

Checks if a character is already in the `arr_occ` array.

### `enc_r(string s)`

Encodes the input string `s` using Huffman coding. Returns the encoded string.

### `dec_r(string coded_s, string filename)`

Decodes the Huffman encoded string `coded_s` and writes the decoded text to the specified output file.

## Usage
### Input

The program will prompt you for the input file name containing the text to be compressed and the output file name for the compressed text. Ensure the input file exists in the same directory as the executable or provide the full path.

### Compilation

To compile the program, use the following command:

## bash
g++ -o huffman huffman.cpp
./huffman

## Programer

### EL KADDAOUI MOSTAFA


