a.exe:bst_app.o bst_imp.o
	c++ bst_app.o bst_imp.o -o a.exe
bst_app.o:bst_app.cpp
	c++ -c bst_app.cpp
bst_imp.o:bst_imp.cpp
	c++ -c bst_imp.cpp