original_string = "pynative"

print("Orginal String is", original_string)
print("Printing only even index chars")

for position in range(len(original_string)):
    if position % 2 == 0:
        print(original_string[position])