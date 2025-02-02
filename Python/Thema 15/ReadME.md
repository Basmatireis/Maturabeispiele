## Aufgabe 1

In dieser Aufgabe wird ein Python-Programm erstellt, das die Summe der aktuellen und der vorherigen Zahl in einer Schleife berechnet und ausgibt.

### Code-Erklärung

```python
# Letzte Zahl initialisieren
last_number = 0
```
Hier wird die Variable `last_number` mit dem Wert `0` initialisiert. Diese Variable speichert die vorherige Zahl in der Schleife.

```python
# Schleife von 0 bis 9
for current_number in range(10):
    # Summe der aktuellen und der letzten Zahl berechnen
    sum = current_number + last_number
    # Aktuelle Zahl, letzte Zahl und deren Summe ausgeben
    print("Current Number:", current_number, "Last Number:", last_number, "SUM:", sum)
    # Die aktuelle Zahl wird zur letzten Zahl für die nächste Iteration
    last_number = current_number
```
In dieser Schleife wird von `0` bis `9` iteriert. Für jede Iteration wird die Summe der aktuellen Zahl (`current_number`) und der letzten Zahl (`last_number`) berechnet und ausgegeben. Danach wird die aktuelle Zahl zur letzten Zahl für die nächste Iteration.

### Zusammenfassung

Dieses Programm zeigt, wie man eine Schleife verwendet, um die Summe der aktuellen und der vorherigen Zahl zu berechnen und auszugeben. Es ist ein einfaches Beispiel für die Verwendung von Schleifen und Variablen in Python.

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

## Aufgabe 2 Teil 2

In dieser Aufgabe wird ein Python-Programm erstellt, das eine bestimmte Anzahl von Zeichen von einer Zeichenkette entfernt.

### Code-Erklärung

```python
# Funktion definieren, um Zeichen zu entfernen
def removeChars(a, n):
    # Zeichenkette ab dem n-ten Index zurückgeben
    x = a[n:]
    return x
```
Hier wird eine Funktion `removeChars` definiert, die zwei Parameter `a` (die Zeichenkette) und `n` (die Anzahl der zu entfernenden Zeichen) akzeptiert. Die Funktion gibt die Zeichenkette ab dem `n`-ten Index zurück.

```python
# Funktion aufrufen und Ergebnis ausgeben
print(removeChars("1234567string", 7))
```
Diese Zeile ruft die Funktion `removeChars` mit der Zeichenkette `"1234567string"` und `n` gleich `7` auf. Das Ergebnis wird ausgegeben, was `"string"` ist, da die ersten 7 Zeichen entfernt wurden.

### Zusammenfassung

Dieses Programm zeigt, wie man eine Funktion definiert und verwendet, um eine bestimmte Anzahl von Zeichen von einer Zeichenkette zu entfernen. Es ist ein einfaches Beispiel für die Verwendung von Funktionen in Python.
