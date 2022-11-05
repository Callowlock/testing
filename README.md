# CS 300 - Autumn 2022 - Team #3
# Distributed Sorting: Sorting Algorithm and Distributed Computing

## Team Members:
X Mark Bonner
- Chris Nevares (team representative)
- Lucas Rassbach

## Instructor:
- Varik Hoang

## Objectives

To build a system that can split the data set into multiple parts and share with other computers. Your computer will be a station node with worker nodes (Let’s say only two at this time and you can have it set up on your local machine using Docker container - feel free to use VMWare or VirtualBox but not recommended because Docker should be easy enough for quick configuration and debugging and of course you do not want to go crazy when something go wrong). After finishing the implementation, you will need to run experiments using your implementation on Cloud machines to prove the efficiency of distributed computing.

## Guidelines:

1. Install Docker (we use Docker to simulate two other machines)
2. Create a simple C++ application to share the data (C++ complex objects with multiple data fields. For example, Student objects with names, age, etc.) between a station and workers. (We assume that there is no network interruption to simplify this extra assignment). The number of fields must be at least 5 fields and sorting criterias are up to you.
3. There should be an option to choose sorting algorithms for all machines (keep this simple instead of each machine having a different sorting algorithm). For example, bubble sort, insertion sort, selection sort, quick sort, merge sort, etc. (must have at least five sorting algorithm)
4. The station read and split data from a CSV file with 100,000 records. Please let me know if you need a big data CSV file.
5. Run experiments with different algorithms (5) vs. different numbers of workers in the network (5).
6. Come up with some graphs (Excel or Spreadsheet) between the studies and what you have learned from the experiments.
7. Use google docs or https://papeeria.com/ (they are free) to write a two-column group report (IEEE template). The report should include: abstract, introduction, background, related works, methodologies, experiments, conclusions, references.
8. Fill up team evaluation (this is a short form)

Note: the application and report must use at least four concepts from the data structures course: Class, Inheritance, Encapsulation, UML Diagrams (1 Class Diagram and 1 Sequence Diagram), File Input/Output, List, Queue, Stack, Map, Graph
