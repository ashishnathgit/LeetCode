# LeetCode Solutions in C++

My solutions to LeetCode problems, written in C++, my main language. Each solution aims for the most efficient approach I can reach.

This repo isn't only for interview prep. The patterns behind these problems show up in everyday software work, and practicing them makes me a better engineer.

---

## How These Problems Apply to Real Work

| Pattern | Where it shows up in practice |
|---|---|
| **Hash maps & sets** | Caching, removing duplicate records, counting events, fast lookups by ID, joining datasets |
| **Two pointers & sliding window** | Processing streams and logs, rate limiting, finding patterns in text, merging sorted data |
| **Sorting & merging** | Ranking results, merging data from several sources, scheduling, preparing data for fast search |
| **Binary search** | Searching large sorted datasets, finding the first failing commit (`git bisect`), tuning thresholds |
| **Linked lists** | LRU caches, undo/redo history, memory allocators, queues inside OS kernels |
| **Trees & recursion** | File systems, the DOM, JSON/XML parsing, compilers, database indexes (B-trees) |
| **Dynamic programming** | Diff tools, spell checkers, route planning, resource allocation, pricing and budgeting |
| **Matrix manipulation** | Image processing (rotating, flipping), game boards, spreadsheets, graphics |
| **Divide and conquer** | Merge sort, parallel processing, counting inversions for ranking and recommendation systems |
| **Date & interval logic** | Booking systems, calendars, finding overlaps between schedules |

---

## Benefits

### Writing faster, cheaper code
Knowing time and space complexity helps me tell the difference between code that works on 100 records and code that works on 100 million. That means lower server costs, faster pages, and fewer timeouts in production.

### Picking the right data structure
Many performance bugs come from using the wrong structure, like scanning a list where a hash set would do. Regular practice makes the right choice automatic.

### Handling edge cases
LeetCode's hidden tests punish missed cases: empty input, one element, duplicates, overflow, negative numbers. Thinking through these becomes a habit, and it carries over to writing reliable production code.

### Breaking down hard problems
Splitting a vague problem into smaller, solvable steps is the core of system design, debugging, and feature planning, not only puzzles.

### Getting fluent in C++
Each solution is practice with the STL (`vector`, `unordered_map`, `set`, `priority_queue`, algorithms), memory handling, and modern C++ features, which pays off in any C++ codebase.

### Reading and reviewing code
Comparing my solution to others teaches me to spot inefficiencies and cleaner approaches quickly. This is useful in code reviews.

### Interview readiness
Technical interviews test exactly these skills. Consistent practice keeps them sharp.

---

## Approach

- All solutions are in **C++**
- Each aims for the best time and space complexity I can reach
- Code is kept clean and readable, not just correct

*Updating regularly.*
