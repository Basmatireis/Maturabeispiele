# Aufgabe 1

In dieser Aufgabe berechnen wir die Einkommenssteuer basierend auf verschiedenen Einkommensstufen. Der Code überprüft das Einkommen und berechnet die Steuer entsprechend den angegebenen Steuersätzen.

## Code-Erklärung

```python
# Definiere das Einkommen
for income in [45000]: 
    # Überprüfe, ob das Einkommen kleiner oder gleich 10.000 ist
    if income <= 10_000: 
        # Setze die Steuer auf 0
        tax = 0 
    # Überprüfe, ob das Einkommen kleiner oder gleich 20.000 ist
    elif income <= 20_000:  
        # Berechne die Steuer für Einkommen zwischen 10.000 und 20.000
        tax = (income - 10_000) * 0.1               
    else: 
        # Berechne die Steuer für Einkommen über 20.000
        tax = (income-20_000) * 0.2 +  10_000*0.1  

    # Drucke das Ergebnis
    print(f"For example, suppose that the taxable income is ${income} the income tax payable is $10000*0% + $10000*10%  + $25000*20% = ${tax}. ")
```

### Detaillierte Erklärung

1. **Einkommen definieren**: Das Einkommen wird in einer Liste definiert, in diesem Fall `45000`.
2. **Überprüfung der Einkommensstufen**:
    - Wenn das Einkommen kleiner oder gleich `10_000` ist, wird die Steuer auf `0` gesetzt.
    - Wenn das Einkommen zwischen `10_000` und `20_000` liegt, wird die Steuer für den Betrag über `10_000` mit `10%` berechnet.
    - Wenn das Einkommen über `20_000` liegt, wird die Steuer für den Betrag über `20_000` mit `20%` berechnet, zusätzlich zu den `10%` für die ersten `10_000`.
3. **Ergebnis drucken**: Das berechnete Steuerergebnis wird in einem formatierten String ausgegeben.

# Aufgabe 2

In dieser Aufgabe erstellen wir ein Multiplikationstabelle. Der Code durchläuft zwei Schleifen, um die Produkte der Zahlen von 1 bis 10 zu berechnen und anzuzeigen.

## Code-Erklärung

```python
# Schleife durch die Zahlen 1 bis 10
for x in range(1, 11): 
    # Drucke eine neue Zeile
    print("") 
    # Schleife durch die Zahlen 1 bis 10
    for y in range(1, 11): 
        # Drucke das Produkt von x und y, ohne Zeilenumbruch
        print(x * y, end=" ")
```

### Detaillierte Erklärung

1. **Äußere Schleife**: Iteriert durch die Zahlen von `1` bis `10` (Variable `x`).
2. **Neue Zeile drucken**: Für jede Iteration der äußeren Schleife wird eine neue Zeile gedruckt.
3. **Innere Schleife**: Iteriert ebenfalls durch die Zahlen von `1` bis `10` (Variable `y`).
4. **Produkt drucken**: Das Produkt von `x` und `y` wird berechnet und ohne Zeilenumbruch gedruckt, um die Multiplikationstabelle in einer Zeile darzustellen.

