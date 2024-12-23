# Database Server in C

A **database server** is a server that uses a database application that provides database services to other computer programs or computers. It is responsible for storing, retrieving, and managing database services and data.

## Key Features

- **Data Storage**: Stores data in a structured format.
- **Data Retrieval**: Allows for efficient querying and retrieval of data.
- **Data Management**: Provides tools for managing data, including backup, recovery, and security.

## Project Description

Here we are going to design and code a fast in-memory database server. We will use knowledge of structs, linked lists, pointers and function pointers as well as linear searches, performance measuring, binary trees and hyper-optimized hash tables.

### Designing Our Databse

For this we will learn about **binary trees**.

#### Binary Trees

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
