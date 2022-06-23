"""Info Header

    Jeremy Davis
    Project 3
    SNHU CS-210
    June 19, 2022

    Item-Tracking Program
    Takes a list of items purchased during a day (file)
    Counts the number of items and provides an itemized list 

    This program uses C++ and Python functions for data calculations

    These are the Python fucntions."""

import re
import string
import collections
from os import system, name

# fucntion produce a list of items purchased with the quantity for each item purchased
def ListItemsPurchased():
    system('cls')
    frequency = {}
    with open('GroceryList.txt') as file:

        # Finds the frequency of each word in the text file 
        for row in file:
            row = row.strip()
            if row:
                count = frequency.get(row,0)
                frequency[row] = count + 1

        # Allows us to see our keys 
        frequency_list = frequency.keys()

        # Gets the word and its frequency
        for words in frequency_list:
            print(words,frequency[words])

    file.close()

    return None

# function to return quantity of item received as a parameter
def FrequencyOfItem(item):
    frequency = {}
    item_frequency = 0

    with open('GroceryList.txt') as file:

        # Finds the frequency of each word in the text file 
        for row in file:
            row = row.strip()
            if row:
                count = frequency.get(row,0)
            frequency[row] = count + 1

        # Allows us to see our keys 
        frequency_list = frequency.keys()
        frequency_list

        # Gets frequency of item
        for words in frequency_list:
            if words.lower() == item.lower():          # .lower sets the string to lowercase 
                item_frequency = frequency[words]      # if words equals items, count number of times the match occurs.

    return item_frequency

# function to print a histogram of the items purchased
def ItemHistogram():
    system('cls')
    frequency = {}
    with open('GroceryList.txt') as file:

        # Finds the frequency of each word in the text file 
        for row in file:
            row = row.strip()
            if row:
                count = frequency.get(row,0)
                frequency[row] = count + 1

    file.close()

    file1 = open("frequency.dat", "w")

    # Allows us to see our keys 
    frequency_list = frequency.keys()

    # Gets the word and its frequency
    for words in frequency_list:
        count = str(frequency[words])
        file1.write(words + " " + count + "\n")

    file1.close()

    return None