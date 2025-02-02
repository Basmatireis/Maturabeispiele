# Funktion definieren, um Zeichen zu entfernen
def removeChars(a, n):
    # Zeichenkette ab dem n-ten Index zurückgeben
    x = a[n:]
    return x

# Funktion aufrufen und Ergebnis ausgeben
print(removeChars("1234567string", 7))