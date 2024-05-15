
## PURPOSE

Just wanted to make a home for [Advent of Code](https://adventofcode.com/) scripts.

## HOW TO USE

1. Create new folders and files alongside Day_00 as you progress in the challenge.
2. Edit ***main.cpp*** to include your new files and then just call their functions in *main()*.
3. To build and run your code, run ***./build_run.sh*** in your base directory for the repository.

Example Output:
```
user@host:~/cpp_ws/src/Advent-Of-Code$ ./build_run.sh

[BUILDING]
-- Configuring done
-- Generating done
-- Build files have been written to: /home/user/cpp_ws/src/build

[MAKING]
Consolidate compiler generated dependencies of target AdventOfCode
[100%] Built target AdventOfCode

[RUNNING] Advent of Code Project
Day 00 Sample Text!
[COMPLETED] Advent of Code Project
```

## NOTES

- CMakeLists should be flexible enough to extend for new cpp files without needing modification.
- Intending to leave **main** branch as a starter template and I'll do my development on another branch.
