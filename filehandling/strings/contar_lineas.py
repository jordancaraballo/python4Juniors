
# %% Pregunta #1
nombre = input("Ingrese el nombre de su archivo: ")
archivo = open(nombre,'r')

conteo = 1
for linea in archivo:
    newl = linea.replace("\n","").replace(" ", "")
    print ("Linea #: ", conteo, ", # Caracteres: ", len(newl))
    conteo += 1 # add value al contador
# %%

# %% Pregunta #2
nombre = input("Ingrese el nombre de su archivo: ")
cadena = input("Ingrese una cadena: ")

archivo = open(nombre, 'w+')
lcadena = len(cadena)
archivo.write(str(lcadena))
archivo.close()
# %%

