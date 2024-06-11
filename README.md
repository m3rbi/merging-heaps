# Heap simulator

## Purpose
This CLI tool provides a basic heap interface to inspect and operate on.
This program supports up to 2 lists at once (lists `a` and `b`).

## Build and run
In order to build -
```
chmod +x build.sh
./build.sh
```
In order to run -
```
chmod +x out/merging_heaps
out/merging_heaps
```


## Available functionalities
Note: Upon program startup, the user is promopted whether it's lists are
sorted or not. There is no validation performed on it!
* Reset State - Resets both lists.
* Input List - Parse a list from given file. Each node is a single line.
* Print List - Print the nodes of a list, from the first to the last.
* Build Min Heap - Rearranges specified list into a minimum heap.
* Heap Sort - Performs a heap sort on given list.
* Union Heaps - Merges the 2 lists into a single heap in list a. The list in b is emptied but not freed!

## Complexity
| Operation                 | Complexity        | Description                                                       |
|---------------------------|-------------------|-------------------------------------------------------------------|
| Reset State               | O(n)              | Simple iteration over linked list items.                          |
| Input List                | O(n)              | Inserting a node for each line read.                              |
| Print List                | O(n)              | Simple iteration over linked list items.                          |
| Build Min Heap (sorted)   | O(1)              | Sorted list is already a heap.                                    |
| Build Min Heap (unsorted) | O(n)              | While having different constants, same complexity as normal heap. |
| Heap Sort (sorted)        | O(1)              | Already sorted.                                                   |
| Heap Sort (unsorted)      | O(nlogn)          | Same as normal heap.                                              |
| Union Heaps (sorted)      | O(m+n)            | Iterate both lists at the same time, zipping them together.       | 
| Union Heaps (unsorted)    | O((n+m)log(n+m))  | Concatinate lits in O(1) and then heapifying.                     |
| Insert Node (sorted)      | O(n)              | Iterate over the list until finding the correct position.         |
| Insert Node (unsorted)    | O(logn)           | Inserting the node to the end is O(1) and bubbling it is O(logn)  |

## Error codes
### Runtime errors
| Error     | Message                       |
|-----------|-------------------------------|
|   1       | Input error                   |
|   2       | Invalid opertaion arguments   |
|   4       | Null pointer encountered      |
|   5       | List parse error              |
|   6       | Uninitialized list            |
### List parsing errors
| Error     | Message                       |
|-----------|-------------------------------|
|   1       | File not found                |
|   2       | File open error               |
|   3       | File read error               |
|   4       | Empty file                    |
|   5       | Invalid nodes                 |

## Architecture
The heaps are implemented as linked lists with various functions wrapping
the basic heaps and linked list operations.
The CLI tool is a basic state machine designed to make it easy to add and
remove different operations, while keeping an in-memory struct of the
program's statte.

### Project structure
* `operations/` - Contains all possible operations available in the program.
* `runtime/` - The state machine framework and contains the bootstrap and flow
of the program.
* `data_structures/` - Implementations of the data structures themselves.
* `io/` - Basic input-output utilities.
* `consts/` - Constants for the program's use.

## Links
* Project's repository - https://github.com/m3rbi/merging-heaps

