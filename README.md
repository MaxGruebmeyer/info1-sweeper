# info1-sweeper
**DEADLINE: 31.01.2024**

Short summary: Lorem ispum dolor sed...

## Architecture choices
Describe some choices you made along the way here

## Dependencies
Deps needed for building, testing and running go here!

## TODO
- Add build tool (make? ninja? cmake? taskfile? custom?)
- Also add short custom script that compiles all files via `gcc -Wall -Wextra -ansi -pedantic` and spits out an executable so the tutors are happy :)
- Add GitHub build pipeline for branches (pull requests, master pushes) incl. build, running tests and Discord Hook for notifications
- Add unit tests with gtest (googletest) - Needs C++ Compiler? If so -> Dependencies

### Features
- Make minesweeper field non-quadratic
- Allow configuration of field size via cmd args but limit it to 80x24 characters (and therefore a smaller or equal field?) -> Do we need additional chars, e.g. like in chess? Then the board would have to be smaller still!
- First field clicked should never return an explosive(?)
- Additional features as specified in the exercise

### Optional features for later
- Give the user an additional life, if he solves a floating point number conversion -> Needs floating point conversion tool!
- Make a web interface without any additional libraries via the unistd socket api and text templating into an html document
- Host said web interface on AWS incl. automatic deployment on successful CI with terraform IaC
