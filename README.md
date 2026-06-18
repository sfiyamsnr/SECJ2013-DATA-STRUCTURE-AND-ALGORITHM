# SECJ2013-DATA-STRUCTURE-AND-ALGORITHM

# 🚀 Data Structure and Algorithm (SECJ2013) - Learning Portfolio & Project Reflection

Welcome to my portfolio for the **Data Structure and Algorithm (SECJ2013)** course.

---

## 📑 Overall Course Reflection

Data Structure and Algorithm was the course that made me stop thinking about "just making the program work" and start thinking about **how data is organized and why that organization matters**. Working entirely in C++, I had to manage memory manually for the first time in a meaningful way — every `new` needed a matching `delete`, every pointer needed to be tracked, and every destructor call printed a small reminder of just how much was happening under the hood that higher-level languages normally hide.

Key personal and technical takeaways include:
* **Pointers and Manual Memory Management:** Implementing linked lists, queues, and dynamic object arrays in raw C++ forced me to actually understand what a pointer holds, how `next`/`prev` links rewire a structure, and why forgetting a `delete` leaks memory. The destructor print statements scattered through my labs were a deliberate (and effective) way to *see* object lifetimes instead of just trusting they happened.
* **Recursion as a Way of Thinking:** Writing recursive functions to print patterns and sum values taught me to trust a function to solve a smaller version of the same problem, rather than mentally tracing every call by hand. It reshaped how I approach problems that have a natural "self-similar" structure.
* **Choosing the Right Structure for the Job:** Comparing array-based lists, linked lists, and queues across labs showed me there's no single "best" structure — it depends entirely on whether you need random access, frequent insertion/deletion, or strict ordering like FIFO.
* **Linked Lists as a Foundation:** Building a singly linked list to manage student records (with sorted insertion, search, and deletion) was the conceptual bridge between simple arrays and the more advanced structures used later, like circular queues and priority queues.
* **Queues and Real-World Simulation:** Modeling a queue — both as a circular linked list and as a priority structure in a flight-landing simulation — showed me how an abstract data structure maps directly onto real scheduling problems, like deciding which aircraft lands next based on fuel level.

---

## 🛠️ Lab-by-Lab Reflection

### 🔹 [Lab 1: Classes, File I/O & Object Arrays]
* **Concepts Focused:** Class design with constructors/destructors, file reading and writing with `fstream`, array of pointers to objects, and computing derived values (grades from marks).
* **Implementation Details:** Built a `Student` class that reads coursework and final exam marks from `Marks.txt`, computes a total mark and letter grade, and writes formatted results out to `Results.txt`. Student objects were stored in a fixed-size array of pointers and explicitly deleted after use.
* **Reflection:** This lab was my first real exposure to managing object lifetimes manually — watching the destructor print "Destroy Student Object" for each student as it was deleted made memory management feel concrete rather than theoretical. Reading and writing files with `fstream` also reinforced that an object's behavior (like `printResultFile()`) can target different output streams without changing its core logic.

### 🔹 [Lab 2: Recursion]
* **Concepts Focused:** Recursive function design, base cases, and recursion with default parameters.
* **Implementation Details:** Wrote `printStar()` and `printNum()` to recursively build a numbered star-pattern, and `totalOdd()` to recursively sum only the odd numbers in an array using a default index parameter to avoid needing a separate helper signature.
* **Reflection:** Designing `totalOdd()` was a small but important lesson in recursive parameter design — using a default `i = 0` parameter let the recursive call signature stay clean without exposing an extra "starting index" argument to the caller. This lab made me genuinely comfortable trusting the recursive call rather than trying to trace every level by hand.

### 🔹 [Lab 3: Doubly Linked List]
* **Concepts Focused:** Node-based structures with `next`/`prev` pointers, forward and reverse traversal, and dynamic insertion/deletion logic.
* **Implementation Details:** Worked with a `List` class wrapping `Node` objects that each store a `next` and `prev` pointer, supporting `displayList()` and `displayListReverse()` traversal in both directions, alongside `findNode()` for searching by value.
* **Reflection:** This lab was a great push into thinking about a list from *both ends* — maintaining a `last` pointer alongside `head` so reverse traversal didn't require walking the whole list forward first. It highlighted how much bookkeeping is needed to keep a doubly linked list internally consistent any time nodes are added or removed.

