## Aufgabe 2 Teil 1

In dieser Aufgabe wird ein Python-Programm erstellt, das Zeichen an geraden Indizes einer Zeichenkette druckt.

### Code-Erklärung

```python
# Originalzeichenkette definieren
original_string = "pynative"
```
Hier wird eine Zeichenkette `original_string` mit dem Wert "pynative" definiert.

```python
# Originalzeichenkette ausgeben
print("Orginal String is", original_string)
# Hinweis, dass nur Zeichen an geraden Indizes gedruckt werden
print("Printing only even index chars")
```
Diese beiden `print`-Anweisungen geben die Originalzeichenkette und einen Hinweis darauf aus, dass nur Zeichen an geraden Indizes gedruckt werden.

```python
# Schleife durch die Zeichenkette, um Zeichen an geraden Indizes zu drucken
for position in range(len(original_string)):
    # Überprüfen, ob der Index gerade ist
    if position % 2 == 0:
        # Zeichen an der aktuellen Position drucken
        print(original_string[position])
```
In dieser Schleife wird durch die Zeichenkette iteriert. Für jede Position in der Zeichenkette wird überprüft, ob der Index gerade ist (`position % 2 == 0`). Wenn dies der Fall ist, wird das Zeichen an dieser Position gedruckt.

### Erklärung des `%` Operators

Der `%` Operator ist der Modulo-Operator in Python. Er gibt den Rest einer Division zurück. Zum Beispiel:

- `5 % 2` ergibt `1`, weil 5 durch 2 geteilt 2 ergibt, mit einem Rest von 1.
- `4 % 2` ergibt `0`, weil 4 durch 2 geteilt 2 ergibt, ohne Rest.

In unserem Code verwenden wir `position % 2 == 0`, um zu überprüfen, ob die Position gerade ist. Wenn der Rest `0` ist, bedeutet dies, dass die Position durch 2 teilbar ist und somit gerade ist.

### Zusammenfassung

Dieses Programm zeigt, wie man durch eine Zeichenkette iteriert und nur die Zeichen an geraden Indizes druckt. Es ist ein einfaches Beispiel für die Verwendung von Schleifen und bedingten Anweisungen in Python.
