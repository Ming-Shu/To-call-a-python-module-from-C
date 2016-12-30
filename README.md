# To-call-a-python-module-from-C
How to easy extend a large C project with some new functionality  in Python. 

Environment:
Hardware Interface  :  Raspberry Pi

Operating System    :  Linux raspberrypi 4.1.18-v7+

Python version      :  2.7


Note:

1. You need to install a package called python-dev.(This package includes header files, a static library and development tools for  building Python modules, extending the Python interpreter or embedding Python in applications.)

Commmand line:

     For Python version 2.x+
     
              sudo apt-get install python-dev
              
     For Python version 3.x+
     
              sudo apt-get install python3-dev


2. You need to provide GCC with the include path for the Python.h header. This can be done with the -I

example:
          gcc test.c -I /usr/include/python2.7 -lpython2.7 -o test
    
3.You must to learn about PyObject that is the basic object for the C API. It can represent any kind of python basic types.
    Reference https://docs.python.org/3/c-api/
