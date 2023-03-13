package kr.hs.dgsw.java.dept23.d0421;

public class Zoo {
//	public void breed(Pig pig) {
//		System.out.printf("%s가 %s웁니다. \n",pig.getName(),pig.getSound());
//	}
//	public void breed(Duck duck) {
//		System.out.printf("%s가 %s웁니다. \n",duck.getName(),duck.getSound());
//	}
	
	// 원래 위처럼 각각의 타입에 맞는 breed를 만들었어야 했지만
	// 상속 받으면 부모의 타입을 받기 때문에
	// animal이라는 객체를 상속받아 사용함으로써 재활용시킨다
	public void breed(Animal animal) {
		System.out.printf("%s가 %s웁니다\n", animal.getName(),animal.getSound());
	}
	public static void main(String[] args) {
		Zoo zoo = new Zoo();
		
		Pig pig = new Pig();
		zoo.breed(pig);
		
		Duck duck = new Duck();
		zoo.breed(duck);
		
		Cat cat = new Cat();
		zoo.breed(cat);
	}
	
	// 이런 상속의 개념을 활용해서 실제로 사용할 때
	// 작은 부분을 고쳐 할 때 상속을 사용해서 효율적으로 해결할 수 있다
}
