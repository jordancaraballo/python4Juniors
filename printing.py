"""
Purpose: Script that indends to ask the user for his name and age, and it will print it in the 
terminal. The program input is the name and age and the output is a sentence with both.
With this script we cover the concepts of user input, printing, and string concatanation.
##
Proposito: Este programa pretende preguntarle al usuario su nombre y edad, para luego imprimir
ambos en el terminal. El program tiene de entrada el nombre y la edad, y de salida imprime una
oracion con el nombre y la edad del usuario.
Con este programa se cubren los conceptos de entrada del usuario, imprimir, y concatenar palabras.
"""
# For the tutorial
print ("Hello World!")

# Asking the user for his name
# Preguntarle al usuario por su nombre
name = input("Ingrese su nombre / Enter your name: ")

# Asking the user for his age
# Preguntarle al usuario por su edad
age = input("Ingrese su edad / Enter you age: ")

# Print a sentence with both variables
# Imprimir oracion con ambas variables
print ("\nHola " + name + ", es un placer conocerte! Tienes " + str(21 - int(age)) + " a/os mas que yo!")
print ("Hey "    + name + ", nice to meet you! You are "      + str(21 - int(age)) + " older than me!\n")

## Assignments
## 1. How old is the computer saying it is?
## 2. Ask the user for his address and create a sentence with the name, age, and address.
## 3. Ask multiple user for their names and print them.
##
## Tareas
## 1. Que edad dice la computadora que tiene?
## 2. Preguntale al usuario por su direccion y haga una oracion con su nombre, edad y direccion.
## 3. Preguntele a multiples usuarios sus nombres e imprimalos.
##
## Think about...
## What if the user is an adult? What if the age is a letter?
## Para pensar...
## Que pasa si el usuario es un adulto? Que pasa si la edad fuera una letra?
## 
