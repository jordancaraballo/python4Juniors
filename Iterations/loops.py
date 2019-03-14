"""
Mix of commands to print different elements using loops
Still in construction...
"""
# Drawing a christmas tree
n = 15   
for i in range(n):
    print ' ' * (n - (i + 1)),'^' * (2*i+1)


# List of names and printing them
namesList = list()
for i in range(n):
    value = raw_input("Ingrese un nombre / Enter a name: ")
    namesList.append(value)
print namesList
    
