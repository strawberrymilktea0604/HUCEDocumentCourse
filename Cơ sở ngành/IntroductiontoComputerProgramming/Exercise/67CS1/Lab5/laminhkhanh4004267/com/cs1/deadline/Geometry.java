package com.cs1.deadline;

import java.util.Scanner;
/**
This program demonstrates static methods
*/
public class Geometry
{
public static void main (String [] args)
{
int choice; //the user’s choice
double value = 0; //the value returned from the method
char letter; //the Y or N from the user’s decision
//to exit
double radius; //the radius of the circle
double length; //the length of the rectangle
double width; //the width of the rectangle
double height; //the height of the triangle
double base; //the base of the triangle
double side1; //the first side of the triangle
double side2; //the second side of the triangle
double side3; //the third side of the triangle
//create a scanner object to read from the keyboard
Scanner keyboard = new Scanner (System.in);
//do loop was chose to allow the menu to be displayed
//first
do
{
//call the printMenu method
printMenu();
choice = keyboard.nextInt();
switch (choice)
{
    case 1:
System.out.print(
"Nhap ban kinh cua hinh tron: ");
radius = keyboard.nextDouble();
//call the circleArea method
value = circleArea(radius);
//store the result in the value
System.out.println(
"Dien tich hinh tron la: " + value);
break;

case 2:
System.out.print(
"Nhap chieu dai cua hinh chu nhat: ");
length = keyboard.nextDouble();
System.out.print(
"Nhap chieu rong cua hinh chu nhat: ");
 width = keyboard.nextDouble();
//call the rectangleArea method
value = rectangleArea(length, width);
//store the result in the value
System.out.println(
"Dien tich hinh chu nhat la: " + value);
break;

case 3:
System.out.print(
"Nhap chieu cao cua tam giac: ");
height = keyboard.nextDouble();
System.out.print(
"Nhap canh day cua tam giac: ");
base = keyboard.nextDouble();
//call the triangleArea method
value = triangleArea(height, base);
//store the result in the value
System.out.println(
"Nhap dien tich cua tam giac: " + value);
break;

case 4:
System.out.print(
"Nhap ban kinh cua hinh tron: ");
radius = keyboard.nextDouble();
//call the circumference method
value = circumference(radius);
//store the result in the value
System.out.println(
"Chu vi duong tron la: " + value);
break;

case 5:
System.out.print(
"Nhap chieu dai cua hinh chu nhat: ");
length = keyboard.nextDouble();
System.out.print(
"Nhap chieu rong cua hinh chu nhat: ");
 width = keyboard.nextDouble();
//call the perimeter method
value = rectanglePerimeter(length, width);
//store the result in the value
System.out.println(
"Chu vi hinh chu nhat la: " + value);
break;

case 6:
System.out.print("Nhap chieu dai canh dau tien cua tam giac: " +
"of the triangle: ");
side1 = keyboard.nextDouble();
System.out.print("Nhap chieu dai canh thu hai cua tam giac: " +
"of the triangle: ");
side2 = keyboard.nextDouble();
System.out.print("Nhap chieu dai canh thu ba cua tam giac: " +
"of the triangle: ");
side3 = keyboard.nextDouble();
//call the perimeter method 
value = trianglePerimeter(side1, side2, side3);
//store the result in the value
System.out.println("Chu vi cua tam giac la: " +
"triangle is " + value);
break;

default:
System.out.println(
"You did not enter a valid choice.");
}
//consumes the new line character after the number
keyboard.nextLine();
System.out.println("Do you want to exit the program " +
"(Y/N)?: ");
String answer = keyboard.nextLine();
letter = answer.charAt(0);
}while (letter != 'Y' && letter != 'y');
}

private static double trianglePerimeter(double side1, double side2, double side3) {{ 
    return side1 + side2 + side3;
  }
}

private static double rectanglePerimeter(double length, double width) {
    return (2*length) + (2*width);
}

private static double circumference(double radius) {
    return 2*Math.PI*radius;
}

private static double triangleArea(double height, double base) {
    return (height/base) * 0.5;
}

private static double rectangleArea(double length, double width) {
    double area;
	  area = length*width;
	  return area;	
}

private static double circleArea(double radius) {
    double area;
	  area = Math.PI*Math.pow(radius, 2);
	  return area;
}

public static void printMenu(){
    System.out.println("This is geometry caclulator");
    System.out.println("Choose vhat you like to caculate");
    System.out.println("1. Find area of Circle");
    System.out.println("2. Find  area of a Rectangle");
    System.out.println("3. Find area of a Triangle");
    System.out.println("4. Find circumfrence of Circle");
    System.out.println("5. Find perimeter of a rectangle");
    System.out.println("6. Find perimeter of triangle");
}
  
 
}