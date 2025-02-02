# Originalzeichenkette definieren
original_string = "pynative"

# Originalzeichenkette ausgeben
print("Orginal String is", original_string)
# Hinweis, dass nur Zeichen an geraden Indizes gedruckt werden
print("Printing only even index chars")

# Schleife durch die Zeichenkette, um Zeichen an geraden Indizes zu drucken
for position in range(len(original_string)):
    # Überprüfen, ob der Index gerade ist
    if position % 2 == 0:
        # Zeichen an der aktuellen Position drucken
        print(original_string[position])