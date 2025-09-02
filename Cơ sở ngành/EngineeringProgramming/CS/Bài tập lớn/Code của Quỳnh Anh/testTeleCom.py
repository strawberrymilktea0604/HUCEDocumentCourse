from itertools import islice
import TeleCom

with open("TelecomInput.txt") as r:
    """Reads the input file and stores the data in a list."""
    numCoordinates = int(r.readline().strip()) #Reads the first line of the file and stores it as an integer.
    data = [line.rstrip("\n") for line in islice(r, 0, None)] #Reads the rest of the file and stores it in a list.
# Coordinates for X and Y are stored in two lists respectively.
x_coordinates = []
y_coordinates = []
for element in data:
    x, y = element.split(" ")
    x_coordinates.append(int(x))
    y_coordinates.append(int(y))
# Creates a list of points from the x and y coordinates.
points = [TeleCom.Point(x, y) for x, y in zip(x_coordinates, y_coordinates)]
mec = TeleCom.welzl(points)
x_center = round(mec.c.x, 6)
y_center = round(mec.c.y, 6)
radius = round(mec.r, 6)
print("Center: ({}, {}), Radius: {}".format(x_center, y_center, radius))
with open("TelecomOutput.txt", "w") as w:
    """Writes the output to a file."""
    w.write(str(x_center) + " " + str(y_center) + "\n" + str(radius))

