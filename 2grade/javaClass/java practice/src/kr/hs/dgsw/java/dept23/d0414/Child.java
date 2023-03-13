package kr.hs.dgsw.java.dept23.d0414;

// extends를 해서 상속받을 수 있다
public class Child extends Parent{
 private int age;
 public void showAge() {
	 System.out.println(age);
 }
 // 자식이 부모를 상속받는다
 public static void main(String[] args) {
	 Child child = new Child();
	 System.out.println(child.age);
	 System.out.println("name : "+child.name);
	 child.sayHello();
	 
	 // ----------------
	 
	 Parent parent = new Child();
	 Parent realParent = new Parent();
//	 Child child1 = new Parent();
	 
	 parent.sayHello();
//	 parent.showAge();
	 
	 System.out.println(parent + " " + parent.getClass());
	 System.out.println(realParent + " " + realParent.getClass());
	 
	 Child child1 = (Child)parent;
	 Child child2 = (Child)realParent; // Parent를 Child로 만들 수 없다
	 
	 // ----------------
 }
}
