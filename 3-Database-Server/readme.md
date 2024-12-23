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