### 🔹 [Lab 4: Circular Linked-List Queue]
* **Concepts Focused:** Queue ADT operations (`enQueue`, `deQueue`, `isEmpty`), implementing a queue using a circular singly linked list rather than a plain array.
* **Implementation Details:** Built a `Queue` class backed by `Node` objects where the `rear` node's `next` pointer always points back to `front`, maintaining the circular property as items are enqueued and dequeued in FIFO order.
* **Reflection:** Implementing the queue circularly instead of with a simple array was the first time I had to think about a structure that "wraps around" itself. Carefully re-pointing `rear->next` back to the new `front` after each dequeue made me appreciate why circular structures need extra care at the boundary cases (e.g., when the queue has exactly one element).

---

## 📝 Assignment Reflections

### 🔹 [Assignment 1: Sorting Student Records with Bubble Sort]
* **Concepts Focused:** Array-of-pointers management, file-driven object creation, and bubble sort algorithm variants (by name, and by grade with name as a tiebreaker).
* **Implementation Details:** Extended the Lab 1 `Student` class with a `getName()` accessor, then implemented an interactive menu allowing results to be listed in original order, sorted alphabetically by name, or sorted by grade (using name as a secondary sort key when grades tie).
* **Reflection:** Writing `listByGrade()` taught me how to handle multi-key sorting cleanly — comparing grades first and only falling back to comparing names when grades were equal. Using a `sorted` flag to allow early-exit optimization in the bubble sort was a small but satisfying step toward writing more efficient code rather than just "correct" code.

### 🔹 [Assignment 2: Sorted Singly Linked List of Students]
* **Concepts Focused:** Maintaining a sorted linked list on insertion (rather than sorting afterward), node-based search, and node deletion with predecessor tracking.
* **Implementation Details:** Replaced the array-based approach from Assignment 1 with a `List` class that inserts each new `Student` node in alphabetical order by name, supports `findNode()` by name, and `deleteNode()` by name while correctly re-linking the previous node and updating the `last` pointer when needed.
* **Reflection:** This assignment made the trade-off between arrays and linked lists very concrete: insertion into a sorted linked list avoids the need to re-sort everything, but only if the list traversal logic for finding the correct insertion point is airtight. Tracking the predecessor node (`prev`) during deletion was the trickiest part — getting it wrong silently breaks the chain, which is a very different failure mode from an array's out-of-bounds error.

---

## ✈️ Group Project Reflection: "Flight Landing Simulation"

* **Concepts Covered:** Class design (`Flight`, `Queue`), array-backed queue implementation, priority-based dequeue logic, and discrete event simulation driven by a cycle loop.
* **Core Design:** Modeled an airport landing system where incoming `Flight` objects are enqueued as they arrive, and a custom `Queue::deQueue()` doesn't simply pop the front — it scans the queue to prioritize the flight with the **lowest fuel** for landing first, simulating real air-traffic urgency.
* **Implementation Details:** Each simulation cycle processes one incoming flight, attempts to land the currently-selected flight by advancing its `status` through stages (`Flying` → `Change altitude` → `Change direction` → `Landing`), and reduces fuel every cycle a flight isn't yet landed — with a flight crashing if its fuel reaches zero before landing completes. The simulation concludes with a statistical summary of crashes, comfortable landings, critical landings, and passenger survival counts.
* **Reflection:** This project was where every earlier lab came together. The `Queue` class structurally resembles the array-based queues from earlier labs, but overriding `deQueue()` to select by lowest fuel rather than strict FIFO order showed me how the *same ADT interface* can support very different underlying selection policies depending on the real-world priority you're modeling. Designing the cycle-based simulation loop — where flight state advances one step per cycle rather than resolving instantly — was also a useful lesson in modeling time-based systems, something that doesn't come up in a typical single-pass program. Working as a four-person team on this also meant agreeing early on what `status` strings the simulation would use consistently, since a single mismatched string (like `"Landing"` vs `"landing"`) would have silently broken the landing-stage logic.
