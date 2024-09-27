package SquareAndCube;

public class SquareAndCube {

	public static void main(String[] args) {\
		int stuNum = 16;
		int square = stuNum * stuNum; // calculate square
		int cubic = stuNum * stuNum * stuNum; // calculate cube
		System.out.println("StudentID MyName");
	    System.out.println("   1	 6666666 ");
	    System.out.println("  11	66     66");
	    System.out.println(" 1 1	6        ");
	    System.out.println("   1	6        ");
	    System.out.println("   1	66666666 ");
	    System.out.println("   1	66     66");
	    System.out.println("   1	6       6");
	    System.out.println("   1	66     66");
	    System.out.println(" 11111	 6666666 ");
		System.out.println("Last two digits of the student ID: "+stuNum+
				"\nSquare: "+square+"\nCube: "+cubic);
	}
}
