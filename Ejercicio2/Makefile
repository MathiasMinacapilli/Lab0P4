
# --------------------------------------------------------------------
# Makefile Laboratorio0 - Programacion 4 2019


# --------------------------------------------------------------------

# Objetivo predeterminado (no se necesita especificarlo al invocar `make').
all: principal

# Objetivos que no son archivos.
.PHONY: all clean entrega 


# directorios
HDIR    = include
CPPDIR  = src
ODIR    = obj

MODULOS = ClaseA ClaseB ClaseC

# cadena de archivos, con directorio y extensión
HS   = $(MODULOS:%=$(HDIR)/%.h)
CPPS = $(MODULOS:%=$(CPPDIR)/%.cpp)
OS   = $(MODULOS:%=$(ODIR)/%.o)

PRINCIPAL=principal
EJECUTABLE=principal

# compilador
CC = g++
# opciones de compilación
CCFLAGS = -Wall -Werror -I$(HDIR) -g
# -DNDEBUG
# se agrega esta opción para que las llamadas a assert no hagan nada.

$(ODIR)/$(PRINCIPAL).o:$(PRINCIPAL).cpp
	$(CC) $(CCFLAGS) -c $< -o $@

# cada .o depende de su .cpp
# $@ se expande para tranformarse en el objetivo
# $< se expande para tranformarse en la primera dependencia
$(ODIR)/%.o: $(CPPDIR)/%.cpp $(HDIR)/%.h
	$(CC) $(CCFLAGS) -c $< -o $@

# $^ se expande para tranformarse en todas las dependencias
$(EJECUTABLE): $(ODIR)/$(PRINCIPAL).o $(OS)
	$(CC) $(CCFLAGS) $^ -o $@



# Genera el entregable.
ENTREGA=Entrega0.tar.gz
CPPS_ENTREGA = $(MODULOS:%=%.cpp)
entrega:
	@rm -f $(ENTREGA)
	tar zcvf $(ENTREGA) -C src $(CPPS_ENTREGA)
	@echo --        El directorio y archivo a entregar es:
	@echo $$(pwd)/$(ENTREGA)


# borra binarios
clean:
	@rm -f $(EJECUTABLE) $(ODIR)/$(PRINCIPAL).o $(OS) ejemplos_letra




check-syntax:
	gcc -o nul -S ${CHK_SOURCES}
