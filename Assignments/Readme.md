MOTIVE: Both the original and final file should be identical, with most of the corner cases handled. 

1.	File Generator 
    Create fixed size file say 10MB with Random Data 
    
2.	File System Traversal
    A.	Write a program which will accept a filename as parameter and traverse through the test directory to find that file.
    B.	Add wild card option to the filename 
    FileName starts with substring
    Filename ends with substring
    Filename Contains substring 
    Eg: FileN* , *Name, *ilenam*
    
3.	Copy Application 
    Read from that file using multiple threads each thread reading 1MB data from the file. & Store each data (1 MB) in a node of linklist. 
    Sort the node according to the sequence of data in the file.
    Write data the data in a different file using again different threads (1MB each). 
    NOTE: Use resource lock for linklist.

