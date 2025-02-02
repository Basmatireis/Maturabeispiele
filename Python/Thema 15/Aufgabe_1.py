# Letzte Zahl initialisieren
last_number = 0

# Schleife von 0 bis 9
for current_number in range(10):
    # Summe der aktuellen und der letzten Zahl berechnen
    sum = current_number + last_number
    # Aktuelle Zahl, letzte Zahl und deren Summe ausgeben
    print("Current Number:", current_number, "Last Number:", last_number, "SUM:", sum)
    # Die aktuelle Zahl wird zur letzten Zahl für die nächste Iteration
    last_number = current_number