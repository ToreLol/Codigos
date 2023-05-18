Algoritmo sin_titulo
		Definir numerotel Como Caracter
		Definir nombretel Como Caracter
		Definir numerotel2 Como Caracter
		Definir nombretel2 Como Caracter
		Definir numerotel3 Como Caracter
		Definir nombretel3 Como Caracter
		escribir "Agenda"
		Escribir "No tienes ningun numero agregado, escriba (agregar) para empezar"
		Leer respuesta
		Si respuesta="agregar" Entonces
			Escribir "escribe el numero que deseas agregar"
			Leer numerotel 
			Escribir "que nombre deberia tener?"
			Leer nombretel
		FinSi
		si respuesta="agregar" Entonces
			Escribir "escribe el numero que deseas agregar"
			Leer numerotel2
			Escribir "que nombre deberia tener?"
			Leer nombretel2
		FinSi
		si respuesta="agregar" Entonces
			Escribir "escribe el numero que deseas agregar"
			Leer numerotel3
			Escribir "que nombre deberia tener?"
			Leer nombretel3
		FinSi
		Repetir
		Escribir "que gustas hacer (buscar, modificar, borrar) para salir escriba cerrar"
		Leer respuesta2
		
		
		Segun respuesta2 Hacer
			"buscar":
				Escribir nombretel
				Escribir numerotel
				Escribir nombretel2
				Escribir numerotel2
				Escribir nombretel3
				Escribir numerotel3
			"borrar":
				Escribir "cual numero deseas borrar? n1,n2,n3"
				leer bor
				si bor="n1" Entonces
					numerotel = "NO HAY NUMERO"
				FinSi
				si bor="n2" Entonces
					numerotel2 = "NO HAY NUMERO"
				FinSi
				si bor="n3" Entonces
					numerotel3 = "NO HAY NUMERO"
				FinSi
			"modificar":
				Escribir "que numero deseas modificar? n1,n2,n3"
				Leer modificar
				si modificar="n1" Entonces
					Escribir "porfavor ponga el nuevo numero"
					Leer numerotel
				FinSi
				si modificar="n2" Entonces
					Escribir "porfavor ponga el nuevo numero"
					Leer numerotel2
				FinSi
				si modificar="n3" Entonces
					Escribir "porfavor ponga el nuevo numero"
					Leer numerotel3
				FinSi
			De Otro Modo:
				
		Fin Segun
	      Hasta Que respuesta2="cerrar"
FinAlgoritmo
