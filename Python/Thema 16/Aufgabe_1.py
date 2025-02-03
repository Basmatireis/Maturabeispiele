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