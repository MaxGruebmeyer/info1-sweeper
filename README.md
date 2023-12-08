# info1-sweeper

```DEADLINE: 31.01.2024```

Short summary: Lorem ispum dolor sed...

## Requirements

Since the core of the project is written in C89 only using the stdlibs, GCC is really all you need.
However, we have introduced several tools to make our life easier:

- Taskfile: Used by us for platform-independent builds. You can learn how to install Taskfile [here](https://taskfile.dev/installation/). We recommend the following options:
  - For Windows: Install it using [Chocolatey](https://chocolatey.org/) via `choco install go-task`
  - For Linux: Install it using [Brew](https://brew.sh/) via `brew install go-task`

## Building & running

### Building via Taskfile

The recommended way to build our project is via our project's [Taskfile](https://taskfile.dev/).
Just run `task build` to build src to `./bin`.
This also creates the executable `./bin/minesweeper.out`, which you can use to run the program.

Optionally you can pass the following parameters to `task build`:

- OUTPUT_FOLDER: The folder to build to. Falls back to the $OUTPUT_FOLDER environment variable or 'bin' if no environment variable is set.
- CFLAGS: The compiler flags to use. Falls back to the $CFLAGS environment variable or '-Wall -Wextra -ansi -pedantic' if no environment variable is set.

Provide them in the following way: `task build OUTPUT_FOLDER='my-output-folder' CFLAGS='-ansi'`

#### Open Taskfile Todos

- TODO (GM): Implement one overarching build task?
- TODO (GM): Implement & test Windows build
- TODO (GM): Find someone with a MacOs (Samu?) to test build-linux!
- TODO (GM): Implement a run task!

### Building via Bash Script

Alternatively, if you have access to Bash you can compile the whole project by running `./compile.sh` which also builds to `./bin`.
Afterwards execute `./bin/minesweeper.out` to run the program.

### Building by hand

If you do not want to use our Taskfile (or are on an unsupported OS) and do not have access to bash you will have to build everything by yourself with a C-Compiler of your choice.
If you're unsure how to do so a look into `compile.sh` might provide some guidance.

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
- Make a web interface without any additional libraries via the unistd socket api and text templating into an html document -> Needs own webserver and templating engine at least. Can one do it without JS? Make sure to limit potential attack vectors in the backend! -> Sanitize user input, as little memory allocation as possible (buffer overflow...), limit permissions and run everything in a docker container (without mounts and in a seperate network if possible)
- Host said web interface on AWS incl. automatic deployment on successful CI with terraform IaC
