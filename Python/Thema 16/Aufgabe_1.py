for income in [45000]: 
    if income <= 10_000: 
        tax = 0 
    elif income <= 20_000:  
        tax = (income - 10_000) * 0.1               
    else: 
        tax = (income-20_000) * 0.2 +  10_000*0.1  

    print(f"For example, suppose that the taxable income is ${income} the income tax payable is $10000*0% + $10000*10%  + $25000*20% = ${tax}. ") 