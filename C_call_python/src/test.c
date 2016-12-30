#include <stdio.h>
#include <stdlib.h>
#include <python2.7/Python.h>
#include "interface.h"

int HelloWorld(int a,int b)
{
	int r;

	Py_Initialize();  
	PyRun_SimpleString("import sys;sys.path.append('.')");
	PyObject * pName = NULL;  
	PyObject * pModule = NULL;  
	PyObject * pFunc = NULL;
	PyObject * pArg  = NULL;
	PyObject * value = NULL;

	pName = PyString_FromString((char*)"pyHello");/*Build the name object*/  
	
	pModule = PyImport_Import(pName);/*Load the module object*/
	
	pFunc = PyObject_GetAttrString(pModule,(char*)"Hello");/*getting a reference to function name*/
	PyEval_CallObject(pFunc,NULL);	
	Py_DECREF(pFunc);/*Clean up*/

	pFunc = PyObject_GetAttrString(pModule,(char*)"Print_String");
	pArg  = Py_BuildValue("(s)", "This is  argument test !");  
	PyEval_CallObject(pFunc,pArg);  	
	Py_DECREF(pArg);
	Py_DECREF(pFunc);


	pFunc = PyObject_GetAttrString(pModule,(char*)"add");
	//pArg  = Py_BuildValue("(i,i)",5,7);  
	//PyEval_CallObject(pFunc,pArg);
	value = PyEval_CallFunction(pFunc,"(i,i)",a,b);	

	Py_DECREF(pArg);
	Py_DECREF(pFunc);
 	Py_DECREF(pModule);
   	Py_DECREF(pName);

	Py_Finalize();
	
	r = PyInt_AsLong(value);

	return r;  
}

