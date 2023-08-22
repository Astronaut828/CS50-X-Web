from pyfiglet import Figlet
from sys import argv
from sys import exit
import random


figlet = Figlet()
fonts = figlet.getFonts()

if len(argv) == 1:
    input = input("Input: ")
    random = figlet.setFont(font=random.choice(fonts))
    userinput = figlet.renderText(input)
    print("Output:")
    print(userinput)

if len(argv) == 2:
        print('Invalid usage')
        exit(0)

if len(argv) == 3:
    if argv[1] != "-f" and argv[1] != "--font":
        print('Invalid usage')
        exit(1)

    if argv[2] not in fonts:
        print('Invalid usage')
        exit(2)

if len(argv) == 3:
    input = input("Input: ")
    figlet.setFont(font=argv[2])
    request = figlet.renderText(input)
    print("Output:")
    print(request)
