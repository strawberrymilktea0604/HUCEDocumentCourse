
public class StaticMember {
private int x;
static int c;

public int getX() {
	return x;
}

public void setX(int x) {
	System.out.println(this);
	this.x = x;
}

public static int getC() {
	return c;
}

public static void setC(int c) {
	StaticMember.c = c;
}

public static void main(String[]args) {
	StaticMember obj1 = new StaticMember();
	StaticMember obj2 = new StaticMember();
	System.out.println(obj1);
	obj1.setX(10);
	
	System.out.println(obj2);
	obj2.setX(100);
	
	System.out.println("Object 1:"+ obj1.getX()+"\nObject 2:"+obj2.getX());
	obj1.setC(1);
	System.out.println("Object 1 c="+ obj1.getC()+"\nObject 2 c="+obj2.getC());
	obj1.setC(10);
	System.out.println("Object 1 c="+ StaticMember.getC()+"\nObject 2 c="+StaticMember.getC());
	obj2.setC(50);
	System.out.println("Object 1 c="+ obj1.getC()+"\nObject 2 c="+obj2.getC());

}
}
