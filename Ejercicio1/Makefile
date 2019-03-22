# --------------------------------------------------------------------
# Makefile Laboratorio0 - Programacion 4 2019 - Ejercicio 1
# --------------------------------------------------------------------

# Objetivo predeterminado, es decir make = make principal
all: principal

# Objetivos de reglas que no son archivos.
.PHONY: all clean

# declaracion de variables

# variables con los directorios y los modulos
HDIR    = include
CPPDIR  = src
ODIR    = obj

MODULOS = Bicicleta DtBicicleta DtFecha DtMonopatin DtVehiculo DtViaje DtViajeBase Monopatin TipoBici Usuario Vehiculo Viaje

# variables que contienen la cadena de archivos para los .h, .cpp y .o
HS   = $(MODULOS:%=$(HDIR)/%.hpp)
CPPS = $(MODULOS:%=$(CPPDIR)/%.cpp)
OS   = $(MODULOS:%=$(ODIR)/%.o)

PRINCIPAL=principal
EJECUTABLE=principal

# compilador
CC = g++
# opciones de compilación
CCFLAGS = -Wall -I$(HDIR)

# $< es una variable automatica de GNU Make que es el nombre de la primera dependencia
# $@ es una variable automatica de GNU Make que es el nombre del archivo objetivo de la regla
$(ODIR)/$(PRINCIPAL).o:$(PRINCIPAL).cpp
	$(CC) $(CCFLAGS) -c $< -o $@

# cada .o depende de su .cpp y .hpp
# /% es parte de la definicion de reglas con patrones de GNU Make, donde % se matchea con cualquier string que no esté vacío
# $< es una variable automatica de GNU Make que es el nombre de la primera dependencia
# $@ es una variable automatica de GNU Make que es el nombre del archivo objetivo de la regla
# Es decir que esta regla se ejecuta para todos los archivos en CPPDIR que tengan a su igual (en nombre) en HDIR
$(ODIR)/%.o: $(CPPDIR)/%.cpp $(HDIR)/%.hpp
	$(CC) $(CCFLAGS) -c $< -o $@

# $^ es una variable automatica de GNU Make que son todas las dependencias separadas por espacios
# $@ es una variable automatica de GNU Make que es el nombre del archivo objetivo de la regla
# Es decir que esta regla se ejecuta con las dependencias: ../obj/principal.o y todos los archivos de la variable OS separadas por espacios 
$(EJECUTABLE): $(ODIR)/$(PRINCIPAL).o $(OS)
	$(CC) $(CCFLAGS) $^ -o $@

# borra binarios
clean:
	@rm -f $(EJECUTABLE) $(ODIR)/$(PRINCIPAL).o $(OS)
