# Number Guessing Game

A fun command-line game built in C where you need to guess the number.

## Features
- 3 difficulty levels to choose from:
    - `Easy` - guess a number between 1-50 within 10 attempts
    - `Medium` - guess a number between 1-200 within 7 attempts
    - `Hard` - guess a number between 1-500 within 5 attempts
- Hints provided after each wrong guess to help narrow down the number
- If unable to guess within the allowed attempts, the user loses the round
- The user chooses the level for each round and can play any number of times
- A game recap (rounds played, won, lost) is displayed when the user exits

## Tech Stack
- Language: C

## How to Run
```bash
gcc main.c -o number_guessing_game
./number_guessing_game
```

## Usage
1. Choose a level (Easy/Medium/Hard)
2. Start guessing the number — hints are provided after each guess
3. Choose to play another round or exit after each round ends

## How It Works
- A random number is generated using `rand()`, seeded with `srand(time(NULL))` so it's different each run
- The difference between the guess and the actual number is converted to a percentage to decide which hint to show (e.g. "extremely close," "getting warmer")
- The game keeps track of the total number of rounds played, wins, and losses after each round

## Output
- The hints are displayed after each wrong guess
- When the user exits, the game recap is displayed
- All output is displayed directly in the terminal 

## What I Learned
- Using `rand()` and `srand(time(NULL))` to generate random numbers
- Calculating the difference to show the appropriate hint
