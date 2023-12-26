# info1-sweeper

```DEADLINE: 31.01.2024```

Short summary: Lorem ispum dolor sed...

## Requirements

Since the core of the project is written in C89 only using the stdlibs, GCC is really all you need.
However, we have introduced several tools to make our life easier:

- Taskfile: Used by us for platform-independent builds. You can learn how to install Taskfile [here](https://taskfile.dev/installation/).
However, we recommend the following ways:
  - For Windows: Install it using [Chocolatey](https://chocolatey.org/) - everyone's favorite package manager for windows - via `choco install go-task`
  - For Linux/MacOS: Install it using [Brew](https://brew.sh/) via `brew install go-task`
- [Unity](https://www.throwtheswitch.org/unity): A lightweight unit tests framework for (embedded) C.
We included it via a submodule, just load it via `git submodule update --init` and you're good to go.

We feel these are perfectly fine choices since our core product is still pure C89 -
these tools just make our developer life a whole lot easier but you don't really need them to run & use our program: GCC is all you need!

## Building & running

### Building via Taskfile

The recommended way to build our project on Windows or Linux is via our project's [Taskfile](https://taskfile.dev/).
Then you can build and run the project with a single command - `task run`.

Alternatively, if you just want to build the project you can run `task build` to build the sourcecode to `./bin`.
This also creates the executable `./bin/minesweeper.out`, which you can use to run the program.

Optionally you can pass the following parameters to `task build` or `task run`:

- `OUTPUT_FOLDER`: The folder to build to. Falls back to the `$OUTPUT_FOLDER` environment variable or `bin` if no environment variable is set.
Note that this cannot handle folders containing spaces!
- `CFLAGS`: The compiler flags to use. Falls back to the `$CFLAGS` environment variable or `-Wall -Wextra -Werror -ansi -pedantic` if no environment variable is set.

Provide them in the following way: `task run OUTPUT_FOLDER='my-output-folder' CFLAGS='-ansi'`

Note that running `task build/run` under windows requires Git Bash since we need some of the cli tools installed with it (e.g. sed, find, xargs).
Since time was of the essence we opted to reuse the `build-shell` task instead of writing a new build task for windows in CMD/Powershell.
However, even though the current version requires Git Bash the task works on Git Bash, PowerShell, as well as CMD.

### Building via Script

Alternatively, if you have access to Bash you can compile the whole project by running `./compile.sh` which also builds to `./bin`.
Afterwards execute `./bin/minesweeper.out` to run the program.

There is also a build script for powershell - `compile.ps1` - but that leverages Taskfile and Git Bash,
so if you don't have both of these installed, this won't work for you.
And if you do... why not just use our Taskfile?

### Building by hand

If you do not want to use our Taskfile (or are on an unsupported OS) and do not have access to bash you will have to build everything by yourself with a C-Compiler of your choice.
If you're unsure how to do so a look into `compile.sh` might provide some guidance.

## Testing

Even though the requirement was that the whole project had to be written in C89 without any external libraries
we still opted to include a unit test framework: [Unity](https://www.throwtheswitch.org/unity).

We feel this is a fair judgement since the unit tests and therefore Unity are not required
to run the whole project and were no requirement in the first place - they are just here to help with the quality of our "product".

We opted to use Unity instead of other options, e.g. gtest, because it's written in C and not in C++
and therefore does not introduce any more unneccessary dependencies (e.g. g++).
Furthermore it is a fairly minimal and lightweight tool that can easily be embedded as a `git submodule`.
The fact that we included the whole project in this repo as a submodule means that everyone that has
access to this repo can run the tests without needing to install any more libraries.

Since it's included as a submodule you need to load the submodule via `git submodule update --init` before executing the tests for the first time.
You only need to do this once, afterwards the submodule is stored locally.
Not loading the submodule beforehand will result in missing files and test compilation will fail!

You can use any of the following ways to run the tests:

- Use `task test` (recommended)
- Use either of `util/run-tests.sh` or `util/run-tests.ps1`
- Manually compile and run each test file seperately (each file contains a main function)

## Github Actions

Since we are a fan of automated testing and want to confidently support a wide variety of operating systems we implemented
the following two hooks on Ubuntu, Windows, as well as MacOS runners:

- compile-check: Leverages `task build` to verify that the program can be built without errors on the target platform
- run-unit-tests: Leverages `task test` to verify all tests pass on the target platform

All of these are push hooks which means they run on every push to the remote repository - it doesn't matter which branch.

As all github actions, you can find the .yml files under `.github/workflows`.

## Architecture choices

Describe some choices you made along the way here:

- Detail on why you stuff everything in one bit in mines.c -> Tradeoffs? Maybe run a perftest incl. memory profiler?

## Open Todos

- TODO (GM): Adjust build scripts and Taskfile so it goes down multiple layers into src (if required)
- TODO: If you're feeling fancy implement a PS-only version of compile.ps1 and use it in build-windows instead of the current version.
