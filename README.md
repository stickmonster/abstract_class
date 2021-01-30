# abstract_class

/*Abstract and interface accounts form the hidden base from which a 
lot of 'include'd code inherits. I am currently working with wxWidgets 
and it made me think I need to understand the polymorphic process at this 
root. To do so, I have created an interface class bank account, and 
inherited from it to form a savings account and a current account. 
This could, of course, be improved on. 
1) The interface doesn't do anything, or add much to the hierachy.
2) A non-numeric input causes the while loop to continue past future inputs.
3) Although a return code of 1 is used, there's no exceptions structure.
If you can think of other improvements, or just improve this code, please show me how.*/
