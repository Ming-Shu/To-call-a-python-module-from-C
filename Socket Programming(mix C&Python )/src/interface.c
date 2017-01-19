#include <stdio.h>
#include <stdlib.h>
#include <python2.7/Python.h>
#include "interface.h"

int pyTCP_listener(char *host,int socket_port)
{
	int tcp_fd;

	Py_Initialize();  
	PyRun_SimpleString("import sys;sys.path.append('.')");
	PyObject * pName = NULL;  
	PyObject * pModule = NULL;  
	PyObject * pFunc = NULL;
	PyObject * value = NULL;
	pName = PyString_FromString((char*)"pysocket");/*Build the name object*/  
	
	pModule = PyImport_Import(pName);/*Load the module object*/
	
	pFunc = PyObject_GetAttrString(pModule,(char*)"createTCP_listener");/*getting a reference to function name*/
	value = PyEval_CallFunction(pFunc,"(s,i)",host,socket_port);
	tcp_fd = PyObject_AsFileDescriptor(value);/*Return the file descriptor associated with p as an int.*/
	Py_DECREF(pFunc);
 	Py_DECREF(pModule);
   	Py_DECREF(pName);
	Py_Finalize();
	
	return tcp_fd;  
}

int pyTCP_acceptMsg(int tcp_fd)
{
	Py_Initialize();  
	PyRun_SimpleString("import sys;sys.path.append('.')");
	PyObject * pName = NULL;  
	PyObject * pModule = NULL;  
	PyObject * pFunc = NULL;
	PyObject * pArg  = NULL;
	PyObject * value = NULL;
	pName = PyString_FromString((char*)"pysocket");/*Build the name object*/  
	
	pModule = PyImport_Import(pName);/*Load the module object*/
	
	pFunc = PyObject_GetAttrString(pModule,(char*)"msgTCP_handle");/*getting a reference to function name*/
	
	pArg  = Py_BuildValue("(i)",tcp_fd);
	PyEval_CallObject(pFunc,pArg);/*This function has two arguments, both pointers to arbitrary Python objects*/
	Py_DECREF(pArg);
	Py_DECREF(pFunc);
 	Py_DECREF(pModule);
   	Py_DECREF(pName);
	Py_Finalize();
	
	return tcp_fd;  
}
