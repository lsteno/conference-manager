# conference-manager
# Conference Scheduling Program

## Overview
This program manages and validates a conference schedule by reading a list of articles and presenters, checking scheduling constraints, and verifying that all articles are assigned correctly. It ensures that presenters are not double-booked and that each article receives the appropriate number of slots.

## Features
- Reads a list of articles from a file.
- Reads a proposed conference schedule from a file.
- Validates the schedule based on predefined constraints.
- Prints errors if scheduling conflicts are found.
- Outputs the schedule and validation results.

## File Structure
```
|-- articolo.h
|-- programma.h
|-- articolo.c
|-- programma.c
|-- main.c
|-- articoli.txt
|-- README.md
```

## Compilation & Execution
### Compilation
To compile the program, use a C compiler like `gcc`:
```sh
gcc -o scheduler main.c articolo.c programma.c -Wall -Wextra
```

### Execution
Run the program:
```sh
./scheduler
```
The program will prompt for an input file containing the schedule and validate it.

## Input File Format
### `articoli.txt`
This file contains a list of articles with the following format:
```
<number_of_articles>
<title> <presenter> <slots> <topic>
...
```
Example:
```
3
AI_Research John_Doe 2 Machine_Learning
Blockchain_Market Alice_Smith 1 Cryptography
Quantum_Computing Bob_Lee 3 Physics
```

### Conference Schedule File
This file contains the proposed schedule format:
```
<number_of_rows> <number_of_columns>
<article_title_or_0> <article_title_or_0> ...
...
```
Example:
```
3 3
AI_Research 0 Blockchain_Market
AI_Research Quantum_Computing 0
0 Quantum_Computing Quantum_Computing
```

## Functionality
### Article Management (`articolo.c`)
- **`ARTICOLIread(FILE *in)`**: Reads articles from a file.
- **`ARTICOLIprint(ARTICOLI a, FILE *out)`**: Prints the list of articles.
- **`ARTICOLOinit(char titolo[], char relatore[], int slot, char argomento[])`**: Initializes a new article.
- **`ARTICOLOread(FILE *in)`**: Reads a single article.
- **`ARTICOLOprint(ARTICOLO item, FILE *out)`**: Prints a single article.

### Schedule Management (`programma.c`)
- **`PROGRAMMA getsol(FILE *in)`**: Reads the conference schedule from a file.
- **`PROGRAMMAprint(PROGRAMMA p, FILE *out)`**: Prints the schedule.
- **`checkprogramma(PROGRAMMA sol, ARTICOLI a)`**: Checks for scheduling conflicts.

### Main Execution (`main.c`)
- Reads `articoli.txt`.
- Prompts the user for a schedule file.
- Reads the schedule file and prints it.
- Calls `checkprogramma()` to validate the schedule.

## Constraints & Validation Rules
- Each article must receive the exact number of slots it requires.
- A presenter cannot be scheduled in two rooms simultaneously.
- Every article must be scheduled exactly once.

## Example Run
```
$ ./scheduler
Inserire il nome del file di input della soluzione: schedule.txt
Soluzione proposta valida
```
Or, in case of errors:
```
Il relatore John_Doe dovrebbe presentare in due sale contemporaneamente
Soluzione proposta non valida
```

## Notes
- This implementation uses dynamic memory allocation.
- Ensure input files are formatted correctly.
- The program assumes `MAXC` is defined in `programma.h` and `articolo.h`.

## Authors
Developed by [Your Name].

