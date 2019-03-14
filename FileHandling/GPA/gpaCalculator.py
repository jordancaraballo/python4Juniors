# -*- coding: utf-8 -*-
"""
Purpose: Script to Calculate GPA. Python4Kids tutorials.
Author: Jordan A Caraballo Vega
"""
import csv

credTotal      = 0 # define count for total of credits
gradesTotal    = 0 # define count for total of grades
gradesFilename = 'Grades.csv' # define grades filename

print ("Hey, I am Calculating your GPA...")

with open(gradesFilename) as csvfile: # open csv file
    reader = csv.DictReader(csvfile) # read csv elements as dict
    for row in reader: # for each row (class) in the file
        if row['Score'] != 'S' and row['Score'] != 'P': # ignore non-approved classes
            credTotal += int(row['Credits']) # add to the credits counter
            gradesTotal += int(row['Credits']) * int(row['Score']) # add to the grades counter

    gpa = float(gradesTotal) / float(credTotal) # calculate gpa

print ("Hey, Your GPA is: ", gpa)
