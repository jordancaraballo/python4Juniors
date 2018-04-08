"""
Purpose: Script that indends to ask the user for his grade and the score of his test
and it will print the percentage of the score.
With this script we cover arithmetic operations, user input, printing, and lists.
##
Proposito: Este programa pretende preguntarle al usuario por su nota y su resultado en un examen, 
este imprimira el porcentaje de la nota.
Con este programa se cubren los topicos de operaciones aritmetics, input de usuario y listas. 
"""
# Asking the user for his grade
# Preguntarle al usuario por su nota
result = raw_input("Ingrese su nota / Enter your grade: ")

# Asking the user for his age
# Preguntarle al usuario por su edad
value = raw_input("Ingrese el valor del examen / Enter the test value: ")

# Lets calculate the score
percentage = (float(result) / float(value)) * 100

# Print a sentence with both variables
# Imprimir oracion con ambas variables
print "Su resultado en el examen fue de " + str(percentage) + "%."

## Assignments
## 1. How to calculate many test? 
## 2. How to calculate my class full grade?
##
## Tareas
## 1. Como calcular muchos examenes?
## 2. Como calcular mi nota final de la clase?
##

# List with all my scores
scores = [96 , 65, 86, 56, 90, 100, 100]
values = [100, 75, 90, 80, 100, 100, 100]

# Iterate to get the scores and put them in another list
grades = list()
for i in range(len(scores)):
    per = (float(scores[i]) / float(values[i])) * 100
    grades.append(per)

print grades

## Think about...
## How could I save all my scores in one file?
## Para pensar...
## Como podria guardar mis notas y resultados en un nuevo archivo?
## 
