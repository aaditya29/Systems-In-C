# Database Server in C

A **database server** is a server that uses a database application that provides database services to other computer programs or computers. It is responsible for storing, retrieving, and managing database services and data.

### Key Features

- **Data Storage**: Stores data in a structured format.
- **Data Retrieval**: Allows for efficient querying and retrieval of data.
- **Data Management**: Provides tools for managing data, including backup, recovery, and security.

## Project Description

Here we are going to design and code a fast in-memory database server. We will use knowledge of structs, linked lists, pointers and function pointers as well as linear searches, performance measuring, binary trees and hyper-optimized hash tables.

## Designing Our Database

For this we will learn about **binary trees**.

### Binary Trees

A **binary tree** is a tree data structure in which each node has at most two children, referred to as the left child and the right child. It is used for various applications such as searching, sorting, and maintaining a dynamic set of ordered data.

#### Structure of a Binary Tree

Each node in a binary tree contains the following components:

- **Data**: The value stored in the node.
- **Left Child**: A pointer/reference to the left child node.
- **Right Child**: A pointer/reference to the right child node.

#### Example Diagram

Here is a simple diagram of a binary tree:

```
       [A]
      /   \
    [B]   [C]
   /  \   /  \
 [D] [E] [F] [G]
```

In this example:

- `A` is the root node.
- `B` and `C` are the children of `A`.
- `D`, `E`, `F`, and `G` are the children of `B` and `C`.
- The leaves of the tree can be int. char or char \* with string inside to store the data of binary tree in standard way.

> But we are going to modify the binary tree in the following way

```
       [ROOT]
         /
    [/USER/]---------------------------------
       /        |         |         |
      /      [Value1] [Value2]   [Value3] etc.
     /
 [/USER/LOGIN]-------------------------------
                |         |         |
             [Value1] [Value2]   [Value3] etc.
```

Here we are using the leaf nodes as file system so they become like folders for example we have aboce `USER` folder and further inside its value.

But to define the data structure of this kind in the C language we will have to modify it. So here we will use `Union` to store the tree.

```C
union u_tree{
    struct s_node n;
    struct s_leaf l;
};
```

Here we have a data structure `Union` which looks like a structure but there is significant difference between them. If it was a struct then `s_node n` and `s_leaf l` would have its own memory location but here they share the same memory location. Hence here `Union` contains either node or leaf not both.

> What is `struct s_node`

```C
struct s_node{
    struct s_node *up;
    struct s_node *left;
    struct s_leaf *right;
    Tag tag;//to define what kind of struct we have
}
```

Here we are building `s_node` structure for a **tree** where:

- Internal nodes (`s_node`) point to both other `s_node` elements (via `up` and `left`) and leaf nodes (`s_leaf` via `right`).
- Each node can differentiate between its type or function using the `Tag`.
- Internal nodes (`s_node`) handle structural connections.
- Leaf nodes (`s_leaf`) store data.

Also in addition we will need for path `char path[size]` for the path of node to access on the user level.<br>
The usage of this is that when user connects to database then it should be able to do something like **create /Users** to put one of the users inside this path.

> Defining `LEAF`

```C
struct s_leaf{
    struct s_tree *left;//link of the leaf
    char key[size];
    char *value;
    int count;//to count how many characters value will be
    Tag tag
}
```

Here we have leaf's link which contains one element which is string which will be allocated to the heap i.e. value pointer.

## Creating Our Own Redis Database Server

Redis is an open-source, in-memory data structure store, used as a database, cache, and message broker. It supports various data structures such as strings, hashes, lists, sets, and sorted sets with range queries, bitmaps, hyperloglogs, geospatial indexes, and streams.

> Applications Where These Data Structures Help:

- Realtime Chat
- Message Buffers
- Gaming Leaderboards
- Auth Session Stores
- Media Streaming
- Realtime Analytics

> What Makes Redis Special:

Every operation on `Redis` such as:

- Putting a key
- adding to the lists
- set union/intersection
- incrementing the value

are <b>atomic</b> i.e. series of database operations within a transaction are treated as a single unit. In layman terms it means that either all operations in the transaction are completed successfully, or none of them are. If any operation within the transaction fails, the entire transaction is rolled back, leaving the database in its original state before the transaction began.

Also data is stored <b>in-memory</b> hence the most common use of Redis is for 'caching' but Redis also provides configurable persistence i.e. peridocially dumping data to disk, write-ahead log of all commands and no persistence at all.

### Programming Models of Redis

Redis has programming model called 'Concurrent Programming Model(Single Process)' which is all about doing more than one thing at the same time. We have following ways to achieve concurrency in a single process model:

1. **Multi-Threading:** <br>
   Each incoming request over the network is accepted by the server and executed in a separate thread.<br>
   <b>For example:</b><br>
   a) $R1--> INCR K-->T1$<br>
   b) $R2-->INCR K-->T2$

   But this might lead to a problem where we have to ensure data correctness because for example if $K=10$, and two threads executing K++ then possible final values of K are 11 and 12.<br>
   Hence we have to make sure other threads wait while one thread is executing the critical section.

2. **I/O Multiplexing(Apparent Concurrency):**<br>
   I/O multiplexing is a programming technique that allows a single process to manage multiple I/O operations simultaneously. is a crucial feature in Redis that enables it to efficiently manage multiple client connections simultaneously. This technique allows Redis to serve a high number of requests without the need for multiple threads, leveraging a single-threaded event loop to handle I/O operations.<br>
   This is also how event loops are implemented.<br>

### How Single-Threaded Redis is So Fast?

> Redis Uses following two tricks:

- It keeps network I/O slow i.e. it waits to recieve commands.
- In-memory operations is fast i.e. upon receiving commands Redis can very quickly execute them.

This is why Redis is:

- Single Threaded as no need of mutex, semaphores and waiting.
- Also doing I/O Multiplexing i.e. handling multiple TCP connections concurrently.

#### Structure of Our Database Server

In our database we will focus on CPU optimisation rather than focussing on size. Our protocol will use `ASCII` and we will be able to use protocols like telnet, localhost and port for example like 6565.
Rough skeleton of our protocol will look as follows:

```SQL
CREATE /Users/
200 OK
INSERT /Users/key value
SELECT /Users/key
```
